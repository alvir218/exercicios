//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//primeira operacao de acumulacao
//estrutura de repeticao ate informar menos 1
//relatorio de toda operacao
//soma dos numeros digitados, media e numero de iteracoes



algoritmo "acumulacao"

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
    escreval("foram feitas",q," tentativas.")
    escreval("média",sm/q)
fimalgoritmo
