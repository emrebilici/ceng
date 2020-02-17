
/*
Emre Bilici 2171353
Onur Aydin 
At the beginning of the planning, we think that writing code with separate functions will make our job easy. 
So we write firstly 3 seconds waiting. Then enter voters screen. Then, during voting there should be a loop.
This loop should update seven segment, update lcd since both of them can be changed by interrupts. 
For blinking cursor and remaining time, we write separate functions. 
This functions are in the voting function.
If the remaining time equals to 00, a flag is set in the remainingTime function
and then upper part of lcd is stopped and blinking is stopped. 
Also if all voters vote, voting function is done. 
In the ISR, in the rb interrupt we set flag for the rb6 and rb7. 
So ın the main code, we can understand which button does interrupt and get action according to it.
In the adc interrupt, we decide which candidate is selected. 
We have 3 arrays for 7 segment display values, id numbers and vote numbers.
*/



#include <xc.h>
//#include <p18cxxx.h>
#pragma config OSC = HSPLL, FCMEN = OFF, IESO = OFF, PWRT = OFF, BOREN = OFF, WDT = OFF, MCLRE = ON, LPT1OSC = OFF, LVP = OFF, XINST = OFF, DEBUG = OFF

#define _XTAL_FREQ   40000000

#include "Includes.h"
#include "LCD.h"




unsigned int rb6State = 0;
unsigned int rb6Flag = 0;
unsigned int rb7Flag = 0;
unsigned int stage = 1;
unsigned int increaseVote = 0;
unsigned int secondDigit = 0;
unsigned int firstDigit = 0;
unsigned int timerSecondDigit = 0;
unsigned int timerFirstDigit = 0;
unsigned int stopBlink = 0;
unsigned int switchFlag = 0;
unsigned int secondChange = 0;
unsigned int tmr1Counter = 20;
unsigned int tmr0250Counter = 50;
unsigned int tmr0100Counter = 20;
unsigned int blinkState = 0;
unsigned int canIndex = 0;
unsigned int maxIndex = 0;
unsigned int canValue = 0;
unsigned int maxCache = 0;
unsigned int segArr[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01100111};
unsigned int votePool[8] = {0,0,0,0,0,0,0,0};
unsigned int idPool[8] = {18,64,34,23,33,67,63,99};
unsigned int lcdFlag = 0;
unsigned int rb7counter = 0;
unsigned int curVote = 0;
unsigned int curCan = 0;
unsigned int maxVoters = 0;
unsigned int sum = 0;
unsigned int sumFlag = 0;
unsigned int firstVote = 0;
unsigned int segIndex = 0;
unsigned int kaydir = 0;
unsigned int segPre = 0;
unsigned int sec3Flag = 0;
unsigned int timerStage = 1;
unsigned int sec3Counter = 0;

void init();
void initTMR();
void initINTR();
void initADC();
void wait3seconds();
void firstLCD();
void rbIntEnable();
void initializeVoters();
void voteStartingLcd();
void remainingTime();
void voting();
void blink();
void lcdUpdate();
void update7segment();
void results();
// Main Function
void main(void)
{

    InitLCD();          // Initialize LCD in 4bit mode
    ClearLCDScreen();   // Clear LCD screen
    init();
    initINTR();
    initTMR();
    initADC();
    firstLCD();       // show electrovote on the screen and wait for re1(push and release) to return
    GIE = 1;
    wait3seconds();     // 3 second busy waiting with directly loops
    GIE = 1;
    initializeVoters(); // in this part, first line will be set, number of voters will be set by user
    voteStartingLcd();  // starting screen is set
    voting();           // all operations related to 90 second
    results();          // after 90 seconds only adc related operations continue
    

    

    
}


