/*    Copyright 2013-2014 Convey Compliance Systems, Inc.
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include "ctrie.h"

addDownResult_t hashTrie_addDown( hashTrieTreeItem_t* _this, size_t value, size_t data, size_t hash ) {
  addDownResult_t result;

  result.added = 1;
  result.oldData = 0;

  return result;
}