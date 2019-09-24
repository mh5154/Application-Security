#include "stdio.h"
#include "stdlib.h"
#include "dictionary.h"
#include "string.h"

//test

int check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[])
{
    int num_misspelled = 0;
    while(fp != EOF)
    {
        char* readLine;
        fscanf(fp, "%[^\n]", readLine);
        char* temp = strtok(readLine, "'");
        if(check_word(temp, hashtable) == false)
        {
            strcat(misspelled, temp);
            num_misspelled++;
        }
    }
    return num_misspelled;
}





bool check_word(const char* word, hashmap_t hashtable[])
{
    int bucket = 0;
    bucket = hash_function(word);
    hashmap_t = hashtable[bucket];
    while(hashmap_t != NULL)
    {
        if(word == hashmap_t->word)
            return true;
        hashmap_t = hashmap_t->next;
    }

    bucket = hash_function(word);
    hashmap_t = hashtable[bucket];
    while(hashmap_t != NULL)
    {
        if(strlwr(word) == hashmap_t->word)
            return true;
        hashmap_t  = hashmap_t->next;
    }

    return false;

}






bool load_dictionary(const char* dictionary_file, hashmap_t hashtable[])
{
    for(int i = 0; i < 1000; i++)
    {
        hashtable[i] = NULL;
    }

    FILE *fp = fopen("wordlist.txt", "r");
    if(fp == NULL)
    {
        return false;
    }
    else
    {
        char *readWord[20];
        int bucket = 0;
        while(fp != EOF)
        {
            fscanf(fp, "%[^\n]", readWord);



            struct node* newNode = NULL;
            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->next = NULL;
            newNode->word = readWord;

            bucket = hash_function(readWord);

            if(hashtable[bucket] == NULL)
                hashtable[bucket] = newNode;
            else
            {
                newNode->next = hashtable[bucket];
                hashtable[bucket] = newNode;
            }

            /*node* temp = new node;
            node* temp2;
            temp->word = readWord;
            temp->next = NULL;

            hashtable[bucket]->next
            if(hashtable[bucket]->next == NULL)
            {
                hashtable[bucket]->next = temp;
            }
            else
            {
                temp2 = hashtable[bucket]->next;
                while(temp2->next != NULL)
                    temp2 = temp2->next;
                temp2->next = temp;
                temp2 = NULL;
            }*/
        }
        fclose(fp);

    }
}

/*
int main() {
    printf("Hello, World!\n");
    return 0;
}*/