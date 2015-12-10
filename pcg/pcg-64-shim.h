#define __SIZEOF_INT128__ 16

#include <stdint.h>
#include "pcg_variants.h"


typedef struct s_aug_state {
    pcg64_random_t *rng;
    pcg128_t state, inc;

    int has_gauss, shift_zig_random_int, has_uint32;
    double gauss;
    uint32_t uinteger;
    uint64_t zig_random_int;
} aug_state;

inline uint32_t random_uint32(aug_state* state)
{
    if (state->has_uint32)
    {
        state->has_uint32 = 0;
        return state->uinteger;
    }
    state->has_uint32 = 1;
    uint64_t temp;
    temp = pcg64_random_r(state->rng);
    state->uinteger = (uint32_t)(temp >> 32);
    return (uint32_t)(temp & 0xFFFFFFFFLL);
}

inline uint64_t random_uint64(aug_state* state)
{
    return pcg64_random_r(state->rng);
}
