/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:16:56 by taebkim           #+#    #+#             */
/*   Updated: 2024/11/24 11:04:07 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	/* data */
	pthread_t		philosopher;
	/*
		thread
	*/
	int				id;
	/*
		철학자 unique id
	*/
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long			last_eat;
}					t_philo;

typedef struct s_rules
{
	/* data */

	int				number_of_philosophers;
	/*
		철학자의 수 :
		철학자의 수와 포크의 수입니다.
	*/

	int				time_to_die;
	/*
		철학자의 수명(밀리초 단위) :
		철학자가 마지막으로 밥을 먹기 시작한 시점으로부터
		time_to_die 시간만큼이 지나거나,
		프로그램 시작 후 time_to_die 시간만큼이 지나도록
		식사를 시작하지 않으면 해당 철학자는 사망합니다.
	*/

	int				time_to_eat;
	/*
		밥을 먹는데 걸리는 시간(밀리초 단위) :
		철학자가 밥을 먹는데 걸리는 시간입니다.
		해당 시간동안 철학자는 두 개의 포크를 잡고 있어야 합니다.
	*/

	int				time_to_sleep;
	/*
		잠자는 시간(밀리초 단위) :
		잠을 자는 데 소모되는 시간 입니다.
	*/

	int				number_of_times_each_philosopher_must_eat;
	/*
		각 철학자가 최소한 밥을 먹어야 하는 횟수(선택적 인자):
		모든 철학자가 number_of_times_each_philosopher_must_eat 번 이상
		밥을 먹으면 시뮬레이션이 종료됩니다.
		지정되지 않은 경우, 철학자가 죽을 때 시뮬레이션이 종료됩니다.
	*/

}					t_rules;

typedef struct s_table
{
	t_rules			*rule;
	long			time;
	t_philo			**link_philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t print;    // printf
	pthread_mutex_t last_ate; // 공유자원
}					t_table;

void				error(char *msg);

// utils
int					ft_atoi(const char *nptr);
long				get_time(long set_time);

// is_ utils
int					is_arg_valid(int number, int die, int eat, int sleep);

#endif