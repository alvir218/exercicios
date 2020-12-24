;programador: allan stuart virmond
;professor: winston sen lun fung
;instituicao de ensino: escola superior politecnica uninter
;disciplina: microprocessadores e microcontroladores
;ide: mplab 7
;microcontrolador: pic16f877a
;dev kit: HJ_5G

;exercicio: 
;teste do motor de passo em wave drive
;giro anti horario



;TESTE1 WAVE DRIVE
;SOMENTE UMA BOBINA POR VEZ
;TORQUE FRACO
;GIRANDO ANTI HORARIO
;*********************  Defini??o do processador *****************************

			#include p16F877A.inc 
			__config _HS_OSC & _WDT_OFF & _LVP_OFF & _PWRTE_ON 

;************************** Mem?ria de programa ******************************
INTERVALO EQU 7EH
VEZES EQU 7FH

;CBLOCK 0X20	
		;CRIANDO PONTEIROS A PARTIR DO ENDERECO 0X20
		;ANTES DO ORG SOMENTE A DECLARACAO, 
		;INICIAR APENAS DEPOIS DE ACESSAR O BANCO CORRETO
;	CONTADOR0	;PONTEIRO CONTADOR0 PARA 0X20
;	CONDICAOC	;PONTEIRO CONDICAOC PARA 0X21
;	CONDICAOM	;PONTEIRO CONDICAOM PARA 0X22
;	ENDC

 			ORG	0 

RESET
	NOP             
	GOTO SETUP

;***************************** Interrup??o **********************************
 			ORG 4 

;*************************** Inicio do programa ******************************



SETUP	
	BSF STATUS,RP0
		;CONFIGURA O BIT RP0 DO REGISTRADOR
		;STATUS RP0 PARA 1
		;ACESSA O BANK 1 DE MEMORIA
		;S DE SET   
	MOVLW B'00000000'
		;SALVA ESSE BINARIO NO W
	MOVWF TRISB
		;MANDA O WORK PRO TRISB 
		;CONFIGURANDO COMO ENTRADA 1 NO TRISB
		;OS BOTOES K4-K1

	BCF STATUS,RP0
		;configura bit rp0 do registrador
		;status rp0 para 0, acessa o bank0 de memoria
		;c de clear

	CLRF PORTB

	CLRW



LOOP
	MOVLW B'00001000'
	MOVWF PORTB
	CALL AGUARDAR

	MOVLW B'00000100'
	MOVWF PORTB
	CALL AGUARDAR

	MOVLW B'00000010'
	MOVWF PORTB
	CALL AGUARDAR

	MOVLW B'00000001'
	MOVWF PORTB
	CALL AGUARDAR

GOTO LOOP



AGUARDAR
	MOVLW B'11111111'
		;CONTROLA O TEMPO
	MOVWF VEZES

	LACO_VEZES
		MOVLW B'11111111'
		MOVWF INTERVALO
		CALL INTERVALO_US
		DECFSZ VEZES,1
		GOTO LACO_VEZES
	RETURN

	INTERVALO_US
		NOP
		NOP
		DECFSZ INTERVALO,1
		GOTO INTERVALO_US
	RETURN



END
