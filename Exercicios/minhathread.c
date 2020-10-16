#include <stdio.h>
#include <phtread.h>
#include <stdlib.h>

void *function(void *a){
    printf("Sou uma thread\n");
    while(1);
}

int main(){
    thread_t tid;
    phtread_create(&tid,NULL,&function,NULL);
    printf("thread criada\n");
    printf("thread principal dormindo\n");
    sleep(10);
    printf("thread principal consumindo um pouco de CPU\n");
    for (int i = 0; i < 1000000000; i++){
        getppid();
    }
    printf("thread principal dormindo\n");
    sleep(10);
    printf("tchau\n");
    return 0;
}