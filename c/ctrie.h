/*    Copyright 2013-2014 Convey Compliance Systems, Inc.
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#ifndef HASH_TRIE_H
#define HASH_TRIE_H

#include <stdlib.h>

#define LEAF_SIZE 256

typedef struct hashTrieTreeItem_t {
  int level;
  int filled;
  void* items[LEAF_SIZE];
} hashTrieTreeItem_t;

typedef struct addDownResult_t {
  int added;
  size_t oldData;
} addDownResult_t;

addDownResult_t hashTrie_addDown( hashTrieTreeItem_t* _this, size_t value, size_t data, size_t hash );

#endif