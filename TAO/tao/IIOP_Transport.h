// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//     IIOP_Transport.h
//
// = DESCRIPTION
//     IIOP Transport specific processing
//
// = AUTHOR
//     Fred Kuhns <fredk@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_IIOP_TRANSPORT_H
#define TAO_IIOP_TRANSPORT_H

#include "tao/Pluggable.h"

// Forward decls.
class TAO_IIOP_Handler_Base;
class TAO_Client_Connection_Handler;
class TAO_Server_Connection_Handler;
class TAO_ORB_Core;

class TAO_Export TAO_IIOP_Transport : public TAO_Transport
{
  // = TITLE
  //   This class acts as a bridge class to the transport specific 
  //   connection handler (handler_).  
  //
  // = DESCRIPTION
  //   Specialization of the base TAO_Transport class to handle the IIOP
  //   protocol.  This class in turn will be further speciialized for
  //   the client and server side.
public:
  TAO_IIOP_Transport (TAO_IIOP_Handler_Base *handler);
  // Base object's creator method. 

  ~TAO_IIOP_Transport (void);
  // Default destructor.

  CORBA::ULong tag (void);
  // Returns the specific IOP instance, in this case UIOP.

  void close_connection (void);
  // Call the corresponding connection handlers handle_close method.

  void resume_connection (ACE_Reactor *reactor);
  // Calls the reactors resume_handler on behalf of the corresponding
  // connection handler.

  int idle (void);
  // Idles the corresponding connection handler.

  TAO_IIOP_Handler_Base *&handler (void);
  // Return a reference to the corresponding connection handler.

  int is_nil (TAO_Transport *obj);
  // Returns 0 if the obj is 0, else 1.

  TAO_Transport *_nil (void);
  // Return a NULL pointer of type TAO_Transport *.

  ACE_HANDLE handle (void);
  // Return the underlying connection handle.

  ssize_t send (const ACE_Message_Block *mblk,
                ACE_Time_Value *s = 0);
  // Write the contents of the Message_Block to the connection.

  ssize_t send (const u_char *buf,
                size_t len,
                ACE_Time_Value *s = 0);
  // Write the contents of the buffer of length len to the connection.

  ssize_t send (const iovec *iov,
                int iovcnt,
                ACE_Time_Value *s = 0);
  // Write the contents of iovcnt iovec's to the connection.

  ssize_t recv (char *buf,
                size_t len,
                ACE_Time_Value *s = 0);
  // Read len bytes from into buf.

  ssize_t recv (char *buf,
                size_t len,
                int flags,
                ACE_Time_Value *s = 0);
  // Read len bytes from into buf using flags.

  ssize_t recv (iovec *iov,
                int iovcnt,
                ACE_Time_Value *s = 0);
  //  Read received data into the iovec buffers.

  // @@ Fred, why is this method defined inline?  It should be defined
  // in the *.cpp file!
  virtual int send_request (TAO_ORB_Core *  /* orb_core */,
                            TAO_OutputCDR & /* stream   */,
                            int             /* twoway   */) { return -1; };
  // Default action to be taken for send request.

protected:
  TAO_IIOP_Handler_Base *handler_;
  // the connection service handler used for accessing lower layer
  // communication protocols.
};

class TAO_Export TAO_IIOP_Client_Transport : public TAO_IIOP_Transport
{
  // = TITLE
  //   The Transport class used for Client side communication with a
  //   server.
  // 
  // = DESCRIPTION
  //   Specialization of the TAO_IIOP_Transport class for client
  //   side.  Methods related to sending one and two way requests
  //   lives here.
public:
  TAO_IIOP_Client_Transport (TAO_Client_Connection_Handler *handler);
  // Constructor.  Note, TAO_IIOP_Handler_Base is the base class for
  // both TAO_Client_Connection_Handler and
  // TAO_Server_Connection_Handler.

  ~TAO_IIOP_Client_Transport (void);
  // destructor

  TAO_Client_Connection_Handler *client_handler (void);
  // return a pointer to the client's connection handler.

  int send_request (TAO_ORB_Core *orb_core,
                    TAO_OutputCDR &stream,
                    int twoway);
  // This is a bridge method for the connection handlers
  // <send_request> method.  The connection handler is responsible for
  // concurrency strategies, typically using the leader-follower
  // pattern.

private:
  TAO_Client_Connection_Handler *client_handler_;
  // pointer to the corresponding client side connection handler.
};

class TAO_Export TAO_IIOP_Server_Transport : public TAO_IIOP_Transport
{
  // = TITLE
  //   The Transport class used for server communication with a
  //   connected client.
  //
  // = DESCRIPTION
  //   Specialization of the TAO_IIOP_Transport class for the server side.
  //   methods for reading messages (requests) and sending replies live
  //   here.
public:

  TAO_IIOP_Server_Transport (TAO_Server_Connection_Handler *handler);
  //  Default creator method.

  ~TAO_IIOP_Server_Transport (void);
  // Default destructor

  TAO_Server_Connection_Handler *server_handler (void);
  //  Return a pointer to the underlying connection handler. 

private:
  TAO_Server_Connection_Handler *server_handler_;
  // Pointer to the corresponding connection handler.
};

#endif  /* TAO_IIOP_TRANSPORT_H */
