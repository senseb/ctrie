/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include "ctrie.h"

void CTrie_init( CTrie_t* _this ) {
  _this->root = NULL;
}

void CTrie_insert( CTrie_t* _this, Key_t* key, void* value ) {
}