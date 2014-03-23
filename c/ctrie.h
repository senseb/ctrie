/*    Copyright 2013-2014 Convey Compliance Systems, Inc.
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#ifndef HASH_TRIE_H
#define HASH_TRIE_H

#include <stdlib.h>

#define BOOL int
#define W 5

typedef enum NodeType_t { 
  CNode = 0, 
  SNode = 1 
} NodeType_t;

typedef struct CNode_t {
  unsigned int bmp;
  struct MainNode_t* array[2 << (W - 1)];
} CNode_t;

typedef struct SNode_t {
  void* key;
  void* value;
  BOOL tomb;
} SNode_t;

typedef struct MainNode_t {
  NodeType_t type;
  union {
    CNode_t cnode;
    SNode_t snode;
  };
} MainNode_t;

typedef struct INode_t {
  MainNode_t* mainnode;
} INode_t;

typedef struct CTrie_t {
  INode_t* root;
} CTrie_t;

typedef struct addDownResult_t {
  int added;
  size_t oldData;
} addDownResult_t;

void ctrie_insert( CTrie_t* _this, void* key, void* value );

#endif