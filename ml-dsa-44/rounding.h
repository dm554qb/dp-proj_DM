#ifndef PQCLEAN_MLDSA44_CLEAN_ROUNDING_H
#define PQCLEAN_MLDSA44_CLEAN_ROUNDING_H
#include "params.h"
#include <stdint.h>

int32_t PQCLEAN_MLDSA44_CLEAN_power2round(int32_t *a0, int32_t a);

int32_t PQCLEAN_MLDSA44_CLEAN_decompose(int32_t *a0, int32_t a);

unsigned int PQCLEAN_MLDSA44_CLEAN_make_hint(int32_t a0, int32_t a1);

int32_t PQCLEAN_MLDSA44_CLEAN_use_hint(int32_t a, unsigned int hint);

#endif
