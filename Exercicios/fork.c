#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void fazoqueopaifaz(){
    printf("Sou o pai!\n", getpid());
    pid_t p;
    int ret;
    p = wait(&ret);
    printf("Filho %d terminou com %d, também vou\n", p, ret);
    exit(0);
}

void fazoqueofilhofaz(){
    printf("Sou o filho!\n", getpid());
}

int main(){
    pid_t p;
    p = fork();
    if (p>0){
        fazoqueopaifaz();
    } else if(p==0) {
        fazoqueofilhofaz();
    } else {
        printf("Fork falhou\n");
    }
}