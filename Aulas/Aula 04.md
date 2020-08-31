## Aula 04 - Processos

Um processo é basicamente um programa em execução. Associado a cada processo está o seu espaço de endereçamento e uma lista de posições de memória que este processo pode ler e escrever. 

### Monoprogramação
    Apenas um processo em execução

### Multiprogramação
    Mais de um processo em execução

Comando que mostra todos os processos que estão rodando na máquina: ``` ps aux ```

### Escalonador de processos

    Escalonamento de processos é o ato de realizar o chaveamento dos processos ativos, de acordo com regras bem estabelecidas, de forma que todos os processos tenham chance de utilizar a UCP.

    O escalonador é a parte do SO encarregada de decidir entre os processos prontos, qual será colocado em execução.

    As transições são causadas pelo escalonador de processos sem que o processo saiba disso. 

