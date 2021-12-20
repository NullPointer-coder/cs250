/*
 * Jingbo Wang
 * the represented value
 */
 
#ifndef ATOH_H
#define ATOH_H
#define SHIFT_PLACES 4
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * convert an ascii string representing one byte in the hex into
 * the actual value
 * @param string a 4-character string in the form 0xnn
 * @return the represented value
 */
uint8_t atoh8(const char* string);

/**
 * convert an ascii string representing one byte in the hex into
 * the actual value
 * @param string a 6-character string in the form 0xnn
 * @return the represented value
 */
uint16_t atoh16(const char* string);

/**
 * convert one hex dight into its actual value
 * @param digit character representing a hex digit (lowercase)
 * @return the represented 8 bits value
 */
uint8_t convert_one_hex_digit8(char digit);

/**
 * convert one hex dight into its actual value
 * @param digit character representing a hex digit (lowercase)
 * @return the represented 16 bits value
 */
uint16_t convert_one_hex_digit16(char digit);

#endif
