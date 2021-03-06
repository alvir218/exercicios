;programador: allan stuart virmond
;professor: winston sen lun fung
;instituicao de ensino: escola superior politecnica uninter
;disciplina: microprocessadores e microcontroladores
;ide: mplab 7
;microcontrolador: pic16f877a
;dev kit: HJ_5G

;exercicio: 
;programacao de um braco robotico com
;dois motores de passo
;um servo motor de giro 360
;comandos por teclado matricial



;VERSAO 4
;AUTENTICANDO
;2 MOTORES DE PASSO HORARIO ANTI HORARIO
;ON OFF
;MODO DE EDICAO DE SENHA
;LDR ;REMOVIDO POR NAO FUNCIONAR ADEQUADAMENTE
;MOTOR SERVO DE 360



				;DEFINICAO DO PROCESSADOR
			#include p16F877A.inc 
			__config _HS_OSC & _WDT_OFF & _LVP_OFF & _PWRTE_ON 

	;MEMORIA DE PROGRAMA
INTERVALO EQU 7EH
VEZES EQU 7FH

CBLOCK 0X20	
		;CRIANDO PONTEIROS A PARTIR DO ENDERECO 0X20
		;ANTES DO ORG SOMENTE A DECLARACAO, 
		;INICIAR APENAS DEPOIS DE ACESSAR O BANCO CORRETO
	ESTADO	;0X20 ESTADO GERAL DO DISPOSITIVO
	DIGITO1	;0X21 SALVA O DIGITO 1 DA SENHA
	DIGITO2	;0X22 SALVA O DIGITO 2 DA SENHA
	DIGITO3 ;0X23 SALVA O DIGITO 3 DA SENHA
	DIGITO4 ;0X24 SALVA O DIGITO 4 DA SENHA
	DIGITO5 ;0X25 SALVA O DIGITO 5 DA SENHA
	DIGITO6 ;0X26 SALVA O DIGITO 6 DA SENHA
	DIGITOATUAL ;0X27 DIGITANDO QUAL DIGITO DA SENHA..
	DIGITOPRESSIONADO ;0X28 NUMERO PRESSIONADO
	SENHA	;0X29 ACERTOU QUANTOS DIGITOS EM SEQUENCIA..
	ITERACAO	;0X30 USADO NO LACO DE REPETICAO
	DIGITO1AUX	;0X31 CADASTRANDO DIGITO1
	DIGITO2AUX	;0X32 CADASTRANDO DIGITO2
	DIGITO3AUX	;0X33 CADASTRANDO DIGITO3
	DIGITO4AUX	;0X34 CADASTRANDO DIGITO4
	DIGITO5AUX	;0X35 CADASTRANDO DIGITO5
	DIGITO6AUX	;0X36 CADASTRANDO DIGITO6
	TENTATIVAS	;0X37 NUMERO DE TENTATIVAS DE ABRIR O COFRE
	ENDC

 			ORG	0 

RESET
	NOP
	NOP
	NOP             
	GOTO SETUP

				;INTERRUPCAO
			ORG 4 

	;PROGRAMA
SETUP	
	BSF STATUS,RP0
		;CONFIGURA O BIT RP0 DO REGISTRADOR
		;STATUS RP0 PARA 1
		;ACESSA O BANK 1 DE MEMORIA
		;S DE SET
	MOVLW B'00000001'
		;MOVE ESSE BINARIO PARA O WORK
	MOVWF TRISA
		;MOVE DO WORK PRO TRISA
		;SELECAO DE DISPLAY
	MOVLW B'00001111'
		;SALVA ESSE BINARIO NO W
	MOVWF TRISB
		;MANDA O WORK PRO TRISB 
		;CONFIGURANDO COMO ENTRADA 1 SAIDA 0 NO TRISB
		;TECLADO MATRICIAL
	MOVLW B'00000000'
		;MANDA ESSE BINARIO PARA O WORK
	MOVWF TRISC
		;CONFIGURA TODO TRISC PARA SAIDA
		;MOTOR
	MOVLW B'00000000' 
		;PREENCHE O W COM 0 EM TODOS OS BITS
	MOVWF TRISD
		;ENVIA O WORK PARA O TRISD
		;CONFIGURANDO O TRISD TODO PARA SAIDA 0
		;SEGMENTOS	

	MOVLW B'00000000' 
		;PREENCHE O W COM 0 EM TODOS OS BITS
	MOVWF TRISE
		;ENVIA O WORK PARA O TRISE
		;CONFIGURANDO O TRISD TODO PARA SAIDA 0
		;SEGMENTOS	

;		;REMOVIDO JUNTO COM LDR		
;	MOVLW B'00001110'
;	MOVWF ADCON1

	BCF STATUS,RP0
		;configura bit rp0 do registrador
		;status rp0 para 0, acessa o bank0 de memoria
		;c de clear
		
