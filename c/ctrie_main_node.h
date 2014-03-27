/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#ifndef CTRIE_MAIN_NODE_H
#define CTRIE_MAIN_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum MainNodeType_t {
  CNODE = 0,
  TNODE = 1,
  LNODE = 2
} MainNodeType_t;

typedef struct MainNode_t {
  MainNodeType_t type;  
} MainNode_t;

#ifdef __cplusplus
}
#endif

#endif
