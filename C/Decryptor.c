#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() 
{
    printf("\033[2J\033[?25l");
    for(int step = 0; step <= 30 ; step++)
    {
        printf("\033[H\033[1;36m\n [ DECRYPTING MAINFRAME] \n\n");
        for(int i = 0; i < 12; i++) 
        {
            printf("  ");
            for(int j = 0; j < 25; j++)
            {
                if ((i+j) < step)
                {
                    printf("\033[1;32m%02X ", (i * j + step) % 256);
                }
                else 
                {
                    printf("\033[1;34m%c ", 33 + rand() % 60);
                }            
            }
            printf("\n");
        }
        struct timespec ts = {0, 80000 * 1000};
        nanosleep(&ts, NULL);
    }
    printf("\n\033[1;32m [SYSTEM COMPROMISED: ACCESS GRANTED] \n");
    return 0;   
}