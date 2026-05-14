#include <iostream>
using namespace std;

int main()
{
    // Define string using char pointer
    char *str = (char *)"Hello World";

    cout << "Original String: " << str << endl;

    cout << "\nAfter AND with 127:\n";

    for (int i = 0; str[i] != '\0'; i++)
    {
        char result = str[i] & 127;
        cout << result;
    }

    cout << "\n\nAfter XOR with 127:\n";

    for (int i = 0; str[i] != '\0'; i++)
    {
        char result = str[i] ^ 127;
        cout << result;
    }

    cout << endl;

    return 0;
}

/*
============================================================================
                                THEORY
============================================================================

AIM:
To perform encryption using AND and XOR bitwise operations.

----------------------------------------------------------------------------

WHAT IS ENCRYPTION?

Encryption converts:
- readable data (plaintext)

into:
- unreadable data (ciphertext)

to provide security.

----------------------------------------------------------------------------

WHAT ARE BITWISE OPERATIONS?

Bitwise operators work directly on binary bits.

Common operators:
1. AND  (&)
2. OR   (|)
3. XOR  (^)
4. NOT  (~)

----------------------------------------------------------------------------

WHAT IS XOR OPERATION?

XOR compares two bits.

Rules:

0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0

Important Property:

A ^ B ^ B = A

Meaning:
Applying same XOR key twice gives original data.

----------------------------------------------------------------------------

WHY XOR WITH 127?

127 in binary:

01111111

XOR with 127 flips lower 7 bits of ASCII character.

Used for simple encryption.

----------------------------------------------------------------------------

WHAT IS AND OPERATION?

AND compares bits.

Rules:

1 & 1 = 1
Otherwise = 0

AND with 127:
- keeps lower 7 bits
- removes most significant bit

----------------------------------------------------------------------------

WORKING OF PROGRAM

1. Store string:
   "Hello World"

2. Traverse each character

3. Perform:
   character & 127

4. Perform:
   character ^ 127

5. Display results

----------------------------------------------------------------------------

APPLICATIONS

1. Simple encryption
2. Password masking
3. Data security
4. Network communication

----------------------------------------------------------------------------

ADVANTAGES OF XOR ENCRYPTION

1. Fast
2. Simple
3. Easy decryption

----------------------------------------------------------------------------

DISADVANTAGES

1. Weak security
2. Easy to crack
3. Not suitable for modern encryption

----------------------------------------------------------------------------

TIME COMPLEXITY

:contentReference[oaicite:0]{index=0}

Where:
n = length of string

----------------------------------------------------------------------------

OUTPUT EXAMPLE

Original String:
Hello World

After AND with 127:
Hello World

After XOR with 127:
(Encrypted unreadable characters)

----------------------------------------------------------------------------

VIVA QUESTIONS

1. What is XOR cipher?
Encryption using XOR operation.

2. Why XOR is reversible?
Because:
A ^ B ^ B = A

3. What does AND with 127 do?
Keeps lower 7 bits.

4. Is XOR symmetric?
Yes.

5. Is this secure for real systems?
No, modern systems use AES/RSA.

============================================================================
*/