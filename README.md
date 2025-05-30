# dp-proj_DM



## Príkazy OpenSSL

### generovanie klucov 
```bash
openssl genpkey -algorithm mldsa44 -out privkey.pem
openssl pkey -in privkey.pem -pubout -out pubkey.pem
```

### generovanie publickey z privkey v DER
```bash
openssl pkey -in privkey.der -inform DER -pubout -outform DER -out pubkey.der
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

### Podpis súboru DER
```bash
openssl dgst -sigopt alg=mldsa44 -sign privkey.der -keyform DER -out signature.bin subor.txt
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
