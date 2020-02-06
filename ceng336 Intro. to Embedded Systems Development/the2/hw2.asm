; When you press the button RB4, the counter increments and it is displayed on 7-segment D3 and on PORTA asa binary number
; To execute this program The jumper J13 should be ground side
    LIST    P=18F8722

#INCLUDE <p18f8722.inc>
    CONFIG OSC = HS, FCMEN = OFF, IESO = OFF, PWRT = OFF, BOREN = OFF, WDT = OFF, MCLRE = ON, LPT1OSC = OFF, LVP = OFF, XINST = OFF, DEBUG = OFF

Count	equ	0x25
L1         EQU 0X21
L2         EQU 0X22
number     udata 0x23
number
number1    udata 0x24
number1
    
value_timer1 udata 0x25
value_timer1

aLaser udata 0x26
aLaser

bLaser udata 0x27
bLaser

cLaser udata 0x28
cLaser

dLaser udata 0x29
dLaser

eLaser udata 0x30
eLaser

fLaser udata 0x31
fLaser

aMeteor udata 0x32
aMeteor 

bMeteor udata 0x33
bMeteor

cMeteor udata 0x34
cMeteor 

dMeteor udata 0x35
dMeteor 

eMeteor udata 0x36
eMeteor

fMeteor udata 0x37
fMeteor

laser_pushed udata 0x38
laser_pushed
 
down_pushed udata 0x39
down_pushed

score_Prev  udata 0x3A
score_Prev
 
value_timer1L udata 0x40
value_timer1L 

value_timer1H udata 0x41
value_timer1H 
 
posShip udata 0x42
posShip
 
counter udata 0x43
counter

score   udata 0x44
score 

mid_limiter udata 0x45
mid_limiter
 
counter_mid udata 0x46
counter_mid
 
counter_last udata 0x47
counter_last 

counterShift udata 0x48
counterShift
 
gMeteor udata 0x49
gMeteor
 
bas100	udata	0x4A
bas100

bas10	udata	0x4B
bas10

up_pushed   udata 0x50
up_pushed

status_temp udata 0x51
status_temp
 
w_temp  udata 0x52
w_temp
 
pclath_temp udata 0x53
pclath_temp
 
timer1h0bit udata 0x54
timer1h0bit
 
isrCheck udata 0x55
isrCheck

gameOverStatus udata 0x56
gameOverStatus
 

 
basamakKontrol100	udata	0x57
basamakKontrol100

basamakKontrol10	udata	0x58
basamakKontrol10

basamak3    udata   0x59
basamak3
    
basamak2    udata   0x5A
basamak2

basamak1    udata   0x5B
basamak1

w_table        udata 0x5C
w_table

score_cache	udata 0x5D
score_cache	
	
displayFlag	udata 0x5E
displayFlag
	
counterD	udata 0x5F
counterD
	
    org     0x00
    goto    init

    org     0x08
    goto    isr  

init:
    clrf INTCON
    CLRF INTCON2
    goto    configPorts
end_configPorts:
    goto    configVariables
end_configVariables:
    goto    configTimers
end_configTimers:    
    goto    configInterrupts
end_configInterrupts:  
    bsf	posShip,3
    bsf	LATA,3
    goto    main

main:
    goto    rg0Button
end_rg0Button:
gameRoutine:
    btfsc   isrCheck,0
    goto    phaseChange
end_phaseChange:
    ;bsf LATA,0
    btfsc   displayFlag,0
    goto    updateDisplay
end_updateDisplay:
    goto    rg1Check
end_rg1Check:
    goto    rg2Check
end_rg2Check:
    goto    rg3Check
end_rg3Check:
    btfss   gameOverStatus,0
    goto gameRoutine
    goto init
    
   
    
