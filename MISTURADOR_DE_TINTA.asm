;programador: allan stuart virmond
;professor: winston sen lun fung
;instituicao de ensino: escola superior politecnica uninter
;disciplina: microprocessadores e microcontroladores
;ide: mplab 7
;microcontrolador: pic16f877a
;dev kit: HJ_5G

;exercicio: 
;Um misturador de tintas está representado pela figura a seguir. Neste sistema temos o motor que gira a hélice que mistura a tinta, representado pela letra M, o sensor de nível A, que indica que o nível do tanque já atingiu o valor mínimo para que o motor comece a funcionar. Temos também as válvulas que permitem a passagem das tintas, representadas pelas letras BeC.
;Tanto  o  motor,  quanto  o  sensor  e  as  válvulas  são  considerados  ligados  ou  ativados  quando estiverem com nível lógico 1 e desligados ou desativados quando estiverem com nível lógico 0.
;Projete ocontrole do motor M para que somente quando o nível do tanque atingir o sensor A e a válvula B estiver acionada o motor possa serligado. A válvula Csomente pode ser aberta se o motor estiver desligado, válvulas B fechadas e o nível superior ao sensor A.
;Diretrizes:
;O sensor de nível será representado pelo botão K1.
;A válvula B será simulada pelo botão K2, C pelo botão K3 e Motorpelo botão K4.
;Os botões funcionaram da seguinte maneira, quando pressionado passa para estado de ligado, quando pressionado novamente passa para estado de desligado.
;O acionamento de cada válvula, sensor e motor deve ser sinalizado visualmente.
;Atividade:
;Projete um programa  em linguagem Assembly, utilizando a placa de prototipação HJ-5G  para solucionar o problema proposto.



;ENTREGAR
;*********************  Defini??o do processador *****************************

			#include p16F877A.inc 
			__config _HS_OSC & _WDT_OFF & _LVP_OFF & _PWRTE_ON 

;************************** Mem?ria de programa ******************************
INTERVALO EQU 7EH
VEZES EQU 7FH

CBLOCK 0X20	
		;CRIANDO PONTEIROS A PARTIR DO ENDERECO 0X20
		;ANTES DO ORG SOMENTE A DECLARACAO, 
		;INICIAR APENAS DEPOIS DE ACESSAR O BANCO CORRETO
	CONTADOR0	;PONTEIRO CONTADOR0 PARA 0X20
	CONDICAOC	;PONTEIRO CONDICAOC PARA 0X21
	CONDICAOM	;PONTEIRO CONDICAOM PARA 0X22
	ENDC

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
	MOVLW B'00001111'
		;SALVA ESSE BINARIO NO W
	MOVWF TRISB
		;MANDA O WORK PRO TRISB 
		;CONFIGURANDO COMO ENTRADA 1 NO TRISB
		;OS BOTOES K4-K1

	MOVLW B'00000000' 
		;PREENCHE O W COM 0 EM TODOS OS BITS
	MOVWF TRISD
		;ENVIA O WORK PARA O TRISD
		;CONFIGURANDO O TRISD TODO PARA SAIDA 0
		;OS LEDS	

	BCF STATUS,RP0
		;configura bit rp0 do registrador
		;status rp0 para 0, acessa o bank0 de memoria
		;c de clear

	CLRF PORTD

	CLRF CONTADOR0
		;ZERA O CONTADOR0

	MOVLW B'11110100'
	MOVWF CONDICAOC

	MOVLW B'11111000'
	MOVWF CONDICAOM
	
	CLRW



