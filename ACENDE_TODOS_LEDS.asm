;programador: allan stuart virmond
;professor: winston sen lun fung
;instituicao de ensino: escola superior politecnica uninter
;disciplina: microprocessadores e microcontroladores
;ide: mplab 7
;microcontrolador: pic16f877a
;dev kit: HJ_5G

;exercicio: 
;acender todos os leds
;Configurar como saída o PORTD, configurando o registrador TRISD.
;Deixar todos os pinos do PORTD em 1;



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
DELAY 		EQU 0x20
VEZES		EQU 0x21


START		bsf STATUS,RP0    ;Vai para o Bank1 de memória
			movlw b'00000000' ;Gravando em W todos os pinos como saida
			movwf TRISD		  ; Configura TRISD com o valor de W

			bcf STATUS,RP0    ;Vai para o Bank0 de memória
			movlw b'11111111' ;Vamos acender o bit menos significativo
			movwf PORTD			
	
			goto START

			END
