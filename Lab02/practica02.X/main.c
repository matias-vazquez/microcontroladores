////+++++++++++++++++++++++++++++++++++++| LIBRARIES / HEADERS |+++++++++++++++++++++++++++++++++++++
#include "device_config.h"
#include <math.h>
//+++++++++++++++++++++++++++++++++++++| DIRECTIVES |+++++++++++++++++++++++++++++++++++++
#define _XTAL_FREQ 1000000
#define DELAY 100

//+++++++++++++++++++++++++++++++++++++| DATA TYPES |+++++++++++++++++++++++++++++++++++++
enum por_dir{ output, input };              // output = 0, input = 1
enum por_ACDC { digital, analog };          // digital = 0, analog = 1
enum resistor_state { set_ON, res_ON };     // set_ON = 0, res_ON = 1
enum led_state { led_OFF, led_ON };         // led_OFF = 0, led_ON = 1
enum butto_state { pushed, no_pushed };     // pushed = 0, no_pushed = 1

////+++++++++++++++++++++++++++++++++++++| ISRs |+++++++++++++++++++++++++++++++++++++
//// ISR for high priority
//void __interrupt ( high_priority ) high_isr( void );
//// ISR for low priority
//void __interrupt ( low_priority ) low_isr( void ); 

//+++++++++++++++++++++++++++++++++++++| FUNCTION DECLARATIONS |+++++++++++++++++++++++++++++++++++++
void portsInit( void );

//+++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++
void main( void ){
    portsInit();
    char molePosition, buttonStatus = 0;
    while(1){
        unsigned char num = rand() % 8 ;
        switch(num) {
            case 0:
                molePosition = 0x01;
                break;
            case 1:
                molePosition = 0x02;
                break;
            case 2:
                molePosition = 0x04;
                break;
            case 3:
                molePosition = 0x08;
                break;
            case 4:
                molePosition = 0x10;
                break;
            case 5:
                molePosition = 0x20;
                break;
            case 6:
                molePosition = 0x40;
                break;
            default:
                molePosition = 0x80;
                break;
        }
        LATA = molePosition;
        __delay_ms(1000);
        buttonStatus = ~PORTD;
        if (molePosition == buttonStatus)
        {
            for (unsigned char i = 0; i < 7; i++){
                LATA = (unsigned char) pow(2, i);
                __delay_ms(DELAY);
            }
            for (unsigned char i = 7; i > 0; i--){
                LATA = (unsigned char) pow(2, i);
                __delay_ms(DELAY);
            }   
            LATA = 0x01;
            __delay_ms(DELAY);
        }
    }
}

//+++++++++++++++++++++++++++++++++++++| FUNCTIONS |+++++++++++++++++++++++++++++++++++++
void portsInit( void ){
    ANSELA = digital;                       // Set port A as Digital
    TRISA  = 0x00;                          // RA as Output for LEDs
    ANSELD = digital;                       // Set port D as Digital
    TRISD  = 0xFF;                          // RD as Input for push buttons

}