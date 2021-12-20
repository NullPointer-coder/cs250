/*
 * a code could to read, search, add, delete, and store the contacts 
 * in the contacts.txt
 * Jingbo Wang 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "contacts.h"
#include "create.h"
#include "search.h"
#include "add.h"
#include "delete.h"
#include "exit.h"

int main(int argc, char** argv)
{
  char* filename;
  Contact* contacts[MAX_ENTERED_CONTACTS]; 
  
  if (argc != 2)
  {
    fprintf(stderr, "usage: %s foo.bar\n", argv[0]);
    fprintf(stderr, "  where foo.bar is file name and extension \n");
    return 1;
  }
  filename = (char*)(argv[1]);
  contacts_database(filename,contacts);
  return 0;
}

