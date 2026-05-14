#include <iostream>
#include <cmath>

using namespace std;

// Function to find GCD
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }

    return a;
}

// Function to compute (base^exp) % mod
long long modExp(long long base, long long exp, long long mod)
{
    long long result = 1;

    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;

        exp = exp / 2;
    }

    return result;
}

int main()
{
    int p, q;

    cout << "Enter two prime numbers (p and q): ";

    cin >> p >> q;

    int n = p * q;

    int phi = (p - 1) * (q - 1);

    int e;

    cout << "Enter public key (e): ";

    cin >> e;

    // Check if e is valid
    if (gcd(e, phi) != 1)
    {
        cout << "Invalid e! It must be coprime with phi.\n";

        return 0;
    }

    // Find d (private key)
    int d = 1;

    while ((d * e) % phi != 1)
    {
        d++;
    }

    cout << "\nPublic Key (e, n): (" << e << ", " << n << ")";

    cout << "\nPrivate Key (d, n): (" << d << ", " << n << ")\n";

    int msg;

    cout << "\nEnter message (integer): ";

    cin >> msg;

    // Encryption
    long long cipher = modExp(msg, e, n);

    cout << "Encrypted Message: " << cipher << endl;

    // Decryption
    long long decrypted = modExp(cipher, d, n);

    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}

/*
============================================================================
                                THEORY
============================================================================

AIM:
To implement RSA Algorithm using C++.

----------------------------------------------------------------------------

WHAT IS RSA?

RSA is:
- asymmetric encryption algorithm
- public key cryptography technique

Developed by:
Rivest, Shamir, and Adleman.

----------------------------------------------------------------------------

WHAT IS ASYMMETRIC ENCRYPTION?

Uses TWO keys:

1. Public Key
   - used for encryption

2. Private Key
   - used for decryption

Different keys are used unlike AES/DES.

----------------------------------------------------------------------------

RSA WORKING

STEP 1:
Choose two prime numbers:
p and q

STEP 2:
Compute:

:contentReference[oaicite:0]{index=0}

STEP 3:
Compute Euler Totient:

:contentReference[oaicite:1]{index=1}

STEP 4:
Choose public key:
e

Condition:
gcd(e, φ(n)) = 1

STEP 5:
Find private key:
d

Condition:

:contentReference[oaicite:2]{index=2}

----------------------------------------------------------------------------

ENCRYPTION FORMULA

:contentReference[oaicite:3]{index=3}

Where:
M = Message
e = Public key
C = Ciphertext

----------------------------------------------------------------------------

DECRYPTION FORMULA

:contentReference[oaicite:4]{index=4}

Where:
d = Private key

----------------------------------------------------------------------------

WHAT IS GCD?

GCD = Greatest Common Divisor

Used to check:
e and φ(n) are coprime.

----------------------------------------------------------------------------

WHAT IS MODULAR EXPONENTIATION?

Efficient way to calculate:

(base^exp) % mod

Used in RSA because numbers become very large.

----------------------------------------------------------------------------

WORKING OF PROGRAM

1. Input prime numbers p and q
2. Calculate n and phi
3. Input public key e
4. Generate private key d
5. Encrypt message
6. Decrypt ciphertext

----------------------------------------------------------------------------

TIME COMPLEXITY

Modular exponentiation:

:contentReference[oaicite:5]{index=5}

----------------------------------------------------------------------------

ADVANTAGES

1. Secure communication
2. Public key sharing possible
3. Widely used

----------------------------------------------------------------------------

DISADVANTAGES

1. Slower than AES
2. Large computations
3. Large key sizes required

----------------------------------------------------------------------------

APPLICATIONS

1. HTTPS
2. Digital signatures
3. Secure email
4. Banking systems
5. SSL/TLS

----------------------------------------------------------------------------

OUTPUT EXAMPLE

Enter two prime numbers:
3 11

Enter public key:
7

Public Key:
(7, 33)

Private Key:
(3, 33)

Enter message:
5

Encrypted Message:
14

Decrypted Message:
5

----------------------------------------------------------------------------

VIVA QUESTIONS

1. What is RSA?
Asymmetric encryption algorithm.

2. Difference between symmetric and asymmetric encryption?
Symmetric uses same key.
Asymmetric uses public/private keys.

3. Why prime numbers are used?
Provides mathematical security.

4. What is public key?
Key used for encryption.

5. What is private key?
Key used for decryption.

============================================================================
*/