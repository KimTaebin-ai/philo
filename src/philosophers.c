/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimtaebin <kimtaebin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:46:35 by kimtaebin         #+#    #+#             */
/*   Updated: 2024/11/24 17:20:01 by kimtaebin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philosopher_routine(void *arg)
{
    t_philo *phlio = (t_philo *)arg;

    while (1)
    {
        /**
         * pick_up_fork();
         * eat();
         * put_down_fork();
         * sleep_philo();
         *
         *
         */
    }

    return NULL;
}

void pick_up_forks(t_philo *philo)
{
}

void eat()
{
}

void put_down_fork()
{
}

void sleep_philo()
{
}

void think()
{
}