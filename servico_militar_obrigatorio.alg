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
   escreva("Descubra se voc� est� apto a prestar servi�o militar obrigat�rio...")
   escreval
   escreval
   escreval("Preencha com o n�mero relacionado ao seu g�nero:")
   escreval("1 - Masculino.")
   escreval("2 - Feminino.")
   leia(g)
   se g=2 entao
   escreval("Voc� est� dispensada do servi�o militar obrigat�rio.")
   fimse
   se g=1 entao
      escreval("Qual � a sua idade?")
      leia(i)
         se i>=17 entao
           escreval("Voc� est� apto para prestar servi�o militar obrigat�rio.")
         senao
             se i<=16 entao
            escreval("Voc� est� dispensado do servi�o militar obrigat�rio.")
             fimse
         fimse
   fimse
fimalgoritmo

