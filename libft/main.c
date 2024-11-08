#include "libft.h"
#include <ctype.h>

int main()
{
    char *v = NULL;
    char *c = "How are you doing ?";

    char *r = ft_strjoin(v, c);
    if (r == NULL)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < ft_strlen(r); i++)
        {
            printf("%c", r[i]);
        }
        printf("\n");
    }
    
    
    return 0;    
}