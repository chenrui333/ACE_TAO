// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_SERVANTMANAGERC_H_
#define _TAO_IDL_ORIG_SERVANTMANAGERC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "portableserver_export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_PortableServer_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from 
// be\be_visitor_root/root_ch.cpp:62

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  class Collocation_Proxy_Broker;
  
  template<typename T> class Narrow_Utils;
  template<typename T> class AbstractBase_Narrow_Utils;
}

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace PortableServer
{
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_PORTABLESERVER_SERVANTMANAGER__VAR_OUT_CH_)
#define _PORTABLESERVER_SERVANTMANAGER__VAR_OUT_CH_
  
  class ServantManager;
  typedef ServantManager *ServantManager_ptr;
  
  typedef
    TAO_Objref_Var_T<
        ServantManager
      >
    ServantManager_var;
  
  typedef
    TAO_Objref_Out_T<
        ServantManager
      >
    ServantManager_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLESERVER_SERVANTMANAGER_CH_)
#define _PORTABLESERVER_SERVANTMANAGER_CH_
  
  class TAO_PortableServer_Export ServantManager
    : public virtual CORBA::Object
  {
  public:
    typedef ServantManager_ptr _ptr_type;
    typedef ServantManager_var _var_type;
    
    // The static operations.
    static ServantManager_ptr _duplicate (ServantManager_ptr obj);
    
    static void _tao_release (ServantManager_ptr obj);
    
    static ServantManager_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ServantManager_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ServantManager_ptr _nil (void)
    {
      return static_cast<ServantManager_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    ServantManager (void);
    
    virtual ~ServantManager (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ServantManager (const ServantManager &);
    
    void operator= (const ServantManager &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr const _tc_ServantManager;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module PortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLESERVER_SERVANTMANAGER__TRAITS_CH_)
#define _PORTABLESERVER_SERVANTMANAGER__TRAITS_CH_
  
  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::ServantManager>
  {
    static ::PortableServer::ServantManager_ptr duplicate (
        ::PortableServer::ServantManager_ptr
      );
    static void release (
        ::PortableServer::ServantManager_ptr
      );
    static ::PortableServer::ServantManager_ptr nil (void);
    static CORBA::Boolean marshal (
        ::PortableServer::ServantManager_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::ServantManager_ptr); // copying
TAO_PortableServer_Export void operator<<= (CORBA::Any &, PortableServer::ServantManager_ptr *); // non-copying
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableServer::ServantManager_ptr &);

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

// TAO_IDL - Generated from
// be\be_codegen.cpp:969

#if defined (__ACE_INLINE__)
#include "ServantManagerC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


