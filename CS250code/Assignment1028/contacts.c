/*
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

void contacts_database(char* filename, Contact* contacts[])
{
  
  size_t count;
  size_t index;
  char chosen[MAX_CHOSEN + 2];
  unsigned bool = 0;
  FILE* input_file;
  
  input_file = fopen(filename, "r");
  
  if (input_file == NULL)
  {
    fprintf(stderr, "An invalid file name.\n");
  }
  else
  {
    count = create_contact(input_file, contacts);
    list_contacts(contacts, count);

    do
    {
      fprintf(stdout, "\n%s\n", "S: Search");
      fprintf(stdout, "%s\n", "A: Add");
      fprintf(stdout, "%s\n", "D: Delete");
      fprintf(stdout, "%s\n", "Q: Quit");
      fprintf(stdout, "%s\n", "Choice: ");
      fgets(chosen, MAX_CHOSEN + 3, stdin); 	
      remove_newline_char(chosen);
      if (chosen[0] == 's' || chosen[0] == 'S')
      {
        search_contact(contacts, count);
      }
      else if (chosen[0] == 'a' || chosen[0] == 'A')
      {
        count++;
        add_contact(contacts, count);
        fprintf(stdout, "%s", "\n");
        list_contacts(contacts, count);
      }
      else if (chosen[0] == 'd' || chosen[0] == 'D')
      { 
        delete_contact(contacts, count);
        count--;
        fprintf(stdout, "%s", "\n");
        list_contacts(contacts, count);
      }
      else if (chosen[0] == 'q' || chosen[0] == 'Q')
      {
        bool = 1;
      } 
    } while (bool == 0);
  
    exit_control(contacts, filename, count);
    
    for (index = 0; index < count; index++)
    {
      free(contacts[index]);
    }
  }
}
