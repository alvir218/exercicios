algoritmo "notaexame"

// Data : 4/14/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Um aluno realizou tr�s provas de uma determinada disciplina.A m�dia na disciplina � a m�dia  simples  das  tr�s  notas.O  aluno  deve  tirar  mais  do  que  7,0  para  ser  aprovado, caso contr�rio, estar� em exame.Levando em considera��o o crit�rio apresentado, fa�a um programa que mostre se ele ficou em exame e, em caso, positivo, mostre a nota que o aluno precisa obter, no exame, para passar de ano.Considere que, a m�dia final com exame � dada pela m�dia simples da nota do exame com a nota antes do exame e que � necess�rio 5,0 para passar no exame.



var
   nota:vetor[0..6]de real
//nota[0]=notaprova1
//nota[1]=notaprova2
//nota[2]=notaprova3
//nota[3]=mediaprovas
//nota[4]=notaexame
//nota[5]=notanecessariaexame
//nota[6]=mediaexame
inicio
// Se��o de Comandos
   escreval("calculo de media e recuperacao por exame")
   escreval
   escreval
   escreval("qual foi a nota da primeira prova?")
   leia(nota[0])
   escreval("qual foi a nota da segunda prova?")
   leia(nota[1])
   escreval("qual foi a nota da terceira prova?")
   leia(nota[2])
   nota[3]<-((nota[0]+nota[1]+nota[2])/3)
   se nota[3]<70 entao
      escreval("sua media e de ",nota[3]," portanto estara em exame")
      nota[5]<-((70*2)-nota[3])
      escreval("a nota necessaria para aprovacao em exame deve ser de ",nota[5]," pontos")
      escreval("qual a nota do exame?")
      leia(nota[4])
      nota[6]<-((nota[3]+nota[4])/2)
      se nota[6]<70 entao
         escreval("reprovado por exame com media de ",nota[6]," pontos")
      senao
         escreval("aprovado por exame com media de ",nota[6]," pontos")
      fimse
   senao
      escreval("aprovado diretamente com media de ",nota[3]," pontos")
   fimse
fimalgoritmo
