/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#ifndef CTRIE_L_NODE_H
#define CTRIE_L_NODE_H

#include "ctrie_s_node.h"

#ifdef __cplusplus
  extern "C" {
#endif

typedef struct LNode_t {
  SNode_t sn;
  struct LNode_t* next;
} LNode_t;

#ifdef __cplusplus
  }
#endif

#endif
