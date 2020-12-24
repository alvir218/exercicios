//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//laco de repeticao utilizado para mostrar a tabuada escolhida



Algoritmo "contagem_para"

Var

   i,n,nu,onu:inteiro
   

Inicio
   escreval("exercício 1:")
   escreval("visualize abaixo a  tabuada do 7")
     para n de 0 ate 10 passo 1 faca
      escreval ("7 x",n,"=",n*7)
   fimpara
   escreval("exercicio 2:")
   escreval("visualize uma determinada tabuada")
   leia(nu)
     para n de 0 ate 10 faca
      escreval (nu," x",n,"=",n*nu)
   fimpara
   escreval("exercicio 3:")
   escreval("visualize determinadas tabuadas determinadas por voce:")
   leia(n)
   leia(nu)
   para n de 0 ate 10 faca
   para onu de n ate nu faca
     escreval (nu," x",n,"=",n*nu)
   fimpara
Fimalgoritmo
