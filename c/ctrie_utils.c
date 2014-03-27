/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include "ctrie_utils.h"

BOOL CAS( void** src, void* comperand, void* newvalue ) {
  if( *src == comperand ) {
    *src = newvalue;
    return TRUE;
  } else {
    return FALSE;
  }
}

unsigned int NumberOfSetBits(unsigned int i) {
  i = i - ( ( i >> 1 ) & 0x55555555 );
  i = ( i & 0x33333333 ) + ( ( i >> 2 ) & 0x33333333 );
  return ( ( ( i + ( i >> 4 ) ) & 0x0F0F0F0F ) * 0x01010101 ) >> 24;
}

void Key_flagpos( Key_t* key, unsigned int level, unsigned int bmp, FlagPos_t* flagPos ) {
  flagPos->flag = 1 << ( (key->hc >> ( K * level )) & ( ( 1 << K ) - 1 ) );
  flagPos->pos = NumberOfSetBits( ( flagPos->flag - 1 ) & bmp );
}