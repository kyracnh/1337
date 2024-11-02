#include <stdio.h>
#include <stdlib.h>
#include "libft.h" // Adjust to your libft header

void print_split_result(char **result) {
    if (result == NULL) {
        printf("Result: NULL\n");
        return;
    }
    for (int i = 0; result[i] != NULL; i++) {
        printf("Part %d: '%s'\n", i, result[i]);
        free(result[i]); // Free each part after printing
    }
    free(result); // Free the array itself
}

int main() {
    // Test 1: A long string with various delimiters
    char **result1 = ft_split("One, Two; Three: Four|Five", ',');
    printf("Test 1:\n");
    print_split_result(result1); // Expected: "One", " Two; Three: Four|Five"

    // Test 2: A string with emojis
    char **result2 = ft_split("😊,😂,😎", ',');
    printf("Test 2:\n");
    print_split_result(result2); // Expected: "😊", "😂", "😎"

    // Test 3: String with numbers and letters
    char **result3 = ft_split("abc123;def456;ghi789", ';');
    printf("Test 3:\n");
    print_split_result(result3); // Expected: "abc123", "def456", "ghi789"

    // Test 4: Input with mixed whitespace
    char **result4 = ft_split("   A    B    C   ", ' ');
    printf("Test 4:\n");
    print_split_result(result4); // Expected: "A", "B", "C"

    // Test 5: String with special characters
    char **result5 = ft_split("!@#$%^&*()_+", ' ');
    printf("Test 5:\n");
    print_split_result(result5); // Expected: "!@#$%^&*()_+" (if there's no space)

    // Test 6: Very long string
    char long_str[1000];
    for (int i = 0; i < 999; i++) long_str[i] = 'a'; // Fill with 'a'
    long_str[999] = '\0';
    char **result6 = ft_split(long_str, 'a');
    printf("Test 6:\n");
    print_split_result(result6); // Expected: Many empty strings

    // Test 7: String with a single character
    char **result7 = ft_split("Z", 'Z');
    printf("Test 7:\n");
    print_split_result(result7); // Expected: NULL

    // Test 8: Strings that are purely delimiters
    char **result8 = ft_split(";;;;;;", ';');
    printf("Test 8:\n");
    print_split_result(result8); // Expected: Empty strings

    // Test 9: Input with no delimiters
    char **result9 = ft_split("JustOneString", ' ');
    printf("Test 9:\n");
    print_split_result(result9); // Expected: "JustOneString"

    // Test 10: Multi-line string
    char **result10 = ft_split("Line1\nLine2\nLine3", '\n');
    printf("Test 10:\n");
    print_split_result(result10); // Expected: "Line1", "Line2", "Line3"

    return 0;
}
