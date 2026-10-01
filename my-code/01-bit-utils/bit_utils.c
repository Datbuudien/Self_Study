#include "bit_utils.h"
uint32_t set_bit(uint32_t val, uint8_t bit) {
    return val | (1u << bit);
}
uint32_t clear_bit(uint32_t val,uint8_t bit){
    return val & ~(1u<<bit);
}
uint32_t toggle_bit(uint32_t val, uint8_t bit){
    return val ^ (1u<<bit);
}
bool check_bit(uint32_t val, uint8_t bit){
    return (val>>bit)&1u ;
}
static uint32_t low_mask(uint8_t width){
    return (width>=32u)? 0xFFFFFFFFu : ((1u<<width)-1u);
}
uint32_t read_bitfield(uint32_t val, uint8_t pos, uint8_t width){
    return (val>>pos) & low_mask(width);
}
uint32_t write_bitfield(uint32_t val, uint8_t pos,uint8_t width, uint32_t field){
    return (val& ~(low_mask(width)<<pos)) | ((low_mask(width)<<pos)&(field<<pos));
}