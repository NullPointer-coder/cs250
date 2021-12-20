/*
 * Jingbo Wang
 * A program that implements functions to:
 * 1. reverse the bits of a value
 * 2. convert ascii 0xnn hex representation into an 8-bit value
 * 3. convert ascii 0xnnnn hex representation into an 16-bit value
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "atoh.h"
#include "revbits.h"

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

  value = (uint8_t)(atoh8(argv[1]));
  value_reversed = revbits8(value);

  printf("0x%x reversed is 0x%x\n", value, value_reversed);
  return 0;
}
