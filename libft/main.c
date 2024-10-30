#include "libft.h"

void toggle_case_at_even_index(unsigned int i, char *c)
{
    if (i % 2 == 0)  // Toggle case only at even indices
    {
        if (*c >= 'a' && *c <= 'z')
            *c = *c - 32;  // Convert to uppercase
        else if (*c >= 'A' && *c <= 'Z')
            *c = *c + 32;  // Convert to lowercase
    }
}

int main()
{
	char str[] = "iiiiiiii";
    printf("Result: %s\n", str);
    ft_striteri(str, toggle_case_at_even_index);
    printf("Result: %s\n", str);  // Expected: "ToGgLeCaSe"

	return 0;
}
