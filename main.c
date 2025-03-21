#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cipher.h"
#include "tests.h"
#include <stdbool.h>
#include <limits.h>

#define C_1 "cipher"
#define C_2 "decipher"
#define improper_num_args_msg "The program receives 1 or 4 arguments only.\n"
#define improper_single_arg_msg "Usage: cipher test\n"
#define improper_comm_quad_arg_msg "The given command is invalid.\n"
#define improper_key_quad_arg_msg "The given shift value is invalid.\n"
#define invalid_file_msg "The given file is invalid.\n"

bool is_integer(const char* str);
void type_1_cipher(int key, FILE* source_file, FILE* destination_file);
void type_1_decipher(int key, FILE* source_file, FILE* destination_file);
int type_2_test();
bool is_read_file_path_valid(char file_path[]);
bool is_write_file_path_valid(char file_path[]);
int std_procedure(char* argv[]);


int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "test") == 0)
    {
        return type_2_test();
    }
    if (argc != 2 && argc != 5)
    {
        fprintf(stderr, improper_num_args_msg);
        return EXIT_FAILURE;
    }
    else if (argc == 2 && strcmp(argv[1], "test") != 0)
    {
        fprintf(stderr, improper_single_arg_msg);
        return EXIT_FAILURE;
    }
    else if (argc == 5 && strcmp(argv[1], C_1) != 0 && strcmp(argv[1], C_2) != 0)
    {
        fprintf(stderr, improper_comm_quad_arg_msg);
        return EXIT_FAILURE;
    }
    else if (argc == 5 && !is_integer(argv[2]))
    {
        fprintf(stderr,improper_key_quad_arg_msg);
        return EXIT_FAILURE;
    }
    else if (argc == 5 && !is_read_file_path_valid(argv[3]))
    {
        fprintf(stderr, invalid_file_msg);
        return EXIT_FAILURE;
    }
    return std_procedure(argv);
}

bool is_integer(const char* str)
{
    char* end_ptr;
    long int num = strtol(str, &end_ptr, 10);
    if (str == NULL || *str == '\0' || end_ptr == str || num < INT_MIN || num > INT_MAX)
    {
        return false;
    }
    while (*end_ptr)
    {
        if (!isspace((unsigned char)*end_ptr))
        {
            //If the trailing chars are not spaces, return false meow.
            return false;
        }
        end_ptr++;
    }
    return true;
}

bool is_read_file_path_valid(char file_path[])
{
    FILE* file = fopen(file_path, "r");
    if (file == NULL)
    {
        return false;
    }
    fclose(file);
    return true;
}


int std_procedure(char* argv[])
{
    char* command = argv[1];
    const char* key = argv[2];
    char* message_to_process_path = argv[3];
    char* processed_message_path = argv[4];

    FILE* source_file = fopen(message_to_process_path, "r");
    if (source_file == NULL)
    {
        fprintf(stderr, invalid_file_msg);
        return EXIT_FAILURE;
    }

    FILE* destination_file = fopen(processed_message_path, "w");
    if (destination_file == NULL)
    {
        fprintf(stderr, invalid_file_msg);
        fclose(source_file); // Close the source file before returning
        return EXIT_FAILURE;
    }
    if (strcmp(command, C_1) == 0)
    {
        type_1_cipher((int)strtol(key, NULL, 10), source_file, destination_file);
    }
    else if (strcmp(command, C_2) == 0)
    {
        type_1_decipher((int)strtol(key, NULL, 10), source_file, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);
    return EXIT_SUCCESS;
}

void type_1_cipher(const int key, FILE* source_file, FILE* destination_file)
{
    char buffer[1025];
    while (fgets(buffer, 1025, source_file))
    {
        cipher(buffer, key);
        fputs(buffer, destination_file);
    }
}

void type_1_decipher(const int key, FILE* source_file, FILE* destination_file)
{
    char buffer[1025];
    while (fgets(buffer, sizeof(buffer), source_file))
    {
        decipher(buffer, key);
        fputs(buffer, destination_file);
    }
}

int type_2_test()
{
    int failed_tests = 0;

    failed_tests += test_cipher_non_cyclic_lower_case_positive_k() == 1;
    failed_tests += test_cipher_cyclic_lower_case_special_char_positive_k() == 1;
    failed_tests += test_cipher_non_cyclic_lower_case_special_char_negative_k() == 1;
    failed_tests += test_cipher_cyclic_lower_case_negative_k() == 1;
    failed_tests += test_cipher_cyclic_upper_case_positive_k() == 1;
    failed_tests += test_decipher_non_cyclic_lower_case_positive_k() == 1;
    failed_tests += test_decipher_cyclic_lower_case_special_char_positive_k() == 1;
    failed_tests += test_decipher_non_cyclic_lower_case_special_char_negative_k() == 1;
    failed_tests += test_decipher_cyclic_lower_case_negative_k() == 1;
    failed_tests += test_decipher_cyclic_upper_case_positive_k() == 1;

    if (failed_tests != 0)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
