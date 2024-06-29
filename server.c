#include "minitalk.h"

void    Receive_signal(int signal)
{
    static char current_char;
    static int  b = 0;
    current_char <<= 1;
    current_char |= (signal == SIGUSR2);
    b++;
    if (b == 8)
    {
        if (current_char == '\0')
            printf("\n");
        else
            printf("%c", current_char);
        b = 0;
        current_char = 0;
    }
}


int main()
{
    struct sigaction sa;

    sa.sa_handler = Receive_signal;
    sa.sa_flags = 0;
    printf("%d\n",getpid());
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
        system("leaks server");
    return 0;
}
