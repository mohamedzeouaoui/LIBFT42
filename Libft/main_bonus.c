#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*multiply_by_two(void *data)
{
	int	*value;
	int	*result;

	value = (int *)data;
	result = malloc(sizeof(int));
	if (result != NULL)
	{
		*result = (*value) * 2;
	}
	return (result);
}

int	main(void)
{
	
    int arr[3] = {1,2,3};
	// Create a linked list with some integer values
	t_list *lst = ft_lstnew(&arr[0]);
	ft_lstadd_back(&lst, ft_lstnew(&arr[1]));
	ft_lstadd_back(&lst, ft_lstnew(&arr[2]));

	// Apply ft_lstmap to multiply each integer value by two
	t_list *new_lst = ft_lstmap(lst, multiply_by_two, free);

	while (new_lst)
	{
		printf("->>> %d\n", *(int *)(new_lst->content));
        new_lst = new_lst->next;
	}

	return (0);
}