;		;REMOVIDO JUNTO COM O LDR
;		;LIGA O SISTEMA DE CONVERSAO AD
;	MOVLW B'00000001'
;	MOVWF ADCON0
		
		;ZERA ESSES REGISTRADORES
	CLRW
	CLRF PORTA
	CLRF PORTB
	CLRF PORTC
	CLRF PORTD
	MOVLW B'00000001'
	MOVWF PORTE
	CLRF ESTADO
	CLRF DIGITO1
	CLRF DIGITO2
	CLRF DIGITO3
	CLRF DIGITO4
	CLRF DIGITO5
	CLRF DIGITO6
	CLRF DIGITOATUAL
	CLRF SENHA
	CLRF DIGITOPRESSIONADO
	CLRF VEZES
	CLRF INTERVALO
	CLRF ITERACAO
	CLRF DIGITO1AUX
	CLRF DIGITO2AUX
	CLRF DIGITO3AUX
	CLRF DIGITO4AUX
	CLRF DIGITO5AUX
	CLRF DIGITO6AUX
	CLRF TENTATIVAS



		;RECUPERA DA MEMORIA AUXILIAR O DIGITO1
	BSF     STATUS,RP1     ;
	BCF     STATUS,RP0     ; ACESSA O Bank 2
	MOVLW D'1'			   ; ENDERECO 1 DA EEPROM
	MOVWF   EEADR          ; Address to read
	BSF     STATUS,RP0     ; Bank 3
	BCF     EECON1,EEPGD   ; Point to Data; memory
	BSF     EECON1,RD      ; EE Read
	BCF     STATUS,RP0     ; Bank 2 
	MOVF    EEDATA,W       ; W = EEDATA
	BCF STATUS,RP1		   ; BANK 0
	MOVWF DIGITO1

		;RECUPERA DA MEMORIA AUXILIAR O DIGITO2
	BSF     STATUS,RP1     ;
	BCF     STATUS,RP0     ; ACESSA O Bank 2
	MOVLW D'2'			   ; ENDERECO 2 DA EEPROM
	MOVWF   EEADR          ; Address to read
	BSF     STATUS,RP0     ; Bank 3
	BCF     EECON1,EEPGD   ; Point to Data; memory
	BSF     EECON1,RD      ; EE Read
	BCF     STATUS,RP0     ; Bank 2 
	MOVF    EEDATA,W       ; W = EEDATA
	BCF STATUS,RP1		   ; BANK 0
	MOVWF DIGITO2

		;RECUPERA DA MEMORIA AUXILIAR O DIGITO3
	BSF     STATUS,RP1     ;
	BCF     STATUS,RP0     ; ACESSA O Bank 2
	MOVLW D'3'			   ; ENDERECO 3 DA EEPROM
	MOVWF   EEADR          ; Address to read
	BSF     STATUS,RP0     ; Bank 3
	BCF     EECON1,EEPGD   ; Point to Data; memory
	BSF     EECON1,RD      ; EE Read
	BCF     STATUS,RP0     ; Bank 2 
	MOVF    EEDATA,W       ; W = EEDATA
	BCF STATUS,RP1		   ; BANK 0
	MOVWF DIGITO3

		;RECUPERA DA MEMORIA AUXILIAR O DIGITO4
	BSF     STATUS,RP1     ;
	BCF     STATUS,RP0     ; ACESSA O Bank 2
	MOVLW D'4'			   ; ENDERECO 4 DA EEPROM
	MOVWF   EEADR          ; Address to read
	BSF     STATUS,RP0     ; Bank 3
	BCF     EECON1,EEPGD   ; Point to Data; memory
	BSF     EECON1,RD      ; EE Read
	BCF     STATUS,RP0     ; Bank 2 
	MOVF    EEDATA,W       ; W = EEDATA
	BCF STATUS,RP1		   ; BANK 0
	MOVWF DIGITO4

		;RECUPERA DA MEMORIA AUXILIAR O DIGITO5
	BSF     STATUS,RP1     ;
	BCF     STATUS,RP0     ; ACESSA O Bank 2
	MOVLW D'5'			   ; ENDERECO 5 DA EEPROM
	MOVWF   EEADR          ; Address to read
	BSF     STATUS,RP0     ; Bank 3
	BCF     EECON1,EEPGD   ; Point to Data; memory
	BSF     EECON1,RD      ; EE Read
	BCF     STATUS,RP0     ; Bank 2 
	MOVF    EEDATA,W       ; W = EEDATA
	BCF STATUS,RP1		   ; BANK 0
	MOVWF DIGITO5

		;RECUPERA DA MEMORIA AUXILIAR O DIGITO6
	BSF     STATUS,RP1     ;
	BCF     STATUS,RP0     ; ACESSA O Bank 2
	MOVLW D'6'			   ; ENDERECO 6 DA EEPROM
	MOVWF   EEADR          ; Address to read
	BSF     STATUS,RP0     ; Bank 3
	BCF     EECON1,EEPGD   ; Point to Data; memory
	BSF     EECON1,RD      ; EE Read
	BCF     STATUS,RP0     ; Bank 2 
	MOVF    EEDATA,W       ; W = EEDATA
	BCF STATUS,RP1		   ; BANK 0
	MOVWF DIGITO6


		;TESTE
		;INICIA AUTENTICADO
		;SE INICIAR DESAUTENTICADO 
		;SEM SENHA SALVA 
		;NAO TEM COMO MEXER
		;COMENTAR ESSA LINHA DEPOIS DOS TESTES
	BSF ESTADO,0



