#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
    printf("\033[2J\033[?25l");
    for (int i=0; i<20; i++)
    
    {
        printf("\033[H\n\n\n");

        printf("\033[1;36m        O \n");
        printf("      /|\\ ");

        printf("\033[1;31m");
        for (int j=0; j<i; j++)
        {
           printf("=");
        }
        if(i > 0)
        {
            printf(">");
        }
        else
        {
            printf(" ");
        }

        for (int j=i; j<18; j++)
        {
           printf(" ");
        }
        if(i < 19)
        {
            printf("\033[1;37m[ TARGET] \n");
        }
        else
        {
            printf("\033[1;33m * BOOM * \n"); 
        }

        printf("\033[1;36m       / \\  \n");

        struct timespec ts = {0, 120000 * 1000};
        nanosleep(&ts, NULL);
        
    }
    
    return 0;
}