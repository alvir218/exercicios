//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//determina aptidao para servico militar obrigatorio



algoritmo "smo3"

var
i:inteiro
s:caracter
inicio
  escreval("Informe idade e sexo:")
  leia(i,s)
//  se ((i>=18)e(s="m")) entao
  se((i>=18)e((s="m")ou(s="M"))) entao
    escreval("Apto ao SMO.")
  senao
    escreval("Inapto ao SMO.")
  fimse
fimalgoritmo