LOOP
		;CADASTRAR NOVA SENHA SE ESTIVER NESSE MODO
	BTFSC ESTADO,1
	GOTO NOVASENHA
	RNOVASENHA

		;VARRER TECLADO MATRICIAL DE 0-B
	MOVLW B'11101111'
	MOVWF PORTB
	BTFSS PORTB,0
	CALL TECLA0
	BTFSS PORTB,1
	CALL TECLA1
	BTFSS PORTB,2
	CALL TECLA2
	BTFSS PORTB,3
	CALL TECLA3
	
	MOVLW B'11011111'
	MOVWF PORTB
	BTFSS PORTB,0
	CALL TECLA4
	BTFSS PORTB,1
	CALL TECLA5
	BTFSS PORTB,2
	CALL TECLA6
	BTFSS PORTB,3
	CALL TECLA7
	
	MOVLW B'10111111'
	MOVWF PORTB
	BTFSS PORTB,0
	CALL TECLA8
	BTFSS PORTB,1
	CALL TECLA9
	BTFSS PORTB,2	;A
	CALL TECLAA
	BTFSS PORTB,3	;B
	CALL TECLAB

GOTO LOOP



TECLA0
	BTFSS ESTADO,0
	CALL PRESSIONOU

	BTFSS ESTADO,0
	CALL TECLA0DESAUTENTICADO

	BTFSC ESTADO,0
	CALL TECLA0AUTENTICADO
RETURN

TECLA0DESAUTENTICADO
	INCF DIGITOATUAL,1
	CLRW
	MOVWF DIGITOPRESSIONADO
	CALL COMPARAR
RETURN

TECLA0AUTENTICADO
	BTFSS ESTADO,1
	CALL MOTOR1HORARIO

	BTFSC ESTADO,1
	CALL TECLA0EDITARSENHA
RETURN

TECLA0EDITARSENHA
	CALL PRESSIONOU

	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00111111'  ; 0
	MOVWF PORTD

	INCF SENHA,1

	CLRW
	MOVWF DIGITOATUAL

	CALL ATRIBUIRDIGITO
RETURN

TECLA1
	BTFSS ESTADO,0
	CALL PRESSIONOU

	BTFSS ESTADO,0
	CALL TECLA1DESAUTENTICADO

	BTFSC ESTADO,0
	CALL TECLA1AUTENTICADO
RETURN

TECLA1DESAUTENTICADO
	INCF DIGITOATUAL,1
	MOVLW D'1'
	MOVWF DIGITOPRESSIONADO
	CALL COMPARAR
RETURN

TECLA1AUTENTICADO
	BTFSS ESTADO,1
	CALL MOTOR2HORARIO

	BTFSC ESTADO,1
	CALL TECLA1EDITARSENHA
RETURN

TECLA1EDITARSENHA
	CALL PRESSIONOU

	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00000110'  ; 1
	MOVWF PORTD

	INCF SENHA,1

	MOVLW D'1'
	MOVWF DIGITOATUAL

	CALL ATRIBUIRDIGITO
RETURN


TECLA2
	BTFSS ESTADO,0
	CALL PRESSIONOU

	BTFSS ESTADO,0
	CALL TECLA2DESAUTENTICADO

	BTFSC ESTADO,0
	CALL TECLA2AUTENTICADO
RETURN

TECLA2DESAUTENTICADO

	INCF DIGITOATUAL,1
	MOVLW D'2'
	MOVWF DIGITOPRESSIONADO
	CALL COMPARAR
RETURN

TECLA2AUTENTICADO
	BTFSS ESTADO,1
	CALL MOTOR3ABRIR

	BTFSC ESTADO,1
	CALL TECLA2EDITARSENHA

RETURN

TECLA2EDITARSENHA
	CALL PRESSIONOU

	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'01011011'  ; 2
	MOVWF PORTD

	INCF SENHA,1

	MOVLW D'2'
	MOVWF DIGITOATUAL

	CALL ATRIBUIRDIGITO
RETURN


TECLA3
	BTFSS ESTADO,0
	CALL PRESSIONOU

	BTFSS ESTADO,0
	CALL TECLA3DESAUTENTICADO

	BTFSC ESTADO,0
	CALL TECLA3AUTENTICADO
RETURN

TECLA3DESAUTENTICADO
	INCF DIGITOATUAL,1
	MOVLW D'3'
	MOVWF DIGITOPRESSIONADO
	CALL COMPARAR
RETURN

TECLA3AUTENTICADO
	BTFSC ESTADO,1
	CALL TECLA3EDITARSENHA
RETURN

TECLA3EDITARSENHA
	CALL PRESSIONOU

	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'01001111'  ; 3
	MOVWF PORTD

	INCF SENHA,1

	MOVLW D'3'
	MOVWF DIGITOATUAL

	CALL ATRIBUIRDIGITO
RETURN

TECLA4
	BTFSS ESTADO,0
	CALL PRESSIONOU

	BTFSS ESTADO,0
	CALL TECLA4DESAUTENTICADO

	BTFSC ESTADO,0
	CALL TECLA4AUTENTICADO
RETURN

TECLA4DESAUTENTICADO
	INCF DIGITOATUAL,1
	MOVLW D'4'
	MOVWF DIGITOPRESSIONADO
	CALL COMPARAR
RETURN

TECLA4AUTENTICADO
	BTFSS ESTADO,1
	CALL MOTOR1ANTIHORARIO

	BTFSC ESTADO,1
	CALL TECLA4EDITARSENHA
RETURN

TECLA4EDITARSENHA
	CALL PRESSIONOU

	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'01100110'  ; 4
	MOVWF PORTD

	INCF SENHA,1

	MOVLW D'4'
	MOVWF DIGITOATUAL

	CALL ATRIBUIRDIGITO
