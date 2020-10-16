#include <stdio.h>
#include <phtread.h>
#include <stdlib.h>

void *function(void *a){
    *((int *)a)=444;
    while(1);
}

int main(){
    thread_t tid;
    int a = 10;
    printf("a=%d\n",a);
    phtread_create(&tid,NULL,&function,(void *)&a);
    printf("thread criada\n");
    sleep(10);
    phtread_join(tid,NULL);
    printf("a=%d\n",a);
    return 0;
}