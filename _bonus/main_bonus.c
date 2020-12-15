#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
#define COLOR
//////////////////////////////////////////////////////
typedef struct		s_list						 	//
{													//
	void			*data;							//
	struct s_list	*next;							//
}					t_list;							//
													//
t_list	*ft_create_elem(void *data)					//
{													//
	t_list	*elem;									//
	elem = malloc(sizeof(t_list));					//
													//
	if (elem)										//
	{												//
		elem->data = data;							//
		elem->next = NULL;							//
	}												//
	return (elem);									//
}													//
//////////////////////////////////////////////////////

///////////////////////////////////////////ft_lstsize_bonus///////////////////////////////////////////////////
int		ft_lst_size_bonus(t_list *lst)																		//
{																											//
	int		size;																							//
																											//
	size = 0;																								//
	while (lst)																								//
	{																										//
		size++;																								//
		lst = lst->next;																					//
	}																										//
	return (size);																							//
}																											//
///////////////////////////////////////////ft_list_push_front_bonus///////////////////////////////////////////
void	ft_list_push_front_bonus(t_list **begin_list, void *data)											//
{																											//
	t_list	*ptr;																							//
																											//
	ptr = ft_create_elem(data);																				//
	ptr->next = *begin_list;																				//
	*begin_list = ptr;																						//
}																											//
//////////////////////////////////////////////ft_list_sort_bonus//////////////////////////////////////////////
void	ft_list_sort_bonus(t_list **begin_list, int (*cmp)())												//
{																											//
	void	*keep;																							//
	t_list	*list;																							//
	t_list	*next_ptr;																						//
																											//	
	list = *begin_list;																						//
	if (*begin_list)																						//
	{																										//
		while (list)																						//
		{																									//
			next_ptr = list->next;																			//
			while (next_ptr)																				//
			{																								//
				if ((*cmp)(list->data, next_ptr->data) >= 0)												//
				{																							//
					keep = list->data;																		//
					list->data = next_ptr->data;															//
					next_ptr->data = keep;																	//
				}																							//
				next_ptr = next_ptr->next;																	//
			}																								//
			list = list->next;																				//
		}																									//
	}																										//
}																											//
///////////////////////////////////////////list_remove_if/////////////////////////////////////////////////////
void	remove_it_from_start(t_list **curr, void *data_ref, int (*cmp)(), t_list **next)					//
{																											//
	while (*curr && (*cmp)((*curr)->data, data_ref) == 0)													//
	{																										//
		*next = (*curr)->next;																				//
		free(*curr);																						//
		*curr = *next;																						//
	}																										//
}																											//
void	free_it(t_list **prev, t_list **curr, t_list **next)												//
{																											//
	(*prev)->next = *next;																					//
	free(*curr);																							//
	*curr = *next;																							//
}																											//
																											//
void	list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())									//
{																											//
	t_list	*curr;																							//
	t_list	*next;																							//
	t_list	*prev;																							//
																											//
	if (begin_list)																							//
	{																										//
		curr = *begin_list;																					//
		next = NULL;																						//
		remove_it_from_start(&curr, data_ref, cmp, &next);													//
		*begin_list = curr;																					//
		if (curr)																							//
		{																									//
			prev = curr;																					//
			curr = curr->next;																				//
		}																									//
		while (curr)																						//
		{																									//
			next = curr->next;																				//
			if ((*cmp)(curr->data, data_ref) == 0)															//
				free_it(&prev, &curr, &next);																//
			else																							//
			{																								//
				prev = curr;																				//
				curr = curr->next;																			//
			}																								//
		}																									//
	}																										//
}																											//
///////////////////////////////////////////atoi base//////////////////////////////////////////////////////////
int     check_errors(char n, char *base)																	//
{																											//
    if (n == '+' || n == '-')																				//
        return (1);																							//
    while (*base)																							//
    {																										//
        if (n == *base)																						//
            return (1);																						//
        base++;																								//
    }																										//
    return (0);																								//
}																											//
																											//
int     check_base(char *base)																				//
{																											//
    int     d_base;																							//
																											//
    d_base = -1;																							//
    while (base[++d_base])																					//
        if (check_errors(base[d_base],base + d_base + 1))													//
            return (0);																						//
    return (d_base);																						//
}																											//
																											//
int     check_existence(char n, char *base)																	//
{																											//
    while (*base)																							//
    {																										//
        if (n == *base)																						//
            return (1);																						//
        base++;																								//
    }																										//
    return (0);																								//
}																											//
																											//
