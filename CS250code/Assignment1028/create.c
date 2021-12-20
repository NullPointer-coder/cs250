/*
 * Jingbo Wang
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"
#include "create.h"
                       
size_t create_contact (FILE* input_file, Contact* contacts[])
{
  char* token;
  char string[MAX_CHARS];
  Contact* new_contact;
  size_t total_count = 0;
  size_t index = 0;
  while (fgets(string, MAX_CHARS, input_file))
  {
    new_contact = malloc(sizeof(Contact));
    token = strtok (string, "\t");
    strncpy (new_contact->name, token, MAX_NAME_CHARS + 2);
    token = strtok (NULL, "\t");
    strncpy (new_contact->phone, token, MAX_PHONE_CHARS + 2);
    token = strtok (NULL, "\n");
    strncpy (new_contact->email, token, MAX_EMAIL_CHARS + 2);
    contacts[index] = new_contact;
    index++;
  }
  total_count = index;
  fclose(input_file);
  return total_count;
}

void list_contacts(Contact* contacts[], size_t total_count)
{
  size_t index;
  for (index = 0; index < total_count; index++)
  {
    fprintf (stdout, "%lu: %s  %s %s\n", index, contacts[index]->name,
                       contacts[index]->phone, contacts[index]->email);
  }
}

void remove_newline_char(char* input_value)
{
  size_t index;
  size_t value_length = strlen(input_value);
  for (index = 0; index < value_length; index++)
  {
    if (input_value[index] == '\n')
    {
      input_value[index] = '\0';	
    }
  }
}
