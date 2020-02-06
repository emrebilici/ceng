/*
 * File:   labexamahazirlik.c
 * Author: e2171353
 *
 * Created on May 3, 2019, 2:01 PM
 */


#include <xc.h>

unsigned int tmr0counter = 0;
unsigned int ledflag = 0;
unsigned int tmr1counter = 0;
void init();
void initializeTMR();

void main(void) {
    init();
    initializeTMR();
    while(1){
        if(ledflag){
            LATB4 = 1;
        }
        else{
            LATB4 = 0;
        }
    }
}

void initializeTMR(){
    T0CON =  0;
    T08BIT = 1;
    T0PS0 = 1;
    T0PS1 = 1;
    T0PS2 = 1;
    TMR0 = 61; // 5MS = 256*(256-61)---> 50000 / 256
    PSA = 0;
    TMR0IE = 1;
    
    TMR0ON = 0;
    
    T1CKPS0 =1 ;
    T1CKPS1 = 1;
    TMR1H = 11;         //50000/8 = 62500. 2**16-62500 = 3036. 
    TMR1L = 220;           //256*11+220 = 3036. HESAP = 8*(62500)
    TMR1IE = 1;
    TMR1ON = 1;
    GIE = 1;
    PEIE = 1;
    
}
void init(){
    GIE = 0;
    INTCON = 0;
    //RBPU = 1;
    TRISB = 0;
    TRISB = 0b00000000;
    
    ADIE = 1;
    CHS0 = 1;
    CHS1= 1;
    CHS2 = 1;
    ADCS0 = 0;
    ADCS1 = 1;
    ADCS2 = 0;
    ACQT2 = 1;
    ACQT1 = 0;
    ACQT0 = 1;
    ADFM = 1;
    
    
    ADON = 1;
    
}
void __interrupt() ISR(void){
    if(TMR0IE && TMR0IF){
        TMR0IF = 0;
        tmr0counter++;
        if(tmr0counter==20){
            ledflag = !ledflag;
            tmr0counter = 0;
        }
        TMR0 = 61;
    }
    if(TMR1IE && TMR1IF){
        TMR1IF = 0;
        tmr1counter++;
        if(tmr1counter==20){
            ledflag = !ledflag;
            tmr1counter = 0;
        }
        TMR1 = 3036;
    }
    if(ADIE && ADIF){
        ADIF = 0;
    }
    if(RBIE && RBIF){
        RBIF = 0;
        if()
    }
    
}