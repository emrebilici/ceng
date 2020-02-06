; When you press and relase the RB0 then the four top most LEDs connected to PORTC will be turned on
; Then when you press the RB0 the other four LEDs connected to PORTC  will be turned on
; To execute this program The jumper J13 should be ground side

LIST    P=18F8722

#INCLUDE <p18f8722.inc> 
    
CONFIG OSC = HSPLL, FCMEN = OFF, IESO = OFF, PWRT = OFF, BOREN = OFF, WDT = OFF, MCLRE = ON, LPT1OSC = OFF, LVP = OFF, XINST = OFF, DEBUG = OFF

L1         EQU 0X21
L2         EQU 0X22
 ra4_flag        udata 0X23
 ra4_flag

 

counter1 udata 0x25
counter1

counter2 udata 0x26
counter2

counter3 udata 0x27
counter3

ORG     0x00

goto    main

init
 
BCF INTCON2,7
clrf PORTA
 clrf PORTB
 clrf PORTC
 clrf PORTD
 
movlw h'00'
 
clrf  LATC
movwf TRISC

 
clrf  LATB
movwf TRISB

 
clrf  LATA
movlw 0Fh
movwf ADCON1

movlw h'00'
movwf TRISA

clrf  LATD
movwf TRISD



movlw b'00010000'  ;ra4 input 
movwf TRISA
clrf LATA


movlw b'00011000'  ;re3, re4 input 

movwf TRISE
clrf LATE
clrf PORTE

movlw h'0F'  ;first 4 led is open
movwf LATA

movlw h'0F'
movwf LATB
 
movlw h'0F'
movwf LATC
 
movlw h'0F'
movwf LATD


call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay

 

movlw h'00'    ;leds are closed 
movwf LATA
 
movlw h'00'
movwf LATB
 
movlw h'00'
movwf LATC
 
movlw h'00'
movwf LATD
 
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay
call bigdelay



return
 
sta1:

btfss LATA,0  ;ra0 yanmamissa buradan basla
goto ra0    
btfss LATA,1
goto ra1    
btfss LATA,2
goto ra2    
btfss LATA,3    
goto ra3
    
    
btfss LATB,0  ;ra0 yanmamissa buradan basla
goto rb0    
btfss LATB,1
goto rb1    
btfss LATB,2
goto rb2    
btfss LATB,3    
goto rb3
    
btfss LATC,0  ;ra0 yanmamissa buradan basla
goto rc0    
btfss LATC,1
goto rc1    
btfss LATC,2
goto rc2    
btfss LATC,3    
goto rc3
    
btfss LATD,0  ;ra0 yanmamissa buradan basla
goto rd0    
btfss LATD,1
goto rd1    
btfss LATD,2
goto rd2    
btfss LATD,3    
goto rd3    
    
    
ra0:    
movlw h'01'    
movwf LATA
    
call ra4p
ra1:  
movlw h'03'
movwf LATA


call ra4p
ra2: 
movlw h'07'
movwf LATA
    

call ra4p
ra3: 
movlw h'0F'
movwf LATA


call ra4p
rb0:    
movlw h'01'    
movwf LATB


call ra4p
rb1:    
movlw h'03'
movwf LATB
 
call ra4p
rb2:
movlw h'07'
movwf LATB
 

call ra4p
rb3:    
movlw h'0F'
movwf LATB

call ra4p
rc0:
movlw h'01'    
movwf LATC

call ra4p
rc1:   
movlw h'03'
movwf LATC

call ra4p
rc2:    
movlw h'07'
movwf LATC

call ra4p
rc3:    
movlw h'0F'
movwf LATC

call ra4p  
rd0:    
movlw h'01'    
movwf LATD

call ra4p   
rd1:    
movlw h'03'
movwf LATD
 
call ra4p
rd2:    
movlw h'07'
movwf LATD

call ra4p
rd3:    
    
movlw h'0F'
movwf LATD
    
call onra4
;RA4 beklicek    sonra re3 ya da re4 icin bekliyo
;
    
sta3:

btfsc LATD,3		    ;rd3u control et ac?ksa goto d3
goto d3
    
btfsc LATD,2		    ;rd2yi control
goto d2
    
btfsc LATD,1
goto d1
    
btfsc LATD,0
goto d0
    
btfsc LATC,3		    ;rd3u control et ac?ksa goto d3
goto c3
    
btfsc LATC,2		    ;rd2yi control
goto c2
    
btfsc LATC,1
goto c1
    
btfsc LATC,0
goto c0
    
btfsc LATB,3		    ;rB3u control et ac?ksa goto d3
goto b3
    
btfsc LATB,2		    ;rB2yi control
goto b2
    
btfsc LATB,1
goto b1
    
btfsc LATB,0
goto b0
    
