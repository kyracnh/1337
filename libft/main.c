#include "libft.h"

void list_print(t_list *list)
{
        while (list)
        {
            printf("%d -> ", (char *)list->content);
            list = list->next;
        }
        printf("NULL\n");
}

void del(void *content)
{
    if (content)
    {
        free(content);
    }
}

void *_upper(void *cha)
{
    if (cha)
    {
        char *con = (char *)cha;
        for (int i = 0; con[i]; i++)
        {
            if (con[i] >= 'a' && con[i] <= 'z')
            {
                con[i] -= 32;
            }
            
        }
        
    }

}

void *double_value(void *content)
{
    int *smart = malloc(sizeof(int));
    if (!smart)
        return NULL;
    *smart = (*(int*)content) * 2;
    return smart;
}

int main()
{
    int a = 1, b = 2, c = 3;
    t_list *list = ft_lstnew(a);
    list->next = ft_lstnew(b);
    list->next->next = ft_lstnew(c);

    printf("Original list is this : ");
    list_print(list);

    t_list *mapped = ft_lstmap(list, double_value, del);

    printf("Mapped List : ");
    list_print(mapped);



    
    
    return 0;
}