;*************
;   INIT
;*************
configPorts:
    clrf    PORTA
    clrf    PORTB
    clrf    PORTC
    clrf    PORTD
    clrf    PORTE
    clrf    PORTF
    clrf    PORTG

    clrf    LATA
    movlw   0Fh
    movwf   ADCON1
    
    movlw   h'00'
    movwf   TRISA

    clrf    LATB
    movwf   TRISB 
 
    clrf    LATC
    movwf   TRISC

    clrf    LATD
    movwf   TRISD
 
    clrf    LATE
    movwf   TRISE

    clrf    LATF
    movwf   TRISF 

    CLRF LATJ ;display baslangic
    CLRF PORTJ

    MOVWF   TRISH
    
    

    MOVWF   TRISJ ; display end
    
    movlw   b'00111111'
    MOVWF LATJ
    BSF   LATH,0
    bcf LATH,1
    bcf LATH,2
    bcf LATH,3
    
    movlw   b'00111111'
    MOVWF LATJ
    BSF   LATH,1
    bcf LATH,0
    bcf LATH,2
    bcf LATH,3
    
    movlw   b'00111111'
    MOVWF LATJ
    BSF   LATH,2
    bcf LATH,0
    bcf LATH,1
    bcf LATH,3

    movlw   b'00111111'
    MOVWF LATJ
    BSF   LATH,3
    bcf LATH,0
    bcf LATH,1
    bcf LATH,2
    
    clrf    LATG
    movlw   h'0F'
    movwf   TRISG
    goto end_configPorts
    

configVariables:
    clrf    Count
    clrf    L1
    clrf    L2
    clrf    number
    clrf    number1
    clrf    value_timer1
    clrf    aLaser
    clrf    bLaser
    clrf    cLaser
    clrf    dLaser
    clrf    eLaser
    clrf    fLaser
    clrf    aMeteor
    clrf    bMeteor
    clrf    cMeteor
    clrf    dMeteor
    clrf    eMeteor
    clrf    fMeteor
    clrf    laser_pushed
    clrf    down_pushed
    clrf    value_timer1L
    clrf    value_timer1H
    clrf    posShip
    clrf    counter
    clrf    score
    clrf    w_table
    clrf    score_cache
    clrf    score_Prev
    clrf    mid_limiter
    clrf    counter_mid
    clrf    counter_last
    clrf    counterShift
    clrf    gMeteor
    clrf    up_pushed
    clrf    status_temp
    clrf    w_temp
    clrf    pclath_temp
    clrf    timer1h0bit
    clrf    isrCheck
    clrf    gameOverStatus    
    clrf    basamak1
    clrf    basamak2
    clrf    basamak3
    goto end_configVariables

configTimers:
    movlw   b'01000111' ;Disable Timer0 by setting TMR0ON to 0 (for now)
                        ;Configure Timer0 as an 8-bit timer/counter by setting T08BIT to 1
                        ;Timer0 increment from internal clock with a prescaler of 1:256.
    movwf   T0CON ; T0CON = b'01000111'

    movlw   b'10000001' ;16bit t1con seventh bit is 1. Activate Timer1 by setting TMR1ON to 1 || tmr1<0> = 1
    movwf   T1CON ; T1CON = b'00000001'
    goto end_configTimers

configInterrupts:
    movlw   b'10100000' ;Enable Global, peripheral, Timer0  interrupts by setting GIE, PEIE, TMR0IE bits to 1
    movwf   INTCON


    movlw   b'00000101'
    movwf   mid_limiter
    goto end_configInterrupts
    
    
;*************
;   MAIN
;*************
rg0Button:   
rg0loop:
    btfss   PORTG,0
	goto    rg0loop				
	bsf     T0CON, 7    ;Enable Timer0 by setting TMR0ON to 1
	goto    save_timer1
end_save_timer1:

    goto end_rg0Button
    
save_timer1:
	movf    TMR1L, 0
	movwf   value_timer1L
	movf 	TMR1H,0
	movwf 	value_timer1H
	goto	end_save_timer1
	
rg1Check:
    btfsc   laser_pushed,0
    goto    checkReleaseRG1
checkNewPushRG1:
    btfss   PORTG,1 ; ates ete simdi mi basildi
    goto end_rg1Check
    bsf     laser_pushed,0
    movf    aMeteor, 0
    xorwf   PORTA,0
    iorwf   aLaser,1
checkReleaseRG1:
    btfss   PORTG,1
    clrf    laser_pushed
    goto end_rg1Check




rg2Check: ; down
    btfsc   down_pushed,0
    goto    checkReleaseRG2
