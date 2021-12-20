/*
 *Jingbo Wang 
 */

#ifndef SEARCH_H
#define SEARCH_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "create.h"
#include "contacts.h"

/**
 * search the input contact by user
 * @param contacts the contacts array
 * @param total_count the total count of the contacts in the array
*/
void search_contact(Contact* contacts[], size_t total_count);
                    
/**
 * make the input string into lowwer case
 * @param input_string the input string form the name in the contacts
*/ 
void upper_to_lower(char* input_string);
#endif
