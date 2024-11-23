/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:41:01 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/24 03:45:20 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_arg_valid(int number, int die, int eat, int sleep)
{
	return (number > 0 && die > 0 && eat > 0 && sleep > 0);
}

int	ft_atoi(const char *nptr)
{
	int						sign;
	int						i;
	unsigned long long int	num;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
		i++;
	if (nptr[i] == '-' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
	{
		sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * num);
}

/**
 * @param long set_time
 * @returns 해당 과제에서의 시간 단위는 ms
 * 현재 ms 단위 시간에서 set_time 을 뺀 값을 반환
 */
long	get_time(long set_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - set_time);
}
