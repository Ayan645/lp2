#include <iostream>
#include <cstring>
#include <openssl/des.h>

using namespace std;

int main()
{
    DES_cblock key = "mykey12"; // 8-byte key

    DES_key_schedule schedule;

    // Set key
    DES_set_key_unchecked(&key, &schedule);

    char plainText[] = "HelloDES";

    char encrypted[9], decrypted[9];

    // Encrypt
    DES_ecb_encrypt(
        (DES_cblock *)plainText,
        (DES_cblock *)encrypted,
        &schedule,
        DES_ENCRYPT);

    // Decrypt
    DES_ecb_encrypt(
        (DES_cblock *)encrypted,
        (DES_cblock *)decrypted,
        &schedule,
        DES_DECRYPT);

    cout << "Original: " << plainText << endl;

    cout << "Encrypted: ";

    for (int i = 0; i < 8; i++)
        printf("%02X ", (unsigned char)encrypted[i]);

    cout << endl;

    cout << "Decrypted: " << decrypted << endl;

    return 0;
}

/*
============================================================================
                                THEORY
============================================================================

AIM:
To implement DES (Data Encryption Standard) algorithm using C++.

----------------------------------------------------------------------------

WHAT IS ENCRYPTION?

Encryption converts:
- readable data (plaintext)

into:
- unreadable data (ciphertext)

to provide security.

Decryption converts ciphertext back into plaintext.

----------------------------------------------------------------------------

WHAT IS DES?

DES = Data Encryption Standard

It is:
- symmetric key encryption algorithm
- block cipher

Introduced by IBM and adopted in 1977.

----------------------------------------------------------------------------

FEATURES OF DES

1. Block Size:
   64 bits

2. Key Size:
   56 bits
   (64 bits including parity bits)

3. Number of Rounds:
   16 rounds

4. Type:
   Symmetric encryption

----------------------------------------------------------------------------

WHAT IS SYMMETRIC ENCRYPTION?

Same key used for:
- encryption
- decryption

Example:

Plaintext + Key → Ciphertext

Ciphertext + Same Key → Plaintext

----------------------------------------------------------------------------

WHAT IS ECB MODE?

ECB = Electronic Code Book

In ECB:
- each block encrypted independently

Advantage:
- simple

Disadvantage:
- patterns may be visible

----------------------------------------------------------------------------

WORKING OF PROGRAM

1. Define 8-byte key
2. Create DES key schedule
3. Encrypt plaintext
4. Display encrypted hexadecimal data
5. Decrypt encrypted text
6. Display original text

----------------------------------------------------------------------------

IMPORTANT FUNCTIONS

DES_set_key_unchecked()
- prepares DES key schedule

DES_ecb_encrypt()
- performs encryption/decryption

----------------------------------------------------------------------------

WHY HEXADECIMAL OUTPUT?

Encrypted data may contain:
- non-printable characters

So hexadecimal representation is displayed.

----------------------------------------------------------------------------

TIME COMPLEXITY

DES performs:
16 Feistel rounds

Complexity approximately:

:contentReference[oaicite:0]{index=0}

----------------------------------------------------------------------------

ADVANTAGES

1. Fast
2. Simple implementation
3. Historical importance

----------------------------------------------------------------------------

DISADVANTAGES

1. Small key size
2. Vulnerable to brute-force attack
3. No longer secure

----------------------------------------------------------------------------

WHAT REPLACED DES?

1. 3DES
2. AES

AES is modern and more secure.

----------------------------------------------------------------------------

APPLICATIONS

1. Banking systems (older)
2. Secure communication
3. Educational cryptography

----------------------------------------------------------------------------

OUTPUT EXAMPLE

Original: HelloDES

Encrypted:
(HEX values)

Decrypted:
HelloDES

----------------------------------------------------------------------------

VIVA QUESTIONS

1. What is DES?
Symmetric block cipher algorithm.

2. What is block size of DES?
64 bits.

3. How many rounds in DES?
16 rounds.

4. Why DES is insecure?
56-bit key is small and brute-forceable.

5. Difference between DES and AES?
AES is more secure and uses larger keys.

============================================================================
*/