/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:33:49 by iltafah           #+#    #+#             */
/*   Updated: 2020/11/20 14:36:33 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    fill_buff_with_neg_one(int *buff)
{
    int     i;

    i = 0;
    while (i < 96)
        buff[i++] = -1;
}

int     check_base(char *base, int *buff)
{
    int     d_base;
    int     index;

    d_base = 0;
    while (base[d_base])
    {
        index = (int)base[d_base] - 32;
        if (buff[index] == -1)
            buff[index] = d_base;
        else
        {
            d_base = 0;
            break ;   
        }
        d_base++;
    }
    if (buff[43 - 32] >= 0 || buff[45 - 32] >= 0)
        return (0);
    return (d_base);
}


int     check_num(char *str, int d_base, int *buff)
{
    int     index;
    int     count;
    
    if (*str == '+' || *str == '-')
        str++;
    while (str[count])
    {
        index = (int)str[count] - 32;
        if (buff[index] == -1)
            return (0);
        count++;
    }
    return (count);
}

int     convert_num_to_decimal(char *str, int *buff, int count, int d_base)
{
    int     num;
    int     base_pow;
    
    num = 0;
    base_pow = 1;
    while (--count >= 0)
    {
        num += (buff[(int)str[count] - 32] * base_pow);
        printf("num = %d  str[count] = %c  buff = %d  pow = %d\n",num,str[count],buff[(int)str[count] - 32],base_pow);
        base_pow *= d_base;
    }
    return (num);
}

int     ft_atoi_base(char *str, char *base)
{
    int     d_base; 
    int     num;
    int     count;
    int     *buff;
    
    buff = malloc(sizeof(int) * 96 + 1);
    buff[96] = '\0';
    fill_buff_with_neg_one(buff);
    d_base = check_base(base, buff);
    if (d_base < 2)
        return (0);
    count = check_num(str, d_base, buff);
    if (count == 0)
        return (0);
    num = convert_num_to_decimal(str, buff, count, d_base);
    free(buff);
    return (num);
}

int     main()
{                                             
    char    *str = strdup("13f5");              //base 10 = (1 * 10^2) + (3 * 10^1) + (5 * 10^0) = 100 + 30 + 5 = 135
    char    *base = strdup("0123456789abcdef");

    printf("%d\n",ft_atoi_base(str, base));
    return (0);
}