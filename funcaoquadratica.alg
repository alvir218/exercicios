algoritmo "funcaoquadratica"

// Data : 4/14/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Escreva  um  algoritmo que  leia  3  valores inteiros  (a, b  e  c)para  calcular Bhaskara. No pseudocódigo, calcule primeiro o ?(??2-4????)e considere os seguintes cenários:Se ?< 0, imprima na tela que a resposta conterá números imaginários e encerre o programasem calcular a Bhaskara;Se ?= 0, calcule a única raizexistentee mostre a resposta na tela;Se ?> 0, calcule as duas raízes existentes e mostre-as na tela;

var
   a,b,c,delta,x1,x2:real

inicio
// Seção de Comandos 

   escreval("calculo das raizes de uma funcao quadratica")
   escreval
   escreval
   escreval("informe o valor da incognita de segundo grau (a)")
   leia(a)
   escreval("informe o valor da incognita de primeiro grau (b)")
   leia(b)
   escreval("informe o termo independente (c)")
   leia(c)
   delta<-((b^2)-(4*a*c))
   se delta<0 entao
      escreval("delta = ",delta," a equacao possui raizes imaginarias")
   senao
      se delta>0 entao
         escreval("delta = ",delta," a equacao possui duas raizes diferentes")
         escreval("resultado:")
         x1<-((-(b)-delta^(1/2))/(2*a)))
         x2<-((-(b)+delta^(1/2))/(2*a)))
         escreval("x-= ",x1)
         escreval("x+= ",x2)
      senao
         se (delta=0) entao
            escreval("delta = ",delta," a equacao possui duas raizes iguais")
            x1<-((-(b)-delta^(1/2))/(2*a)))
            x2<-((-(b)+delta^(1/2))/(2*a)))
            escreval("x-= ",x1)
            escreval("x+= ",x2)
         senao
            escreval("erro desconhecido")
         fimse
      fimse
   fimse
fimalgoritmo
