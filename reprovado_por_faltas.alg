//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//calculo de frequencia que determina se foi reprovado por faltas
//frequencia minima determinada pelo usuario



algoritmo "FALTAS"
//descobre se voc� est� aprovado por presen�a.
var
at,f,p,r,fm:real
rl:logico
inicio
      escreval("Descubra se voc� est� reprovado(a) por faltas...")
      escreval
      escreval("Qual � o n�mero total de aulas lecionadas?")
      leia(at)
      escreval("Quantas vezes voc� faltou?")
      leia(f)
      escreval("Qual � a frequ�ncia m�nima de presen�a em porcentagem?")
      leia(fm)
      escreval
      escreval
      escreval
      escreval("Resultado:")
      escreval("Voc� esteve presente",at-f," vezes.")
      r<-f/at*100
      escreval("Sua frequ�ncia de faltas � de ",r,"%.")
      rl<-((100-r)>=fm))
      se rl = VERDADEIRO entao
         escreval("Voc� n�o foi reprovado(a) por faltas.")
      senao
         escreval("Voc� foi reprovado(a) por faltas.")
      fimse
fimalgoritmo
