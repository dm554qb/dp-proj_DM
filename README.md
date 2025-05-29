# dp-proj_DM



## Príkazy OpenSSL

### generovanie klucov 
```bash
    openssl-3.5.0/bin/openssl genpkey -algorithm mldsa44 -out privkey.pem
    openssl-3.5.0/bin/openssl pkey -in privkey.pem -pubout -out pubkey.pem
```

### test kľúčov
```bash
    openssl-3.5.0/bin/openssl pkey -in privkey.pem -text -noout 
    openssl-3.5.0/bin/openssl pkey -in pubkey.pem -pubin -text -noout 
```

### Podpis súboru
```bash
    openssl-3.5.0/bin/openssl pkeyutl -sign -inkey privkey.pem -rawin -in tvojsubor.txt -out signature.bin
```

### Overenie podpisu
```bash
    openssl-3.5.0/bin/openssl pkeyutl -verify -pubin -inkey pubkey.pem -sigfile signature.bin -rawin -in tvojsubor.txt
```

### Prevod z PEM na DER format
```bash
    openssl pkey -in privkey.pem -outform DER -out privkey.der
    openssl pkey -pubin -in publickey.pem -outform DER -out publickey.der
```
