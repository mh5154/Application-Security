#include "stdio.h"
#include "stdlib.h"
#include "dictionary.h"
#include "dictionary.c"
#include "string.h"
#include "ctype.h"

//10AM9/28

int check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[])
{
    int num_misspelled = 0;
    while(!feof(fp))
    {
        char readLine[LENGTH] = "";
        char word[LENGTH] = "";
        fscanf(fp, "%[^\n]", readLine);
        //getline(readLine,LENGTH,fp);

        for(int i = 0; i < strlen(word); i++) //Use LENGTH or strlen() here????
        {
            if(isspace(readLine[i]))
            {
                if(ispunct(word[0]))
                {
                    for(int z = 0; z < strlen(word)-2; z++)
                        word[z] = word[z+1];
                }
                if(ispunct(word[strlen(word)-1]))
                {
                    word[strlen(word)-1] = '\0';
                }
                if (check_word(word, hashtable) == false)
                {
                        misspelled[num_misspelled] = word;
                        num_misspelled++;
                }
                for(int s = 0; s < word[strlen(word)-1]; s++)
                    word[s] = '\0';
            }
            else
            {
                word[i] = readLine[i];
            }
        }

    }

    return num_misspelled;
}



bool check_word(const char* word, hashmap_t hashtable[])
{
    int bucket = 0;
    bucket = hash_function(word);
    struct node* nodeCursor = hashtable[bucket];
    while(nodeCursor != NULL)
    {
        if(word == nodeCursor->word)
            return true;
        nodeCursor = nodeCursor->next;
    }

    bucket = hash_function(word);
    nodeCursor = hashtable[bucket];


    int wordSize = strlen(word);
    char lowerWord[LENGTH] = "";

    for(int i = 0; i < wordSize; i++)
    {
        if(ispunct(word[i]))
            return false;
        if(isupper(word[i]))
            lowerWord[i] = word[i]+32;
    }

    while(nodeCursor != NULL)
    {

        if(lowerWord == nodeCursor->word)
            return true;
        nodeCursor  = nodeCursor->next;
    }

    return false;

}



bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[])
{
    for(int i = 0; i < 1000; i++)
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
        int bucket = 0;
        fclose(fp);
        //while(!feof(fp))
        while(fscanf(fp, "%[^\n]", readWord) != EOF)
        {

            struct node* newNode = NULL;
            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->next = NULL;
            strncpy(newNode->word,readWord,LENGTH);

            bucket = hash_function(readWord);

            if(hashtable[bucket] == NULL)
                hashtable[bucket] = newNode;
            else
            {
                newNode->next = hashtable[bucket];
                hashtable[bucket] = newNode;
            }
        }

    }
    //printf("Dictionary Loaded! \n");
    return true;
}