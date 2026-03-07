#ifndef CORE_H
#define CORE_H
#include <stdint.h>

void derive_key_from_password(const uint8_t *password, uint8_t *key);

#endif