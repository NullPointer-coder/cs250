/*
 *Jingbo Wang 
 */

#ifndef ADD_H
#define ADD_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contacts.h"
#include "create.h"

/**
 * add the new contact by user input
 * @param contacts the contacts array
 * @param total_count the total count of the contacts in the array
*/
void add_contact(Contact* contacts[], size_t total_count);


#endif