void firstLCD() {
    
    WriteCommandToLCD(0x80);   // G
    WriteStringToLCD(" #Electro Vote# ");    // Write Hello World on LCD
    WriteCommandToLCD(0xC0); // Goto to the beginning of the second line
    WriteStringToLCD(" ############## ");   // Write Hello World on LCD
    while(1){
        
        if(PORTEbits.RE1==0){  // clr oldugu icin her turlu giriyor
            while(1){ // set olana kadar burda donuyor
                update7segment();
                if(PORTEbits.RE1){ // set olursa cik
                    break;
                }  
            }
        }
        break; // re1 birakilirsa buna girip buyuk while dan cikcak
    }

}
void wait3seconds(){
    TMR0ON = 1;
    while(1){
        if(sec3Flag){
            break;
        }
    }
    TMR0ON = 0;
 
}
void rbIntEnable(){
    INTCONbits.RBIE = 1;   //enable rb interrupts
    INTCONbits.RBIF = 0;   //clear rb interrupt flag
    INTCON2bits.RBPU = 0;   //clear rb interrupt flag
    INTCONbits.GIE_GIEH = 1;   //clear rb interrupt flag
    INTCONbits.PEIE_GIEL = 1;   //clear rb interrupt flag
    
    
}

void initializeVoters(){
    WriteCommandToLCD(0x80);   // G
    WriteStringToLCD(" #Enter Voters# ");    // Write Hello World on LCD
    WriteCommandToLCD(0xC0); // Goto to the beginning of the second line
    WriteStringToLCD(" 00             ");   // Write Hello World on LCD
    
    while(1){
        update7segment();   // 7 segment will be - - - -
        if(rb7Flag==0){     // When rb7flag = 0, then firstdigit should be set    
            if(rb6Flag==1){     //If rb6 is pressed, first digit will increase.
                rb6Flag=0;
                if(firstDigit==9){
                    firstDigit=0;
                }
                else{
                    firstDigit++;
                }
            }
            WriteCommandToLCD(0xC1);  
            WriteDataToLCD('0'+firstDigit);

        }
        else if(rb7Flag==2 ){       //rb7 is pressed, then second digit wil be activated.
            if(rb6Flag==1){
                rb6Flag=0;
                if(secondDigit==9){
                    secondDigit=0;
                }
                else{
                    secondDigit++;
                }
               
            }
            WriteCommandToLCD(0xC2);  
            WriteDataToLCD('0'+secondDigit);

        }
        else if(rb7Flag > 2) {      // rb7Flag is pressed more than two, it will go voteStartingLcd()

            rb7Flag = 0;
            break;
        }
    }
    maxVoters = firstDigit*10 + secondDigit;       // This is the voter numbers. 
    

}

void voteStartingLcd(){
    WriteCommandToLCD(0x80);  
    WriteStringToLCD("  Time Left :90 ");    // First screen while beginning the voting
    timerFirstDigit = 9;        
    timerSecondDigit = 1;
}

void remainingTime(){       // this function is just decrease 90 seconds to 00. 
    
    secondChange = 0;
        if(timerFirstDigit == 0 && timerSecondDigit == 0 ){
            stopBlink = 1;          // If the time is up, blinking will be stopped.
            WriteCommandToLCD(0x8D);
            
            WriteDataToLCD('0');
            
            WriteCommandToLCD(0x8E);
            
            WriteDataToLCD('0');
            
        } 
        else{
            if(timerSecondDigit == 0){
                timerSecondDigit = 9;   
                timerFirstDigit--;
            }
            else{
                timerSecondDigit--;
            }
        }
    WriteCommandToLCD(0x8D);
    
    WriteDataToLCD(timerFirstDigit+'0');
    WriteCommandToLCD(0x8E);
    
    WriteDataToLCD(timerSecondDigit+'0');
    
}
  
 

void blink(){           //Each time this function is called, it show " " and, next time is called it will show ">".and this function is called each 250ms
    if(switchFlag){
        switchFlag = 0;
        blinkState = !blinkState;   //boolean blinkState
        if(blinkState){
            WriteCommandToLCD(0xC1); 
            
            WriteStringToLCD(" ");
            
        }        
        else{
            WriteCommandToLCD(0xC1); 
            
            WriteStringToLCD(">");
            
        }
    }
}

