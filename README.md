# Caesar Cipher Implementation

This is an implementation of the classical Caesar cipher encryption and decryption algorithm in C.

## What is a Caesar Cipher?

The Caesar cipher is one of the simplest and most widely known encryption techniques. It is a type of substitution cipher in which each letter in the plaintext is shifted a certain number of places down or up the alphabet. For example, with a left shift of 3, 'D' would be replaced by 'A', 'E' would become 'B', and so on.

This implementation handles both uppercase and lowercase letters independently (preserving case), leaves non-alphabetic characters unchanged, and properly handles negative shift values.

## Features

- Encryption and decryption using the Caesar cipher algorithm
- Support for both positive and negative shift values
- Preservation of case (uppercase/lowercase)
- Non-alphabetic characters remain unchanged
- File-based input and output
- Comprehensive test suite

## How to Compile

```bash
gcc -Wextra -Wall -Wvla -std=c99 -lm cipher.c tests.c main.c -o cipher
```

## Usage

### Encrypting a File

```bash
./cipher cipher <shift> <input_file> <output_file>
```

Example:
```bash
./cipher cipher 3 plain.txt encrypted.txt
```
This will encrypt the contents of `plain.txt` using a shift of 3 and save the result in `encrypted.txt`.

### Decrypting a File

```bash
./cipher decipher <shift> <input_file> <output_file>
```

Example:
```bash
./cipher decipher 3 encrypted.txt decrypted.txt
```
This will decrypt the contents of `encrypted.txt` using a shift of 3 and save the result in `decrypted.txt`.

### Running Tests

```bash
./cipher test
```
This will run all the built-in tests to verify that the cipher and decipher functions work correctly.

## Examples

Original text: "Hello, world!"  
Encrypted (shift=3): "Khoor, zruog!"  
Decrypted (shift=3): "Hello, world!"

## Algorithm Details

The Caesar cipher works by shifting each letter in the plaintext by a fixed number of positions in the alphabet:

- For encryption: (letter position + shift) % 26
- For decryption: (letter position - shift + 26) % 26

The modulo operation ensures the value wraps around correctly for any integer shift value.

## Error Handling

The program validates all inputs and reports errors for:
- Invalid number of arguments
- Invalid command (only "cipher", "decipher", or "test" are allowed)
- Invalid shift value
- Invalid input or output files

## License

This project is provided under the MIT License. See the LICENSE file for details.
