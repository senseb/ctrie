/*
 *     SuperFastHash by Paul Hsieh
 */

#ifndef CTRIE_UTILS_H
#define CTRIE_UTILS_H

#include "ctrie_key.h"

#ifdef __cplusplus
  extern "C" {
#endif

#define BOOL int
#define FALSE 0
#define TRUE 1
#define K 5

typedef struct FlagPos_t {
  unsigned int flag;
  unsigned int pos;
} FlagPos_t;

BOOL CAS( void** src, void* comperand, void* newvalue );
unsigned int NumberOfSetBits( unsigned int i );
void Key_flagpos( Key_t* key, unsigned int level, unsigned int bmp, FlagPos_t* flagPos );

#ifdef __cplusplus
  }
#endif

#endif