void lcdUpdate(){   //If lcdFlag = 1, this function is called and according to canIndex, it will show the candidate and vote numbers. 
    lcdFlag = 0;
switch(canIndex){
            case 0:
                
                WriteCommandToLCD(0xC2);   // Goto to the beginning of the first line                
                WriteStringToLCD("18 Poe    ");                
                WriteCommandToLCD(0xCC);   // Goto to the beginning of the first line                
                WriteStringToLCD(":");                                
                WriteCommandToLCD(0xCD);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]/10);                
                WriteCommandToLCD(0xCE);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]%10);
                break;
            case 1:
                
                WriteCommandToLCD(0xC2);   // Goto to the beginning of the first line                
                WriteStringToLCD("64 Galib  ");                
                WriteCommandToLCD(0xCC);   // Goto to the beginning of the first line                
                WriteStringToLCD(":");                                 
                WriteCommandToLCD(0xCD);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]/10);                
                WriteCommandToLCD(0xCE);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]%10);
                break;
            case 2:
                
                WriteCommandToLCD(0xC2);   // Goto to the beginning of the first line                
                WriteStringToLCD("34 Selimi ");                
                WriteCommandToLCD(0xCC);   // Goto to the beginning of the first line                
                WriteStringToLCD(":");                                
                WriteCommandToLCD(0xCD);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]/10);                
                WriteCommandToLCD(0xCE);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]%10);
                break;
            case 3:
                
                WriteCommandToLCD(0xC2);   // Goto to the beginning of the first line                
                WriteStringToLCD("23 Nesimi ");                
                WriteCommandToLCD(0xCC);   // Goto to the beginning of the first line                
                WriteStringToLCD(":");                                 
                WriteCommandToLCD(0xCD);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]/10);                
                WriteCommandToLCD(0xCE);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]%10);
                break;
            case 4:
                
                WriteCommandToLCD(0xC2);   // Goto to the beginning of the first line                
                WriteStringToLCD("33 Hatayi ");                
                WriteCommandToLCD(0xCC);   // Goto to the beginning of the first line                
                WriteStringToLCD(":");                                 
                WriteCommandToLCD(0xCD);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]/10);                
                WriteCommandToLCD(0xCE);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]%10);
                break;
            case 5:
                
                WriteCommandToLCD(0xC2);   // Goto to the beginning of the first line                
                WriteStringToLCD("67 Zweig  ");                
                WriteCommandToLCD(0xCC);   // Goto to the beginning of the first line                
                WriteStringToLCD(":");                                 
                WriteCommandToLCD(0xCD);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]/10);                
                WriteCommandToLCD(0xCE);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]%10);
                break;
            case 6:
                
                WriteCommandToLCD(0xC2);   // Goto to the beginning of the first line                
                WriteStringToLCD("63 Nabi   ");                
                WriteCommandToLCD(0xCC);   // Goto to the beginning of the first line                
                WriteStringToLCD(":");                                 
                WriteCommandToLCD(0xCD);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]/10);                
                WriteCommandToLCD(0xCE);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]%10);
                break;
            case 7:
                
                WriteCommandToLCD(0xC2);   // Goto to the beginning of the first line                
                WriteStringToLCD("99 Austen ");                
                WriteCommandToLCD(0xCC);   // Goto to the beginning of the first line               
                WriteStringToLCD(":");                                 
                WriteCommandToLCD(0xCD);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]/10);                
                WriteCommandToLCD(0xCE);   // Goto to the beginning of the first line                
                WriteDataToLCD('0'+votePool[canIndex]%10);
                break;
        }
}

void voting(){
    TRISB6 = 0;
    TMR1ON = 1;
    TMR1IE = 1;
    TMR0ON = 1;
    stage = 2;
    maxCache= 0;

    while(1){

        if(sumFlag){  //total number of votes == votes when voting() function
            break;
        }
        
        if(lcdFlag){
            lcdUpdate();
        } 
        //        
        // zamanlayici
        if(secondChange){               // each 1 second, secondChange = 1

            remainingTime();
        }
        //
        //  blink
        if(stopBlink==0){           //if time is counting
            
            blink();
        }
        else{                       // if time is up continuously show ">" 

            break;       
        }
        

    }
    WriteCommandToLCD(0xC1); // Goto to the beginning of the second line
    WriteStringToLCD(">");
}

void results(){         // when voting stage is end
    RBIE = 0;
    TMR1IE = 0;

    while(1){
        if(lcdFlag){
                lcdUpdate();
        } 
        
    }
}

