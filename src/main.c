/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:21:03 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/24 04:19:43 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @param int number_of_philosophers
 * @param int time_to_die
 * @param int time_to_eat
 * @param int time_to_sleep
 * @param int number_of_times_each_philosopher_must_eat
 *
 * @returns int is_arg_valid()
 * 허용함수에 별도의 에러처리 함수(exit등)이 없어 main 함수서 flag 값으로 처리
 */
void	set_rules(int argc, char **argv, t_table *table)
{
	table->rule->number_of_philosophers = ft_atoi(argv[1]);
	table->rule->time_to_die = ft_atoi(argv[2]);
	table->rule->time_to_eat = ft_atoi(argv[3]);
	table->rule->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->rule->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		table->rule->number_of_times_each_philosopher_must_eat = 0;
}

int	init_rules(int argc, char **argv, t_table *table)
{
	set_rules(argc, argv, table);
	if (!is_arg_valid(table->rule->number_of_philosophers,
			table->rule->time_to_die, table->rule->time_to_eat,
			table->rule->time_to_sleep) || (argc == 6
			&& table->rule->number_of_times_each_philosopher_must_eat <= 0))
	{
		error("arguments error");
		return (1);
	}
	table->time = get_time(0);
	table->link_philo = malloc(sizeof(t_table *)
			* table->rule->number_of_philosophers);
	/*
		철학자 수만큼 동적할당
	*/
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	/*
		각 철학자는 1부터 number_of_philosophers까지의 고유 번호를 가지고 있습니다.
	*/
	/*
		철학자 번호 1은 철학자 번호 number_of_philosophers의 옆에 앉습니다.
		그 외에 철학자 번호 N 은 철학자 번호 N - 1 과 철학자 번호 N + 1 사이에 앉습니다.
	*/
	if (!(argc == 5 || argc == 6))
	{
		error("invalid argument");
		return (0);
	}
	if (init_rules(argc, argv, &table))
		return (0);
	return (0);
}