LOOP
	BTFSS PORTB,0
		;verifica o bit posicional 0 DO PORTB
		;e pula se for 1
		;LINHA 3 POR PADRAO
		;SE O BOTAO K1 ESTIVER APERTADO
	GOTO TOGGLEK1

	RETORNARTOGGLEK1

	BTFSC CONTADOR0,0
		;verifica o bit posicional 0 DO CONTADOR0
		;e pula se for 0
	GOTO NIVELALTO
	GOTO NIVELBAIXO
	
	 RETORNARNIVEL



	BTFSS PORTB,1
		;verifica o bit posicional 1 DO PORTB
		;e pula se for 1
		;LINHA 3 POR PADRAO
		;SE O BOTAO K2 ESTIVER APERTADO
	GOTO TOGGLEK2

	RETORNARTOGGLEK2

	BTFSC CONTADOR0,1
		;verifica o bit posicional 1 DO CONTADOR0
		;e pula se for 0
	GOTO ENCHERDETINTA
	GOTO SESSARENCHIMENTO

	RETORNARENCHIMENTO



	BTFSS PORTB,2
		;verifica o bit posicional 2 DO PORTB
		;e pula se for 1
		;LINHA 3 POR PADRAO
		;SE O BOTAO K3 ESTIVER APERTADO
	GOTO TOGGLEK3

	RETORNARTOGGLEK3

	BTFSC CONTADOR0,2
		;verifica o bit posicional 2 DO CONTADOR0
		;e pula se for 0
	GOTO ESCOARTINTA
	GOTO SESSARESCOAR
	
	RETORNARESCOAR



	BTFSS PORTB,3
		;verifica o bit posicional 3 DO PORTB
		;e pula se for 1
		;LINHA 3 POR PADRAO
		;SE O BOTAO K4 ESTIVER APERTADO
	GOTO TOGGLEK4

	RETORNARTOGGLEK4

	BTFSC CONTADOR0,3
		;verifica o bit posicional 3 DO CONTADOR0
		;e pula se for 0
	GOTO LIGARMOTOR
	GOTO DESLIGARMOTOR
	
	RETORNARDOMOTOR



GOTO LOOP



TOGGLEK1
;	CALL AGUARDAR
	BSF PORTD,7
		;LIGA O LED AZUL
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	BCF PORTD,7
		;APAGA O LED AZUL
	BTFSC CONTADOR0,0
		;CHECA O BIT POSICIONAL 0 DO CONTADOR0 0 PULA SE FOR 0
	GOTO  NIVELBAIXO
	
	BTFSS CONTADOR0,0
		;CHECA O BIT POSICIONAL 0 DO CONTADOR0 E PULA SE FOR 1
	GOTO NIVELALTO
GOTO RETORNARTOGGLEK1

NIVELBAIXO
	;DESATIVAR NIVEL DE TINTA
	BCF PORTD,0
		;ZERA O PORTD NO POSICIONAL 0
		;APAGA O LED 0
	BCF CONTADOR0,0
		;DESATIVAR SE ESTIVER ATIVADO
	BCF CONDICAOC,0
		;MARCAR CONDICAO 0 PARA LIGAR C COMO NAO ATENDIDA
	BCF CONDICAOM,0
		;MARCAR CONDICAO 0 PARA LIGAR M COMO NAO ATENDIDA
GOTO  RETORNARNIVEL

NIVELALTO
	;ACIONAR NIVEL DE TINHA
	BSF PORTD,0
		;LIGA O LED 0
	BSF CONTADOR0,0
	BSF CONDICAOC,0
		;MARCAR CONDICAO 0 PARA LIGAR C COMO ATENDIDA
	BSF CONDICAOM,0
		;MARCAR CONDICAO 0 PARA LIGAR M COMO ATENDIDA
GOTO  RETORNARNIVEL



TOGGLEK2
;	CALL AGUARDAR
	BSF PORTD,7
		;LIGA O LED AZUL
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	BCF PORTD,7
		;DESLIGA O LED AZUL

	BTFSC CONTADOR0,1
		;TESTA O BIT POSICIONAL 1 DO CONTADOR0 E PULA SE FOR 0
	GOTO SESSARENCHIMENTO
	
	BTFSS CONTADOR0,1
		;TESTA O BIT POSICIONAL 1 DO CONTADOR0 E PULA SE FOR 1
	GOTO ENCHERDETINTA
GOTO RETORNARTOGGLEK2

