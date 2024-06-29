#include "minitalk.h"

int	isoverflow(long long int check, long long int res)
{
	if (res / 10 == check)
		return (0);
	return (1);
}

int	is_sspace(const char *str, int *pt)
{
	int	i;
	int	retsi;

	i = 0;
	retsi = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			retsi *= -1;
		i++;
	}
	*pt = i;
	return (retsi);
}

int	ft_atoi(const char *str)
{
	long long int	r;
	int				s;
	long long int	check;
	int				i;

	r = 0;
	s = is_sspace(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = r;
		r = r * 10 + (str[i] - '0');
		if (isoverflow(check, r) == 1)
		{
			if (s == -1)
				return (0);
			return (-1);
		}
		i++;
	}
	return (r * s);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int check(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

size_t	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}