checkNewPushRG2:
    btfss   PORTG,2
    goto end_rg2Check
    bsf     down_pushed,0
    btfsc   posShip,5
    goto end_rg2Check
    rlncf    posShip,1
    movf    posShip,0
    movwf   LATA,0
    movf    posShip,0
    cpfseq  aMeteor
    goto end_rg2Check
    bsf    gameOverStatus,0

checkReleaseRG2:
    btfss   PORTG,2
    clrf    down_pushed
    goto end_rg2Check

rg3Check: ; up
    btfsc   up_pushed,0
    goto    checkReleaseRG3
checkNewPushRG3:
    btfss   PORTG,3
    goto end_rg3Check
    bsf     up_pushed,0
    btfsc   posShip,0
    goto end_rg3Check
    rrncf    posShip,1
    movf    posShip,0
    movwf   LATA,0
    movf    posShip,0
    cpfseq  aMeteor
    goto end_rg3Check
    bsf    gameOverStatus,0

checkReleaseRG3:
    btfss   PORTG,3
    clrf    up_pushed
    goto end_rg3Check


;*************
;   PHASE CHANGE
;*************


phaseChange:
    bcf	    INTCON,7
    goto    create_asteroid
end_create_asteroid:
    goto    locateMeteor
end_locateMeteor:
    goto    setMidLimiter
end_setMidLimiter:
    goto    columnMatcher   ;it also handles laser shift
end_columnMatcher:
    goto    meteorShift
end_meteorShift:
    goto    updateLed
end_updateLed:
    
    goto    isGameOver
end_isGameOver:
    clrf    isrCheck
    bsf	    INTCON,7
    goto end_phaseChange


create_asteroid:
    movf value_timer1H,0
    movwf timer1h0bit
    rrncf value_timer1H
    btfsc value_timer1L,0
    goto timerh7_1
    bcf value_timer1H,7
    goto lowerbits  
timerh7_1:
    bsf value_timer1H,7 
    
lowerbits:
    rrncf   value_timer1L
    btfss   timer1h0bit,0
    goto    highTime0
    bsf     value_timer1L,7
    goto    checkComplement
highTime0:
    bcf     value_timer1L,7
checkComplement:

    incf	counterShift, f              ;Timer interrupt handler part begins here by incrementing count variable
    movf	counterShift, w              ;Move count to Working register
    sublw	d'10'                    ;Decrement 2 from Working register to be activate isr every 100ms
    btfss	STATUS, Z               ;Is the result Zero?
    goto end_create_asteroid  ;goto	goto end_     ;No, then exit from interrupt service routine
    comf    value_timer1H
    comf    value_timer1L
    clrf	counter
    goto end_create_asteroid

locateMeteor:
    clrf WREG
    movlw   b'00000111' 
    andwf   value_timer1L,0
    btfss value_timer1L,2
    goto check0to3
    goto check4to7
    
check4to7:
    btfss value_timer1L,1
    goto check4to5
    goto check6to7
    
check6to7:
    btfss value_timer1L,0
    goto check6
    movlw   b'00000010'  ;check7
    goto    moduloDone
check6:
    movlw   b'00000001'
    goto    moduloDone
check4to5:
    btfss value_timer1L,0
    goto check4
    movlw   b'00100000' ;check5
    goto    moduloDone
check4:    
    movlw   b'00010000'
    goto    moduloDone
    
check0to3:
    btfss value_timer1L,1
    goto check0to1
    goto check2to3
    
check2to3:
    btfss value_timer1L,0
    goto check2
    movlw   b'00001000'  ;check3
    goto    moduloDone
check2:
    movlw   b'00000100'
    goto    moduloDone
check0to1:
    btfss value_timer1L,0
    goto check0
    movlw   b'00000010' ;check1
    goto    moduloDone
check0:    
    movlw   b'00000001'
    goto    moduloDone

moduloDone:
    ;call modtable
    movwf gMeteor
    goto end_locateMeteor


setMidLimiter:
    movlw   d'50'
    cpfsgt  counter_last            ; check for 10th meteor
    goto    checkAfter30
    movlw   d'2'                    ; 5 to the w 
    movwf   mid_limiter             ;
    goto end_setMidLimiter
checkAfter30:
    movlw   d'30'
    cpfsgt  counter_last            ; check for 10th meteor
    goto    checkAfter10
    movlw   d'3'                    ; 5 to the w 
    movwf   mid_limiter             ;
    goto end_setMidLimiter
