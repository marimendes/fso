### Aula 05 - Estado dos processos

**Programa x Processo**
- Programa: é o arquivo binário, não faz nada.
- Processo: programa em execução, carrega na memória...

**Chamadas de sistema:**
- fork( )
- exit( )
- open( )
- read( )
- write( )

**Estados dos processos:**
- 1 - Executando
- 2 - Bloqueado
- 3 - Pronto

**Tabela de processos:**

Possui informações sobre os processos
- Registradores salvos
- Estado do processo
- Id do processo (PID)
- Id do proprietario
- Id do grupo
- Prioridade
- Utilização e mapeamento de memoria
- Status dos arquivos abertos

**CISC** 

Significa Conjunto de instruções complexas. Instrução que salva o dados de todos os registradores.

**RISC**

Significa um Conjunto de instruções reduzidas. Reserva alguns registradores para o SO.

**Troca de contexto**
- Custo direto: 
    - Copiar os valores dos registradores
    - Escalonador: Escolher o proximo processo
- Custos indiretos:
    - Invalidação os caches
    - Espera as instruções no PIPELINE terminar