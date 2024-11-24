/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimtaebin <kimtaebin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:21:03 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/24 17:54:03 by kimtaebin        ###   ########.fr       */
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
void set_rules(int argc, char **argv, t_table *table)
{
	table->rule = malloc(sizeof(t_rules)); // 동적할당 필요
	table->rule->number_of_philosophers = ft_atoi(argv[1]);
	table->rule->time_to_die = ft_atoi(argv[2]);
	table->rule->time_to_eat = ft_atoi(argv[3]);
	table->rule->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->rule->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		table->rule->number_of_times_each_philosopher_must_eat = -1;
}

int init_rules(int argc, char **argv, t_table *table)
{
	set_rules(argc, argv, table);
	// TODO 유효성 논리 연산
	if (!is_arg_valid(table->rule->number_of_philosophers,
					  table->rule->time_to_die, table->rule->time_to_eat,
					  table->rule->time_to_sleep) ||
		(argc == 6 && table->rule->number_of_times_each_philosopher_must_eat <= 0))
	{
		error("arguments error");
		return (1);
	}
	table->time = get_time(0);
	table->link_philo = malloc(sizeof(t_table *) * table->rule->number_of_philosophers);
	// 철학자 수(number_of_philosophers)만큼 동적할당
	return (0);
}

/**
 * 공유자원인 포크의 개수만큼 mutex 생성
 */
void init_mutex(t_table *table)
{
	int i;

	i = 0;
	table->fork = malloc(sizeof(pthread_mutex_t) * table->rule->number_of_philosophers);
	while (i < table->rule->number_of_philosophers)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->print, NULL);
	/*
		printf() 함수는 버퍼에 쌓여있는 입력값들을 개행문자 '\n' 가 나오면
		버퍼를 비워주며 출력하는 함수이다.
		여러 쓰레드가 동시에 printf() 를 호출하게 될 때
		출력 메시지가 중첩되거나 엉킬 수 있다
		따라서 뮤텍스를 활용해 한 번에 하나의 쓰레드만을 사용함을 "보장"하고
		출력 결과를 예상 가능한 형태로 만들어준다.
	*/
	pthread_mutex_init(&table->last_ate, NULL);
	printf("%d", i);
}

/**
 * @param pthread_t philosopher
 * @param int id
 * @param int left_fork
 * @param int right_fork
 * @param int eat_cout
 * @param long last_eat
 *
 * philosophers 구조체 초기화
 */
int init_philosophers(t_table *table)
{
	int i = 0;

	// TODO allocate 2차원 배열 수정
	table->link_philo = malloc(sizeof(t_philo *) * table->rule->number_of_philosophers);

	if (!table->link_philo)
	{
		error("philosophers allocate failed");
		return 1;
	}

	while (i < table->rule->number_of_philosophers)
	{
		table->link_philo[i] = malloc(sizeof(t_philo));
		table->link_philo[i]->id = i;
		table->link_philo[i]->left_fork = i;
		table->link_philo[i]->right_fork = (i + 1) % table->rule->number_of_philosophers;
		table->link_philo[i]->eat_count = 0;
		table->link_philo[i]->last_eat = table->time;
		// pthread_create(&table->link_philo[i]->philosopher, NULL, philosopher_routine, );
		i++;
	}

	return 0;
}

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

int main(int argc, char **argv)
{
	t_table table;

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
	if (!(argc == 5 || argc == 6))
	{
		error("invalid argument");
		return (0);
	}
	if (init_rules(argc, argv, &table))
		return (0);
	init_mutex(&table);
	if (init_philosophers(&table))
		return 0;
	return (0);
}
