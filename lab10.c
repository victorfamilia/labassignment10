#include <time.h>
#include <stdlib.h>
#include <stdio.h>

struct TrieNode 
{
    int count;
    struct TrieNode* children[26];
};

void insert(struct TrieNode** ppTrie, char* word) 
{
    struct TrieNode* pTrie = *ppTrie;
    if (pTrie == NULL) 
    {
        pTrie = (struct TrieNode*)calloc(1, sizeof(struct TrieNode));
        *ppTrie = pTrie;
    }
    for (int i = 0; word[i] != '\0'; i++) 
    {
        char c = word[i];
        if (c >= 'a' && c <= 'z') {
            c -= 'a';
            if (!pTrie->children[c]) {
                pTrie->children[c] = (struct TrieNode*)calloc(1, sizeof(struct TrieNode));
            }
            pTrie = pTrie->children[c];
        }
    }
    pTrie->count++;
}

int numberOfOccurrences(struct TrieNode* pTrie, char* word) 
{
    if (pTrie == NULL) {
        return 0;
    }
    for (int i = 0; word[i] != '\0'; i++) {
        char c = word[i];
        if (c >= 'a' && c <= 'z') {
            c -= 'a';
            pTrie = pTrie->children[c];
            if (pTrie == NULL) {
                return 0;
            }
        }
    }
    return pTrie->count;
}

struct TrieNode* deallocateTrie(struct TrieNode* pTrie) 
{
    if (pTrie == NULL) {
        return NULL;
    }
    for (int i = 0; i < 26; i++) {
        pTrie->children[i] = deallocateTrie(pTrie->children[i]);
    }
    free(pTrie);
    return NULL;
}

int main(void) 
{
    struct TrieNode* trie = NULL;
    char* pWords[] = { "notaword", "ucf", "no", "note", "corg" };
    for (int i = 0; i < 5; i++) {
        insert(&trie, pWords[i]);
        printf("%s : %d\n", pWords[i], numberOfOccurrences(trie, pWords[i]));
    }
    trie = deallocateTrie(trie);
    if (trie != NULL) {
        printf("There is an error in this program\n");
    }
    return 0;
}