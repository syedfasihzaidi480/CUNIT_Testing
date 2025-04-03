/*
 * hash_sha256_cp.h
 *
 *  Created on: 20 Mar 2025
 *      Author: alij7
 */

#ifndef LIBSODIUM_HASH_SHA256_CP_H_
#define LIBSODIUM_HASH_SHA256_CP_H_


#include <stdint.h>

typedef struct {
    uint64_t count;
    uint32_t state[8];
    unsigned char buf[64];
} crypto_hash_sha256_state;

int crypto_hash_sha256_init(crypto_hash_sha256_state *state);
int crypto_hash_sha256_update(crypto_hash_sha256_state *state, const unsigned char *in, unsigned long long inlen);
int crypto_hash_sha256_final(crypto_hash_sha256_state *state, unsigned char *out);
int crypto_hash_sha256(unsigned char *out, const unsigned char *in, unsigned long long inlen);

#endif /* LIBSODIUM_HASH_SHA256_CP_H_ */