btfsc LATA,3		    ;rA3u control et ac?ksa goto d3
goto a3
    
btfsc LATA,2		    ;rA2yi control
goto a2
    
btfsc LATA,1
goto a1
    
btfsc LATA,0
goto a0
    
d3:    
movlw h'07'
movwf LATD

call ra4p    
    
d2:    
movlw h'03'
movwf LATD
 
call ra4p   
    
d1:    
movlw h'01'    
movwf LATD

call ra4p       
    
d0:    
movlw h'00'    
movwf LATD  
    
    call ra4p   
 
c3:    
movlw h'07'
movwf LATC

    call ra4p   
    
c2:    
movlw h'03'
movwf LATC
 
    call ra4p   
    
c1:
movlw h'01'    
movwf LATC

    call ra4p   
    
c0:   
movlw h'00'    
movwf LATC  

    call ra4p   
    
b3:    
movlw h'07'
movwf LATB
    
    call ra4p   
    
b2:
movlw h'03'
movwf LATB
 
    call ra4p   
    
b1:    
movlw h'01'    
movwf LATB

    call ra4p   
    
b0:    
movlw h'00'    
movwf LATB

    call ra4p   
    
a3:    
movlw h'07'
movwf LATA

    call ra4p   
    
a2:    
movlw h'03'
movwf LATA

    call ra4p   
    
a1:    
movlw h'01'    
movwf LATA

    call ra4p   
    
a0:
movlw h'00'    
movwf LATA    
    
       
call offra4   
;sonda ra4u bekle
    
   
offra4
    pressra4:
	btfss PORTA,4
	goto pressra4
    releasera4:
	btfsc PORTA,4
	goto releasera4
	goto offrecontrol
    
onra4
    pressedra4:
	btfss PORTA,4
	goto pressedra4
    releasedra4:
	btfsc PORTA,4
	goto releasedra4
	goto onrecontrol
    
recontrol
    prere3:
    btfss PORTE,3     ;basildiysa rere3e git
    goto prere4		;basilmadiyse re4u control et
    rere3:
    btfsc PORTE,3	;birakildiysa don ve aynen devam sta1
    goto rere3
    goto sta1		;goto sta1 olmasi gerek sta1de de sta3 gibi yapcan
    
    prere4:	
    btfss PORTE,4   ;basilana kadar bunlarin arasinda dolas
    goto prere3
    rere4:
    btfsc PORTE,4   ;birakildiysa don ve sta3e gec
    goto rere4
    goto sta3	;goto rd3 falan dicen    
    
    
offrecontrol
    oprere3:
    btfss PORTE,3     ;basildiysa rere3e git
    goto oprere3		;basilmadiyse re4u control et
    orere3:
    btfsc PORTE,3	;birakildiysa don ve bastan sta1
    goto orere3
    goto sta1 
    
onrecontrol
    onprere4:
    btfss PORTE,4     ;basildiysa rere3e git
    goto onprere4		;basilmadiyse re4u control et
    onrere4:
    btfsc PORTE,4	;birakildiysa don ve bastan sta1
    goto onrere4
    goto sta3 
    


return

    

main:
call init
loop:
    call sta1
    ;call sta2
    ;call sta3
goto loop

bigdelay
    call delay
    call delay
    call delay
    call delay
    call delay
    call delay
    call delay
    call delay   
    call delay
    call delay
    call delay
    call delay
    call delay
    call delay
    call delay
    call delay

       

    
    return
    
   
ra4p

iniloop:
    movlw   0x55
    movwf   counter2
loop2:
    movlw   0x19
    movwf   counter3
loop3:
    btfsc  ra4_flag,0	 ;daha once basilmissa ra4pressede git
    goto    ra4pressed
    btfss   PORTA, 4	;basilmamissa loopa git
    goto    genloop
    setf    ra4_flag
ra4pressed:
    btfsc   PORTA, 4	;basilip birakildiysa flagi sifirla falan 
    goto    genloop
    clrf    ra4_flag
    goto recontrol
    return
genloop:
    decfsz  counter3
    goto    loop3
    decfsz  counter2
    goto    loop2
    decfsz  counter1
    goto    iniloop
    return
delay:  
delay                            ; Time Delay Routines
     MOVLW 0x52                        ; Copy 50 to W
     MOVWF L2                    ; Copy W into L2
 LOOP2:
     MOVLW 0xfd                   ; Copy 255 into W
     MOVWF L1                    ; Copy W into L1
 LOOP1:
     
     decfsz L1,F                    ; Decrement L1. If 0 Skip next instruction
         GOTO LOOP1                ; ELSE Keep counting down
     decfsz L2,F                    ; Decrement L2. If 0 Skip next instruction
         GOTO LOOP2                ; ELSE Keep counting down
     return 
end



