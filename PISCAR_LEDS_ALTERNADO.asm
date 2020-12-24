;programador: allan stuart virmond
;professor: winston sen lun fung
;instituicao de ensino: escola superior politecnica uninter
;disciplina: microprocessadores e microcontroladores
;ide: mplab 7
;microcontrolador: pic16f877a
;dev kit: HJ_5G

;exercicio: 
;piscar os leds em sequencia
;Utilizar a rotina PERDE_TEMPO para colocar de intervalo entre as mudanças nos pinos.
;Sugestão:   Tente   acender   um   led   por   vez.   Mude   o   tempo   veja   o   efeito correspondente.



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
DELAY 		EQU 0x20		;aplica um apelido em EQU 0x40
VEZES		EQU 0x21


START		bsf STATUS,RP0    ;Vai para o Bank1 de memória
			movlw b'00000000' ;Gravando em W todos os pinos como saida
			movwf TRISD		  ; Configura TRISD com o valor de W

;-----------------------------------------------------------------------------

			bcf STATUS,RP0    ;Vai para o Bank0 de memória
			movlw b'00000000' ;Vamos acender o bit menos significativo 0xFF
			movwf PORTD			

			CALL PERDE_TEMPO

			MOVLW b'10000000'
			MOVWF PORTD

			CALL PERDE_TEMPO



			bcf STATUS,RP0    ;Vai para o Bank0 de memória
			movlw b'00000000' ;Vamos acender o bit menos significativo 0xFF
			movwf PORTD			

			CALL PERDE_TEMPO

			MOVLW b'01000000'
			MOVWF PORTD

			CALL PERDE_TEMPO



			bcf STATUS,RP0    ;Vai para o Bank0 de memória
			movlw b'00000000' ;Vamos acender o bit menos significativo 0xFF
			movwf PORTD			

			CALL PERDE_TEMPO

			MOVLW b'00100000'
			MOVWF PORTD

			CALL PERDE_TEMPO



			bcf STATUS,RP0    ;Vai para o Bank0 de memória
			movlw b'00000000' ;Vamos acender o bit menos significativo 0xFF
			movwf PORTD			

			CALL PERDE_TEMPO

			MOVLW b'00010000'
			MOVWF PORTD

			CALL PERDE_TEMPO



			bcf STATUS,RP0    ;Vai para o Bank0 de memória
			movlw b'00000000' ;Vamos acender o bit menos significativo 0xFF
			movwf PORTD			

			CALL PERDE_TEMPO

			MOVLW b'00001000'
			MOVWF PORTD

			CALL PERDE_TEMPO



			bcf STATUS,RP0    ;Vai para o Bank0 de memória
			movlw b'00000000' ;Vamos acender o bit menos significativo 0xFF
			movwf PORTD			

			CALL PERDE_TEMPO

			MOVLW b'00000100'
			MOVWF PORTD

			CALL PERDE_TEMPO



			bcf STATUS,RP0    ;Vai para o Bank0 de memória
			movlw b'00000000' ;Vamos acender o bit menos significativo 0xFF
			movwf PORTD			

			CALL PERDE_TEMPO

			MOVLW b'00000010'
			MOVWF PORTD

			CALL PERDE_TEMPO



			bcf STATUS,RP0    ;Vai para o Bank0 de memória
			movlw b'00000000' ;Vamos acender o bit menos significativo 0xFF
			movwf PORTD			

			CALL PERDE_TEMPO

			MOVLW b'00000001'
			MOVWF PORTD

			CALL PERDE_TEMPO



	
			goto START

PERDE_TEMPO	MOVLW d'255'
			MOVWF VEZES

LOOP_VEZES	MOVLW d'255'
			MOVWF DELAY
			CALL DELAY_US
			DECFSZ VEZES,1
			GOTO LOOP_VEZES
			RETURN

DELAY_US	NOP
			NOP
			DECFSZ DELAY,1
			GOTO DELAY_US
			RETURN

			END