checkAfter10:
    movlw   d'10'
    cpfsgt  counter_last            ; check for 10th meteor
    goto    checkFirst10
    movlw   d'4'                    ; 5 to the w 
    movwf   mid_limiter             ;
    goto end_setMidLimiter
checkFirst10:
    movlw   d'5'                    ; 5 to the w 
    movwf   mid_limiter             ;
    goto end_setMidLimiter



columnMatcher:
; FLASER VS FLASER
        movf    fLaser,0
    andwf   fMeteor,0
    movwf   number
    movlw   b'00000000'
    cpfseq  number
    incf    score
    
    movf    fLaser, 0
    xorwf   fMeteor,0  ; aLaser xor bMeteor
;    cpfseq  fLaser
;    incf    score
    
    andwf   fLaser   ; aLaser and(aLaser xor bMeteor) -> cakismayan lazerler
    andwf   fMeteor   ; bMeteor and (aLaser xor bMeteor) -> cakismayan meteorlar

    
; ELASER VS ELASER
        movf    eLaser,0
    andwf   eMeteor,0
    movwf   number
    movlw   b'00000000'
    cpfseq  number
    incf    score
    
    movf    eLaser, 0
    xorwf   eMeteor,0  ; aLaser xor bMeteor
    ;cpfseq  eLaser
    ;incf    score
    andwf   eLaser   ; aLaser and(aLaser xor bMeteor) -> cakismayan lazerler
    andwf   eMeteor   ; bMeteor and (aLaser xor bMeteor) -> cakismayan meteorlar


; DLASER VS DLASER
        movf    dLaser,0
    andwf   dMeteor,0
    movwf   number
    movlw   b'00000000'
    cpfseq  number
    incf    score
    
    movf    dLaser, 0
    xorwf   dMeteor,0  ; aLaser xor bMeteor
    ;cpfseq  dLaser
    ;incf    score
    andwf   dLaser   ; aLaser and(aLaser xor bMeteor) -> cakismayan lazerler
    andwf   dMeteor   ; bMeteor and (aLaser xor bMeteor) -> cakismayan meteorlar


; CLASER VS CLASER
    movf    cLaser,0
    andwf   cMeteor,0
    movwf   number
    movlw   b'00000000'
    cpfseq  number
    incf    score    
    
    movf    cLaser, 0
    xorwf   cMeteor,0  ; aLaser xor bMeteor
    ;cpfseq  cLaser
    ;incf    score
    andwf   cLaser   ; aLaser and(aLaser xor bMeteor) -> cakismayan lazerler
    andwf   cMeteor   ; bMeteor and (aLaser xor bMeteor) -> cakismayan meteorlar
    

; BLASER VS BMETEOR
    movf    bLaser,0
    andwf   bMeteor,0
    movwf   number
    movlw   b'00000000'
    cpfseq  number
    incf    score
    
    movf    bLaser, 0
    xorwf   bMeteor,0  ; aLaser xor bMeteor
    ;cpfseq  bLaser
    ;incf    score
    andwf   bLaser   ; aLaser and(aLaser xor bMeteor) -> cakismayan lazerler
    andwf   bMeteor   ; bMeteor and (aLaser xor bMeteor) -> cakismayan meteorlar
    



; fLASER vs gMETEOR    
    movf    fLaser,0
    andwf   gMeteor,0
    movwf   number
    movlw   b'00000000'
    cpfseq  number
    incf    score
    
    movf    fLaser, 0
    xorwf   gMeteor,0  ; aLaser xor bMeteor
    ;cpfseq  fLaser bence bunun score sayılması lazim
    ;incf    score
    andwf   fLaser   ; aLaser and(aLaser xor bMeteor) -> cakismayan lazerler
    andwf   gMeteor  ; bMeteor and (aLaser xor bMeteor) -> cakismayan meteorlar
    
