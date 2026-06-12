class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t retInt;
        uint32_t mask = 1 << 31;
        for (int i = 0; i < 32; i++) {
            retInt = retInt << 1;
            retInt = retInt | (0x01 & n);
            n = n >> 1;
        }
        return retInt;
    }
};
