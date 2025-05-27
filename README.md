# dp-proj_DM
dp ml-dsa-44

#generovanie klucov
$HOME/openssl-3.5.0/bin/openssl genpkey -algorithm mldsa44 -out privkey.pem
$HOME/openssl-3.5.0/bin/openssl pkey -in privkey.pem -pubout -out pubkey.pem

#test
$HOME/openssl-3.5.0/bin/openssl pkey -in privkey.pem -text -noout
$HOME/openssl-3.5.0/bin/openssl pkey -in pubkey.pem -pubin -text -noout
#test

#podpis
$HOME/openssl-3.5.0/bin/openssl pkeyutl -sign -inkey privkey.pem -rawin -in tvojsubor.txt -out signature.bin

#overenie
$HOME/openssl-3.5.0/bin/openssl pkeyutl -verify -pubin -inkey pubkey.pem -sigfile signature.bin -rawin -in tvojsubor.txt
