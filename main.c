//
// Created by mhamdan03 on 9/26/19.
//

#include "dictionary.h"
#include "spell.c"
#include "stdio.h"
#include "stdlib.h"

int main()
{
    hashmap_t hashtable[HASH_SIZE];

    if(load_dictionary("/home/mhamdan03/Application-Security/wordlist.txt",hashtable))
        printf("Dictionary loaded \n");
    else
        printf("Did not load \n");

   /* struct node* nodeHead = NULL;
    for(int i = 0; i < HASH_SIZE; i++)
    {
        if(hashtable[i] != NULL)
        {
            printf("word: %s \n", hashtable[i]->word);
            nodeHead = hashtable[i];
            while(nodeHead->next != NULL)
            {
                nodeHead = nodeHead->next;
                printf("word: %s \n", nodeHead->word);

            }
        }
    }*/


    FILE *fptr = fopen("/home/mhamdan03/Application-Security/test5.txt", "r");
    char *mispelled[MAX_MISSPELLED];
    int num_mispelled = check_words(fptr, hashtable, mispelled);

    printf("Number of mispelled words is: %d \n", num_mispelled);


    return 0;



}