RETURN

TECLA5
	BTFSS ESTADO,0
	CALL PRESSIONOU

	BTFSS ESTADO,0
	CALL TECLA5DESAUTENTICADO

	BTFSC ESTADO,0
	CALL TECLA5AUTENTICADO
RETURN

TECLA5DESAUTENTICADO
	INCF DIGITOATUAL,1
	MOVLW D'5'
	MOVWF DIGITOPRESSIONADO
	CALL COMPARAR
RETURN


TECLA5AUTENTICADO
	BTFSS ESTADO,1
	CALL MOTOR2ANTIHORARIO

	BTFSC ESTADO,1	
	CALL TECLA5EDITARSENHA
RETURN

TECLA5EDITARSENHA
	CALL PRESSIONOU

	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'01101101'  ; 5
	MOVWF PORTD

	INCF SENHA,1

	MOVLW D'5'
	MOVWF DIGITOATUAL

	CALL ATRIBUIRDIGITO
RETURN

TECLA6
	BTFSS ESTADO,0
	CALL PRESSIONOU

	BTFSS ESTADO,0
	CALL TECLA6DESAUTENTICADO

	BTFSC ESTADO,0
	CALL TECLA6AUTENTICADO
RETURN

TECLA6DESAUTENTICADO
	INCF DIGITOATUAL,1
	MOVLW D'6'
	MOVWF DIGITOPRESSIONADO
	CALL COMPARAR
RETURN

TECLA6AUTENTICADO
	BTFSS ESTADO,1
	CALL MOTOR3FECHAR

	BTFSC ESTADO,1
	CALL TECLA6EDITARSENHA
RETURN

TECLA6EDITARSENHA
	CALL PRESSIONOU

	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'01111101'  ; 6
	MOVWF PORTD

	INCF SENHA,1

	MOVLW D'6'
	MOVWF DIGITOATUAL

	CALL ATRIBUIRDIGITO
RETURN

TECLA7
	BTFSS ESTADO,0
	CALL PRESSIONOU

	BTFSS ESTADO,0
	CALL TECLA7DESAUTENTICADO

	BTFSC ESTADO,0
	CALL TECLA7AUTENTICADO
RETURN

TECLA7DESAUTENTICADO
	INCF DIGITOATUAL,1
	MOVLW D'7'
	MOVWF DIGITOPRESSIONADO
	CALL COMPARAR
RETURN

TECLA7AUTENTICADO
	BTFSC ESTADO,1
	CALL TECLA7EDITARSENHA
RETURN

TECLA7EDITARSENHA
	CALL PRESSIONOU

	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00000111'  ; 7
	MOVWF PORTD

	INCF SENHA,1

	MOVLW D'7'
	MOVWF DIGITOATUAL

	CALL ATRIBUIRDIGITO
RETURN

TECLA8
	BTFSS ESTADO,0
	CALL PRESSIONOU

	BTFSS ESTADO,0
	CALL TECLA8DESAUTENTICADO

	BTFSC ESTADO,0
	CALL TECLA8AUTENTICADO
RETURN

TECLA8DESAUTENTICADO
	INCF DIGITOATUAL,1
	MOVLW D'8'
	MOVWF DIGITOPRESSIONADO
	CALL COMPARAR
RETURN

TECLA8AUTENTICADO
	BTFSC ESTADO,1
	CALL TECLA8EDITARSENHA
RETURN

TECLA8EDITARSENHA
	CALL PRESSIONOU

	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'01111111'  ; 8
	MOVWF PORTD

	INCF SENHA,1

	MOVLW D'8'
	MOVWF DIGITOATUAL

	CALL ATRIBUIRDIGITO	
RETURN

TECLA9
	BTFSS ESTADO,0
	CALL PRESSIONOU

	BTFSS ESTADO,0
	CALL TECLA9DESAUTENTICADO

	BTFSC ESTADO,0
	CALL TECLA9AUTENTICADO
RETURN

TECLA9DESAUTENTICADO
	INCF DIGITOATUAL,1
	MOVLW D'9'
	MOVWF DIGITOPRESSIONADO
	CALL COMPARAR
RETURN

TECLA9AUTENTICADO
	BTFSC ESTADO,1
	CALL TECLA9EDITARSENHA
RETURN

TECLA9EDITARSENHA
	CALL PRESSIONOU

	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'01101111'  ; 9
	MOVWF PORTD

	INCF SENHA,1

	MOVLW D'9'
	MOVWF DIGITOATUAL

	CALL ATRIBUIRDIGITO
RETURN

TECLAA
	CALL PRESSIONOU

		;SE ESTIVER AUTENTICADO VAI PRO MODO DE ALTERAR SENHA
	BTFSC ESTADO,0
	BSF ESTADO,1

	BTFSC ESTADO,1
	CALL ESCREVERCODE

		;CONFERE SE ACERTOU A SENHA
	MOVLW D'6'
	SUBWF SENHA,0
	BTFSC STATUS,Z
	CALL LIGAR
RETURN


TECLAB
	CALL PRESSIONOU
	CALL ZERARTENTATIVA
	BCF ESTADO,0
	BCF ESTADO,1
	CLRF SENHA
	CALL ESCREVEROFF
RETURN


PRESSIONOU
			;LIGA O PONTO DO DISPLAY 0 PRA SABER QUE APERTOU ALGUM BOTAO
	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'10000000'
	MOVWF PORTD
	CALL AGUARDARB
	CALL AGUARDARB
	CALL AGUARDARB
	CLRF PORTA
	CLRF PORTD
