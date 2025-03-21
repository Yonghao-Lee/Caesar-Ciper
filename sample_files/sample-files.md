# Sample Files

This directory contains sample input and output files for testing the Caesar cipher implementation.

## Files

- `plain.txt` - A sample plain text file
- `encrypted_shift_3.txt` - The result of encrypting plain.txt with a shift of 3
- `encrypted_shift_13.txt` - The result of encrypting plain.txt with a shift of 13 (ROT13)

## Examples

To encrypt the sample file:
```
./cipher cipher 3 sample_files/plain.txt sample_files/your_encrypted.txt
```

To decrypt the sample file:
```
./cipher decipher 3 sample_files/encrypted_shift_3.txt sample_files/your_decrypted.txt
```

You can compare your output with the provided samples to verify the program works correctly.
