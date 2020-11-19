#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstnew(void *data)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

int		ft_lstsize_bonus(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/*
void	ft_lstadd_front_bonus(t_list **alst, t_list *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}*/

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;
	elem = malloc(sizeof(t_list));

	if (elem)
	{
		elem->data = data;
		elem->next = NULL;
	}
	return (elem);
}

void	ft_list_push_front_bonus(t_list **begin_list, void *data)
{
	t_list	*ptr;

	ptr = ft_create_elem(data);
	ptr->next = *begin_list;
	*begin_list = ptr;
}

void	ft_list_sort_bonus(t_list **begin_list, int (*cmp)())
{
	void	*keep;
	t_list	*list;
	t_list	*next_ptr;

	list = *begin_list;
	if (*begin_list)
	{
		while (list)
		{
			next_ptr = list->next;
			while (next_ptr)
			{
				if ((*cmp)(list->data, next_ptr->data) >= 0)         // 2 5 1 3 0 4
				{
					keep = list->data;
					list->data = next_ptr->data;
					next_ptr->data = keep;
				}
				next_ptr = next_ptr->next;
			}
			list = list->next;
		}
	}
}

int		ft_lstsize(t_list *lst);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_sort(t_list **begin_list, int (*cmp)());

int		intcmp(int a, int b)
{
	//printf("%d <><><><> %d  ===> %d >> %s\n",a,b,a - b, a-b >= 0 ? "j" : "dnj");
	//printf("%p\n",0x0 - 0x4);
	int sum = a - b;
	return (sum);
}

int     main()
{
    void    *data;
	t_list	*tmp;
	t_list	*NULL_list = NULL;
	//int		*arr;

	//arr = malloc(sizeof(int) * 9);
	//printf("%zu %zu\n", sizeof(int), sizeof(arr));
   
   
	printf(";;;;;;;;;;;;;;;;;;;;;;;integer;;;;;;;;;;;;;;;;;;;;;;;\n");
    t_list  *my_list;
    my_list = ft_lstnew((void*)-3);
	my_list->next = ft_lstnew((void*)4); 
    my_list->next->next = ft_lstnew((void*)1);
    my_list->next->next->next = ft_lstnew((void*)0);
    my_list->next->next->next->next = ft_lstnew((void*)2);
    my_list->next->next->next->next->next = ft_lstnew((void*)-1);
    my_list->next->next->next->next->next->next = ft_lstnew((void*)3);
	my_list->next->next->next->next->next->next->next = ft_lstnew((void*)5);
    my_list->next->next->next->next->next->next->next->next = ft_lstnew((void*)-2);

	printf("list size is = %d\n", ft_lstsize(my_list));
	tmp = my_list;
	while (tmp)
	{
        printf("%d\n", (int)tmp->data);
		tmp = tmp->next;
	}
    
	printf("==========before sorting=========\n");

	ft_list_sort(&my_list, intcmp);

	printf("===========after sorting=========\n");
	tmp = my_list;
	while (tmp)
	{
        printf("%d\n", (int)tmp->data);
		tmp = tmp->next;
	}

	printf(";;;;;;;;;;;;;;;;;;;;;;;string;;;;;;;;;;;;;;;;;;;;;;;\n");
	t_list  *my_list2;
	my_list2 = ft_lstnew((void*)"3");
	my_list2->next = ft_lstnew((void*)"4"); 
    my_list2->next->next = ft_lstnew((void*)"1");
	my_list2->next->next->next = ft_lstnew((void*)"0");
    my_list2->next->next->next->next = ft_lstnew((void*)"2");

	

    printf("list size is = %d\n", ft_lstsize(my_list2));
	tmp = my_list2;
	while (tmp)
	{
        printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
    
	printf("==========before sorting=========\n");

	//ft_list_sort(&my_list, intcmp);
	ft_list_sort(&my_list2, &strcmp);

	printf("===========after sorting=========\n");
	tmp = my_list2;
	while (tmp)
	{
        printf("%s\n", tmp->data);
		tmp = tmp->next;
	}

    return (0);
}
