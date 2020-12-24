//programador: allan stuart virmond
//professor: fernando maia
//instituicao de ensino: colegio estadual do parana
//disciplina: linguagem de programacao
//ide: visualg.2

//exercicio: 
//calculo do indice de massa corporal
//avalia caso de obesidade morbida



algoritmo "imc2"
//imc com alerta de obesidade morbida
//peso dividido pela altura em metros elevada ao quadrado
var
a,p,i:real
inicio
escreval("Cálculo de Índice de Massa Corporal...")
escreval
escreval
escreval("Qual é a sua altura medida em Metros?")
leia(a)
escreval("Qual é o seu peso medido em Kilogramas?")
leia(p)
i <- p/(a^2)
se i>40 entao
   escreval("Atenção! Obesidade Mórbida!")
fimse
fimalgoritmo