;movwf aMeteor		;aMeteora geciyor artik   
 
    ; ELASER vs FMETEOR  
    movf    eLaser,0
    andwf   fMeteor,0
    movwf   number
    movlw   b'00000000'
    cpfseq  number
    incf    score
    
    movf    eLaser, 0
    xorwf   fMeteor,0  ; aLaser xor bMeteor
    ;cpfseq  eLaser
    ;incf    score
    andwf   eLaser   ; aLaser and(aLaser xor bMeteor) -> cakismayan lazerler
    andwf   fMeteor   ; bMeteor and (aLaser xor bMeteor) -> cakismayan meteorlar
;movwf aMeteor		;aMeteora geciyor artik
    
    
    
; DLASER vs EMETEOR    
    movf    dLaser,0
    andwf   eMeteor,0
    movwf   number
    movlw   b'00000000'
    cpfseq  number
    incf    score
    
    movf    dLaser, 0
    xorwf   eMeteor,0  ; aLaser xor bMeteor
    ;cpfseq  dLaser
    ;incf    score
    andwf   dLaser  ; aLaser and(aLaser xor bMeteor) -> cakismayan lazerler
    andwf   eMeteor  ; bMeteor and (aLaser xor bMeteor) -> cakismayan meteorlar
;movwf aMeteor		;aMeteora geciyor artik
    
    
; CLASER vs DMETEOR   
    movf    cLaser,0
    andwf   dMeteor,0
    movwf   number
    movlw   b'00000000'
    cpfseq  number
    incf    score
    
    movf    cLaser, 0
    xorwf   dMeteor,0  ; aLaser xor bMeteor
    ;cpfseq  cLaser
    ;incf    score
    andwf   cLaser   ; aLaser and(aLaser xor bMeteor) -> cakismayan lazerler
    andwf   dMeteor  ; bMeteor and (aLaser xor bMeteor) -> cakismayan meteorlar
;movwf aMeteor		;aMeteora geciyor artik   
    

; BLASER vs CMETEOR  
    movf    bLaser,0
    andwf   cMeteor,0
    movwf   number
    movlw   b'00000000'
    cpfseq  number
    incf    score 
    
    movf    bLaser, 0
    xorwf   cMeteor,0  ; aLaser xor bMeteor
    ;cpfseq  bLaser
    ;incf    score
    andwf   bLaser   ; aLaser and(aLaser xor bMeteor) -> cakismayan lazerler
    andwf   cMeteor  ; bMeteor and (aLaser xor bMeteor) -> cakismayan meteorlar
;movwf aMeteor		;aMeteora geciyor artik
       
    
; ALASER vs BMETEOR    
    movf    aLaser,0
    andwf   bMeteor,0
    movwf   number
    movlw   b'00000000'
    cpfseq  number
    incf    score
    
    movf    aLaser, 0
    xorwf   bMeteor,0  ; aLaser xor bMeteor
   ; cpfseq  aLaser
   ; incf    score
    andwf   aLaser   ; aLaser and(aLaser xor bMeteor) -> cakismayan lazerler
    andwf   bMeteor  ; bMeteor and (aLaser xor bMeteor) -> cakismayan meteorlar
;movwf aMeteor		;aMeteora geciyor artik
    
    
    goto end_columnMatcher


meteorShift:
    movf    bMeteor,0
    movwf   aMeteor,0

    movf    cMeteor,0
    movwf   bMeteor,0

    movf    dMeteor,0
    movwf   cMeteor,0

    movf    eMeteor,0
    movwf   dMeteor,0

    movf    fMeteor,0
    movwf   eMeteor,0

    movf    gMeteor,0
    movwf   fMeteor,0
    clrf    gMeteor


    movf    eLaser,0
    movwf   fLaser,0

    movf    dLaser,0
    movwf   eLaser,0

    movf    cLaser,0
    movwf   dLaser,0

    movf    bLaser,0
    movwf   cLaser,0

    movf    aLaser,0
    movwf   bLaser,0
    clrf    aLaser
    goto end_meteorShift


updateLed:
    movf    aMeteor,0
    iorwf   posShip,0
    movwf   LATA
    


    movf    bMeteor,0
    iorwf   bLaser,0
    movwf   LATB

    movf    cMeteor,0
    iorwf   cLaser,0
    movwf   LATC

    movf    dMeteor,0
    iorwf   dLaser,0
    movwf   LATD

    movf    eMeteor,0
    iorwf   eLaser,0
    movwf   LATE

    movf    fMeteor,0
    iorwf   fLaser,0
    movwf   LATF
    goto end_updateLed


