/*
 * Jingbo Wang
 * a vector with bits reversed from the input
 */
 
#include "revbits.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t revbits8(uint8_t value)
{
  const unsigned BITSPLACES = 8;
  const uint8_t TEST_MASK = 1;
  const uint8_t SHIFT_PLACE = 1;
  size_t index = 0;
  uint8_t bit = 0;
  uint8_t temp_value = 0;
  do
  {
     temp_value <<= SHIFT_PLACE;
     bit = TEST_MASK & value;
     value >>= SHIFT_PLACE;
     temp_value = temp_value | bit;
     index++;
  } while (index < BITSPLACES);
  return temp_value;
}

uint16_t revbits16(uint16_t value)
{
  const unsigned BITSPLACES = 16;
  const uint16_t TEST_MASK = 1;
  const uint16_t SHIFT_PLACE = 1;
  size_t index = 0;
  uint16_t bit = 0;
  uint16_t temp_value = 0;
  do
  {
     temp_value <<= SHIFT_PLACE;
     bit = TEST_MASK & value;
     value >>= SHIFT_PLACE;
     temp_value = temp_value | bit;
     index++;
  } while (index < BITSPLACES);
  return temp_value;
}
