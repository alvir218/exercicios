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
  escreval("Classificar triângulo...")
  escreval
  escreval
  escreval("Qual é a medida do lado maior do triângulo?")
  leia(lm)
  escreval("Qual é a medida do outro lado do triângulo?")
  leia(l2)
  escreval("Qual é a medida do último lado do triângulo?")
  leia(l3)
  se (lm>=(l2+l3)) entao
    escreval("Isso não é um triângulo")
  senao
    se(lm<(l2+l3))
      escreval("Isso é um triângulo")
  fimse
fimalgoritmo
