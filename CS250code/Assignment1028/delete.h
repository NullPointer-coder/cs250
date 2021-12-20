/*
 *Jingbo Wang 
 */
 
#ifndef DELETE_H
#define DELETE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contacts.h"

/**
 * delete the object contact by user
 * @param contacts the contacts array
 * @param total_count the total count of the contacts in the array
*/
void delete_contact(Contact* contacts[], size_t total_count);
#endif
