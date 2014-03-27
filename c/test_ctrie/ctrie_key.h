/*    Copyright 2013-2014 Jose Sebastian Battig, Inc.
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include "branch_array.h"

#ifndef KEY_H
#define KEY_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Key_t {
  unsigned int hc;
  void* key;
} Key_t;

#endif
