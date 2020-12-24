;programador: allan stuart virmond
;professor: winston sen lun fung
;instituicao de ensino: escola superior politecnica uninter
;disciplina: microprocessadores e microcontroladores
;ide: mplab 7
;microcontrolador: pic16f877a
;dev kit: HJ_5G

;exercicio: 
;faz a leitura de um botao sendo pressionado



;*********************  Definição do processador *****************************

			#include p16F877A.inc 
			__config _HS_OSC & _WDT_OFF & _LVP_OFF & _PWRTE_ON 

;************************** Memória de programa ******************************
 			ORG	0 

reset 		NOP             
 			GOTO START

;***************************** Interrupção **********************************
 			ORG 4 

;*************************** Inicio do programa ******************************
; atividade pratica 1c tarefa 1
; apertar um botao e acender um led

;VARIAVELEXEMPLO 		EQU 0x20
;VARIAVEL2				EQU 0x21


START	
	BSF STATUS,RP0    ;Vai para o Bank1 de memória
	MOVLW B'11111111' ;Gravando em W todos os pinos como entrada
	MOVWF TRISB		  ; Configura TRISB com o valor de W

;	BSF STATUS,RP0    ;Vai para o Bank1 de memória ;;JA ESTA NO BANCO 1
	MOVLW B'00000000' ;configura todos d para saida
	MOVWF TRISD

	BCF STATUS,RP0
		;configura bit rp0 do registrador
		;status rp0 para 0, acessa o bank0 de memoria;
		;c de clear

	BTFSC PORTB,0		;verifica o bit posicional 0 e pula se for 0
	GOTO APAGARLED0
	GOTO ACENDERLED0

	GOTO START

ACENDERLED0
;	BCF STATUS,RP0 ;nao precisa mudar de banco ja esta nele
	MOVLW B'00000001'
	MOVWF PORTD
	GOTO START

APAGARLED0
;	BCF STATUS,RP0 ;nao precisa mudar de banco ja esta nele
	MOVLW B'00000000'
	MOVWF PORTD
	GOTO START



END