RETURN


MOTOR1HORARIO
	;REMOVIDO POR NAO APRESENTAR COMPORTAMENTO ESPERADO
;		;CHECA O LDR 
;	BSF ADCON0,GO 
;	NAOPRONTO
;	BTFSC ADCON0,GO
;	GOTO NAOPRONTO
;;
;;;		;SE ESTIVER ESCURO NAO ACIONA O MOTOR
;;;	BTFSS ADRESH,7
;;;	GOTO NAOACIONAR
;;
;	MOVLW B'11111100'
;	ADDWF ADRESH,W
;
;;	BTFSS STATUS,C
;;	BTFSC STATUS,C
;	BTFSC STATUS,C
;	GOTO NAOACIONAR

	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00000100'
	MOVWF PORTD


	MOVLW B'00000001'
	MOVWF PORTC
	CALL AGUARDARM


	MOVLW B'00000010'
	MOVWF PORTC
	CALL AGUARDARM


	MOVLW B'00000100'
	MOVWF PORTC
	CALL AGUARDARM

	MOVLW B'00001000'
	MOVWF PORTC
	CALL AGUARDARM

	CLRF PORTC

	CLRF PORTA
	CLRF PORTD

	NAOACIONAR
RETURN


MOTOR1ANTIHORARIO
	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00010000'
	MOVWF PORTD


	MOVLW B'00001000'
	MOVWF PORTC
	CALL AGUARDARM

	MOVLW B'00000100'
	MOVWF PORTC
	CALL AGUARDARM

	MOVLW B'00000010'
	MOVWF PORTC
	CALL AGUARDARM

	MOVLW B'00000001'
	MOVWF PORTC
	CALL AGUARDARM

	CLRF PORTC

	CLRF PORTA
	CLRF PORTD
RETURN


MOTOR2HORARIO
	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00000010'
	MOVWF PORTD

	MOVLW B'00010000'
	MOVWF PORTC
	CALL AGUARDARM


	MOVLW B'00100000'
	MOVWF PORTC
	CALL AGUARDARM


	MOVLW B'01000000'
	MOVWF PORTC
	CALL AGUARDARM

	MOVLW B'10000000'
	MOVWF PORTC
	CALL AGUARDARM

	CLRF PORTC

	CLRF PORTA
	CLRF PORTD
RETURN


MOTOR2ANTIHORARIO
	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00100000'
	MOVWF PORTD


	MOVLW B'10000000'
	MOVWF PORTC
	CALL AGUARDARM

	MOVLW B'01000000'
	MOVWF PORTC
	CALL AGUARDARM

	MOVLW B'00100000'
	MOVWF PORTC
	CALL AGUARDARM

	MOVLW B'00010000'
	MOVWF PORTC
	CALL AGUARDARM

	CLRF PORTC

	CLRF PORTA
	CLRF PORTD
RETURN


MOTOR3ABRIR
	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00000001'
	MOVWF PORTD

	MOVLW B'00000011'
	MOVWF PORTE
	CALL AGUARDARSERVO1
	MOVLW B'00000001'
	MOVWF PORTE

	CLRF PORTA
	CLRF PORTD
RETURN


MOTOR3FECHAR
	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00001000'
	MOVWF PORTD

	MOVLW B'00000011'
	MOVWF PORTE
	CALL AGUARDARSERVO2
	MOVLW B'00000001'
	MOVWF PORTE

	CLRF PORTA
	CLRF PORTD
RETURN


COMPARAR
		;CHAMA COMPARAR DE ACORDO COM QUAL E O DIGITO DA SEQUENCIA DE SENHA
	MOVLW D'1'
	SUBWF DIGITOATUAL,0	
	BTFSC STATUS,Z
	CALL COMPARAR1

	MOVLW D'2'
	SUBWF DIGITOATUAL,0	
	BTFSC STATUS,Z
	CALL COMPARAR2

	MOVLW D'3'
	SUBWF DIGITOATUAL,0	
	BTFSC STATUS,Z
	CALL COMPARAR3

	MOVLW D'4'
	SUBWF DIGITOATUAL,0	
	BTFSC STATUS,Z
	CALL COMPARAR4

	MOVLW D'5'
	SUBWF DIGITOATUAL,0	
	BTFSC STATUS,Z
	CALL COMPARAR5

	MOVLW D'6'
	SUBWF DIGITOATUAL,0	
	BTFSC STATUS,Z
	CALL COMPARAR6

RETURN


	;COMPARA O DIGITO PRESSIONADO COM O DIGITO DA POSICAO DA SENHA
	;SE TIVER CORRETO MARCA COMO CORRETO PARA CONFERIR O PROXIMO DIGITO
	;SE ESTIVER ERRADO ZERA A TENTATIVA
COMPARAR1
	MOVF DIGITOPRESSIONADO,0
	SUBWF DIGITO1,0
	BTFSC STATUS,Z
	GOTO DIGITOCORRETO1
	CALL ZERARTENTATIVA
	RDIGITOCORRETO1
RETURN


COMPARAR2
	MOVF DIGITOPRESSIONADO,0
	SUBWF DIGITO2,0
	BTFSC STATUS,Z
	GOTO DIGITOCORRETO2
	CALL ZERARTENTATIVA
	RDIGITOCORRETO2