updateDisplay:
    movf score,0
    cpfslt  score_Prev
    goto    noChangeInScore
    ;movlw   d'152'
    movwf   score_Prev
    movlw   d'99'
    movwf   basamakKontrol100
    movlw   d'9'
    movwf   basamakKontrol10
    movf    score,0
    ;movlw   d'152'
    movwf   score_cache
    clrf    basamak1
    clrf    basamak2
    clrf    basamak3
    
yuzler:  
    movf    score_cache,0
    cpfslt  basamakKontrol100
    goto    onlar
    movlw   d'100'
    subwf   score_cache
    incf    basamak3
    goto    yuzler
onlar:
    movf    score_cache,0
    cpfslt  basamakKontrol10
    goto    birler
    movlw   d'10'
    subwf   score_cache
    
    ;movwf   score_cache
    incf    basamak2
    goto    onlar
birler:
    movf    score_cache,0
    movwf   basamak1
    
    ;place 
     ; kontrol et
   
noChangeInScore: 
    movlw   d'10'
    movwf   bas10
    movlw   d'100'
    movwf   bas100
    
    movf    score,0
    cpfsgt  bas100
    goto    ucBasamak
    cpfsgt  bas10
    goto    ikiBasamak
    clrf    LATH
    bsf	    LATH,3
    goto    BIRLER
ikiBasamak:
    btfsc   LATH,3
    goto    LATH3SET
    goto    LATH1SET
ucBasamak:
    btfsc    LATH,3
    goto    LATH3SET
    btfsc   LATH,2
    goto    LATH2SET
LATH1SET:
    clrf    LATH
    bsf	    LATH,3
    goto    BIRLER
LATH2SET:
    rrncf   LATH
    goto    YUZLER
LATH3SET:
    rrncf   LATH
    goto    ONLAR
    
    

YUZLER:
    movf basamak3,0
    movwf w_table
    clrf WREG
    ;movlw b'01100110'
    ;cpfslt w_table
    btfsc w_table,3
    goto _YUZLER8to9
    goto _YUZLER0to7
_YUZLER8to9:
    btfss w_table,0
    goto _YUZLER8
    movlw b'01100111'   ;9
    goto showScoreYUZLER
    
_YUZLER8:
    movlw b'01111111'    ;8
    goto showScoreYUZLER
    
_YUZLER0to7:
    btfss w_table,2
    goto _YUZLER0to3
    goto _YUZLER4to7
    
_YUZLER4to7:
    btfss w_table,1
    goto _YUZLER4to5
    goto _YUZLER6to7
    
_YUZLER6to7:	
    btfss w_table,0
    goto _YUZLER6
    movlw   b'00000111'  ;check7
    goto    showScoreYUZLER
_YUZLER6:	
    movlw   b'01111101'
    goto    showScoreYUZLER
_YUZLER4to5:
    btfss w_table,0
    goto _YUZLER4
    movlw   b'01101101' ;check5
    goto    showScoreYUZLER
_YUZLER4:    
    movlw   b'01100110'
    goto    showScoreYUZLER
    
_YUZLER0to3:
    btfss w_table,1
    goto _YUZLER0to1
    goto _YUZLER2to3
    
_YUZLER2to3:
    btfss w_table,0
    goto _YUZLER2
    movlw   b'01001111'  ;check3
    goto    showScoreYUZLER
_YUZLER2:
    movlw   b'01011011'
    goto    showScoreYUZLER
_YUZLER0to1:
    btfss w_table,0
    goto _YUZLER0
    movlw   b'00000110' ;check1
    goto    showScoreYUZLER
_YUZLER0:    
    movlw   b'00111111'
    goto    showScoreYUZLER
    
showScoreYUZLER:
    ;BSF   LATH,1
    ;BCF	    LATH,0
    ;BCF	    LATH,2
    ;BCF	    LATH,3
    
