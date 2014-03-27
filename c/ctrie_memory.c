/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include <memory.h>

void* ctrie_alloc( size_t size ) {
  return malloc( size );
}

void ctrie_free( void* p ) {
  free( p );
}

void* ctrie_realloc( void* p, size_t size ) {
  return realloc( p, size );
}
