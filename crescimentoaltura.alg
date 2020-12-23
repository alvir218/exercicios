algoritmo "crescimentoaltura"

// Data : 4/14/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Pedro tem 1,50m e cresce 2 cm por ano, enquanto Lucas tem 1,10m e cresce 3 cm por ano. Construa um algoritmo que calcule e imprima quantos anos serão necessários para que: a.Lucas e Pedro tenham o mesmo tamanho; b.Lucas seja maior que Pedro.



var
   pedro,lucas:real
   contador:inteiro
inicio
// Seção de Comandos 
   escreval("repeticao ate um valor ser igual a outro")
   escreval
   escreval
   pedro<-1.5
   lucas<-1.1
   contador<-0
   repita
   contador<-contador+1
   pedro<-pedro+0.02
   lucas<-lucas+0.03
   ate (pedro = lucas)
   escreval("levara ",contador," anos para lucas e pedro terem a mesma altura")


   pedro<-1.5
   lucas<-1.1
   contador<-0
   repita
   contador<-contador+1
   pedro<-pedro+0.02
   lucas<-lucas+0.03
   ate (lucas>pedro)
   escreval("levara ",contador," anos para lucas ficar maior que pedro")
fimalgoritmo
