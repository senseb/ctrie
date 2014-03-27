/*    Copyright 2013-2014 Jose Sebastian Battig
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#ifndef CTRIE_BRANCH_ARRAY_H
#define CTRIE_BRANCH_ARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum BranchType_t {
  INODE = 1,
  SNODE = 2
} BranchType_t;

typedef struct Branch_t {
  BranchType_t type;
} Branch_t;

typedef Branch_t* Branch_Array;

#ifdef __cplusplus
}
#endif

#endif