void update7segment(){  // her cagrildiginda bir sonraki 7 segment yaniyor. bu da her tmr0 interrupta girdiginde cagriliyor.
    LATH = LATH & 0xF0;
    segIndex++;
    if(segIndex==4){
            segIndex =0;
        }
        
    if(firstVote){
        curVote = votePool[maxIndex];       // this is max vote number
        curCan = idPool[maxIndex];          // this is the candidate who takes max vote

        
        switch(segIndex){
                case 0:
                    LATH3 = 0;
                    LATJ = segArr[curCan/10];       // according to number, segArr choose the proper 7segment display binary.
                    LATH0 = 1;
                    break;
                case 1:
                    LATH0 = 0;
                    LATJ = segArr[curCan%10];
                    LATH1 = 1;
                    break;
                case 2:
                    LATH1 = 0;
                    LATJ = segArr[curVote/10];
                    LATH2 = 1;
                    break;
                case 3:
                    LATH2 = 0;
                    LATJ = segArr[curVote%10];
                    LATH3 = 1;
                    break;

            }
    }
    else{

        switch(segIndex){       // before first vote is sent, print - - - -
        case 0:
            LATH3 = 0;
            LATJ = 0b01000000;
            LATH0 = 1;
            break;
        case 1:
            LATH0 = 0;
            LATJ = 0b01000000;
            LATH1 = 1;
            
            break;
        case 2:
            LATH1 = 0;
            LATJ = 0b01000000;
            LATH2 = 1;
            break;
        case 3:
            LATH2 = 0;
            LATJ = 0b01000000;
            LATH3 = 1;
            break;
            
    }

    }
}




void init(){
    GIE = 0;    //global interrupt is disabled

    TRISE1 = 1; // conver re1 to input

    INTCON = 0; // clear INTCON    
    TRISC = 0;
    PORTC = 0;
    LATC = 0;
    TRISH4 = 1;   
    TRISJ = 0;                      
    LATJ = 0;                       
    LATH = 0;                       
    TRISH = TRISH & 0b11110000;  // sadece sagdaki 4 bit output olsun onlara ihtiyac var


}    

void initTMR(){ // tmr alakali
    TMR0IE = 1; // tmr0 interrupt enable edildi
    T0CON = 0;  // registeri clear ettik
    T08BIT = 1; // 8 bit counter
    PSA = 0;    //prescaler kullanmak icin aktif ettik
    T0PS0 = 1; // bu uc satir prescale icin 111 -> 1:256 
    T0PS1 = 1;
    T0PS2 = 1;
    TMR0 = 61; //(256-61)*256 49920 0.05 ms  diyelim
    T0IF = 0; //flagi clearladik her ihtimale karsi
    PEIE = 1; // peripheral enable edildi ama tmr sectionuna koymasak daha mantikli olabilir kontrol edelim
    TMR1IE = 1; //tmr1 interrupt enable edildi
    TMR1L = 220; // (2^16 -(11*256 + 220))*8 for 0.05 second bekliyo ama hesabimiza gore 0.5 olmali?
    TMR1H = 11;  
    T1CKPS1 = 1; // prescale 8 olsun diye
    T1CKPS0 = 1;
}


void initINTR(){

    TRISB = 0;  // ilk hepsini output yapip sonra gerekli rb7 rb6 yi setledik
    TRISB6 = 1; 
    TRISB7 = 1; 
    PORTB = 0;  
    LATB = 0;
    RBIF = 0; // ilk flag clear edip sonra int enable etti gereksiz cagrilmasin diye diye
    RBIE = 1;      
    RBPU = 0;   // bunu arastiralim bu olmadan calismiyo

}


void initADC(){// configurations are taken from the recitation

    CHS3 = 1;   // bununla alakali pek bilgi bulamadik datasheette, recitte de bahsedilmedi cok pic18 de implemente edilenlerin  
                // ilki diye sectik calisti oyle biraktik sonra
    CHS2 = 1; 
    ADIE = 1;       //Enable ADCON
    ACQT2 = 1;      //12
    ACQT1 = 0;
    ACQT0 = 1;
    ADIF = 0;      
    ADFM = 1;      //right
    
    ADCS2 = 0;     
    ADCS1 = 1;
    ADCS0 = 0;
    
    ADON = 1;      //ADCON is on

}


