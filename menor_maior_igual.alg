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
   escreval("Compara��o de n�meros...")
   escreval("Digite o n�mero A:")
   leia(na)
   escreval("Digite o n�mero B:")
   leia(nb)
   se na<nb entao
      escreval(na," � menor que ",nb)
   senao
      se na>nb entao
         escreval(na," � maior que ",nb)
      senao
         se na=nb entao
            escreval (na," � igual a ",nb)
         fimse
      fimse
   fimse
fimalgoritmo