RETURN


COMPARAR3
	MOVF DIGITOPRESSIONADO,0
	SUBWF DIGITO3,0
	BTFSC STATUS,Z
	GOTO DIGITOCORRETO3
	CALL ZERARTENTATIVA
	RDIGITOCORRETO3
RETURN


COMPARAR4
	MOVF DIGITOPRESSIONADO,0
	SUBWF DIGITO4,0
	BTFSC STATUS,Z
	GOTO DIGITOCORRETO4
	CALL ZERARTENTATIVA
	RDIGITOCORRETO4
RETURN


COMPARAR5
	MOVF DIGITOPRESSIONADO,0
	SUBWF DIGITO5,0
	BTFSC STATUS,Z
	GOTO DIGITOCORRETO5
	CALL ZERARTENTATIVA
	RDIGITOCORRETO5
RETURN


COMPARAR6
	MOVF DIGITOPRESSIONADO,0
	SUBWF DIGITO6,0
	BTFSC STATUS,Z
	GOTO DIGITOCORRETO6
	CALL ZERARTENTATIVA
	RDIGITOCORRETO6
RETURN


ZERARTENTATIVA
		;ZERA O PROGRESSO DA CADEIA DE DIGITACAO DE SENHA
	CLRF SENHA
	CLRF DIGITOATUAL
;	BCF ESTADO,3
RETURN


DIGITOCORRETO1
	INCF SENHA,1
GOTO RDIGITOCORRETO1


DIGITOCORRETO2
	INCF SENHA,1
GOTO RDIGITOCORRETO2


DIGITOCORRETO3
	INCF SENHA,1
GOTO RDIGITOCORRETO3


DIGITOCORRETO4
	INCF SENHA,1
GOTO RDIGITOCORRETO4


DIGITOCORRETO5
	INCF SENHA,1
GOTO RDIGITOCORRETO5


DIGITOCORRETO6
	INCF SENHA,1
GOTO RDIGITOCORRETO6

ESCREVEROFF
	MOVLW B'11111111'
	MOVWF ITERACAO
	
	ESCREVEROFFPASSO
	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00111111'  ; 0	
	MOVWF PORTD
	CALL AGUARDAR

	MOVLW B'00010000'
	MOVWF PORTA
	MOVLW B'01110001'  ; F
	MOVWF PORTD
	CALL AGUARDAR

	MOVLW B'00001000'
	MOVWF PORTA
	MOVLW B'01110001'  ; F
	MOVWF PORTD
	CALL AGUARDAR

	CLRF PORTA
	CLRF PORTD

		;ESCREVER ON ITERACAO VEZES
	DECFSZ ITERACAO,1
	GOTO ESCREVEROFFPASSO
RETURN

ESCREVERON
	MOVLW B'11111111'
	MOVWF ITERACAO
	
	ESCREVERONPASSO
	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00111111'  ; 0	
	MOVWF PORTD
	CALL AGUARDAR

	MOVLW B'00010000'
	MOVWF PORTA
	MOVLW B'01010100'  ; n
	MOVWF PORTD
	CALL AGUARDAR

	CLRF PORTA
	CLRF PORTD

		;ESCREVER ON ITERACAO VEZES
	DECFSZ ITERACAO,1
	GOTO ESCREVERONPASSO
RETURN

LIGAR
	BSF ESTADO,0
		;SE TIVER LIGADO NAO ESCREVE LIGANDO
	BTFSS ESTADO,1
	CALL ESCREVERON
RETURN

ESCREVERCODE
	MOVLW B'11111111'
	MOVWF ITERACAO

		;ESCREVER CODE
	ESCREVERCODEPASSO
	MOVLW B'00100000'
	MOVWF PORTA
	MOVLW B'00111001'  ; C
	MOVWF PORTD
	CALL AGUARDAR
	MOVLW B'00010000'
	MOVWF PORTA
	MOVLW B'00111111'  ; 0	
	MOVWF PORTD
	CALL AGUARDAR
	MOVLW B'00001000'
	MOVWF PORTA
	MOVLW B'01011110'  ; D
	MOVWF PORTD
	CALL AGUARDAR
	MOVLW B'00000100'
	MOVWF PORTA
	MOVLW B'01111001'  ; E
	MOVWF PORTD
	CALL AGUARDAR
	CLRF PORTA
	CLRF PORTD
		;ESCREVER CODE ITERACAO VEZES
	DECFSZ ITERACAO,1
	GOTO ESCREVERCODEPASSO
;
;		;0 JA ESCREVEU CODE 
;		;1 ESCREVENDO CODE	
;	BCF ESTADO,5
;		;PARA INICIAR O CADASTRO DE SENHA
	CLRF SENHA
RETURN


NOVASENHA
		;A PARTIR DAQUI SE ESTIVER SALVO OS 6 DIGITOS AUX VAI SALVAR A SENHA
	MOVLW D'6'
	SUBWF SENHA,0
	BTFSC STATUS,Z
	CALL SALVARSENHA
GOTO RNOVASENHA


