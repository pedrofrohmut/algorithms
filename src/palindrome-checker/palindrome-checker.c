#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(const char* src)
{
    assert(src != NULL);

    int len = strlen(src);

    if (len <= 1) return true;

    int low = 0;
    int high = len - 1;

    while (low < high) {
        if (src[low] != src[high]) {
            return false;
        }
        low++;
        high--;
    }

    return true;
}

const char* bool_to_str(const bool b)
{
    return b ? "true" : "false";
}

void test_palindrome(const char* src, bool expected)
{
    bool result = is_palindrome(src);
    if (expected != result) {
        printf("Error: Testing palindrome for `%s`. Expected result to be %s but got %s instead.\n",
               src, bool_to_str(expected), bool_to_str(result));
    }
}

int main(void)
{
    test_palindrome("", true);
    test_palindrome("x", true);
    test_palindrome("xamax", true);
    test_palindrome("ababa", true);
    test_palindrome("racecar", true);

    test_palindrome("xy", false);
    test_palindrome("foobar", false);
    test_palindrome("hello", false);

    return 0;
}