int     check_num(char *str, char *base)																	//
{																											//
    int     count;																							//
																											//
    count = 0;																								//
    while (str[count])																						//
    {																										//
        if (check_existence(str[count], base) == 0)															//
            return (0);																						//
        count++;																							//
    }																										//
    return (count);																							//
}																											//
																											//
int     get_value(char n, char *base)																		//
{																											//
    int     index;																							//
																											//
    index = 0;																								//
    while (base[index])																						//
    {																										//
        if (n == base[index])																				//
            break ;																							//
        index++;																							//
    }																										//
    return (index);																							//
}																											//
																											//
int     convert_num_to_decimal(char *str, char *base, int d_base, int count)								//
{																											//
    int     num;																							//
    int     base_pow;																						//
																											//
    num = 0;																								//
    base_pow = 1;																							//
    while (--count >= 0)																					//
    {																										//
        num += get_value(str[count], base) * base_pow;														//
        base_pow *= d_base;																					//
    }																										//
    return (num);																							//
}																											//
																											//
int     atoi_base(char *str, char *base)																	//
{																											//
    int     d_base;																							//
    int     count;																							//
    int     num;																							//
    int     neg;																							//
																											//
    if (!str || !base)																						//
        return(0);																							//
    neg = *str == '-' ? -1 : 1;																				//
    if (*str == '-' || *str == '+')																			//
        str++;																								//
    if ((d_base = check_base(base)) < 2)																	//
        return (0);																							//
    if ((count = check_num(str, base)) == 0)																//
        return (count);																						//
    num = convert_num_to_decimal(str, base, d_base, count);													//
    return (num * neg);																						//
}																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////PROTOTYPES////////////////////////////////////
int		ft_list_size(t_list *lst);												//
void	ft_list_push_front(t_list **begin_list, void *data);					//
void	ft_list_sort(t_list **begin_list, int (*cmp)());						//
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());	//
int     ft_atoi_base(char *str, char *base);									//
//////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////USEFUL FUNCTIONS///////////////////////////////////////////////
int		intcmp(int a, int b)																				//
{																											//
	int sum = a - b;																						//
	return (sum);																							//
}																											//
																											//
void	calc_line_printed_for_int(int *sprint_ret, t_list *list)											//
{																											//
	char    *sprint_buff;																					//
																											//
	*sprint_ret = 2;																						//
	sprint_buff = calloc(sizeof(char), 1337 + 1);															//
	if (list)																								//
	{																										//
		while (list->next)																					//
		{																									//
        	*sprint_ret += snprintf(sprint_buff , 1337, "%d", (int)list->data);								//
			*sprint_ret += snprintf(sprint_buff , 1337, " -> ");											//
			list = list->next;																				//
		}																									//
		*sprint_ret += snprintf(sprint_buff , 1337, "%d", (int)list->data);									//
	}																										//
	free(sprint_buff);																						//
}																											//
																											//
void	calc_line_printed_for_string(int *sprint_ret, t_list *list)											//
{																											//
	char    *sprint_buff;																					//
																											//
	*sprint_ret = 2;																						//
	sprint_buff = calloc(sizeof(char), 1337 + 1);															//
	if (list)																								//
	{																										//
		while (list->next)																					//
		{																									//
        	*sprint_ret += snprintf(sprint_buff , 1337, "%s", (char*)list->data);							//
			*sprint_ret += snprintf(sprint_buff , 1337, " -> ");											//
			list = list->next;																				//
		}																									//
		*sprint_ret += snprintf(sprint_buff , 1337, "%s", (char*)list->data);								//
	}																										//
	free(sprint_buff);																						//
}																											//
																											//
void	print_separator1(int sprint_ret)																	//
{																											//
	if (sprint_ret < 35)																					//
		sprint_ret = 35;																					//
	for (int i = -1; i <= sprint_ret; i++)																	//
		printf(GRN "=");																					//
	printf("\n");																							//
}																											//
																											//
void	print_separator2(int printed, int sprint_ret, char *str)											//
{																											//
	if (sprint_ret < 35)																					//
		sprint_ret = 35;																					//
	while (printed++ < sprint_ret)																			//
		printf(" ");																						//
	printf(GRN "%s\n", str);																				//
}																											//
																											//
