//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//verifica se as medidas informadas geram um triangulo



algoritmo "triangulo"
  //classificar triangulo
var
  lm,l2,l3,am,a2,a3:real
inicio
  escreval("Classificar tri�ngulo...")
  escreval
  escreval
  escreval("Qual � a medida do lado maior do tri�ngulo?")
  leia(lm)
  escreval("Qual � a medida do outro lado do tri�ngulo?")
  leia(l2)
  escreval("Qual � a medida do �ltimo lado do tri�ngulo?")
  leia(l3)
  se (lm>=(l2+l3)) entao
    escreval("Isso n�o � um tri�ngulo")
  senao
    se(lm<(l2+l3))
      escreval("Isso � um tri�ngulo")
  fimse
fimalgoritmo
