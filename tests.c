#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K_1 3
#define K_2 2
#define K_3 -1
#define K_4 -3
#define K_5 29

// See full documentation in header file
int test_cipher_non_cyclic_lower_case_positive_k ()
{
  char in[] = "abc";
  char out[] = "def";
  cipher (in, K_1);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_cipher_cyclic_lower_case_special_char_positive_k ()
{
  char in[] = "fizz!";
  char out[] = "hkbb!";
  cipher (in, K_2);
  return strcmp (in, out) != 0;
  // your code goes here
}

// See full documentation in header file
int test_cipher_non_cyclic_lower_case_special_char_negative_k ()
{
  // your code goes here
  char in[] = "bcd?";
  char out[] = "abc?";
  cipher (in, K_3);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_cipher_cyclic_lower_case_negative_k ()
{
  // your code goes here
  char in[] = "cljjb";
  char out[] = "ziggy";
  cipher (in, K_4);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_cipher_cyclic_upper_case_positive_k ()
{
  // your code goes here
  char in[] = "XYZ";
  char out[] = "ABC";
  cipher (in, K_5);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decipher_non_cyclic_lower_case_positive_k ()
{
  char in[] = "def";
  char out[] = "abc";
  decipher (in, K_1);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decipher_cyclic_lower_case_special_char_positive_k ()
{
  // your code goes here
  char in[] = "abba!";
  char out[] = "yzzy!";
  decipher (in, K_2);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decipher_non_cyclic_lower_case_special_char_negative_k ()
{
  // your code goes here
  char in[] = "meow?";
  char out[] = "nfpx?";
  decipher (in, K_3);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decipher_cyclic_lower_case_negative_k ()
{
  // your code goes here
  char in[] = "xyzzy!";
  char out[] = "abccb!";
  decipher (in, K_4);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decipher_cyclic_upper_case_positive_k ()
{
  // your code goes here
  char in[] = "TOP!";
  char out[] = "QLM!";
  decipher (in, K_5);
  return strcmp (in, out) != 0;
}
