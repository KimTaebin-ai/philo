/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimtaebin <kimtaebin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:46:35 by kimtaebin         #+#    #+#             */
/*   Updated: 2024/11/24 21:24:57 by kimtaebin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * 철학자들은 번갈아가며 먹기, 생각하기, 자기를 합니다.
 * 철학자가 먹고 있을 때에는 생각하거나 자지 않습니다.
 * 생각하고 있을 때에는 먹거나 자지 않습니다.
 * 물론 자고 있을 때에는 먹거나 생각하지 않습니다.
 *
 */

void *philosopher_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (1)
    {
        // think(philo);
        pick_up_forks(philo);
        // eat(philo);
        // put_down_forks(philo);
        // sleep_philo(philo);
    }

    return NULL;
}

void pick_up_forks(t_philo *philo)
{
    t_table *table = philo->link_table;
    pthread_mutex_lock(&table->fork[philo->left_fork]);
    pthread_mutex_lock(&table->print);
    printf("Philosopher %d picked up left fork\n", philo->id);
    pthread_mutex_unlock(&table->print);

    pthread_mutex_lock(&table->fork[philo->right_fork]);
    pthread_mutex_lock(&table->print);
    printf("Philosopher %d picked up right fork\n", philo->id);
    pthread_mutex_unlock(&table->print);
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