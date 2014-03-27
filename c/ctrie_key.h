/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include "ctrie_branch_array.h"

#ifndef CTRIE_KEY_H
#define CTRIE_KEY_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Key_t {
  unsigned int hc;
  void* key;
} Key_t;

#ifdef __cplusplus
}
#endif

#endif
