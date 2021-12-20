/*
 * Jingbo Wang
 * a vector with bits reversed from the input
 */
 
#ifndef REVBITS_H
#define REVBITS_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * reverse the 8 bits, left to right, of a bit vector
 * @param value the 8 bits vector input
 * @return a vector with bits reversed from the input
 */
uint8_t revbits8(uint8_t value);

/**
 * reverse the 16 bits, left to right, of a bit vector
 * @param value the 16 bits vector input
 * @return a vector with bits reversed from the input
 */
uint16_t revbits16(uint16_t value);

#endif
