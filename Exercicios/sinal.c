#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void tratasinal(int s){
    if (s==SIGINT){
        printf("%d: control C comigo nao!\n", getpid());
    } else if (s==SIGALRM) {
        printf("ALARME\n");
        alarm(1);
    }
    else {
        printf("%d: Sinal recebido\n", getppid());
    }
}

void fazcoisadefilho(){
    while(1){
        printf("%d: chamando o pai %d\n", getpid(), getppid());
        kill(getppid(), SIGUSR1);
        sleep(1);
    }
}

int main(void){
    signal(SIGUSR1, tratasinal);
    signal(SIGUSR2, tratasinal);
    signal(SIGTERM, tratasinal);
    signal(SIGINT, tratasinal);
    signal(SIGALRM, tratasinal);

    pid_t p=fork();

    if(p==0){ //processo filho
        fazcoisadefilho();
    }

    while(1)
        pause();
    // só retorna quando o sinal for pego
    printf("Meu sleep acabou\n");
}