SALVARSENHA
		;SALVA A SENHA AUXILIAR NA MEMORIA PRINCIPAL
		;SALVA O AUXILIAR NO W E MANDA DO W PRA MEMORIA PRINCIPAL
	MOVF DIGITO1AUX,0
	MOVWF DIGITO1

	MOVF DIGITO2AUX,0
	MOVWF DIGITO2

	MOVF DIGITO3AUX,0
	MOVWF DIGITO3

	MOVF DIGITO4AUX,0
	MOVWF DIGITO4

	MOVF DIGITO5AUX,0
	MOVWF DIGITO5

	MOVF DIGITO6AUX,0
	MOVWF DIGITO6


		;SALVANDO DIGITO 1 DA SENHA NA MEMORIA AUXILIAR
	MOVF DIGITO1AUX,W
	BSF    STATUS,RP1
	BSF    STATUS,RP0	;BANK3
	BTFSC EECON1,WR      ;Wait for write
	GOTO   $-1            ;to complete
	BCF    STATUS,  RP0    ;Bank 2
	MOVWF EEDATA         ;to write
;	MOVF   DATA_EE_ADDR,W ;Data Memory
	MOVLW D'1'
	MOVWF EEADR          ;Address to write
	BSF    STATUS,RP0     ;Bank 3
	BCF    EECON1,EEPGD   ;Point to DATA ;memory
	BSF    EECON1,WREN    ;Enable writes
	BCF    INTCON,GIE     ;Disable INTs.
	MOVLW H'55'            ; 
	MOVWF EECON2         ;Write 55h
	MOVLW H'AA'            ; 
	MOVWF EECON2         ;Write AAh
	BSF    EECON1,WR      ;Set WR bit to;begin write
	BSF    INTCON,GIE     ;Enable INTs.
	BCF    EECON1,WREN    ;Disable writes

		;SALVANDO DIGITO 2 DA SENHA NA MEMORIA AUXILIAR
	BCF STATUS,RP0
	BCF STATUS,RP1	;BANK0
	MOVF DIGITO2AUX,W
	BSF    STATUS,RP1
	BSF    STATUS,RP0	;BANK3
	BTFSC EECON1,WR      ;Wait for write
	GOTO   $-1            ;to complete
	BCF    STATUS,  RP0    ;Bank 2
	MOVWF EEDATA         ;to write
;	MOVF   DATA_EE_ADDR,W ;Data Memory
	MOVLW D'2'
	MOVWF EEADR          ;Address to write
	BSF    STATUS,RP0     ;Bank 3
	BCF    EECON1,EEPGD   ;Point to DATA ;memory
	BSF    EECON1,WREN    ;Enable writes
	BCF    INTCON,GIE     ;Disable INTs.
	MOVLW H'55'            ; 
	MOVWF EECON2         ;Write 55h
	MOVLW H'AA'            ; 
	MOVWF EECON2         ;Write AAh
	BSF    EECON1,WR      ;Set WR bit to;begin write
	BSF    INTCON,GIE     ;Enable INTs.
	BCF    EECON1,WREN    ;Disable writes

		;SALVANDO DIGITO 3 DA SENHA NA MEMORIA AUXILIAR
	BCF STATUS,RP0
	BCF STATUS,RP1	;BANK0
	MOVF DIGITO3AUX,W
	BSF    STATUS,RP1
	BSF    STATUS,RP0	;BANK3
	BTFSC EECON1,WR      ;Wait for write
	GOTO   $-1            ;to complete
	BCF    STATUS,  RP0    ;Bank 2
	MOVWF EEDATA         ;to write
;	MOVF   DATA_EE_ADDR,W ;Data Memory
	MOVLW D'3'
	MOVWF EEADR          ;Address to write
	BSF    STATUS,RP0     ;Bank 3
	BCF    EECON1,EEPGD   ;Point to DATA ;memory
	BSF    EECON1,WREN    ;Enable writes
	BCF    INTCON,GIE     ;Disable INTs.
	MOVLW H'55'            ; 
	MOVWF EECON2         ;Write 55h
	MOVLW H'AA'            ; 
	MOVWF EECON2         ;Write AAh
	BSF    EECON1,WR      ;Set WR bit to;begin write
	BSF    INTCON,GIE     ;Enable INTs.
	BCF    EECON1,WREN    ;Disable writes

		;SALVANDO DIGITO 4 DA SENHA NA MEMORIA AUXILIAR
	BCF STATUS,RP0
	BCF STATUS,RP1	;BANK0
	MOVF DIGITO4AUX,W
	BSF    STATUS,RP1
	BSF    STATUS,RP0	;BANK3
	BTFSC EECON1,WR      ;Wait for write
	GOTO   $-1            ;to complete
	BCF    STATUS,  RP0    ;Bank 2
	MOVWF EEDATA         ;to write
;	MOVF   DATA_EE_ADDR,W ;Data Memory
	MOVLW D'4'
	MOVWF EEADR          ;Address to write
	BSF    STATUS,RP0     ;Bank 3
	BCF    EECON1,EEPGD   ;Point to DATA ;memory
	BSF    EECON1,WREN    ;Enable writes
	BCF    INTCON,GIE     ;Disable INTs.
	MOVLW H'55'            ; 
	MOVWF EECON2         ;Write 55h
	MOVLW H'AA'            ; 
	MOVWF EECON2         ;Write AAh
	BSF    EECON1,WR      ;Set WR bit to;begin write
	BSF    INTCON,GIE     ;Enable INTs.
	BCF    EECON1,WREN    ;Disable writes

		;SALVANDO DIGITO 5 DA SENHA NA MEMORIA AUXILIAR
	BCF STATUS,RP0
	BCF STATUS,RP1	;BANK0
	MOVF DIGITO5AUX,W
	BSF    STATUS,RP1
	BSF    STATUS,RP0	;BANK3
	BTFSC EECON1,WR      ;Wait for write
	GOTO   $-1            ;to complete
	BCF    STATUS,  RP0    ;Bank 2
	MOVWF EEDATA         ;to write
