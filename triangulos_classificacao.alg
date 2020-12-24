//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//classificacao de triangulos quanto a medida dos lados



algoritmo "triangulos"

var

  L1,L2,L3:real

inicio

  escreva("insira as 3 medidas do triangulo:")
  leia(L1,L2,L3)
  se((L1<L2+L3) e (L2<L1+L3) e (L3<L1+L2))entao
  //forma triangulo
    escreval("Forma triangulo")
    se((L1=L2)ou(L2=L3))entao
      escreval("Triangulo isosceles")
      se((L1=L2)e(L2=L3))entao
        escreval("Triangulo equilatero")
      fimse
    senao
      escreval("Triangulo escaleno")
    fimse
  senao
  //nao forma triangulo
  escreval("nao forma trianqulo")
  fimse


fimalgoritmo


