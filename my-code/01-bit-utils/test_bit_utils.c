#include<assert.h>
#include<stdio.h>
#include "bit_utils.h"
#define ENABLE_POS 0u
#define IE_POS 1u
#define MODE_POS 2u
#define MODE_WIDTH 2u
#define PRESCALER_POS 4u
#define PRESCALER_WIDTH 4u
int main (){
    assert(set_bit(0u,0) == 0x00000001u);
    assert(set_bit(0u,31) == 0x80000000u);
    assert(clear_bit(0xFFu,0)==0xFEu);
    assert(toggle_bit(0x1u,0)==0x0u);
    assert(toggle_bit(0x2u,0)==0x3u);
    assert(check_bit(0x4u,2)==true);
    assert(check_bit(0x4u,1)==false);
    assert(read_bifield(0xF0u,4,4)==0xFu);
    assert(write_bitfield(0u,2,2,0xFu)==0xC0u);
    uint32_t reg=0u;
    reg=set_bit(reg,ENABLE_POS);
    reg=set_bit(reg,IE_POS);
    reg=write_bitfield(reg,MODE_POS,MODE_WIDTH,1u);
    reg=write_bitfield(reg,PRESCALER_POS,PRESCALER_WIDTH,0xFu);
    assert(check_bit(reg,ENABLE_POS)==true);
    assert(read_bitfield(reg,MODE_POS,MODE_WIDTH)==1u);
    assert(read_bitfield(reg,PRESCALER_POS,PRESCALER_WIDTH)==0xFu);
    assert(reg==0xF7u);
    printf("Control reg=0x%02X\n",(unsigned int)reg);
    printf("Done\n");
    return 0;
}