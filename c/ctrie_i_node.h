/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#ifndef CTRIE_I_NODE_H
#define CTRIE_I_NODE_H

#include "ctrie_main_node.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct INode_t {
  MainNode_t* mainnode;
} INode_t;

#ifdef __cplusplus
}
#endif

#endif

