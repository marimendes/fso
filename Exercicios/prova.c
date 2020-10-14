#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void tratasinal(int s){
    if (s==SIGINT){
        printf("Recebi 2\n");
    } else if (s==SIGUSR1) {
        printf("Recebi 10\n");
    } else if (s==SIGUSR2) {
        printf("Recebi 12\n");
    } else if (s==SIGTERM) {
        printf("Recebi 15\n");
    }
}

int main(void){
    signal(SIGUSR1, tratasinal);
    signal(SIGUSR2, tratasinal);
    signal(SIGTERM, tratasinal);
    signal(SIGINT, tratasinal);

    while(1)
        pause();

}