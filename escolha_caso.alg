//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//estrutura escolha caso



algoritmo "Prova"

var

  op:caracter

inicio

  escreval("Quem descobriu o Brasil?")
  escreval("a)Batel")
  escreval("b)Mossunguê")
  escreval("c)CIC")
  escreval("d)Cabral")
  escreval("c)NDA")
  escreva("R:")
  leia(op)
  //da para escolher o programa adiconando "ate".
  //ou se deixar mais longo adiciona um caso e um escreval pra cada.
    escolha op
      caso "a" ate "c","e"
        escreval("erouuu")
      caso "d"
        escreval("Acertouuuu")
      outrocaso
        escreval("Inválido")
    fimescolha
fimalgoritmo
