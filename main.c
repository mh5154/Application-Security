//
// Created by mhamdan03 on 9/26/19.
//

#include "dictionary.h"
//#include "dictionary.c"
#include "spell.c"
#include "stdio.h"
#include "stdlib.h"

int main()
{
    hashmap_t hashtable[HASH_SIZE];

    if(load_dictionary("/home/mhamdan03/Application-Security/wordlist.txt",hashtable))
        printf("Dictionary loaded");
    else
        printf("Did not load");

    return 0;



}