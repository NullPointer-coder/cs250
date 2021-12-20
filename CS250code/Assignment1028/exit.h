/*
 *Jingbo Wang 
 */
 
#ifndef EXIT_H
#define EXIT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contacts.h"

/**
 * store the contacts array into the contacts.txt
 *  @param contacts the contacts array
 *  @param file_name the output file name
 *  @param total_count the total count of the contacts in the array
*/ 
void exit_control(Contact* contacts[], char* file_name, size_t total_count);
#endif
