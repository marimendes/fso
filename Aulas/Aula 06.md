### Aula 06 - Criando processos, chamadas de sistema FORK

**Criação de processos:**

Hierarquia de processos:
- Processo cria outro processo = processo pai cria um processo filho (clone).
- Processos filhos podem criar outros processos filhos.
- Podem executar concorrente (pais e filhos)
- Processo pai pode esperar o filho terminar 
    - Wait ( )

Endereçamento
- Filho é uma duplicada do pai
- Filho tem programa carregado do pai (substituição)

Criar o processo
- Fork ( )
    - Função que retorna 2 vezes (retorna uma vez no pai e uma vez no filho)
    - Se ele retornar 0 - está no filho
    - Se ele retornar um valor > 0 - está no pai e o número é o PID do filho
    - Se ele retornar um valor negativo - o fork( ) falhou
    - O fork pode falhar se for extrapolado o número de processos
    

**OBS:** se o processo filho morre, mas o pai não pega o retorno disso, o processo vira um "zumbi" e não da pra matar esse processo.
Se o processo pai morre antes do processo filho, o processo anterior passa a ser o pai desse filho.
