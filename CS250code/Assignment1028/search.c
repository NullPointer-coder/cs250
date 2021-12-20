/*
 *Jingbo Wang 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "contacts.h"
#include "create.h"
#include "search.h"

void search_contact(Contact* contacts[], size_t total_count)
{
  size_t index;
  char search_string[MAX_NAME_CHARS + 2];
  char temp_name[MAX_NAME_CHARS + 1];
  char* cutoff;
  fprintf(stdout, "%s\n", "Enter search string: ");
  fgets(search_string, MAX_NAME_CHARS + 2, stdin);
  
  remove_newline_char(search_string);
  upper_to_lower(search_string);
  
  for (index = 0; index < total_count; index++)
  {
    strncpy(temp_name, contacts[index]->name, MAX_NAME_CHARS + 1);
    
    upper_to_lower(temp_name);
    cutoff = strstr(temp_name, (char*)search_string);
    if (cutoff != NULL)
    {
      fprintf(stdout, "%lu: %s %s %s\n", index, contacts[index]->name, 
                                                contacts[index]->phone,
                                                contacts[index]->email);
    }
  }
}

void upper_to_lower(char* input_string)
{
  size_t index;
  size_t string_length = strlen(input_string);
  for (index = 0; index < string_length; index++)
  {
    if (isupper(input_string[index]))
    {
      input_string[index] = (char)tolower(input_string[index]);	
    }
  }
}
