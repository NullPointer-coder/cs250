/*
 * Jingbo Wang 
*/
#ifndef CONTACTS_H
#define CONTACTS_H
#define MAX_NAME_CHARS 40
#define MAX_PHONE_CHARS 12
#define MAX_EMAIL_CHARS 30
#define MAX_CHARS MAX_NAME_CHARS + MAX_PHONE_CHARS + MAX_EMAIL_CHARS + 2
#define MAX_ENTERED_CONTACTS 1024
#define MAX_ID_CHARS 4
#define MAX_CHOSEN 1

typedef struct
{
  char name[MAX_NAME_CHARS + 1];
  char phone[MAX_PHONE_CHARS + 1];
  char email[MAX_EMAIL_CHARS + 1];
} Contact;

/**
 * to reading from contacts.txt, adding, deleting, 
 * and storing the contacts_database
 * @param filename the input file name
 * @param contacts the contacts array
 */
void contacts_database(char* filename, Contact* contacts[]);
#endif
