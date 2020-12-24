;programador: allan stuart virmond
;professor: winston sen lun fung
;instituicao de ensino: escola superior politecnica uninter
;disciplina: microprocessadores e microcontroladores
;ide: mplab 7
;microcontrolador: pic16f877a
;dev kit: HJ_5G

;exercicio: 
;escrever um numero no display de 7 segmentos
;Para controlar qual display ficará aceso, deve-se usar os pinos: RA2, RA3, RA4 e RA5, RC5 e RC6.  



;*********************  Definição do processador *****************************

			#include p16F877A.inc 
			__config _HS_OSC & _WDT_OFF & _LVP_OFF & _PWRTE_ON 

;************************** Memória de programa ******************************
 			ORG	0 

RESET 		nop             
 			goto START 

;***************************** Interrupção **********************************
 			ORG 4 

;*************************** Inicio do programa ******************************



START		bsf STATUS,RP0		;Vai para o Bank1 de memória
			movlw b'00000000'	;Gravando em W todos os pinos como saida
			movwf TRISA
			movlw 0x00
			movwf TRISD			;Configura TRISD com o valor de W
		  
			bcf STATUS,RP0  	;Vai para o Bank0 de memória
			movlw b'00100000' 	;escolhe o display por posiçao do bit binaria contando do 0 da direita para esquerda
			movwf PORTA			;joga do work pro portA
			movlw b'01111101'	;representaçao do display em binario no work
			movwf PORTD			;escreve o padrao do work para o portD
			goto START

			END

;acende o numero 6 no display 1

; tem que abrir o jumper dos leds

;	  a
;	  -
;	f| |b
;	  -   g
;	e| |c
;	  - o h
;	  d

;	  0
;	  -
;	5| |1
;	  -   6
;	4| |2
;	  - o 7
;	  3

;mapeamento dos segmentos
;0 = 00000001
;1 = 00000010
;2 = 00000100
;3 = 00001000
;4 = 00010000
;5 = 00100000
;6 = 01000000
;7 = 10000000
