/*    Copyright 2013-2014 Jose Sebastian Battig, Inc.
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#ifndef L_NODE_H
#define L_NODE_H

#include "ctrie_s_node.h"

#ifdef __cplusplus
  extern "C" {
#endif

typedef struct LNode_t {
  SNode_t sn;
  struct LNode_t* next;
} LNode_t;

#endif
