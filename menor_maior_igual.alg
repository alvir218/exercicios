//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//identifica se um numero e menor maior ou igual



algoritmo "menormaior"

var
   na,nb:real
inicio
   escreval("Comparação de números...")
   escreval("Digite o número A:")
   leia(na)
   escreval("Digite o número B:")
   leia(nb)
   se na<nb entao
      escreval(na," é menor que ",nb)
   senao
      se na>nb entao
         escreval(na," é maior que ",nb)
      senao
         se na=nb entao
            escreval (na," é igual a ",nb)
         fimse
      fimse
   fimse
fimalgoritmo