void	free_list(t_list **list)																			//
{																											//
	t_list	*tmp;																							//
																											//
	if (list)																								//
	{																										//
		while (*list)																						//
		{																									//
			tmp = (*list)->next;																			//
			free(*list);																					//
			*list = tmp;																					//
		}																									//
	}																										//
}																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////		
//													MAIN													//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int     main()																								
{																											
	t_list	*tmp;   																						
    t_list  *my_list;																						
    int     sprint_ret;																						
	int		printed;																						
	int		spaces;																							
	int		len;

    ft_list_push_front(&my_list, (void*)-3);
	ft_list_push_front(&my_list, (void*)4);
	ft_list_push_front(&my_list, (void*)1);
	ft_list_push_front(&my_list, (void*)0);
	ft_list_push_front(&my_list, (void*)2);
	ft_list_push_front(&my_list, (void*)-1);
	ft_list_push_front(&my_list, (void*)3);
	ft_list_push_front(&my_list, (void*)5);
	ft_list_push_front(&my_list, (void*)-2);
	ft_list_push_front(&my_list, (void*)-2);
	ft_list_push_front(&my_list, (void*)-2);
	ft_list_push_front(&my_list, (void*)-2);
	
	calc_line_printed_for_int(&sprint_ret, my_list);
	len = strlen("ft_list_sort()");
	print_separator1(sprint_ret);
	printed = printf("**");
	printf(MAG);
	spaces = (sprint_ret/2) + len/2;
	spaces = spaces < len ? len + spaces/2 : spaces;
	printed += printf("%*s", spaces, "ft_list_sort()");
	print_separator2(printed, sprint_ret, "**");
	print_separator1(sprint_ret);
	
	printed = printf("||");
	printf(RESET);
	printed += printf("testing using integers :");
	print_separator2(printed, sprint_ret, "||");

	printed = printf("||");
	printf(RESET);
	printed += printf("==========before sorting=========");
	print_separator2(printed, sprint_ret, "||");

	printf("||");
	tmp = my_list;
	if (tmp)
	{
		while (tmp->next)
		{
        	printf(RED "%d", (int)tmp->data);
			printf(YEL " -> ");
			tmp = tmp->next;
		}
		printf(RED "%d", (int)tmp->data);
		print_separator2(sprint_ret, sprint_ret, "||");
	}

	ft_list_sort(&my_list, intcmp);
	
	printed = printf("||");
	printf(RESET);
	printed += printf("===========after sorting=========");
	print_separator2(printed, sprint_ret, "||");

	printed = printf("||");
	tmp = my_list;
	if (tmp)
	{
		while (tmp->next)
		{
        	printf(GRN "%d", (int)tmp->data);
			printf(YEL " -> ");
			tmp = tmp->next;
		}
		printf(GRN "%d", (int)tmp->data);
		print_separator2(sprint_ret, sprint_ret, "||");
	}

	printed = printf("||");
	printf(CYN);
	printed += printf("list size is = %d", ft_list_size(my_list));
	print_separator2(printed, sprint_ret, "||");
	print_separator1(sprint_ret);
	free_list(&my_list);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ft_list_push_front(&my_list, (void*)"3");
	ft_list_push_front(&my_list, (void*)"4");
	ft_list_push_front(&my_list, (void*)"1");
	ft_list_push_front(&my_list, (void*)"0");
	ft_list_push_front(&my_list, (void*)"2");

	calc_line_printed_for_string(&sprint_ret, my_list);
	print_separator1(sprint_ret);
	printed = printf("||");
	printf(RESET);
	printed += printf("testing using strings :");
	print_separator2(printed, sprint_ret, "||");

	printed = printf("||");
	printf(RESET);
	printed += printf("==========before sorting=========");
	print_separator2(printed, sprint_ret, "||");

	printf("||");
	tmp = my_list;
	if (tmp)
	{
		while (tmp->next)
		{
        	printf(RED "%s", tmp->data);
			printf(YEL " -> ");
			tmp = tmp->next;
		}
		printf(RED "%s", tmp->data);
		print_separator2(sprint_ret, sprint_ret, "||");
	}

	ft_list_sort(&my_list, &strcmp);

	printed = printf("||");
	printf(RESET);
	printed += printf("===========after sorting=========");
	print_separator2(printed, sprint_ret, "||");

	printf("||");
	tmp = my_list;
	if (tmp)
	{
		while (tmp->next)
		{
        	printf(GRN "%s", tmp->data);
			printf(YEL " -> ");
			tmp = tmp->next;
		}
		printf(GRN "%s", tmp->data);
		print_separator2(sprint_ret, sprint_ret, "||");
	}
	printed = printf("||");
	printf(CYN);
	printed += printf("list size is = %d", ft_list_size(my_list));
	print_separator2(printed, sprint_ret, "||");
	print_separator1(sprint_ret);
	free_list(&my_list);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	char	*imposter = strdup("Z");
	char	*ptr = imposter;
	ft_list_push_front(&my_list, (void*)imposter);
	ft_list_push_front(&my_list, (void*)imposter);
	ft_list_push_front(&my_list, (void*)"a");
	ft_list_push_front(&my_list, (void*)imposter);
	ft_list_push_front(&my_list, (void*)imposter);
	ft_list_push_front(&my_list, (void*)"b");
	ft_list_push_front(&my_list, (void*)"c");
	ft_list_push_front(&my_list, (void*)"d");
	ft_list_push_front(&my_list, (void*)imposter);
	ft_list_push_front(&my_list, (void*)"e");
	ft_list_push_front(&my_list, (void*)"f");
	ft_list_push_front(&my_list, (void*)imposter);
	ft_list_push_front(&my_list, (void*)imposter);
    
	calc_line_printed_for_string(&sprint_ret, my_list);
	printf("\n");
	print_separator1(sprint_ret);
	printed = printf("**");
	printf(MAG);
	len = strlen("ft_list_remove_if()");
	spaces = (sprint_ret/2) + len/2;
	spaces = spaces < len ? len + spaces/2 : spaces;
	printed += printf("%*s", spaces, "ft_list_remove_if()");
	print_separator2(printed, sprint_ret, "**");
	print_separator1(sprint_ret);

	printed = printf("||");
	printf(RESET);
    printed += printf("==========before removing========");
	print_separator2(printed, sprint_ret, "||");

	printed = printf("||");
	tmp = my_list;
	if (tmp)
	{
		while (tmp->next)
		{
			if (!strcmp(imposter, tmp->data))
       			printf(RED "%s", tmp->data);
			else
				printf(GRN "%s", tmp->data);
			printf(YEL " -> ");
			tmp = tmp->next;
		}
		if (!strcmp(imposter, tmp->data))
			printf(RED "%s", tmp->data);
		else
			printf(GRN "%s", tmp->data);
		print_separator2(sprint_ret, sprint_ret, "||");
	}

	printed = printf("||");
	printf(CYN);
	printed += printf("list size is = %d", ft_list_size(my_list));
	print_separator2(printed, sprint_ret, "||");

    list_remove_if(&my_list, imposter, strcmp);
	int	sprint_ret2;
	calc_line_printed_for_string(&sprint_ret2, my_list);

	printed = printf("||");
	printf(RESET);
    printed += printf("==========after removing=========");	
	print_separator2(printed, sprint_ret, "||");

	printed = printf("||");
	tmp = my_list;
	if (tmp)
	{
		while (tmp->next)
		{
			if (!strcmp(imposter, tmp->data))
       			printf(RED "%s", tmp->data);
			else
				printf(GRN "%s", tmp->data);
			printf(YEL " -> ");
			tmp = tmp->next;
		}
		if (!strcmp(imposter, tmp->data))
			printf(RED "%s", tmp->data);
		else
			printf(GRN "%s", tmp->data);
		print_separator2(sprint_ret2, sprint_ret, "||");
	}

	printed = printf("||");
	printf(CYN);
	printed += printf("list size is = %d", ft_list_size(my_list));
	print_separator2(printed, sprint_ret, "||");
	print_separator1(sprint_ret);
	free_list(&my_list);
////////////////////////////////////////////////////////////////////////////
	//char    *str = strdup("-135");              //base 10 = (1 * 10^2) + (3 * 10^1) + (5 * 10^0) = 100 + 30 + 5 = 135
    //char    *base = strdup("0123456789abcdef");
//0a
    // printf("atoi_base = |%d|\n",atoi_base("", "cab"));
    // printf("ft_atoi = |%d|\n",ft_atoi_base("", "cab"));
    // printf("atoi_base = |%d|\n",atoi_base("13", ""));
    // printf("ft_atoi = |%d|\n",ft_atoi_base("13", ""));
    // printf("atoi_base = |%d|\n",atoi_base("13", NULL));
    // printf("ft_atoi = |%d|\n",ft_atoi_base("13", NULL));
    // printf("atoi_base = |%d|\n",atoi_base(NULL, "0123"));
    // printf("ft_atoi = |%d|\n",ft_atoi_base(NULL, "0123"));
    // printf("atoi_base = |%d|\n",atoi_base("b", "cab"));
    // printf("ft_atoi = |%d|\n",ft_atoi_base("b", "cab"));
    // printf("atoi_base = |%d|\n",atoi_base("a", "0a"));
    // printf("ft_atoi_base = |%d|\n",ft_atoi_base("a", "0a"));
    // printf("atoi_base = |%d|\n",atoi_base("+10100111001", "01"));
	// printf("ft_atoi_base = |%d|\n",ft_atoi_base("+10100111001", "01"));

	return (0);
}


