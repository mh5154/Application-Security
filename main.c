//
// Created by mhamdan03 on 9/26/19.
//

#include "dictionary.h"
//#include "spell.c"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
    hashmap_t hashtable[HASH_SIZE];

    if(load_dictionary(argv[2],hashtable))
        printf("Dictionary loaded \n");
    else
        printf("Did not load \n");

    //"/home/mhamdan03/Application-Security/mydic.txt"

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


    FILE *fptr = fopen(argv[1], "r");
    char *mispelled[MAX_MISSPELLED];
    for(int z = 0; z < MAX_MISSPELLED; z++)
        mispelled[z] = "";
    int num_mispelled = check_words(fptr, hashtable, mispelled);

    printf("Number of mispelled words is: %d \n", num_mispelled);

    printf("The mispelled words are: ");
    for(int i = 0; i < num_mispelled; i++)
        printf("%s\n", mispelled[i]);

    fclose(fptr);

    struct node *freeCursor = NULL;
    struct node *head = NULL;
    for(int g = 0; g < HASH_SIZE; g++)
    {
        //free(hashtable[g]);
        if(hashtable[g] != NULL)
        {
            if(hashtable[g]->next != NULL)
            {
                freeCursor = hashtable[g];
                while(freeCursor->next != NULL)
                {
                    head = freeCursor->next;
                    free(freeCursor);
                    freeCursor = head;
                }
                free(freeCursor);
                head = NULL;
                freeCursor = NULL;
            }
            else
                free(hashtable[g]);
        }
    }
    for(int k = 0; k < num_mispelled; k++)
        free(mispelled[k]);

    return 0;



}