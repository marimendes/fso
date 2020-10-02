#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

// void trata_SIGALRM(int signum) {
//   printf("Ai que sono! Queria dormir mais...\n");
// }
// int main() {
//     pid_t pid;
    
//     if ((pid = fork()) != 0) {
//         signal(SIGALRM, trata_SIGALRM); /* Instalacao do tratador de sinal */
//         pause();  /* Pai espera ser acordado pelo filho */
//     }
//     else
//     kill (getppid(), SIGALRM); /* Filho envia sinal para acordar o pai */
//     return 0;
// }

 void trata_SIGTERM(int signum) {
   if (fork()) {
     printf("Meu filho continuara a tradicao da familia!\n");
     signal(SIGTERM, SIG_DFL); /* Reinstala tratador padrao e */
     raise(SIGTERM);           /* levanta SIGTERM para encerrar execucao*/
    }
}

 int main() {
    pid_t pid;
    signal(SIGTERM, trata_SIGTERM); /* Instala o tratador de sinal */
    kill(pid,SIGTERM);
    pause(); /* Interrompe a execucao e aguarda um sinal */
    return 0;
}