; DELAY FOR YUZLER
;     MOVLW 50                        ; Copy 50 to W
;     MOVWF L2                    ; Copy W into L2
;LOOPYUZLER2:
;     MOVLW 80                   ; Copy 255 into W
;     MOVWF L1                    ; Copy W into L1
;LOOPYUZLER1:
;     decfsz L1,F                    ; Decrement L1. If 0 Skip next instruction
;         GOTO LOOPYUZLER1                ; ELSE Keep counting down
;     decfsz L2,F                    ; Decrement L2. If 0 Skip next instruction
;         GOTO LOOPYUZLER2                ; ELSE Keep counting down
	
	 

    movwf   LATJ
    clrf    displayFlag
    goto    end_updateDisplay
   
ONLAR:
    movf basamak2,0
    movwf w_table
    clrf WREG
    ;movlw b'01100110'
    ;cpfslt w_table
    btfsc w_table,3
    goto _ONLAR8to9
    goto _ONLAR0to7
_ONLAR8to9:
    btfss w_table,0
    goto _ONLAR8
    movlw b'01100111'   ;9
    goto showScoreONLAR
    
_ONLAR8:
    movlw b'01111111'    ;8
    goto showScoreONLAR
    
_ONLAR0to7:
    btfss w_table,2
    goto _ONLAR0to3
    goto _ONLAR4to7
    
_ONLAR4to7:
    btfss w_table,1
    goto _ONLAR4to5
    goto _ONLAR6to7
    
_ONLAR6to7:	
    btfss w_table,0
    goto _ONLAR6
    movlw   b'00000111'  ;check7
    goto    showScoreONLAR
_ONLAR6:	
    movlw   b'01111101'
    goto    showScoreONLAR
_ONLAR4to5:
    btfss w_table,0
    goto _ONLAR4
    movlw   b'01101101' ;check5
    goto    showScoreONLAR
_ONLAR4:    
    movlw   b'01100110'
    goto    showScoreONLAR
    
_ONLAR0to3:
    btfss w_table,1
    goto _ONLAR0to1
    goto _ONLAR2to3
    
_ONLAR2to3:
    btfss w_table,0
    goto _ONLAR2
    movlw   b'01001111'  ;check3
    goto    showScoreONLAR
_ONLAR2:
    movlw   b'01011011'
    goto    showScoreONLAR
_ONLAR0to1:
    btfss w_table,0
    goto _ONLAR0
    movlw   b'00000110' ;check1
    goto    showScoreONLAR
_ONLAR0:    
    movlw   b'00111111'
    goto    showScoreONLAR
    
showScoreONLAR:
    
    ;BSF   LATH,2
    ;BCF	    LATH,0
    ;BCF	    LATH,1
    ;BCF	    LATH,3
    
; DELAY FOR ONLAR
;     MOVLW 50                        ; Copy 50 to W
;     MOVWF L2                    ; Copy W into L2
;LOOPONLAR2:
;     MOVLW 80                   ; Copy 255 into W
;     MOVWF L1                    ; Copy W into L1
;LOOPONLAR1:
;     decfsz L1,F                    ; Decrement L1. If 0 Skip next instruction
;         GOTO LOOPONLAR1                ; ELSE Keep counting down
;     decfsz L2,F                    ; Decrement L2. If 0 Skip next instruction
;         GOTO LOOPONLAR2                ; ELSE Keep counting down
    movwf   LATJ
    clrf    displayFlag
    goto    end_updateDisplay     
	 
BIRLER:	 
    movf basamak1,0
    movwf w_table
    clrf WREG
    ;movlw b'01100110'
    ;cpfslt w_table
    btfsc w_table,3
    goto _BIRLER8to9
    goto _BIRLER0to7
_BIRLER8to9:
    btfss w_table,0
    goto _BIRLER8
    movlw b'01100111'   ;9
    goto showScore
    
_BIRLER8:
    movlw b'01111111'    ;8
    goto showScore
    
_BIRLER0to7:
    btfss w_table,2
    goto _BIRLER0to3
    goto _BIRLER4to7
    
_BIRLER4to7:
    btfss w_table,1
    goto _BIRLER4to5
    goto _BIRLER6to7
    
_BIRLER6to7:	
    btfss w_table,0
    goto _BIRLER6
    movlw   b'00000111'  ;check7
    goto    showScore
_BIRLER6:	
    movlw   b'01111101'
    goto    showScore
_BIRLER4to5:
    btfss w_table,0
    goto _BIRLER4
    movlw   b'01101101' ;check5
    goto    showScore
