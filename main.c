/*
    made by Iwan van Bezouw 21010099 student HHS
 */

#include <avr/io.h>
#include "h_bridge_enA.h"
#include "h_bridge_enB.h"

//Defines Switches:
//#define Sensor_voorkant P.. //...
//#define Sensor_linksonder P.. //...
//#define Sensor_rechtsonder P.. //...
#define Sensor_rechts PA6 //pin 28
#define Sensor_links PA5 //pin 27

/*
//Defines Leds:
#define Led_1_rechts PL7
#define Led_2_links PL6
#define Led_3 PL5
#define Led_4 PL4
#define Led_intern PB7 //indicatie led

//Defines Buzzer
#define Buzzer PL0
void init_Leds(void)
{
    DDRL |= (1 << Led_1_rechts);
    DDRL |= (1 << Led_2_links);
    DDRL |= (1 << Led_3);
    DDRL |= (1 << Led_4);
    DDRB |= (1 << Led_intern);
}
*/
void init_Switches(void)
{
    //DDR.. &= ~(Sensor_voorkant)
    //DDR.. &= ~(Sensor_rechtsonder)
    //DDR.. &= ~(Sensor_linksonder)
    DDRA &= ~(Sensor_rechts);
    DDRA &= ~(Sensor_links);
}
/*
void init_Buzzer(void)
{
    DDRL |= (Buzzer);
}
*/
void init_voids(void)
{
//    init_Leds();
    init_Switches();
//    init_Buzzer();
    init_h_bridge_enA();
    init_h_bridge_enB();
}

int main(void)
{
    init_voids();

    while(1)
    {
        if(PINA & (1 << Sensor_rechts))
        {
          //  PORTB |= (1 << Led_intern);
            h_bridge_set_percentage_enA(0);
            h_bridge_set_percentage_enB(0);
        }

        else if(PINA & (1 << Sensor_links))
        {
           // PORTB |= (1 << Led_intern);
            h_bridge_set_percentage_enA(0);
            h_bridge_set_percentage_enB(0);
        }
        else
        {
         //   PORTB &= ~(1 << Led_intern);
            h_bridge_set_percentage_enA(0);
            h_bridge_set_percentage_enB(0);
        }


        /*if(PIN.. & (1 << Sensor_voorkant))
        {
          //  PORTB |= (1 << Led_intern);
            h_bridge_set_percentage_enA(0);
            h_bridge_set_percentage_enB(0);
        }
        else
        {
         //   PORTB &= ~(1 << Led_intern);
            h_bridge_set_percentage_enA(0);
            h_bridge_set_percentage_enB(0);
        }*/
    }
}