;	MOVF   DATA_EE_ADDR,W ;Data Memory
	MOVLW D'5'
	MOVWF EEADR          ;Address to write
	BSF    STATUS,RP0     ;Bank 3
	BCF    EECON1,EEPGD   ;Point to DATA ;memory
	BSF    EECON1,WREN    ;Enable writes
	BCF    INTCON,GIE     ;Disable INTs.
	MOVLW H'55'            ; 
	MOVWF EECON2         ;Write 55h
	MOVLW H'AA'            ; 
	MOVWF EECON2         ;Write AAh
	BSF    EECON1,WR      ;Set WR bit to;begin write
	BSF    INTCON,GIE     ;Enable INTs.
	BCF    EECON1,WREN    ;Disable writes

		;SALVANDO DIGITO 6 DA SENHA NA MEMORIA AUXILIAR
	BCF STATUS,RP0
	BCF STATUS,RP1	;BANK0
	MOVF DIGITO6AUX,W
	BSF    STATUS,RP1
	BSF    STATUS,RP0	;BANK3
	BTFSC EECON1,WR      ;Wait for write
	GOTO   $-1            ;to complete
	BCF    STATUS,  RP0    ;Bank 2
	MOVWF EEDATA         ;to write
;	MOVF   DATA_EE_ADDR,W ;Data Memory
	MOVLW D'6'
	MOVWF EEADR          ;Address to write
	BSF    STATUS,RP0     ;Bank 3
	BCF    EECON1,EEPGD   ;Point to DATA ;memory
	BSF    EECON1,WREN    ;Enable writes
	BCF    INTCON,GIE     ;Disable INTs.
	MOVLW H'55'            ; 
	MOVWF EECON2         ;Write 55h
	MOVLW H'AA'            ; 
	MOVWF EECON2         ;Write AAh
	BSF    EECON1,WR      ;Set WR bit to;begin write
	BSF    INTCON,GIE     ;Enable INTs.
	BCF    EECON1,WREN    ;Disable writes

		;VOLTA PRO BANK0
	BCF STATUS,RP0
	BCF STATUS,RP1

		;ENCERRA O MODO DE CADASTRO DE SENHA E FECHA O SISTEMA
	CALL TECLAB
RETURN


ATRIBUIRDIGITO
	MOVLW D'1'
	SUBWF SENHA,0
	BTFSC STATUS,Z
	CALL ATRIBUIRDIGITO1

	MOVLW D'2'
	SUBWF SENHA,0
	BTFSC STATUS,Z
	CALL ATRIBUIRDIGITO2

	MOVLW D'3'
	SUBWF SENHA,0
	BTFSC STATUS,Z
	CALL ATRIBUIRDIGITO3

	MOVLW D'4'
	SUBWF SENHA,0
	BTFSC STATUS,Z
	CALL ATRIBUIRDIGITO4

	MOVLW D'5'
	SUBWF SENHA,0
	BTFSC STATUS,Z
	CALL ATRIBUIRDIGITO5

	MOVLW D'6'
	SUBWF SENHA,0
	BTFSC STATUS,Z
	CALL ATRIBUIRDIGITO6

RETURN


ATRIBUIRDIGITO1
	MOVF DIGITOATUAL,0
	MOVWF DIGITO1AUX
RETURN

ATRIBUIRDIGITO2
	MOVF DIGITOATUAL,0
	MOVWF DIGITO2AUX
RETURN

ATRIBUIRDIGITO3
	MOVF DIGITOATUAL,0
	MOVWF DIGITO3AUX
RETURN

ATRIBUIRDIGITO4
	MOVF DIGITOATUAL,0
	MOVWF DIGITO4AUX
RETURN

ATRIBUIRDIGITO5
	MOVF DIGITOATUAL,0
	MOVWF DIGITO5AUX
RETURN

ATRIBUIRDIGITO6
	MOVF DIGITOATUAL,0
	MOVWF DIGITO6AUX
RETURN



AGUARDARSERVO1
	MOVLW D'2'
		;CONTROLA O TEMPO
	MOVWF VEZES
	GOTO LACO_VEZES

AGUARDARSERVO2
	MOVLW D'10'
		;CONTROLA O TEMPO
	MOVWF VEZES
	GOTO LACO_VEZES

AGUARDARB
		;PRO BOTAO DEIXAR NO MAXIMO 
	MOVLW B'11111111'
		;CONTROLA O TEMPO
	MOVWF VEZES
	GOTO LACO_VEZES

AGUARDARM
		;PRO MOTOR ALGO ENTRE 
		;B'00111111' E B'00011111'
		;MEDIA D'47'
		;FICOU BOM EM D'56' MAS AS VEZES NAO RESPONDE AO FECHAR	
	MOVLW D'60'
		;CONTROLA O TEMPO
	MOVWF VEZES
	GOTO LACO_VEZES

AGUARDAR
		;PRO DISPLAY
		;B'00000111'
	MOVLW B'00000111'
		;CONTROLA O TEMPO
	MOVWF VEZES

	LACO_VEZES
		MOVLW D'250'
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
