#include "philo.h"

void	write_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(2, &str[i++], 1);
}

void	write_message(t_philos *philo, int flag)
{
	if (!flag && !philo->context->some_die && !philo->context->finished)
	{
		printf("[%lu] %d is eating\n", get_time(philo, 1) - philo->context->start_time, philo->id);
	}
	else if (flag == 1 && !philo->context->some_die && !philo->context->finished)
		printf("[%lu] %d is sleeping\n", get_time(philo, 0) - philo->context->start_time, philo->id);
	else if (flag == 2 && !philo->context->some_die && !philo->context->finished)
		printf("[%lu] %d is thinking\n", get_time(philo, 0) - philo->context->start_time, philo->id);
}

int	find_dead_man(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].context->num_philos)
	{
		if (philos[i].dead)
			return (i + 1);
		i++;
	}
	return (0);
}

void	print_info(t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].context->num_philos)
		printf("Il filosofo %d ha mangiato %d volte\n", philos[i].id, philos[i].times_eaten);
}

int	monitor_meals(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].context->num_philos)
	{
		if (philos[i].times_eaten < philos[i].context->times_to_eat)
			return (0);
		i++;
	}
	return (1);
}
