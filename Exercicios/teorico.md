## Exercicio T1 

Suponha que um processo está inconformado com ter de morrer após a recepção de um sinal do tipo SIGTERM. Resolveu, então, criar um filho para garantir a sobrevivência da família nestes casos. Com base no seu conhecimento sobre a função fork() e tratamento de sinais, explique por que no código abaixo o filho morrerá logo após o pai.

Indique uma alteração para garantir que o filho ficará bravamente esperando um sinal e terá outro filho que fará o mesmo se receber um SIGTERM e assim sucessivamente.

``` 
01: void trata_SIGTERM(int signum) {
02:   if (fork()) {
03:     printf("Meu filho continuara a tradicao da familia!\n");
04:     signal(SIGTERM, SIG_DFL); /* Reinstala tratador padrao e */
05:     raise(SIGTERM);           /* levanta SIGTERM para encerrar execucao*/
06:   }
07: }
08:
09: int main() {
10:   signal(SIGTERM, trata_SIGTERM); /* Instala o tratador de sinal */
11:   pause(); /* Interrompe a execucao e aguarda um sinal */
12:   return 0;
13: }
```

### Resposta: 

A alteração feita foi a adição do trecho de codigo:  "kill(pid,SIGTERM);" para mandar um sinal para o processador

``` 

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
```

## Exercicio T2

Suponha que um processo invoca a função fork(). Imediatamente depois, este processo pai instala um tratador de sinais e vai dormir com o comando pause() (que interrompe a execução de um processo até que este receba um sinal). Quando começa a executar, o filho envia um sinal SIGALRM para acordar o pai. Quando recebe o sinal, o pai exibe uma mensagem e termina sua execução.

```
void trata_SIGALRM(int signum) {
  printf("Ai que sono! Queria dormir mais...\n");
}
int main() {
  if ((pid = fork()) != 0) {
    signal(SIGALRM, trata_SIGALRM); /* Instalacao do tratador de sinal */
    pause();  /* Pai espera ser acordado pelo filho */
  }
  else
  kill (getppid(), SIGALRM); /* Filho envia sinal para acordar o pai */
  return 0;
}
```

Descreva dois cenários em que este código apresentaria uma comportamento diferente do descrito acima.

Resposta: 

    1- Se a linha "if ((pid = fork()) != 0) {" fosse alterada pra "if ((pid = fork()) == 0) {". Pois ai não seria o pai e sim o filho.
    2- Se o tempo for zero, nenhum alarme será programado e qualquer alarme programado será cancelado. Se o valor de retorno for zero, nenhum alarme está programado no momento (alarm(0)). Dessa forma o filho para de enviar sinal para acordar o pai.



