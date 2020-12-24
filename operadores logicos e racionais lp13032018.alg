//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2
//data: 13.03.2018

//exercicio: 
//operadores logicos e relacionais



algoritmo "operadores"


var
//declarar variaveis
   i1,i2:inteiro
   r1,r2:real
   c1,c2:caracter
   l1,l2:logico

inicio
//atribuir valor as variaveis
        i1<-5
        i2<-3
        r1<-3.2
        r2<-7.4
        c1<-"fulano"
        c2<-"detal"
        l1<-verdadeiro
        l2<-falso

//inicio dos comandos
  //calculos com operaçoes usando variaveis declaradas com atribuiçao manual
      escreval(i1+i2)
      escreval(i1-i2)
      escreval(i1*i2)
      escreval(i1/i2)
      escreval(i1\i2)
      escreval(i1%i2)
      escreval(i1^i2)
      
      escreval(c1," ",c2)
	//escreve o que foi atribuido as variaveis 
      escreval(l1)
	//escreve o resultado logico da variavel 
      escreval(l2)
	//escreve o resultado logico da variavel 
      escreval(nao l1)
	//inverte o valor logico da variavel
      escreval(nao l2)
	//inverte o valor logico da variavel
      escreval(l1 e l2)
	//escreve verdadeiro ou falso se ambos os valores coincidirem, caso contrario retorna falso
      escreval(l1 ou l2)
	//escreve verdadeiro se ao menos 1 valor for verdadeiro, em caso de ambos falso retornara falso 
      escreval(i1=i2)
      escreval(i1<>i2)
      escreval(i1>i2)
      escreval(i1<i2)
      escreval(i1<=i2)
      escreval(i1>=i2)
 
fimalgoritmo