SESSARENCHIMENTO
	;DESATIVAR VALVULA DE ENTRADA DE TINTA
	BCF PORTD,1
		;ZERA O PORTD POSICIONAL 1
	BCF CONTADOR0,1
		;DESATIVAR SE ESTIVER ATIVADO
	BSF CONDICAOC,1
		;MARCAR CONDICAO 1 PARA LIGAR C COMO ATENDIDA
	BCF CONDICAOM,1
		;MARCAR CONDICAO 1 PARA LIGAR M COMO NAO ATENDIDA
GOTO RETORNARENCHIMENTO

ENCHERDETINTA
	;ATIVAR VALVULA DE ENTRADA DE TINTA
	BSF PORTD,1
		;LIGA O LED 1
	BSF CONTADOR0,1
	BCF	CONDICAOC,1
		;MARCAR CONDICAO 1 PARA LIGAR C COMO ATENDIDA
	BSF CONDICAOM,1
		;MARCAR CONDICAO 1 PARA LIGAR M COMO NAO ATENDIDA
GOTO RETORNARENCHIMENTO




TOGGLEK3
;	CALL AGUARDAR
	BSF PORTD,7
		;LIGA O LED AZUL
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	BCF PORTD,7
		;DESLIGA O LED AZUL

	BTFSC CONTADOR0,2
		;TESTA O BIT POSICIONAL 2 DO CONTADOR0 E PULA SE FOR 0
	GOTO SESSARESCOAR
		;TEM QUE FAZER UMA OPERACAO PARA SABER SE PODE LIGAR VALVULA C	
	MOVF CONDICAOC,0
		;MOVE O CONDICAOC PARA O W
	ADDLW D'1'
		;ADICIONA O W EM MAIS 1
	BTFSC STATUS,C
		;SE NAO DER CARRY OUT PULA
	GOTO ESCOARTINTA

GOTO RETORNARTOGGLEK3

SESSARESCOAR
	;DESATIVAR VALVULA DE SAIDA DE TINTA
	BCF PORTD,3
		;ZERA O PORTD NO POSICIONAL 2
	BCF CONTADOR0,2
		;DESATIVAR SE ESTIVER ATIVADO
	BSF CONDICAOM,2
		;MARCAR CONDICAO 2 PARA LIGAR M COMO ATENDIDA
GOTO RETORNARESCOAR

ESCOARTINTA
	;ATIVAR VALVULA DE SAIDA DE TINTA
	BSF PORTD,3
		;LIGA O LED VERDE
	BSF CONTADOR0,2
	BCF CONDICAOM,2
		;MARCAR CONDICAO 2 PARA LIGAR M COMO NAO ATENDIDA
GOTO RETORNARESCOAR



TOGGLEK4
;	CALL AGUARDAR
	BSF PORTD,7
		;LIGA O LED AZUL
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	CALL AGUARDAR
	BCF PORTD,7
		;DESLIGA O LED AZUL
	BTFSC CONTADOR0,3
	GOTO DESLIGARMOTOR
		;TEM QUE FAZER UMA OPERACAO PARA SABER SE PODE LIGAR O MOTOR	
	MOVF CONDICAOM,0
		;MOVE O CONDICAOM PARA O W
	ADDLW D'1'
		;ADICIONA O W EM MAIS UM
	BTFSC STATUS,C
		;SE NAO DER CARRY OUT PULA
	GOTO LIGARMOTOR

GOTO RETORNARTOGGLEK4

DESLIGARMOTOR
	;DESATIVAR MOTOR
	BCF PORTD,5
		;ZERA O PORTD NO POSICIONAL 3
	BCF CONTADOR0,3
		;DESATIVAR SE ESTIVER ATIVADO
	BSF CONDICAOC,3
		;MARCAR CONDICAO 3 PARA LIGAR C COMO ATENDIDA
GOTO RETORNARDOMOTOR

LIGARMOTOR
	;ATIVAR MOTOR
	BSF PORTD,5
		;LIGA O LED AMARELO
	BSF CONTADOR0,3
		;LIGA O LED 3
	BCF CONDICAOC,3
		;MARCAR CONDICAO 3 PARA LIGAR C COMO NAO ATENDIDA
GOTO RETORNARDOMOTOR



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
