/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimtaebin <kimtaebin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:21:03 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/25 00:12:52 by kimtaebin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * 1 argv
 * 2 invalid check
 * 3 table init
 * 4 philosopher init
 * 5 eat func
 * 6 sleep func
 * 7 think func
 * 8-1 argc가 5개일 때 죽는 철학자 수 die
 * 8-2 argc가 6개일 때 must 처리
 * 9 pthread join 기다린 후 free
 */

/**
 * 각 철학자는 스레드로 구현되어 있어야 합니다.
 *
 * 두 철학자 사이에 한 개의 포크가 존재하므로, 철학자가 여러명일 경우
 * 각 철학자의 왼쪽과 오른쪽에 포크가 하나씩 존재해야 합니다.
 * 철학자가 한 명일 경우 테이블 위에 포크가 하나만 존재해야 합니다.
 *
 * 철학자가 포크를 복제하는 것을 막기 위해서,
 * 각 포크의 현재 상태를 뮤텍스를 이용하여 보호해주어야 합니다.
 *
 */

/**
 * @param int number_of_philosophers
 * @param int time_to_die
 * @param int time_to_eat
 * @param int time_to_sleep
 * @param int number_of_times_each_philosopher_must_eat
 */
int main(int argc, char **argv)
{
	t_table table;

	if (!(argc == 5 || argc == 6))
	{
		error("invalid argument");
		return (0);
	}
	if (init_rules(argc, argv, &table))
		return (0);
	if (init_mutex(&table))
		return 0;
	if (init_philosophers(&table))
		return 0;
	return (0);
}
