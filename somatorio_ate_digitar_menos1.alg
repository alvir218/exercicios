//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//relatorio de numeros informados ate digitar -1



algoritmo "informar menos um e a soma dos valores"

var

sm,n,q:inteiro

inicio
    sm <- 0
    enquanto n <> -1 faca
      escreval("valor:")
      leia(n)
      sm <- sm+n
      q <- q+1
    fimenquanto
    escreval("numero correto!")
    sm <- sm+1
    q <- q-1
    escreval("sua soma é",sm)
    escreval("valor de q",q)
    escreval("média",sm/q)
fimalgoritmo
