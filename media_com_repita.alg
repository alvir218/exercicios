//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//relatorio de numeros digitados ate digitar -1



Algoritmo "média_repita"

Var

n,s,q:inteiro

Inicio
    repita
       escreva("Valor:")
       leia(n)
       s<-s+n
       q<-q+1
    ate(n=-1)
    s<-s+1
    q<-q-1
    escreval("soma:",s)
    escreval("quantidade:",q)
    escreval("média:",s/q)
Fimalgoritmo