void __interrupt() ISR(void){

    if(TMR0IE && TMR0IF){ //tmr0 for blinking and 3 seconds waiting
        update7segment();
        if (timerStage==1){ // 3 saniye dolmasini buradan kontrol ediyoruz. digerleri de calismasin diye ayri stage yaptik
            sec3Counter++;
            if(sec3Counter == 600){
                sec3Flag = 1;
                timerStage = 2;
            }
        }
        
        else if (timerStage==2){ // voting sirasinda kullanilan islemlerin stagei
        
        tmr0250Counter--;
        tmr0100Counter--;
        
        if(!tmr0100Counter){
            tmr0100Counter = 20;
            GO = 1; // adc conversation baslat
        }
        if(!tmr0250Counter){
            tmr0250Counter = 50;
            switchFlag = 1; // > yaniktan sonuke  geciriyor vice versa
        }
        }
        TMR0 = 61; // 256 - 61
        T0IF = 0; // clear interrupt flag
        return;
        
        


    }else if(TMR1IE && TMR1IF){ //1 saniyelik araliklar burada
        tmr1Counter--;
        if(!tmr1Counter){ // 0.05 saniyede bir intflag enable oluyor, o yüzden 20. gelisini kontrol ediyoruz
            tmr1Counter = 20;
            secondChange = 1; // scond digit yani birler basamagi degissin flagi bu
        }
        TMR1H = 11;
        TMR1L = 220;
        TMR1IF=0;
       // return;
    


        
    }else if(ADIE && ADIF){             // AD interrupt
                                        //  according to potentiometer, it will assign a number between 0 and 7
        canValue = ADRES;                   
        if(canValue >=0 && canValue < 128){
            canIndex = 0;
        }else if(canValue >=128 && canValue < 256){
            canIndex = 1;
        }else if(canValue >=256 && canValue < 384){
            canIndex = 2;
        }else if(canValue >=384 && canValue < 512){
            canIndex = 3;
        }else if(canValue >=512 && canValue < 640){
            canIndex = 4;
        }else if(canValue >=640 && canValue < 768){
            canIndex = 5;
        }else if(canValue >=768 && canValue < 896){
            canIndex = 6;
        }else if(canValue >=896 && canValue < 1024){
            canIndex = 7;
        }

        lcdFlag = 1; // adc de
        ADIF = 0;
        return;
    }else if(RBIE && RBIF){ //when rb7 or rb6 is pressed
        RBIF = 0;

        if (stage == 1) // enter voters part
        {
            if(PORTBbits.RB6){      // rb6 setse ya rb6 yeni basilmistir ya da rb6 basili iken rb7 de degisiklik olmustur
                if (rb6State == 1)// daha onceden basili imis demek dedgisim rb7 da
                {
                    if(PORTBbits.RB7){  // rb7 ise yeni basilmistir basamak degisimi icin flag arttir
                        rb7Flag += 1; 

                    }
                }
                else if (rb6State == 0) // basili degilmis demekki yeni basilmis
                {
                    rb6State = 1;
                    rb6Flag = 1;
                }
            }
            else if(!PORTBbits.RB6) // basili degilse ya yeni cakilmis ya da rb7 da degisim var
            {
                if (rb6State == 1)
                {
                    rb6State = 0;
                }
                else if (rb6State == 0) // onceden basili degilmis demekki degisim rb7 de
                {
                    if(PORTBbits.RB7){  // demekki yeni basilmis
                        rb7Flag += 1; 
 
                    }
                }
            }




        }
        else if(stage == 2)
        {            
            if(PORTBbits.RB7){       
                
                
                rb7counter++;
                
                if (rb7counter==2){
                    rb7counter=0;
                    sum++;
                    if(maxVoters<=sum){ // oylama bitirme flagi
                        sumFlag = 1;
                    }
                    if(maxVoters!=0){
                        votePool[canIndex]++;
                        firstVote = 1;
                    }
                }
                else{
                    //return;
                }
                                
                
                for(int i = 0; i<8;i++){
                    if(votePool[i] > maxCache){ // onceki aramadan kalan maks degerden daha buyuk bi deger cikmis mi diye 
                    //    sum += votePool[i];   // bakilip eger varsa degisim yapilir
                        maxCache = votePool[i];
                        maxIndex = i;
                    }
                }
                lcdFlag = 1;

                
            }
        }
        return;
    }
    return;
}
