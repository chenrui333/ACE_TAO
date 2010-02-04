/* -*- c++ -*- */

//=============================================================================
/**
 *  @file    root_sh.h
 *
 *  $Id$
 *
 *  Concrete visitor for the Root class
 *  This one provides code generation for elements of the Root node in the
 *  server header.
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================


#ifndef _BE_VISITOR_ROOT_ROOT_SH_H_
#define _BE_VISITOR_ROOT_ROOT_SH_H_

/**
 * @class be_visitor_root_sh
 *
 * @brief be_visitor_root_sh
 *
 * This is a concrete visitor to generate the server header for root
 */
class be_visitor_root_sh : public be_visitor_root
{
public:
  /// constructor
  be_visitor_root_sh (be_visitor_context *ctx);

  /// destructor
  ~be_visitor_root_sh (void);

  /// set the right context and make a visitor
  virtual int init (void);
};

#endif /* _BE_VISITOR_ROOT_ROOT_SH_H_ */
