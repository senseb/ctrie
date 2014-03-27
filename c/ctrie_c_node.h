/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include "ctrie_branch_array.h"

#ifndef CTRIE_C_NODE_H
#define CTRIE_C_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CNode_t {
  unsigned int bmp;
  Branch_Array array;
} CNode_t;

CNode_t* CTrie_CNode_createEmpty();

#ifdef __cplusplus
}
#endif

#endif
