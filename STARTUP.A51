; STC32G 单片机启动文件
; 适用于 PAN3031 LoRa 模块项目
; 请将此文件添加到 Keil 工程中

$NOMOD51
;------------------------------------------------------------------------------
;  This file is part of the C51 Compiler package
;  Copyright (C) 2020 Silicon Labs / STC
;  NOTE: This file MODIFIED for STC32G
;------------------------------------------------------------------------------
;  STARTUP.A51: This code is executed after processor reset.
;
;  To translate this file you need the following assembly language editor:
;  ASM51 or compatible.
;------------------------------------------------------------------------------
;
;  User-defined Power-On Initialization of Memory
;
;  With the following EQU statements the initialization of memory
;  at processor reset can be defined:
;
;  The absolute start-address of IDATA memory is always 0x00
;  The absolute end-address of IDATA memory is 0xFF
;
; IDATA: rep 1; uninitialized data-section
;------------------------------------------------------------------------------
; Reconfiguración de la memoria para STC32G
;
IDATALEN        EQU     0x100         ; Longitud de la memoria a inicializar
;
XDATASTART      EQU     0x0000        ; Inicio de XDATA
XDATALEN        EQU     0x1000         ; Longitud de XDATA (4KB para STC32G)
;
;------------------------------------------------------------------------------
; SEGMENTOS DE MEMORIA
;------------------------------------------------------------------------------
;  El segmento de código (CODE) tiene que estar en el espacio de memoria
;  desde 0x1000 hasta 0xFFFF si se usa un chip con más de 64KB de Flash.
;  Para chips de 64KB o menos, el código comienza en 0x0000.
;
;  Si la opción "Use multiple KEIL C51 limit" está deshabilitada,
;  el código puede estar en cualquier dirección.
;
; STC32G tiene 64KB Flash desde 0x0000
;
CSEG    AT      0x0000
START:  LJMP    MAIN

        ORG     0x0003
        LJMP    INT0_Handler      ; External Interrupt 0

        ORG     0x000B
        LJMP    T0_Handler        ; Timer 0

        ORG     0x0013
        LJMP    INT1_Handler      ; External Interrupt 1

        ORG     0x001B
        LJMP    T1_Handler        ; Timer 1

        ORG     0x0023
        LJMP    UART1_Handler     ; UART1

        ORG     0x002B
        LJMP    T2_Handler        ; Timer 2

; Default handlers - redirect to user code
INT0_Handler:
T0_Handler:
INT1_Handler:
T1_Handler:
UART1_Handler:
T2_Handler:
        RETI

;------------------------------------------------------------------------------
; Código de inicio
;------------------------------------------------------------------------------
MAIN:
        MOV     SP,#0xC0          ; Configurar puntero de pila
        
        ; Inicializar memoria IDATA
        MOV     DPTR,#IDATALEN
        MOV     R0,#LOW(IDATALEN - 1)
        CLR     A
IDATALOOP:
        MOVX    @DPTR,A
        DJNZ    R0,IDATALOOP
        DJNZ    DPH,IDATALOOP
        
        ; Saltar al código principal
        LJMP    ?C_START

END
