//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//calculo de media ponderada e geometrica



algoritmo "Avaliação"
// ler as notas das provas.
// descobre as médias ponderada e geométrica de cada nota.
var
   pr1,pr2,pr3,pr4, p1,p2,p3,p4, medp,medg:real
inicio
      escreval("digite a nota da prova 1: ")
      leia(pr1)
      escreval("digite peso 1: ")
      leia(p1)
      escreval("digite a nota da prova 2: ")
      leia(pr2)
      escreval("digite peso 2: ")
      leia(p2)
      escreval("digite nota da prova 3: ")
      leia(pr3)
      escreval("digite peso 3: ")
      leia(p3)
      escreval("digite nota da prova 4: ")
      leia(pr4)
      escreval("digite peso 4: ")
      leia(p4)
//medias ponderada e geometrica
      medp <- (pr1*p1+pr2*p2+pr3*p3+pr4*p4)/p1+p2+p3+p4)
//tentativa de media geometrica 1
//      medg <- EXP (pr1*pr2*pr3*pr4,1/4)
      medg <- ((pr1*pr2*pr3*pr4)^(1/4)))
      escreval("A media pondera é de:",medp)
      escreval("A media geometrica é de:",medg)
      
fimalgoritmo
