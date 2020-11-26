#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct		s_list
// {
// 	void			*data;
// 	struct s_list	*next;
// }					t_list;

// t_list		*ft_lstnew(void *data)
// {
// 	t_list	*list;

// 	if (!(list = (t_list*)malloc(sizeof(t_list))))
// 		return (NULL);
// 	list->data = data;
// 	list->next = NULL;
// 	return (list);
// }

// int		ft_lstsize_bonus(t_list *lst)
// {
// 	int		size;

// 	size = 0;
// 	while (lst)
// 	{
// 		size++;
// 		lst = lst->next;
// 	}
// 	return (size);
// }

// /*
// void	ft_lstadd_front_bonus(t_list **alst, t_list *new)
// {
// 	if (new)
// 	{
// 		new->next = *alst;
// 		*alst = new;
// 	}
// }*/

// t_list	*ft_create_elem(void *data)
// {
// 	t_list	*elem;
// 	elem = malloc(sizeof(t_list));

// 	if (elem)
// 	{
// 		elem->data = data;
// 		elem->next = NULL;
// 	}
// 	return (elem);
// }

// void	ft_list_push_front_bonus(t_list **begin_list, void *data)
// {
// 	t_list	*ptr;

// 	ptr = ft_create_elem(data);
// 	ptr->next = *begin_list;
// 	*begin_list = ptr;
// }

// void	ft_list_sort_bonus(t_list **begin_list, int (*cmp)())
// {
// 	void	*keep;
// 	t_list	*list;
// 	t_list	*next_ptr;

// 	list = *begin_list;
// 	if (*begin_list)
// 	{
// 		while (list)
// 		{
// 			next_ptr = list->next;
// 			while (next_ptr)
// 			{
// 				if ((*cmp)(list->data, next_ptr->data) >= 0)         // 2 5 1 3 0 4
// 				{
// 					keep = list->data;
// 					list->data = next_ptr->data;
// 					next_ptr->data = keep;
// 				}
// 				next_ptr = next_ptr->next;
// 			}
// 			list = list->next;
// 		}
// 	}
// }

// int		ft_lstsize(t_list *lst);
// void	ft_list_push_front(t_list **begin_list, void *data);
// void	ft_list_sort(t_list **begin_list, int (*cmp)());


// int		intcmp(int a, int b)
// {
// 	//printf("%d <><><><> %d  ===> %d >> %s\n",a,b,a - b, a-b >= 0 ? "j" : "dnj");
// 	//printf("%p\n",0x0 - 0x4);
// 	int sum = a - b;
// 	return (sum);
// }
int     atoi_base(char *str, char *base);
int     ft_atoi_base(char *str, char *base);

int     main()
{
   /* void    *data;
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
	*/
	//char    *str = strdup("-135");              //base 10 = (1 * 10^2) + (3 * 10^1) + (5 * 10^0) = 100 + 30 + 5 = 135
    //char    *base = strdup("0123456789abcdef");
//0a
   //printf("atoi = |%d|\n",atoi_base("b", "cab"));
    //printf("ft_atoi = |%d|\n",ft_atoi_base("b", "cab"));
    printf("ft_atoi_base = |%d|\n",ft_atoi_base("a", "0a"));
    printf("atoi_base = |%d|\n",atoi_base("a", "0a"));
    //printf("%d\n",atoi_base("+10100111001", "0123"));
	//printf("%d\n",ft_atoi_base("+10100111001", "0123"));

	return (0);
}


int     check_errors(char n, char *base)
{
    if (n == '+' || n == '-')
        return (1);
    while (*base)
    {
        if (n == *base)
            return (1);
        base++;
    }
    return (0);
}

int     check_base(char *base)
{
    int     d_base;

    d_base = -1;
    while (base[++d_base])
        if (check_errors(base[d_base],base + d_base + 1))
            return (0);
    return (d_base);
}

int     check_existence(char n, char *base)
{
    while (*base)
    {
        if (n == *base)
            return (1);
        base++;
    }
    return (0);
}

int     check_num(char *str, char *base)
{
    int     count;
    
    count = 0;
    while (str[count])
    {
        if (check_existence(str[count], base) == 0)
            return (0);
        count++;
    }
    return (count);
}

int     get_value(char n, char *base)
{
    int     index;

    index = 0;
    while (base[index])
    {
        if (n == base[index])
            break ;
        index++;
    }
    return (index);
}

int     convert_num_to_decimal(char *str, char *base, int d_base, int count)
{
    int     num;
    int     base_pow;

    num = 0;
    base_pow = 1;
    while (--count >= 0)
    {
        num += get_value(str[count], base) * base_pow;
        base_pow *= d_base;
    }
    return (num);
}

int     atoi_base(char *str, char *base)
{
    int     d_base;
    int     count;
    int     num;
    int     neg;
   
    neg = *str == '-' ? -1 : 1;
    if (*str == '-' || *str == '+')
        str++;
    if ((d_base = check_base(base)) < 2)
        return (0);
    if ((count = check_num(str, base)) == 0)
        return (count);
    num = convert_num_to_decimal(str, base, d_base, count);
    return (num * neg);
}