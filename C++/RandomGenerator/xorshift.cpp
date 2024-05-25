// coding: utf-8

#include <bits/stdc++.h>

namespace XorShift {
    // xorshift128((unsigned)time(NULL))

    class xorshift128 {
        private:

        const uint32_t uint32_max = 0xffffffffU;
        uint32_t x[4] = {0, 0, 0, 0};
        uint32_t first_seed;


        public:

        xorshift128(uint32_t seed=0) {
            first_seed = seed;

            x[3] = seed;
            x[2] = 1234567890;
            x[1] = (uint32_max - seed) ^ 0b01001101101001010101001010110011U;
            x[0] = x[2] ^ x[1];
        }

        uint32_t get_first_seed() {
            return this->first_seed;
        }
        
        uint32_t get_max() {
            return this->uint32_max;
        }

        uint32_t gen() {
            uint32_t t = this->x[3];
            uint32_t s = this->x[0];

            for(int i = 3; i > 0; i--) this->x[i] = this->x[i-1];

            t ^= t << 11;
            t ^= t >> 8;
            return this->x[0] = t ^ s ^ (s >> 19);
        }

        uint32_t operator()() {
            return this->gen();
        }
    };
}
