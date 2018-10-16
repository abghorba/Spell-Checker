// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Length of the children array
#define ALPHABET 27

// Define the trie nodes
typedef struct _trie
{
    bool is_word;
    struct _trie *children[ALPHABET];
}
trie;

// Prototypes
int indexer(char x);
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
void destroyer(trie *ptr);
bool unload(void);

#endif // DICTIONARY_H
