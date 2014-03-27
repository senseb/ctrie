/*    Copyright 2013-2014 Jose Sebastian Battig, Inc.
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include "branch_array.h"

#ifndef C_NODE_H
#define C_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CNode_t {
  unsigned int bmp;
  Branch_Array array;
} CNode_t;

#endif
