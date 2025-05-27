#include <stdio.h>
#include <stdlib.h>
#include "api.h"

void write_bin(const char *filename, const uint8_t *data, size_t len);

void write_bin(const char *filename, const uint8_t *data, size_t len) {
    FILE *file = fopen(filename, "wb");
    if (!file) { perror("Zapis"); exit(1); }
    fwrite(data, 1, len, file);
    fclose(file);
}

int main() {
    uint8_t pk[PQCLEAN_MLDSA44_CLEAN_CRYPTO_PUBLICKEYBYTES];
    uint8_t sk[PQCLEAN_MLDSA44_CLEAN_CRYPTO_SECRETKEYBYTES];

    if (PQCLEAN_MLDSA44_CLEAN_crypto_sign_keypair(pk, sk) != 0) {
        fprintf(stderr, "Chyba pri generovani klucov.\n");
        return 1;
    }

    write_bin("publickey.bin", pk, sizeof(pk));
    write_bin("secretkey.bin", sk, sizeof(sk));

    printf("Kluce boli uspesne vygenerovane a ulozene.\n");
    return 0;
}
