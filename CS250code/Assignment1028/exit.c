/*
 *Jingbo Wang 
 */
#include <stdlib.h>
#include "exit.h"
#include "contacts.h"

void exit_control(Contact* contacts[], char* file_name, size_t total_count)
{  
  FILE* output_file = fopen(file_name, "w");
  size_t index = 0;
   
  while (index < total_count)
  {
    fprintf(output_file, "%s\t%s\t%s\n", contacts[index]->name,
                        contacts[index]->phone, contacts[index]->email);
    index++;
  }
  fclose(output_file);
}
