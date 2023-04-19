#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void insert(struct Trie **ppTrie, char *word);
int numberOfOccurances(struct Trie *pTrie, char *word);
struct Trie *deallocateTrie(struct Trie *pTrie);
int main(void)
{
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
      for (int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(&trie, pWords[i]));
     }
    trie = deallocateTree(&trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}