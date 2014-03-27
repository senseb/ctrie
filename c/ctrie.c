/*    Copyright 2013-2014 Jose Sebastian Battig, Inc.
 *
 *    All rights reserved. No warranty, explicit or implicit, provided. 
 */

#include "ctrie.h"
#include <malloc.h>
#include <memory.h>
#include <string.h>

BOOL CAS( void** src, void* comperand, void* newvalue ) {
  if( *src == comperand ) {
    *src = newvalue;
    return TRUE;
  } else {
    return FALSE;
  }
}

#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
  +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif

#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
  +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif

uint32_t SuperFastHash (const char * data, int len) {
  uint32_t hash = len, tmp;

  int rem;
  if (len <= 0 || data == NULL) return 0;

  rem = len & 3;
  len >>= 2;

  /* Main loop */
  for (;len > 0; len--) {
    hash  += get16bits (data);
    tmp    = (get16bits (data+2) << 11) ^ hash;
    hash   = (hash << 16) ^ tmp;
    data  += 2*sizeof (uint16_t);
    hash  += hash >> 11;
  }

  /* Handle end cases */
  switch (rem) {
  case 3: hash += get16bits (data);
    hash ^= hash << 16;
    hash ^= data[sizeof (uint16_t)] << 18;
    hash += hash >> 11;
    break;
  case 2: hash += get16bits (data);
    hash ^= hash << 11;
    hash += hash >> 17;
    break;
  case 1: hash += *data;
    hash ^= hash << 10;
    hash += hash >> 1;
  }

  /* Force "avalanching" of final 127 bits */
  hash ^= hash << 3;
  hash += hash >> 5;
  hash ^= hash << 4;
  hash += hash >> 17;
  hash ^= hash << 25;
  hash += hash >> 6;

  return hash;
}

#define IS_NULL_INODE( node ) ( !r->mainnode )

typedef struct FlagPos_t {
  unsigned int flag;
  unsigned int pos;
} FlagPos_t;

static unsigned int NumberOfSetBits(unsigned int i)
{
  i = i - ( ( i >> 1 ) & 0x55555555 );
  i = ( i & 0x33333333 ) + ( ( i >> 2 ) & 0x33333333 );
  return ( ( ( i + ( i >> 4 ) ) & 0x0F0F0F0F ) * 0x01010101 ) >> 24;
}

static void Key_flagpos( Key_t* key, unsigned int level, unsigned int bmp, FlagPos_t* flagPos ) {
  flagPos->flag = 1 << ( (key->hc >> ( K * level )) & ( ( 1 << K ) - 1 ) );
  flagPos->pos = NumberOfSetBits( ( flagPos->flag - 1 ) & bmp );
}

CNode_t* CNode_create( unsigned int arraySize );

static CNode_t* CNode_clone( CNode_t* src ) {
  CNode_t* res = CNode_create( NumberOfSetBits( src->bmp ) + 1 );

  res->bmp = src->bmp;
  memcpy( res->arr, src->arr, sizeof( NumberOfSetBits( src->bmp ) ) );

  return res;
}

static CNode_t* CNode_create( unsigned int arraySize ) {
  CNode_t* res = ( CNode_t* ) malloc( sizeof( CNode_t ) );

  res->bmp = 0;
  res->arr = ( ArrayNode_t* ) malloc( sizeof( ArrayNode_t ) * arraySize );
  memset( res->arr, 0, sizeof( ArrayNode_t ) * arraySize );  

  return res;
}

void CNode_free( CNode_t* _this, BOOL freeArrElements );
void SNode_free( SNode_t* _this );
void INode_free( INode_t* _this );

static void MainNode_free( MainNode_t* _this, BOOL freeArrElements ) {
  switch( _this->type ) {
    case CNODE: CNode_free( _this->cnode, freeArrElements ); break;
    case SNODE: SNode_free( _this->snode ); break;
  }
  free( _this );
}

static void ArrayNode_free( ArrayNode_t* _this ) {
  switch( _this->type ) {
    case INODE: INode_free( _this->inode ); break;
    case SNODE: SNode_free( _this->snode ); break;
  }
  free( _this );
}

