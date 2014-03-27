/*    Copyright 2013-2014 Jose Sebastian Battig, Inc.
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#ifndef I_NODE_H
#define I_NODE_H

#include "main_node.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct INode_t {
  MainNode_t* mainnode;
} INode_t;

#endif

