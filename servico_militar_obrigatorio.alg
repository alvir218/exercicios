//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//servico militar obrigatorio
//verifica pela idade se esta apto a prestar servico militar obrigatorio



algoritmo "smo"

var
g,i:inteiro
inicio
   escreva("Descubra se você está apto a prestar serviço militar obrigatório...")
   escreval
   escreval
   escreval("Preencha com o número relacionado ao seu gênero:")
   escreval("1 - Masculino.")
   escreval("2 - Feminino.")
   leia(g)
   se g=2 entao
   escreval("Você está dispensada do serviço militar obrigatório.")
   fimse
   se g=1 entao
      escreval("Qual é a sua idade?")
      leia(i)
         se i>=17 entao
           escreval("Você está apto para prestar serviço militar obrigatório.")
         senao
             se i<=16 entao
            escreval("Você está dispensado do serviço militar obrigatório.")
             fimse
         fimse
   fimse
fimalgoritmo

