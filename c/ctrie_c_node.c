/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include <stdlib.h>

#include "ctrie_c_node.h"
#include "ctrie_memory.h"

CNode_t* CTrie_CNode_createEmpty() {
  CNode_t* res = ( CNode_t* ) ctrie_alloc( sizeof( CNode_t ) );
  res->bmp = 0;
  res->array = NULL;

  return res;
}