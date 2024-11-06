#!/bin/sh

number_of_philosophers=100
time_to_die=601
time_to_eat=300
time_to_sleep=300
number_of_times_each_philosopher_must_eat=42

make philo
./philo $number_of_philosophers $time_to_die $time_to_eat $time_to_sleep $number_of_times_each_philosopher_must_eat >logs
for i in `seq $number_of_philosophers`; do
	number_of_meals=$(grep -E "$i\s+is eating" <logs | wc -l)
	if [ $number_of_meals -lt $number_of_times_each_philosopher_must_eat ]; then
		echo "failed: $i ate only $number_of_meals time(s)"
		exit 1
	fi
done
rm logs
