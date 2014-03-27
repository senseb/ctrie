/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include "ctrie_key.h"

#ifndef CTRIE_S_NODE_H
#define CTRIE_S_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SNode_t {
  Key_t key;
  void* value;
} SNode_t;

#ifdef __cplusplus
}
#endif

#endif
