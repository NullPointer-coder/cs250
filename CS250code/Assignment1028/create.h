/*
 *Jingbo Wang 
 */
 
#ifndef CREATE_CONTACT_H
#define CREATE_CONTACT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contacts.h"


/**
 * read the contacts.txt to get each contact and store them 
 * into contact array
 * @param input_file the input file contacts.txt
 * @param contacts the contacts array
 * @return the total count of contacts in the contacts array
*/
size_t create_contact (FILE* input_file, Contact* contacts[]); 
 
/**
 * list each contact in the contact array
 * @param contacts the contacts array
 */                        
void list_contacts(Contact* contacts[], size_t total_count);
  
/**
 * remove the newline character
 * @param input_value the input string whith the newline character 
*/                  
void remove_newline_char(char* input_value);
#endif
