/*
 *Jingbo Wang 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "delete.h"
#include "contacts.h"

void delete_contact(Contact* contacts[], size_t total_count)
{
  char removed_id[MAX_ID_CHARS + 2];
  size_t id;
  size_t index;
  
  fprintf(stdout, "%s\n", "Enter the id of the contact to delete: ");
  fgets(removed_id, MAX_ID_CHARS + 2, stdin);
  id = (size_t)atoi(removed_id); 

  /*compressing the contacts*/
  for (index = id; index < total_count; index++)
  {
    contacts[index] = contacts[index + 1];
  }
  free(contacts[total_count - 1]);
}

