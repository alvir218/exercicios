//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//identificar se o numero � maior, menor ou igual



algoritmo "compara�ao entre dois valores"

var
   Na,Nb:real
inicio
  escreval("Comparando n�meros...")
  escreval("Digite o numero A para a comparacao:")
  leia(Na)
  escreval("Digite o numero B para a comparacao:")
  leia(Nb)
  se Na<Nb entao
    escreval(Na," � menor que ",Nb)
    senao
      se Na>Nb entao
         escreval(Na," � maior que ",Nb)
      senao
         se Na=Nb entao
            escreval(Na," � igual a ",Nb)
         fimse
      fimse
  fimse

fimalgoritmo
