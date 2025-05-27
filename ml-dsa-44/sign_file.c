#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "api.h"

void read_bin(const char *filename, uint8_t *data, size_t len);
void write_bin(const char *filename, const uint8_t *data, size_t len);
uint8_t *read_file(const char *filename, size_t *len);

void read_bin(const char *filename, uint8_t *data, size_t len) {
    FILE *file = fopen(filename, "rb");
    if (!file) { perror("Citanie"); exit(1); }
    if (fread(data, 1, len, file) != len) {
        perror("fread failed");
        fclose(file);
        exit(1);
    }
    fclose(file);
}

void write_bin(const char *filename, const uint8_t *data, size_t len) {
    FILE *file = fopen(filename, "wb");
    if (!file) { perror("Zapis"); exit(1); }
    fwrite(data, 1, len, file);
    fclose(file);
}

uint8_t *read_file(const char *filename, size_t *len) {
    FILE *file = fopen(filename, "rb");
    if (!file) { perror("Citanie vstupneho suboru"); exit(1); }
    fseek(file, 0, SEEK_END);
    *len = ftell(file);
    fseek(file, 0, SEEK_SET);

    uint8_t *buffer = malloc(*len);
    if (!buffer) { perror("malloc"); fclose(file); exit(1); }

    if (fread(buffer, 1, *len, file) != *len) {
        perror("fread failed");
        free(buffer);
        fclose(file);
        exit(1);
    }

    fclose(file);
    return buffer;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Pouzitie: %s vstupny_subor\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    size_t message_len;
    uint8_t *message = read_file(filename, &message_len);

    uint8_t sk[PQCLEAN_MLDSA44_CLEAN_CRYPTO_SECRETKEYBYTES];
    uint8_t signature[PQCLEAN_MLDSA44_CLEAN_CRYPTO_BYTES];
    size_t siglen;

    read_bin("secretkey.bin", sk, sizeof(sk));

    if (PQCLEAN_MLDSA44_CLEAN_crypto_sign_signature(signature, &siglen, message, message_len, sk) != 0) {
        fprintf(stderr, "Podpisovanie zlyhalo.\n");
        free(message);
        return 1;
    }

    write_bin("signature.bin", signature, siglen);
    printf("Subor '%s' bol uspesne podpisany.\n", filename);
    free(message);
    return 0;
}
