# Pridaj na začiatok
OPENSSL_DIR=C:\OPENSSL
INCLUDES=-I$(OPENSSL_DIR)/include
LIBS=-L$(OPENSSL_DIR)/lib -lcrypto

CC=gcc
CFLAGS=-O3 -Wall -Wextra -Wpedantic -Werror -Wmissing-prototypes -Wredundant-decls -std=c99 -I../common $(INCLUDES)

COMMON_SOURCES=../common/fips202.c ../common/randombytes.c
CRYPTO_SOURCES=sign.c packing.c poly.c polyvec.c symmetric-shake.c rounding.c reduce.c ntt.c

all: genkey sign_file verify

genkey: genkey.c $(CRYPTO_SOURCES) $(COMMON_SOURCES)
	$(CC) $(CFLAGS) -o genkey genkey.c $(CRYPTO_SOURCES) $(COMMON_SOURCES) $(LIBS)

sign_file: sign_file.c $(CRYPTO_SOURCES) $(COMMON_SOURCES)
	$(CC) $(CFLAGS) -o sign_file sign_file.c $(CRYPTO_SOURCES) $(COMMON_SOURCES) $(LIBS)

verify: verify.c $(CRYPTO_SOURCES) $(COMMON_SOURCES)
	$(CC) $(CFLAGS) -o verify verify.c $(CRYPTO_SOURCES) $(COMMON_SOURCES) $(LIBS)

clean:
	rm -f ml_dsa_demo verify_only genkey sign_file verify *.bin *.exe

.PHONY: all clean genkey sign_file verify
