algoritmo "FALTAS"
//descobre se você está aprovado por presença.
var
at,f,p,r,fm:real
rl:logico
inicio
      escreval("Descubra se você está reprovado(a) por faltas...")
      escreval
      escreval("Qual é o número total de aulas lecionadas?")
      leia(at)
      escreval("Quantas vezes você faltou?")
      leia(f)
      escreval("Qual é a frequência mínima de presença em porcentagem?")
      leia(fm)
      escreval
      escreval
      escreval
      escreval("Resultado:")
      escreval("Você esteve presente",at-f," vezes.")
      r<-f/at*100
      escreval("Sua frequência é de ",r,"%.")
      rl<-((100-r)>=fm))
      se rl = VERDADEIRO entao
         escreval("Você não foi reprovado(a) por faltas.")
         senao
               escreval("Você foi reprovado(a) por faltas.")
      fimse
fimalgoritmo
