# dp-proj_DM



## Príkazy OpenSSL

### generovanie klucov 
```bash
    openssl genpkey -algorithm mldsa44 -out privkey.pem
    openssl pkey -in privkey.pem -pubout -out pubkey.pem
```

### test kľúčov
```bash
    openssl pkey -in privkey.pem -text -noout 
    openssl pkey -in pubkey.pem -pubin -text -noout 
```

### Podpis súboru
```bash
    openssl pkeyutl -sign -inkey privkey.pem -rawin -in tvojsubor.txt -out signature.bin
```

### Overenie podpisu
```bash
    openssl pkeyutl -verify -pubin -inkey pubkey.pem -sigfile signature.bin -rawin -in tvojsubor.txt
```

### Prevod z PEM na DER format
```bash
    openssl pkey -in privkey.pem -outform DER -out privkey.der
    openssl pkey -pubin -in pubkey.pem -outform DER -out pubkey.der
```
