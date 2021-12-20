/*
 * Jingbo Wang
 * the represented value
 */
 
#include "atoh.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t atoh8(const char* string)
{
  uint8_t temp_value = 0;
  uint8_t valuepart = 0;
  size_t index_1 = 2;
  size_t index_2 = 2;
  unsigned STRING_LENGTH = 4;
  if (string[0] == '0' && string[1] == 'x')
  {
	while (string[index_1] != '\0')
	{
	  if (('/' > string[index_1] || string[index_1] > ':') &&
	      ('@' > string[index_1] || string[index_1] > 'G') &&
	      ('`' > string[index_1] || string[index_1] >  'g'))
	  {
	    return 0;
	  }
	  index_1++;
	}
	while (index_2 < STRING_LENGTH && string[index_2] != '\0')
	{
	  temp_value <<= SHIFT_PLACES;
	  valuepart = (uint8_t)convert_one_hex_digit8(string[index_2]);
	  temp_value += valuepart;
      index_2++;	    
	}
	return temp_value;
  }
  return 0;
}

uint16_t atoh16(const char* string)
{ 
  uint16_t temp_value = 0;
  uint16_t valuepart = 0;
  size_t index_1 = 2;
  size_t index_2 = 2;
  unsigned STRING_LENGTH = 6;
  
  if (string[0] == '0' && string[1] == 'x')
  {
	while (string[index_1] != '\0')
	{
	  if (('/' > string[index_1] || string[index_1] > ':') &&
	      ('@' > string[index_1] || string[index_1] > 'G') &&
	      ('`' > string[index_1] || string[index_1] >  'g'))
	  {
	    return 0;
	  }
	  index_1++;
	}
    while (index_2 < STRING_LENGTH && string[index_2] != '\0')
    {
	  temp_value <<= SHIFT_PLACES;
	  valuepart = (uint16_t)convert_one_hex_digit16(string[index_2]);
	  temp_value += valuepart;	    
	  index_2++;
    }
    return temp_value;
  }
  return 0;
}

uint8_t convert_one_hex_digit8(char digit)
{
  if ('/' < digit && digit < ':')
 {
   return (uint8_t)(digit - '0');
 }
 else if ('@' < digit && digit < 'G')
 {
   return (uint8_t)(digit - 'A' + 10);
 }
 else if ('`' < digit && digit < 'g')
 {
   return (uint8_t)(digit - 'a' + 10);
 }
 return 0;
}

uint16_t convert_one_hex_digit16(char digit)
{
  if ('/' < digit && digit < ':')
 {
   return (uint16_t)(digit - '0');
 }
 else if ('@' < digit && digit < 'G')
 {
   return (uint16_t)(digit - 'A' + 10);
 }
 else if ('`' < digit && digit < 'g')
 {
   return (uint16_t)(digit - 'a' + 10);
 }
 return 0;
}
