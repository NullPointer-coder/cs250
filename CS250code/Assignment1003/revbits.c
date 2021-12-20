/*
 * Jingbo Wang
 * A program that implements functions to:
 * 1. reverse the bits of a value
 * 2. convert ascii 0xnn hex representation into an 8-bit value
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * To reverse the its of a value
 * @param value the input value
 * @return the reversed value
 */
uint8_t revbits(uint8_t value);

/*
 * To translate the char value into hex number
 * @param a input string value
 * @return a hex number
*/
uint8_t atoh(const char* string);

int main(int argc, char** argv)
{
  uint8_t value;
  uint8_t value_reversed;

  if (argc != 2)
  {
    fprintf(stderr, "usage: %s 0xnn\n", argv[0]);
    fprintf(stderr, "  where 0xnn is an 8-bit hex value\n");
    return 1;
  }

  value = (uint8_t)(atoh(argv[1]));
  value_reversed = revbits(value);

  printf("0x%x reversed is 0x%x\n", value, value_reversed);
  return 0;
}

uint8_t revbits(uint8_t value)
{
  const unsigned BITSPLACES = 8;
  const uint8_t TEST_MASK = 1;
  const uint8_t SHIFT_PLACES = 1;
  size_t index = 0;
  uint8_t bit = 0;
  uint8_t temp_value = 0;
  
  do
  {
     temp_value <<= SHIFT_PLACES;
     bit = TEST_MASK & value;
     value >>= SHIFT_PLACES;
     temp_value = temp_value | bit;
     index++;
  } while (index < BITSPLACES);
  return temp_value;
}

uint8_t atoh(const char* string)
{
  const uint8_t ISLETTER = 0x60;
  const uint8_t W_DEXIMAL = 0x57;
  const uint8_t ZERO_DEXIMAL = 0x30; 
  const unsigned SHIFT_PLACES = 4;
  const unsigned STRING_LENGTH = 4;	
  uint8_t valuepart_one = 0;
  uint8_t valuepart_two = 0;
  
  /* to check the char is letter or not */
  if (string[STRING_LENGTH - 2] > ISLETTER)
  {
    valuepart_one += string[STRING_LENGTH - 2] - W_DEXIMAL;
  }
  /* to check the char is number or not */
  else
  {
    valuepart_one += string[STRING_LENGTH - 2] - ZERO_DEXIMAL;
  }
  
  if (string[STRING_LENGTH - 1] > ISLETTER)
  {
    valuepart_two += string[STRING_LENGTH - 1] - W_DEXIMAL;
  }
  else
  {
    valuepart_two += string[STRING_LENGTH - 1] - ZERO_DEXIMAL;
  }
  return (uint8_t)(valuepart_one << SHIFT_PLACxES) + valuepart_two;
}
