#include <iostream>
#include <cstring>
#include <openssl/aes.h>

using namespace std;

int main()
{
    unsigned char key[16] = "1234567890abcdef"; // 16-byte key

    AES_KEY enc_key, dec_key;

    // Set encryption key
    AES_set_encrypt_key(key, 128, &enc_key);

    // Set decryption key
    AES_set_decrypt_key(key, 128, &dec_key);

    unsigned char plainText[16] = "HelloAESWorld!!";

    unsigned char encrypted[16];

    unsigned char decrypted[16];

    // Encrypt plaintext
    AES_encrypt(plainText, encrypted, &enc_key);

    // Decrypt ciphertext
    AES_decrypt(encrypted, decrypted, &dec_key);

    cout << "Original: " << plainText << endl;

    cout << "Encrypted: ";

    for (int i = 0; i < 16; i++)
        printf("%02X ", encrypted[i]);

    cout << endl;

    cout << "Decrypted: " << decrypted << endl;

    return 0;
}

/*
============================================================================
                                THEORY
============================================================================

AIM:
To implement AES (Advanced Encryption Standard) algorithm using C++.

----------------------------------------------------------------------------

WHAT IS AES?

AES = Advanced Encryption Standard

It is:
- symmetric key encryption algorithm
- block cipher
- modern secure encryption standard

AES replaced DES because DES became insecure.

----------------------------------------------------------------------------

FEATURES OF AES

1. Block Size:
   128 bits

2. Key Sizes:
   128 bits
   192 bits
   256 bits

3. Number of Rounds:
   AES-128 → 10 rounds
   AES-192 → 12 rounds
   AES-256 → 14 rounds

----------------------------------------------------------------------------

WHAT IS SYMMETRIC ENCRYPTION?

Same key used for:
- encryption
- decryption

Sender and receiver both use same secret key.

----------------------------------------------------------------------------

WORKING OF AES

Main AES operations:

1. SubBytes
   - byte substitution

2. ShiftRows
   - row shifting

3. MixColumns
   - column mixing

4. AddRoundKey
   - combines key with data

These operations repeat multiple rounds.

----------------------------------------------------------------------------

WORKING OF PROGRAM

1. Define 16-byte secret key
2. Create encryption and decryption keys
3. Encrypt plaintext
4. Display encrypted hexadecimal output
5. Decrypt ciphertext
6. Display original plaintext

----------------------------------------------------------------------------

IMPORTANT FUNCTIONS

AES_set_encrypt_key()
- prepares encryption key

AES_set_decrypt_key()
- prepares decryption key

AES_encrypt()
- encrypts plaintext

AES_decrypt()
- decrypts ciphertext

----------------------------------------------------------------------------

WHY HEXADECIMAL OUTPUT?

Encrypted data may contain:
- non-printable characters

So hexadecimal format is displayed.

----------------------------------------------------------------------------

TIME COMPLEXITY

AES performs fixed number of rounds.

AES-128:
:contentReference[oaicite:0]{index=0}

----------------------------------------------------------------------------

ADVANTAGES

1. Very secure
2. Fast execution
3. Widely used
4. Resistant to attacks

----------------------------------------------------------------------------

DISADVANTAGES

1. More complex than DES
2. Key sharing required

----------------------------------------------------------------------------

APPLICATIONS

1. HTTPS
2. VPN
3. Wi-Fi security
4. File encryption
5. Banking systems

----------------------------------------------------------------------------

DIFFERENCE BETWEEN AES AND DES

AES:
- More secure
- Larger key sizes
- Faster
- Modern standard

DES:
- Old algorithm
- Small key size
- Less secure

----------------------------------------------------------------------------

OUTPUT EXAMPLE

Original:
HelloAESWorld!!

Encrypted:
(Hexadecimal encrypted data)

Decrypted:
HelloAESWorld!!

----------------------------------------------------------------------------

VIVA QUESTIONS

1. What is AES?
Advanced Encryption Standard.

2. Is AES symmetric or asymmetric?
Symmetric encryption algorithm.

3. Why AES replaced DES?
DES had small key size and became insecure.

4. What is AES block size?
128 bits.

5. Where is AES used?
HTTPS, VPN, Wi-Fi, file encryption.

============================================================================
*/