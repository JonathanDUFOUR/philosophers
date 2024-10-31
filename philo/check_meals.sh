#!/bin/sh

number_of_philosophers=2
number_of_times_each_philosopher_must_eat=100

for i in `seq $number_of_philosophers`; do
	number_of_meals=$(grep -E "$i\s+is eating" <logs | wc -l)
	if [ $number_of_meals -lt $number_of_times_each_philosopher_must_eat ]; then
		echo "failed: $i ate only $number_of_meals time(s)"
	fi
done
