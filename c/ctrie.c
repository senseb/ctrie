/*    Copyright 2013-2014 Convey Compliance Systems, Inc.
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include "ctrie.h"

#define IS_NULL_INODE( node ) ( !r->mainnode )

void ctrie_insert( CTrie_t* _this, void* key, void* value ) {
  INode_t* r = _this->root;

  if( !r || IS_NULL_INODE( r ) ) {

  }
}