// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Create the root nodes of the trie
trie *root;

// Keep track of the number of words
unsigned int wordCount = 0;

// Assume input are lowercase alphabetical characters or an apostrophe. Returns an indexing number
int indexer(char x)
{
    int indexNumber = 0;
    if (isalpha(x))
    {
        indexNumber = x - 'a';
    }
    else if (x == '\'')
    {
        indexNumber = ALPHABET - 1;
    }
    return indexNumber;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    trie *trav = root;

    // Iterate through each letter in the word
    int i = 0;
    char ch;
    while (word[i] != '\0')
    {
        ch = tolower(word[i]);

        int index = indexer(ch);

        if (trav -> children[index] == NULL)
        {
            return false;
        }
        else
        {
            trav = trav -> children[index];
            i++;
        }

    }

    if (trav -> is_word)
    {
        return true;
    }
    else
    {
        return false;
    }

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Opens dictionary file
    FILE *dict = fopen(dictionary, "r");
    // Check if we can open the file
    if (dict == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    root = calloc(1, sizeof(trie));
    if (!root)
    {
        printf("Could not load %s.\n Not enough memory.", dictionary);
        return false;
    }
    trie *ptr = root;

    // Iterate through each word in the dictionary
    for (char ch = fgetc(dict); ch != EOF; ch = fgetc(dict))
    {
        int index = indexer(ch);

        // If we reach the end of a word, set is_word to true
        if (ch == '\n')
        {
            ptr -> is_word = true;
            ptr = root;
            wordCount++;
        }
        // If not the end of the word, continue through the trie
        else
        {
            trie *next = ptr -> children[index];
            // If a pointer is NULL, malloc a new node and point to it
            if (!next)
            {
                ptr -> children[index] = calloc(1, sizeof(trie));
                if (ptr -> children[index] == NULL)
                {
                    printf("Could not load %s.\n Not enough memory.", dictionary);
                    return false;
                }
                else
                {
                    ptr = ptr -> children[index];
                }
            }
            else
            {
                ptr = next;
            }
        }
    }

    // Close dictionary file
    fclose(dict);

    // Success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Destroys nodes of the trie recursively
void destroyer(trie *ptr)
{
    for (int i = 0; i < ALPHABET; i++)
    {
        if (ptr -> children[i] != NULL)
        {
            destroyer(ptr -> children[i]);
        }
    }
    free(ptr);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    destroyer(root);
    return true;
}
