// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//      UIOP_Acceptor.cpp
//
// = DESCRIPTION
//
//
// = AUTHOR
//     Fred Kuhns <fredk@cs.wustl.edu>
//     Ossama Othman <othman@cs.wustl.edu>
//
// ============================================================================

#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

#include "tao/UIOP_Acceptor.h"
#include "tao/UIOP_Profile.h"
#include "tao/ORB_Core.h"
#include "tao/Server_Strategy_Factory.h"
#include "tao/GIOP.h"


UIOP_CREATION_STRATEGY TAO_UIOP_Acceptor::UIOP_Creation_Strategy_;
UIOP_ACCEPT_STRATEGY TAO_UIOP_Acceptor::UIOP_Accept_Strategy_;
UIOP_CONCURRENCY_STRATEGY TAO_UIOP_Acceptor::UIOP_Concurrency_Strategy_;
UIOP_SCHEDULING_STRATEGY TAO_UIOP_Acceptor::UIOP_Scheduling_Strategy_;

TAO_UIOP_Acceptor::TAO_UIOP_Acceptor (void)
  : TAO_Acceptor (TAO_IOP_TAG_INTERNET_IOP),  // @@ FIXME:  IIOP specific?
    base_acceptor_ ()
{
}

TAO_Profile *
TAO_UIOP_Acceptor::create_profile (TAO_ObjectKey &)
{
  return 0;
}

ACE_Event_Handler *
TAO_UIOP_Acceptor::acceptor (void)
{
  return &base_acceptor_;
}

int
TAO_UIOP_Acceptor::open (TAO_ORB_Core *orb_core,
                         ACE_CString &address)
{
  ACE_UNIX_Addr addr (address.c_str ());

  if (this->base_acceptor_.open (
                  // orb_core->orb_params ()->addr (),
                  addr,
                  orb_core->reactor(),
                  &UIOP_Creation_Strategy_,
                  &UIOP_Accept_Strategy_,
                  &UIOP_Concurrency_Strategy_,
                  &UIOP_Scheduling_Strategy_) == -1)
      return -1;
    else
      {
        // The following step is necessary since the user may have specified
        // a 0 for a port number.  Once we open the acceptor, we can recheck
        // the address and get the accurate port number.
        ACE_UNIX_Addr new_address;

        if (base_acceptor_.acceptor ().get_local_addr (new_address) == -1)
          return -1;

        // Reset the address
        // orb_core->orb_params ()->addr (new_address);
        // The above call is broken since orb_params still wants a
        // an ACE_INET_Addr.  We need to give it an ACE_UNIX_Addr.
        
        // uiop_acceptor->acceptor ().enable (ACE_CLOEXEC);
        // this is done in the connection handlers open method.

        // @@  This is broken.  The acceptor registry must be able to
        // determine if a given profile refers to a collocated object.
        // for now, this is done using a hash table and the UNIX_Addr
        // as the key.  This poa is the value I believe fredk.
        // this->orb_core->add_to_collocation_table ();
      }
  return 0;
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Acceptor<TAO_UIOP_Server_Connection_Handler, ACE_LSOCK_Acceptor>;
template class ACE_Strategy_Acceptor<TAO_UIOP_Server_Connection_Handler, ACE_LSOCK_Acceptor>;

template class ACE_Creation_Strategy<TAO_UIOP_Server_Connection_Handler>;
template class ACE_Accept_Strategy<TAO_UIOP_Server_Connection_Handler, ACE_LSOCK_ACCEPTOR>;
template class ACE_Concurrency_Strategy<TAO_UIOP_Server_Connection_Handler>;
template class ACE_Scheduling_Strategy<TAO_UIOP_Server_Connection_Handler>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Acceptor<TAO_UIOP_Server_Connection_Handler, ACE_LSOCK_Acceptor>
#pragma instantiate ACE_Strategy_Acceptor<TAO_UIOP_Server_Connection_Handler, ACE_LSOCK_Acceptor>

#pragma instantiate ACE_Creation_Strategy<TAO_UIOP_Server_Connection_Handler>
#pragma instantiate ACE_Accept_Strategy<TAO_UIOP_Server_Connection_Handler, ACE_LSOCK_ACCEPTOR>
#pragma instantiate ACE_Concurrency_Strategy<TAO_UIOP_Server_Connection_Handler>
#pragma instantiate ACE_Scheduling_Strategy<TAO_UIOP_Server_Connection_Handler>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */


#endif  /* !ACE_LACKS_UNIX_DOMAIN_SOCKETS */
