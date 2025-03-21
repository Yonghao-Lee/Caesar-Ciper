#include "cipher.h"

/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.


// See full documentation in header file
void cipher(char s[], int k)
{
    // your code goes here
    k = ((k % 26) + 26) % 26;


    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = (char)((s[i] - 'a' + k) % 26 + 'a');
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = (char)((s[i] - 'A' + k) % 26 + 'A');
        }
    }
}

void decipher(char s[], int k)
{
    // your code goes here
    k = (k % 26 + 26) % 26;
    cipher(s, 26 - k);
}
