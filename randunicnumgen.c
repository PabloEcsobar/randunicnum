/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randunicnumgen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:09:06 by polenyc           #+#    #+#             */
/*   Updated: 2024/02/14 15:46:41 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	checkarr(int *arr, int size, int num)
{
	if (size == 0)
		return (1);
	while(size >= 0)
	{
		if (arr[size] == num)
			return (0);
		--size;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int	size;
	int min;
	int	max;
	int	i;
	int	num;
	int	*arr;
	
	srand(time(NULL));
	printf("Enter size of array: \n");
	scanf("%d", &size);
	printf("Enter min number of array: \n");
	scanf("%d", &min);
	printf("Enter max number of array: \n");
	scanf("%d", &max);
	if (size < 1 || min > max || size >= (max - min))
	{
		printf("ERROE!!! BAd data.\n");
		return(-1);
	}
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (-1);
	i = 0;
	while (i < size)
	{
		num = rand() % max + min;
		if (!checkarr(arr, i, num))
			continue ;
		arr[i] = num;
		++i;
	}
	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		++i;
	}
    return (0);
}