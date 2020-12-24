;programador: allan stuart virmond
;professor: winston sen lun fung
;instituicao de ensino: escola superior politecnica uninter
;disciplina: microprocessadores e microcontroladores
;ide: mplab 7
;microcontrolador: pic16f877a
;dev kit: HJ_5G

;exercicio: 
;botao contador
;conta de 0 a f quantas vezes o botao k1 foi pressionado



;CONTA DE 0 A F 
;QUANTAS VEZES FOI PRESSIONADO K1
;FUNCIONANDO 100 NO SIMULADOR
;FUNCIONANDO 100 NA PLACA
;*********************  Definicão do processador *****************************

			#include p16F877A.inc 
			__config _HS_OSC & _WDT_OFF & _LVP_OFF & _PWRTE_ON 

;************************** Memória de programa ******************************
	CBLOCK 0X20	
		;CRIANDO PONTEIROS A PARTIR DO ENDERECO 0X20
		;ANTES DO ORG SOMENTE A DECLARACAO, 
		;INICIAR APENAS DEPOIS DE ACESSAR O BANCO CORRETO
	CONTADOR0	;PONTEIRO CONTADOR0 PARA 0X20
	CONTADOR0B	;PONTEIRO CONTADOR0B PARA 0X21
	ENDC

DELAY	EQU 0x7E
VEZES	EQU 0x7F

 			ORG	0 

RESET
	NOP
	GOTO SETUP

;***************************** Interrupcão **********************************
 			ORG 4 

;*************************** Inicio do programa ******************************

SETUP
	BSF STATUS,RP0    ;Vai para o Bank1 de memória SET1 RP0
	MOVLW B'11111111' ;Gravando em W todos os pinos como entrada
	MOVWF TRISB		  ; Configura TRISB com o valor de W
	;MOVWF B'00000000' ; ERRADO DEVE SER MOVLW
;	CLRF TRISA
	MOVLW B'00000000'
	MOVWF TRISA		;CONFIGURA PORTA PARA SAIDA

;	BSF STATUS,RP0    ;Vai para o Bank1 de memória ;;JA ESTA NO BANCO 1
		;JA ESTA NO BANK1
	MOVLW B'00000000' ;configura todos d para saida
		;W JA ESTA COM 0X00 MAS PRECISA RECARREGAR
	MOVWF TRISD

	BCF STATUS,RP0
		;configura bit rp0 do registrador
		;status rp0 para 0, acessa o bank0 de memoria;
		;c de clear

	CLRF CONTADOR0	;INICIALIZANDO CONTADOR0 COM 0



CHECARBOTAOK1
;	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
;	MOVWF PORTA			;joga do work pro portA
;	MOVLW B'00000001'	;representacao do display em binario no work; 3
;
	BTFSS PORTB,0 ;1 LINHA TESTE
		;verifica o bit posicional 0 DO PORTB
		;e pula se for 1
		;SEM APERTAR É 0
		;ISSO PRO PORTB0 BOTAOK1
		;2 LINHA EXECUTA QUANDO PRESSIONADO
		;3 LINHA EXECUTA POR PADRAO
	GOTO PRESSIONOUK1

		;COMPARAR A CONTAGEM
	MOVLW 0X00	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY00

	MOVLW 0X01	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY01

	MOVLW 0X02	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY02

	MOVLW 0X03	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY03

	MOVLW 0X04	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY04

	MOVLW 0X05	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY05

	MOVLW 0X06	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY06

	MOVLW 0X07	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY07

	MOVLW 0X08	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY08

	MOVLW 0X09	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY09

	MOVLW 0X0A	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY0A

	MOVLW 0X0B	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY0B

	MOVLW 0X0C	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY0C

	MOVLW 0X0D	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY0D

	MOVLW 0X0E	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY0E

	MOVLW 0X0F	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO DISPLAY0F

	MOVLW 0X10	;CARREGA W COM 3 PARA COMPARACAO
	SUBWF CONTADOR0,0	;W = W - CONTADOR0
	BTFSC STATUS,Z		;verifica o bit FLAG DE 0 Z e pula se for 1
	GOTO RESET

PRESSIONOUK1
		;ACENDERLED
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'10000000'	;representacao do display em binario no work; dp.
	MOVWF PORTD			;escreve o padrao do work para o portD
		;INCREMENTAR CONTADOR0
	INCF CONTADOR0,1
	CALL PERDE_TEMPO
	CALL PERDE_TEMPO
	CALL PERDE_TEMPO
	CALL PERDE_TEMPO
	CALL PERDE_TEMPO
	CALL PERDE_TEMPO
	CALL PERDE_TEMPO
	CALL PERDE_TEMPO
	CALL PERDE_TEMPO
	GOTO CHECARBOTAOK1

DISPLAY00
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'00111111'	;0 representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY01
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'00000110'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY02
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01011011'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY03
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01001111'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY04
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01100110'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY05
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01101101'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY06
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01111101'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY07
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'00000111'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY08
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01111111'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY09
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01100111'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY0A
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01110111'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY0B
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01111100'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY0C
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'00111001'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY0D
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01011110'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY0E
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01111001'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

DISPLAY0F
	MOVLW B'00100000' 	;escolhe o display por posicao do bit binaria contando do 0 da direita para esquerda
	MOVWF PORTA			;joga do work pro portA
	MOVLW B'01110001'	;representacao do display em binario no work
	MOVWF PORTD			;escreve o padrao do work para o portD
	GOTO CHECARBOTAOK1

PERDE_TEMPO
    ;DECLARAR VARIAVEIS
    ;DELAY 		EQU 0x20
    ;VEZES		EQU 0x21

    MOVLW d'255'	;CONTROLA O TEMPO
    MOVWF VEZES

  LOOP_VEZES
    MOVLW d'255'
    MOVWF DELAY
    CALL  DELAY_US
    DECFSZ VEZES,1
    GOTO LOOP_VEZES
    RETURN

  DELAY_US
    NOP
    NOP
    DECFSZ DELAY,1
    GOTO DELAY_US
    RETURN



END
