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