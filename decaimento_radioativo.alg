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
  escreva("C�lculo de decaimento radioativo...")
  escreval
  escreval
  escreval("Qual � o n�mero de n�cleos iniciais?")
  leia(ni)
  escreval("Qual � o tempo da rea��o (escrito em horas e em n�mero decimal)?")
  leia(tr)
  escreval("Qual � o per�odo de meia vida (escrito em horas e em n�mero decimal)?")
  leia(mv)
  ne <- 2.718
  escreval("O n�mero de n�cleos restantes � de: ")
  dr <- ni*(ne^(mv/(-(tr))))
  escreval(dr)
  drp1 <- (dr/ni)*100
  drp2 <- 100-drp1
  escreval("O decaimento radioativo � de",drp1,"%.")
  escreval("A rea��o est� em ",drp2,"% de atividade restante.")
fimalgoritmo
