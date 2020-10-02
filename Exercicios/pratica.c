#include <stdio.h>
#include <stdlib.h>
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
    } else if (s==SIGINT) {
        if (s==SIGUSR2) {
            if (s==SIGTERM) {
                printf("Senha acionada\n");
            }
        }      
    } else if (s==SIGINT) {
        if (s==SIGUSR2) {
            if (s!=SIGTERM){
                printf("Tchau\n");
                exit(0);
            }
        }
    } else if (s==SIGINT) {
        if (s==SIGUSR2){
            if (s==SIGTERM){
                if (s==SIGUSR1) {
                    exit(0);
                }
            }
        }
    }
}

void fazcoisadefilho(){
    while(1){
        kill(getppid(), SIGUSR1);
        kill(getppid(), SIGUSR2);
        kill(getppid(), SIGTERM);
        sleep(1);
    }
}

int main(void){
    signal(SIGUSR1, tratasinal);
    signal(SIGUSR2, tratasinal);
    signal(SIGTERM, tratasinal);
    signal(SIGINT, tratasinal);

    pid_t p=fork();

    if(p==0){ //processo filho
        fazcoisadefilho();
    }

    while(1)
        pause();
}