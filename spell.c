#include "stdio.h"
#include "stdlib.h"
#include "dictionary.h"
//#include "dictionary.c"
#include "string.h"
#include "ctype.h"

//9/28/19 @ 8:13 PM

int check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[])
{
    int num_misspelled = 0;
    char word[LENGTH] = "";

    while(fscanf(fp, "%s", word) != EOF)
    {

        for(int i = 0; i < strlen(word); i++) //Use LENGTH or strlen() here????
        {
            while(ispunct(word[0]))
            {
                //printf("We are punc front\n");
                for(int z = 0; z < strlen(word); z++)
                    word[z] = word[z+1];
                //printf("Current word: %s\n", word);
            }
            int wordEnd = strlen(word);
            while(ispunct(word[wordEnd-1]))
            {
                //printf("We are punc end\n");
                word[strlen(word)-1] = '\0';
                wordEnd--;
            }
            if (check_word(word, hashtable) == false)
            {
                misspelled[num_misspelled] = word;
                num_misspelled++;
            }
            for(int s = 0; s < word[strlen(word)-1]; s++)
                word[s] = '\0';
        }
    }

return num_misspelled;
}



bool check_word(const char* word, hashmap_t hashtable[])
{
    int bucket = 0;
    char lowerWord[LENGTH] = "";
    for(int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i])) {
            lowerWord[i] = word[i] + 32;
        } else {
            lowerWord[i] = word[i];
        }
    }
    bucket = hash_function(lowerWord);
    struct node *nodeCursor = NULL;

    if (hashtable[bucket] != NULL)
    {
        //printf("Inside Check word with: %s \n", lowerWord);
        //printf("HashWord: %s \n", hashtable[bucket]->word);
        if (strcmp(hashtable[bucket]->word, lowerWord) == 0)
        {
            //printf("TRUE 1 right: %s \n", lowerWord);
            return true;
        }
        else
            {
                nodeCursor = hashtable[bucket];
                while (nodeCursor->next != NULL)
                {
                    nodeCursor = nodeCursor->next;
                    if (strcmp(nodeCursor->word, lowerWord) == 0)
                    {
                        //printf("TRUE 2 right: %s \n", lowerWord);
                        return true;
                    }

                }
                //printf("Word: %s \n", lowerWord);
               //printf("NodeCursorWord: %s \n", nodeCursor->word);
                //printf("FALSE 1 \n");
                return false;
            }
    }
    else
    {
        //printf("Word: %s \n", lowerWord);
        //printf("NodeCursorWord: %s \n", nodeCursor->word);
        //printf("FALSE 2 \n");
        return false;
    }

}


bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[])
{
    for(int i = 0; i < HASH_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    FILE *fp;
    fp = fopen(dictionary_file, "r");
    if(fp == NULL)
    {
        return false;
    }
    else
    {
        char readWord[LENGTH];
        char lowerWord[LENGTH] = "";
        int bucket = 0;

        while(fscanf(fp, "%s", readWord) != EOF)
        {
            for(int i = 0; i < strlen(readWord); i++)
            {
                if(isupper(readWord[i]))
                {
                    lowerWord[i] = readWord[i] + 32;
                }
                else
                {
                    lowerWord[i] = readWord[i];
                }
            }
            struct node* newNode = NULL;
            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->next = NULL;
            strncpy(newNode->word,lowerWord,LENGTH);

            bucket = hash_function(lowerWord);

            if(hashtable[bucket] == NULL)
                hashtable[bucket] = newNode;
            else
            {
                newNode->next = hashtable[bucket];
                hashtable[bucket] = newNode;
            }
            strncpy(lowerWord,"",LENGTH);
        }

    }
    fclose(fp);
    return true;
}