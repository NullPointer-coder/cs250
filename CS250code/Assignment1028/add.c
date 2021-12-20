/*
 *Jingbo Wang 
*/

 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contacts.h"
#include "add.h"
#include "create.h"

void add_contact(Contact* contacts[], size_t total_count)
{ 
  Contact* new_contact;
  char added_name[MAX_NAME_CHARS + 2];
  char added_phone[MAX_PHONE_CHARS + 2];
  char added_email[MAX_EMAIL_CHARS + 2];

  /* to add a new contact by user */
  fprintf(stdout, "%s\n", "Enter a name to be added:");
  fgets(added_name, MAX_NAME_CHARS + 2, stdin);
  fprintf(stdout, "%s\n", "Enter the phone number:");
  fgets(added_phone, MAX_PHONE_CHARS + 2, stdin);
  fprintf(stdout, "%s\n", "Enter the email address:");
  fgets(added_email, MAX_EMAIL_CHARS + 2, stdin);
  
  remove_newline_char(added_name);
  remove_newline_char(added_phone);
  remove_newline_char(added_email);
  
  /* to allocte new space to hold new contact */
  new_contact = malloc(sizeof(Contact));
  strncpy(new_contact->name, added_name, MAX_NAME_CHARS + 2);
  strncpy(new_contact->phone, added_phone, MAX_PHONE_CHARS + 2);
  strncpy(new_contact->email, added_email, MAX_EMAIL_CHARS + 2);
  
  contacts[total_count - 1] = new_contact;
}
