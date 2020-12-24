;programador: allan stuart virmond
;professor: winston sen lun fung
;instituicao de ensino: escola superior politecnica uninter
;disciplina: microprocessadores e microcontroladores
;ide: mplab 7
;microcontrolador: pic16f877a
;dev kit: HJ_5G

;exercicio: 
;acender 1 led
;Onde A, B,.., H estão conectados nos pinos do PORTD, sendo A com RD0, B com RD1, etc. Para acender um led deve-se:
;Configurar o PORTD como saída, configurando o registrador TRISD;
;Deixar em 1 o pino que se deseja acender o led;
;Testar isto com cada um dos pinos do PORTD



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
;VARIAVELEXEMPLO 		EQU 0x20
;VARIAVEL2				EQU 0x21


START		bsf STATUS,RP0    ;Vai para o Bank1 de memória
			movlw b'00000000' ;Gravando em W todos os pinos como saida
			movwf TRISD		  ; Configura TRISD com o valor de W

			bcf STATUS,RP0    ;Vai para o Bank0 de memória
			movlw b'00000001' ;Vamos acender o bit menos significativo
			movwf PORTD			
	
			goto START

			END
