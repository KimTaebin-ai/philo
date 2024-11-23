/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:21:03 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/23 07:06:06 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_rules(void)
{
	int	is_error;

	/*
		허용함수에 별도의 에러처리 함수(exit등)이 없어
		main 함수서 flag 값으로 처리
	*/
	is_error = 0;
}

int	main(int argc, char **argv)
{
	/*
		각 철학자는 1부터 number_of_philosophers까지의 고유 번호를 가지고 있습니다.
	*/

	/*
		철학자 번호 1은 철학자 번호 number_of_philosophers의 옆에 앉습니다.
		그 외에 철학자 번호 N 은 철학자 번호 N - 1 과 철학자 번호 N + 1 사이에 앉습니다.
	*/

	if (argc != 5 || argc != 6)
	{
		error("invalid argument");
		return (0);
	}

	return (0);
}