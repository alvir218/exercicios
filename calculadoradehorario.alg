algoritmo "calculodehorarios"

// Data : 4/13/2019

//programador: allan stuart virmond
//professor: vinicius pozzobon borin
//instituicao de ensino: escola superior politecnica uninter
//disciplina: logica de programacao e algoritmos
//ide: visualg.2
//exercicio: Em pseudocódigo, escreva um código que recebadois horários, no formato HH:MM:SS, e que calcule a diferençaentre os dois horários.



var
   ss1,mm1,hh1,ss2,mm2,hh2,st1,st2,hhi,mmi,ssi,it:inteiro
inicio
// Seção de Comandos 
   escreval("calculadora de horario em hh:mm:ss")
   escreval
   escreval
   escreval("informe as horas do horario 1 em formato hh:")
   leia(hh1)
   escreval("informe os minutos do horario 1 em formato mm:")
   leia(mm1)
   escreval("informe os segundos do horario 1 em formato ss:")
   leia(ss1)
   escreval
   escreval
   escreval("informe as horas do horario 2 em formato hh:")
   leia(hh2)
   escreval("informe os minutos do horario 2 em formato mm:")
   leia(mm2)
   escreval("informe os segundos do horario 2 em formato ss:")
   leia(ss2)
   st1<-(ss1+(mm1*60)+(hh1*3600))
   st2<-(ss2+(mm2*60)+(hh2*3600))
   escreval("segundos totais do horario 1: ",st1)
   escreval("segundos totais do horario 2: ",st2)
   it<-st1-st2
   escreval("o intervalo e de: ",it," segundos")
   hhi<-it\3600
   mmi<-((it mod 3600)\60)
   ssi<-((it mod 3600)mod 60)
   escreval("o intervalo de tempo e de: ",hhi," : ",mmi," : ",ssi)
fimalgoritmo
