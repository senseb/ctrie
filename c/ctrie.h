/*    Copyright 2013-2014 Jose Sebastian Battig, Inc.
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#ifndef CTRIE_H
#define CTRIE_H

#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
  extern "C" {
#endif

#define BOOL int
#define FALSE 0
#define TRUE 1
#define K 5
#define ARRAY_COUNT ( 2 << (K - 1) )

typedef struct Key_t {
  unsigned int hc;
  void* key;
} Key_t;

typedef enum NodeType_t { 
  CNODE = 0, 
  SNODE = 1,
  INODE = 2
} NodeType_t;

//typedef struct ArrayNode_t* ArrayNodeArray_t;

typedef struct CNode_t {
  unsigned int bmp;
  struct ArrayNode_t* arr;
} CNode_t;

typedef struct SNode_t {
  Key_t key;
  void* value;
  BOOL tomb;
} SNode_t;

typedef struct ArrayNode_t {
  NodeType_t type;
  union {
    void* node;
    SNode_t* snode;
    struct INode_t* inode;
  };
} ArrayNode_t;

typedef struct CTrie_t {
  INode_t* root;
} CTrie_t;

typedef struct addDownResult_t {
  int added;
  size_t oldData;
} addDownResult_t;

uint32_t SuperFastHash (const char * data, int len);
void CTrie_init( CTrie_t* _this );
void CTrie_insert( CTrie_t* _this, Key_t* key, void* value );

#ifdef __cplusplus
}
#endif

#endif