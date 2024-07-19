#include "minitalk.h"

int errors_in_main(int ac, char **av)
{
    if (ac != 3)
        return (1);
    if (!check(av[1]))
        return (1);
    return (0);
}

void    send_msg(int pid, char *str)
{
    int i;
    int b;

    i = 0;
    while (1)
    {
        b = 8;
        while (b--)
        {
            if (((str[i] >> b) & 1) == 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(500);
        }
        if (str[i] == '\0')
            break;
        i++;
    }
}

int main(int ac, char *av[])
{
    int     pid;
    char    *msg;

    if (errors_in_main(ac, av))
        return (-1);
    pid = ft_atoi(av[1]);
    if (pid <= 0)
        return (-1);
    msg = av[2];
    send_msg(pid, msg);
    return (0);
}
