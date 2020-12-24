//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//exibe tabuada de um numero determinado em um intervalo escolhido pelo usuario



algoritmo "tabuadae3"

var
c,t,i,f:inteiro
inicio
  escreval("Tabuada de qual número?")
  leia (t)
  escreval("Tabuada do",t," de ... (inicio)")
  leia(i)
  escreval("Tabuada do",t," ate ... (fim)" )
  leia(f)
    para c de i ate f faca
      escreval(t," x ",c," = ",t*c)
    fimpara
fimalgoritmo
