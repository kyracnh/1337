#include "libft.h"

char	inc_by_i(unsigned int i, char c)
{
	return (c + i);
}

// 2. Capitalize every letter if it's lowercase
char capitalize_char(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return c;
}

// 3. Replace each character with 'X'
char replace_with_X(unsigned int i, char c) {
    return 'X';
}

// 4. Shift letters by index but wrap around alphabet (e.g., 'z' + 1 -> 'a')
char shift_and_wrap(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z')
        return ((c - 'a' + i) % 26) + 'a';
    return c;
}
// 5. Invert case (lowercase to uppercase, and vice versa)
char invert_case(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z')
        return c - 32;
    else if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int main()
{
	char *result;

	char *res = ft_strmapi("abc", inc_by_i);
	printf("%s\n", res);

	free(res);

	result = ft_strmapi("hello world", capitalize_char);
    printf("Test 2: %s\n", result);  // Expected: "HELLO WORLD"
    free(result);

	// Test 3: Replace each character with 'X'
    result = ft_strmapi("abcdef", replace_with_X);
    printf("Test 3: %s\n", result);  // Expected: "XXXXXX"
    free(result);

	// Test 4: Shift and wrap around alphabet
    result = ft_strmapi("xyz", shift_and_wrap);
    printf("Test 4: %s\n", result);  // Expected: "xyz" -> "yza"
    free(result);

	// Test 5: Invert case
    result = ft_strmapi("HeLLo WoRLd", invert_case);
    printf("Test 5: %s\n", result);  // Expected: "hEllO wOrlD"
    free(result);

	return 0;
}
