#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void fazoqueopaifaz(){
    printf("Sou o pai!\n", getpid());
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