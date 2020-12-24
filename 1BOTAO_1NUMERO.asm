;programador: allan stuart virmond
;professor: winston sen lun fung
;instituicao de ensino: escola superior politecnica uninter
;disciplina: microprocessadores e microcontroladores
;ide: mplab 7
;microcontrolador: pic16f877a
;dev kit: HJ_5G

;exercicio: 
;aperta o botao k1 e acende o numero 3



;APERTA O BOTAO K1
;ACENDE O NUMERO 3
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
	MOVWF B'00000000'
	MOVWF TRISA		;CONFIGURA PORTA PARA SAIDA

;	BSF STATUS,RP0    ;Vai para o Bank1 de memória ;;JA ESTA NO BANCO 1
		;JA ESTA NO BANK1
	MOVLW B'00000000' ;configura todos d para saida
;		JA ESTAVA COM 0X00 MAS PRECISA RECARREGAR
	MOVWF TRISD

	BCF STATUS,RP0
		;configura bit rp0 do registrador
		;status rp0 para 0, acessa o bank0 de memoria;
		;c de clear
;	CBLOCK 0X20	;CRIANDO PONTEIROS A PARTIR DO ENDERECO 0X20
;	CONTADOR0	;PONTEIRO CONTADOR0 PARA 0X20
;	ENDC

	BTFSC PORTB,0		;verifica o bit posicional 0 e pula se for 0
	GOTO APAGARLED0
;	GOTO ACENDERLED0
	GOTO DISPLAY03



DISPLAY03
	MOVLW b'00100000' 	;escolhe o display por posiçao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01001111'	;representaçao do display em binario no work; 3
	MOVWF PORTD			;escreve o padrao do work para o portD
;	GOTO VERIFICARBOTAO1
	GOTO START

APAGARLED0
;	BCF STATUS,RP0 ;nao precisa mudar de banco ja esta nele
	MOVLW B'00000000'
	MOVWF PORTD
	GOTO START


END



ACENDERLED0
;	BCF STATUS,RP0 ;nao precisa mudar de banco ja esta nele
;	MOVLW 0X03 ;CORRIGINDO
	MOVLW B'00000001'	;NAO PRECISA RECARREGAR W
	MOVWF PORTD
	ADDWF CONTADOR0
	MOVLW 0X03
	SUBWF CONTADOR0
	BTFSS STATUS,Z
	GOTO VERIFICARBOTAO1	
	GOTO DISPLAY03

	;GOTO VERIFICARBOTAO1

APAGARLED0
;	BCF STATUS,RP0 ;nao precisa mudar de banco ja esta nele
	MOVLW B'00000000'
	MOVWF PORTD
	GOTO VERIFICARBOTAO1

ACENDERLED1
	MOVLW B'00000100'
	MOVWF PORTD
	GOTO VERIFICARBOTAO2

APAGARLED1
	MOVLW B'00000000'
	MOVWF PORTD
	GOTO VERIFICARBOTAO2

ACENDERLED2
	MOVLW B'00010000'
	MOVWF PORTD
	GOTO VERIFICARBOTAO3

APAGARLED2
	MOVLW B'00000000'
	MOVWF PORTD
	GOTO VERIFICARBOTAO3

ACENDERLED3
	MOVLW B'01000000'
	MOVWF PORTD
	GOTO START

APAGARLED3
	MOVLW B'00000000'
	MOVWF PORTD
	GOTO START

VERIFICARBOTAO1
	BTFSC PORTB,1
	GOTO APAGARLED1
	GOTO ACENDERLED1

VERIFICARBOTAO2
	BTFSC PORTB,2
	GOTO APAGARLED2
	GOTO ACENDERLED2

VERIFICARBOTAO3
	BTFSC PORTB,3
	GOTO APAGARLED3
	GOTO ACENDERLED3

