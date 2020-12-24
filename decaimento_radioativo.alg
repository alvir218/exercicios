//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//calculo de decaimento radioativo



algoritmo "halflife"

var
dr,ni,tr,mv,ne,drp1,drp2:real

inicio
  escreva("Cálculo de decaimento radioativo...")
  escreval
  escreval
  escreval("Qual é o número de núcleos iniciais?")
  leia(ni)
  escreval("Qual é o tempo da reação (escrito em horas e em número decimal)?")
  leia(tr)
  escreval("Qual é o período de meia vida (escrito em horas e em número decimal)?")
  leia(mv)
  ne <- 2.718
  escreval("O número de núcleos restantes é de: ")
  dr <- ni*(ne^(mv/(-(tr))))
  escreval(dr)
  drp1 <- (dr/ni)*100
  drp2 <- 100-drp1
  escreval("O decaimento radioativo é de",drp1,"%.")
  escreval("A reação está em ",drp2,"% de atividade restante.")
fimalgoritmo
