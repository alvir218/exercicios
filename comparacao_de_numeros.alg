//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//identificar se o numero é maior, menor ou igual



algoritmo "comparaçao entre dois valores"

var
   Na,Nb:real
inicio
  escreval("Comparando números...")
  escreval("Digite o numero A para a comparacao:")
  leia(Na)
  escreval("Digite o numero B para a comparacao:")
  leia(Nb)
  se Na<Nb entao
    escreval(Na," é menor que ",Nb)
    senao
      se Na>Nb entao
         escreval(Na," é maior que ",Nb)
      senao
         se Na=Nb entao
            escreval(Na," é igual a ",Nb)
         fimse
      fimse
  fimse

fimalgoritmo