_BIRLER4:    
    movlw   b'01100110'
    goto    showScore
    
_BIRLER0to3:
    btfss w_table,1
    goto _BIRLER0to1
    goto _BIRLER2to3
    
_BIRLER2to3:
    btfss w_table,0
    goto _BIRLER2
    movlw   b'01001111'  ;check3
    goto    showScore
_BIRLER2:
    movlw   b'01011011'
    goto    showScore
_BIRLER0to1:
    btfss w_table,0
    goto _BIRLER0
    movlw   b'00000110' ;check1
    goto    showScore
_BIRLER0:    
    movlw   b'00111111'
    goto    showScore
    
showScore:
    ;BSF   LATH,3
    ;BCF	    LATH,0
    ;BCF	    LATH,1
    ;BCF	    LATH,2
; DELAY FOR BIRLER
;     MOVLW 50                        ; Copy 50 to W
;     MOVWF L2                    ; Copy W into L2
;LOOPBIRLER2:
;     MOVLW 80                   ; Copy 255 into W
;     MOVWF L1                    ; Copy W into L1
;LOOPBIRLER1:
;     decfsz L1,F                    ; Decrement L1. If 0 Skip next instruction
;         GOTO LOOPBIRLER1                ; ELSE Keep counting down
;     decfsz L2,F                    ; Decrement L2. If 0 Skip next instruction
;         GOTO LOOPBIRLER2                ; ELSE Keep counting down
	 
    movwf   LATJ
    clrf    displayFlag
    goto    end_updateDisplay
;    goto end_updateDisplay
    

    
isGameOver:
    movf    aMeteor,0
    cpfseq  posShip ;YERINI KONTROL ET
    goto end_isGameOver
    bsf     gameOverStatus,0
    goto end_isGameOver
    

isr:
    goto    save_registers  ;Save current content of STATUS and PCLATH registers to be able to restore them later
end_save_registers:
;;;;;;;;;;;;;;;;;;;;;;;; Timer interrupt handler part ;;;;;;;;;;;;;;;;;;;;;;;;;;
timer_interrupt:
    bsf		displayFlag,0
    
    incf	counter, f              ;Timer interrupt handler part begins here by incrementing count variable
    movf	counter, w              ;Move count to Working register
    sublw	d'5'                    ;Decrement 2 from Working register to be activate isr every 100ms
    btfss	STATUS, Z               ;Is the result Zero?
    goto	timer_interrupt_exit    ;No, then exit from interrupt service routine
    clrf	counter
    incf    counter_mid,f           ; counts how many 100ms has past
    movf	counter_mid, w          
    subwf   mid_limiter, w          ; to check whether counter_mid reached to limiter
    btfss   STATUS, Z               ;IS reached?
    goto	timer_interrupt_exit    
    clrf	counter_mid
    incf    counter_last,f          ; meteor count
    bsf isrCheck, 0

timer_interrupt_exit:
    bcf     INTCON, 2           ;Clear TMROIF
	movlw	d'61'               ;256-61=195; 195*256*5 = 249600 instruction cycle;
	movwf	TMR0
	goto	restore_registers   ;Restore STATUS and PCLATH registers to their state before interrupt occurs
end_restore_registers:
    retfie FAST

    

    
    
save_registers:
    movwf 	w_temp          ;Copy W to TEMP register
    swapf 	STATUS, W       ;Swap status to be saved into W
    clrf 	STATUS          ;bank 0, regardless of current bank, Clears IRP,RP1,RP0
    movwf 	status_temp     ;Save status to bank zero STATUS_TEMP register
    movf 	PCLATH, W       ;Only required if using pages 1, 2 and/or 3
    movwf 	pclath_temp     ;Save PCLATH into W
    clrf 	PCLATH          ;Page zero, regardless of current page
    goto end_save_registers

restore_registers:
    movf 	pclath_temp, W  ;Restore PCLATH
    movwf 	PCLATH          ;Move W into PCLATH
    swapf 	status_temp, W  ;Swap STATUS_TEMP register into W
    movwf 	STATUS          ;Move W into STATUS register
    swapf 	w_temp, f       ;Swap W_TEMP
    swapf 	w_temp, W       ;Swap W_TEMP into W
    goto end_restore_registers
    

    END
