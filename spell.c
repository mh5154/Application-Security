#include <stdio.h>
#include "dictionary.h"


int check_words(FILE* fp, hashmap_t hashtable[], char * misspelled[]);





bool check_word(const char* word, hashmap_t hashtable[]);






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
        char newword;
        while(fscanf(fp,"%[^\n]", newword) != EOF)
            getle

    }
}


int main() {
    printf("Hello, World!\n");
    return 0;
}