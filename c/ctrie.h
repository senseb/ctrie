/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#ifndef CTRIE_H
#define CTRIE_H

#include <stdlib.h>
#include <stdint.h>

#include "ctrie_utils.h"
#include "ctrie_key.h"
#include "ctrie_i_node.h"

#ifdef __cplusplus
  extern "C" {
#endif

typedef struct CTrie_t {
  INode_t* root;
  BOOL readonly;
} CTrie_t;

void CTrie_init( CTrie_t* _this );
void CTrie_insert( CTrie_t* _this, Key_t* key, void* value );

#ifdef __cplusplus
}
#endif

#endif