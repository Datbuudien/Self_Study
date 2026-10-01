#ifndef BIT_UTILS_H
#define BIT_UTILS_H
#include<stdint.h>
#include<stdbool.h>
uint32_t set_bit(uint32_t val, uint8_t bit);
uint32_t clear_bit(uint32_t val, uint8_t bit);
uint32_t toggle_bit(uint32_t val, uint8_t bit);
bool check_bit(uint32_t val, uint8_t bit);
uint32_t read_bitfield(uint32_t val, uint8_t pos, uint8_t width);
uint32_t write_bitfield(uint32_t val, uint8_t pos,uint8_t width, uint32_t field);
#endif