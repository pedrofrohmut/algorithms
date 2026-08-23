// reverse_string.c

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    REV_OK = 0,
    REV_NULL_SRC,
    REV_NULL_DEST,
    REV_SIZE_MISMATCH,
} Reverse_String_Result;

Reverse_String_Result reverse_string(const char* src, char* dest, size_t dest_size)
{
    if (src == NULL) {
        fprintf(stderr, "Source string is null.");
        return REV_NULL_SRC;
    }

    if (dest == NULL) {
        fprintf(stderr, "Destination string is null.\n");
        return REV_NULL_DEST;
    }

    const size_t src_len = strlen(src);

    if (src_len != dest_size - 1) {
        fprintf(stderr, "Length of the source string and destination does not match. Length of source is %zu and destination is %zu.\n",
               src_len, dest_size - 1);
        return REV_SIZE_MISMATCH;
    }

    for (size_t i = 0; i < src_len; i++) {
        const size_t low = i;
        const size_t high = src_len - 1 - i;

        dest[low] = src[high];
    }

    dest[src_len] = '\0';

    return REV_OK;
}

void test(Reverse_String_Result rev_fun(const char*, char*, size_t), const char* src, const char* expected)
{
    const size_t dest_size = strlen(src) + 1;
    char* dest = (char*) malloc(sizeof(char) * dest_size); // +1 for the null terminator
    if (dest == NULL) {
        fprintf(stderr, "Unable to get memory to allocate a new string.\n");
        return;
    }

    rev_fun(src, dest, dest_size);

    if (strcmp(dest, expected) != 0) {
        printf("Expected reversed string to be `%s` but got `%s` instead.\n", expected, dest);
    }

    free(dest);
}

int main(void)
{
    test(reverse_string, "a", "a");
    test(reverse_string, "", "");
    test(reverse_string, "ab", "ba");

    test(reverse_string, "hello", "olleh");
    test(reverse_string, "foobar", "raboof");
    test(reverse_string, "racecar", "racecar");
    test(reverse_string, "this is my super long string", "gnirts gnol repus ym si siht");

    test(reverse_string, "12345", "54321");
    test(reverse_string, "123456", "654321");

    return 0;
}
