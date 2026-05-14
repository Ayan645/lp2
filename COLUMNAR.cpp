#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate order of columns based on key
vector<int> getOrder(string key)
{
    int n = key.length();

    vector<pair<char, int>> temp;

    for (int i = 0; i < n; i++)
    {
        temp.push_back({key[i], i});
    }

    sort(temp.begin(), temp.end());

    vector<int> order(n);

    for (int i = 0; i < n; i++)
    {
        order[temp[i].second] = i;
    }

    return order;
}

// Encryption function
string encrypt(string text, string key)
{
    int col = key.length();

    int row = (text.length() + col - 1) / col;

    vector<vector<char>> matrix(row, vector<char>(col, 'X'));

    // Fill matrix row-wise
    int k = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (k < text.length())
                matrix[i][j] = text[k++];
        }
    }

    vector<int> order = getOrder(key);

    string cipher = "";

    // Read column-wise based on key order
    for (int o = 0; o < col; o++)
    {
        for (int j = 0; j < col; j++)
        {
            if (order[j] == o)
            {
                for (int i = 0; i < row; i++)
                {
                    cipher += matrix[i][j];
                }
            }
        }
    }

    return cipher;
}

// Decryption function
string decrypt(string cipher, string key)
{
    int col = key.length();

    int row = cipher.length() / col;

    vector<vector<char>> matrix(row, vector<char>(col));

    vector<int> order = getOrder(key);

    int k = 0;

    // Fill matrix column-wise based on key order
    for (int o = 0; o < col; o++)
    {
        for (int j = 0; j < col; j++)
        {
            if (order[j] == o)
            {
                for (int i = 0; i < row; i++)
                {
                    matrix[i][j] = cipher[k++];
                }
            }
        }
    }

    string text = "";

    // Read row-wise
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            text += matrix[i][j];
        }
    }

    return text;
}

int main()
{
    string text, key;

    cout << "Enter plaintext: ";
    cin >> text;

    cout << "Enter key: ";
    cin >> key;

    string cipher = encrypt(text, key);

    cout << "\nEncrypted Text: " << cipher << endl;

    string decrypted = decrypt(cipher, key);

    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}

/*
============================================================================
                                THEORY
============================================================================

AIM:
To implement Columnar Transposition Cipher for encryption and decryption.

----------------------------------------------------------------------------

WHAT IS CRYPTOGRAPHY?

Cryptography is the process of:
- securing information
- converting readable data into unreadable form

Main goals:
1. Confidentiality
2. Integrity
3. Authentication

----------------------------------------------------------------------------

WHAT IS TRANSPOSITION CIPHER?

A transposition cipher:
- rearranges characters
- does NOT change characters

Unlike substitution cipher:
letters remain same but positions change.

----------------------------------------------------------------------------

WHAT IS COLUMNAR TRANSPOSITION?

In this method:
1. Plaintext written row-wise in matrix
2. Columns rearranged using key
3. Cipher text read column-wise

----------------------------------------------------------------------------

EXAMPLE

Plaintext:
HELLOWORLD

Key:
ZEBRA

Matrix:

Z E B R A
H E L L O
W O R L D

Columns are read according to alphabetical order of key.

Final Cipher:
ODLREOLLHW

----------------------------------------------------------------------------

WORKING OF PROGRAM

ENCRYPTION:
1. Take plaintext and key
2. Create matrix
3. Fill matrix row-wise
4. Sort key alphabetically
5. Read columns in sorted order
6. Generate cipher text

DECRYPTION:
1. Create empty matrix
2. Fill columns according to key order
3. Read matrix row-wise
4. Get original plaintext

----------------------------------------------------------------------------

DATA STRUCTURES USED

1. Vector
   - stores matrix

2. Pair
   - stores character and index

3. String
   - stores plaintext/ciphertext

----------------------------------------------------------------------------

TIME COMPLEXITY

Encryption:
:contentReference[oaicite:0]{index=0}

Decryption:
:contentReference[oaicite:1]{index=1}

Where:
n = number of characters

----------------------------------------------------------------------------

ADVANTAGES

1. Easy to implement
2. Better than simple substitution
3. Rearranges data securely

----------------------------------------------------------------------------

DISADVANTAGES

1. Weak against frequency analysis
2. Not secure for modern systems
3. Key management required

----------------------------------------------------------------------------

APPLICATIONS

1. Basic cryptography learning
2. Educational purposes
3. Historical encryption systems

----------------------------------------------------------------------------

OUTPUT EXAMPLE

Enter plaintext:
HELLOWORLD

Enter key:
ZEBRA

Encrypted Text:
ODLREOLLHW

Decrypted Text:
HELLOWORLD

----------------------------------------------------------------------------

VIVA QUESTIONS

1. What is transposition cipher?
Cipher that rearranges character positions.

2. Difference between substitution and transposition?
Substitution changes letters.
Transposition changes positions.

3. What is role of key?
Determines column order.

4. Is this secure today?
No, modern systems use AES and RSA.

5. Why matrix is used?
To arrange text row-wise and column-wise.

============================================================================
*/