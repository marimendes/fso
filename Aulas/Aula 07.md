### Aula 07 - Wait (  )

**Wait**

- ``` man wait ```
- Espera que um processo mude de estado
- O processo pai espera o processo filho morrer, para logo depois morrer também
- Se o processo pai tiver mais que um filho, é preciso rodar um wait pra cada filho.


**Sinais**

- ``` kill ```
- São notificaçãoes assíncronas entre processos
- Interrupções por software
- Cada signal corresponde a uma constante inteira
- alguns sinais são pré-definidos (função ou uo pré determinados) 
- sinais podem vir do mesmo processo ou ser "enviados" de um processo para outro
- é possível definidr procedimentos (funções) em programas que serão executados quando o processo for notificado por algum sinal

