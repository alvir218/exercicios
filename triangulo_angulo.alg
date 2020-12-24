//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//classificacao de triangulo com base no angulo



algoritmo "trinanguloangulo"
//classificacao de triangulos quanto ao angulo
var
a1,a2,a3:real
inicio
  escreval("Informe os ângulos do triângulo")
  leia(a1,a2,a3)
  se ((a1+a2+a3)<>180) entao
    escreval ("Não forma triângulo.")
  senao
    se((a1<90)e(a2<90)e(a3<90)) entao
      escreval ("Triângulo Acutângulo.")
    senao
      se ((a1=90)ou(a2=90)ou(a3=90)) entao
        escreval("Triângulo Retângulo.")
      senao
        se ((a1>90)ou(a2>90)ou(a3>90)) entao
          escreval("Triângulo Obtusângulo.")
        fimse
      fimse
    fimse
  fimse
fimalgoritmo
