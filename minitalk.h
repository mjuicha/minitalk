#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdio.h>
#include <unistd.h>



int 	isoverflow(long long int check, long long int res);
int 	is_sspace(const char *str, int *pt);
int 	ft_atoi(const char *str);
int 	ft_isdigit(int c);
int     check(char *str);
int     errors_in_main(int ac, char **av);
size_t	ft_strlen(char *str);

#endif