static void CNode_free( CNode_t* _this, BOOL freeArrElements ) {
  unsigned int i;  

  if( freeArrElements ) {
    for( i = 0; i < NumberOfSetBits( _this->bmp ); i++ ) {
      switch( _this->arr[i].type ) {
        case SNODE: SNode_free( _this->arr[i].snode ); break;
        case INODE: INode_free( _this->arr[i].inode );
      }
    }
  }
  free( _this->arr );
  free( _this );
}

static SNode_t* SNode_create( Key_t* key, void* value, BOOL tomb ) {
  SNode_t* res = ( SNode_t* ) malloc( sizeof( SNode_t ) );

  res->key = *key;
  res->value = value;
  res->tomb = tomb;

  return res;
}

static void SNode_free( SNode_t* _this ) {
  free( _this );
}

static INode_t* INode_create( MainNode_t* mainnode ) {
  INode_t* res = ( INode_t* ) malloc( sizeof( INode_t ) );

  res->mainnode = mainnode;

  return res;
}

static void INode_free( INode_t* _this ) {
  if( _this->mainnode ) {
    MainNode_free( _this->mainnode, FALSE );
  }
  free( _this );
}

static MainNode_t* MainNode_create_CNode( CNode_t* cnode ) {
  MainNode_t* res = ( MainNode_t* ) malloc( sizeof( MainNode_t ) );

  res->type = CNODE;
  res->cnode = cnode;

  return res;
}

static MainNode_t* MainNode_create_SNode( SNode_t* snode ) {
  MainNode_t* res = ( MainNode_t* ) malloc( sizeof( MainNode_t ) );

  res->type = SNODE;
  res->snode = snode;

  return res;
}

void CTrie_init( CTrie_t* _this ) {
  _this->root = NULL;
}

static void ArrayNode_insert( ArrayNode_t* arr, unsigned int size, unsigned int pos, void* ele, NodeType_t type ) {
  unsigned int i;

  for( i = pos + 1; i < size; i++ ) {
    arr[i].type = arr[i + 1].type;
    arr[i].node = arr[i + 1].node;
  }
  arr[pos].node = ele;
  arr[pos].type = type;
}

BOOL INode_insert( INode_t* _this, Key_t* key, void* value, unsigned int level, void* parent ) {
  MainNode_t* main = _this->mainnode;  

  switch( main->type ) {
    case CNODE: {
      FlagPos_t flagPos[1];

      Key_flagpos( key, level, main->cnode->bmp, flagPos );
      if( ( main->cnode->bmp & flagPos->flag ) == 0 ) {
        SNode_t* nsn = SNode_create( key, value, TRUE );
        CNode_t* ncn = CNode_clone( main->cnode );
        MainNode_t* mn =  MainNode_create_CNode( ncn );
        BOOL CASRes;

        ArrayNode_insert( ncn->arr, NumberOfSetBits( ncn->bmp ) , flagPos->pos, nsn, SNODE );
        ncn->bmp |= flagPos->flag;
       
        CASRes = CAS( ( void** ) &_this->mainnode, main, mn );
        if( !CASRes ) {
          MainNode_free( mn, FALSE );
          SNode_free( nsn );
        }

        return CASRes;
      }
      switch( main->cnode->arr[flagPos->pos].type ) {
        case INODE: return INode_insert( main->cnode->arr[flagPos->pos].inode, key, value, level + 1, _this );
        case SNODE: ;
      }
    }
  }

  return FALSE;
}

void CTrie_insert( CTrie_t* _this, Key_t* key, void* value ) {
  do {
    INode_t* r = _this->root;

    if( !r || IS_NULL_INODE( r ) ) {
      CNode_t* scn = CNode_create( 1 );      
      SNode_t* sn = SNode_create( key, value, FALSE );
      INode_t* nr = INode_create( MainNode_create_CNode( scn ) );
      scn->bmp = 1;
      scn->arr[0].type = SNODE;
      scn->arr[0].snode = sn;
      if( !CAS( (void**) &_this->root, (void*) r, (void*) nr ) ) {
        INode_free( nr );
        continue;
      }
    } else {
      if( !INode_insert( r, key, value, 0, NULL ) ) {
        continue;
      }
    }
  } while( 0 );
}