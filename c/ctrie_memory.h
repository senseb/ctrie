/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#ifndef CTRIE_MEMORY_H
#define CTRIE_MEMORY_H

#include <stdint.h>

#ifdef __cplusplus
  extern "C" {
#endif

void* ctrie_alloc( size_t size );
void ctrie_free( void* p );
void* ctrie_realloc( void* p, size_t size );

#ifdef __cplusplus
  }
#endif

#endif