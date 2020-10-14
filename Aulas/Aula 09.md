### Aula 09 - Escalonamento

- Decide a ordem da execução das tarefas prontas
- Precisa ser justo
- Precisa garantir que todos os processos que estão na fila sejam executados
- Primeiro a chegar é o primeiro a ser servido - fila de processos

#### Fila Circular:
- quantum (0,1s 0,01s)
    - time slice (fatia de tempo) que o processo pode ficar em CPU
- Cada processo tem o seu quantum (tempo igual pra cada processo)


#### Tipos de tarefas

- Tarefas em tempo real: exigem previsibilidade em seus tempos de resposta aos eventos externos, pois geralmente estão associadas ao controle de sistemas criticos.

- Tarefas interativas: são tarefas que recebem eventos externos (do usuário ou da rede) e devem respondê-los rapidamente.

- Tarefas em lote (batch): são tarefas sem requisitos temporais explicitos, que normalmente executam sem intervenção do usuário.

- Tarefas orientadas a processamento: são tarefas que usam intensivamente o processador na maior parte da sua existencia. 

- Tarefas orientadas a entrada/saida: são tarefas que dependem muitos dos dispositivos de entrada/saida do processador. 

