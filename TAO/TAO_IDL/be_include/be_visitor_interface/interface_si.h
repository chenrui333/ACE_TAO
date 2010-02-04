/* -*- c++ -*- */
//=============================================================================
/**
 *  @file    interface_si.h
 *
 *  $Id$
 *
 *  Concrete visitor for the Interface node.
 *  This provides for code generation in the server inline
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================


#ifndef _BE_INTERFACE_INTERFACE_SI_H_
#define _BE_INTERFACE_INTERFACE_SI_H_

/**
 * @class be_visitor_interface_si
 *
 * @brief be_visitor_interface_si
 *
 * This is a concrete visitor to generate the server inline for interface
 */
class be_visitor_interface_si : public be_visitor_interface
{
public:
  /// constructor
  be_visitor_interface_si (be_visitor_context *ctx);

  /// destructor
  ~be_visitor_interface_si (void);

  /// set the right context and make a visitor
  virtual int visit_interface (be_interface *node);

protected:
  virtual int generate_amh_classes (be_interface *node);
};

#endif /* _BE_INTERFACE_INTERFACE_SI_H_ */
