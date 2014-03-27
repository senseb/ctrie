#include "gtest/gtest.h"
#include "ctrie.h"

TEST( TestCTrie, test_create ) {
  CTrie_t trie[1];

  CTrie_init( trie );  
}

TEST( TestCTrie, test_insert ) {
  CTrie_t trie[1];
  Key_t key[1];

  CTrie_init( trie );

  key->key = "hello";
  key->hc = SuperFastHash((const char*) key->key, strlen( ( char* ) key->key ) );
  CTrie_insert( trie, key, (void*) 123 );

  key->key = "world";
  key->hc = SuperFastHash((const char*) key->key, strlen( ( char* ) key->key ) );
  CTrie_insert( trie, key, (void*) 123 );
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
