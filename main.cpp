/* 
Convert the flow chart to allow the LED's to toggle. Button release will not make the state change. 
The end result of the program will make the button act as a switch. when you press the button the LEDs toggle, button release has no effect.
When the blue button is pressed the LED's Toggle to the opposite state. When it is pressed again they toggle back to the original state. 
*/

#include "mbed.h"

// Define the button input and the two LED outputs 
DigitalIn buttn(PC_13);
DigitalOut led1(PA_5);
DigitalOut led2(PB_14);

int main() {
    led1 = 1; // set intial value of LED 1 to 'on'
    led2 = 0; // set intial value of LED 2 to 'off'

    int my_flag = 0; // sets my_flag to 0
    int buttn_pressed = 0; // button press state to 0
    
    while (1) {
        if(buttn == 0 && buttn_pressed == 0){ // if button is pressed 
            my_flag = 1; // sets my_flag to 1
            buttn_pressed = 1; 
            }
        else if (buttn == 1){ // if button is released
            buttn_pressed = 0; // resets the button press flag 
        }
        if(my_flag == 1){ // sets the flag 
            led1 = !led1; // toggle led 1
            led2 = !led2; // toggle led 2
            my_flag = 0; // resets my_flag to zero 
            printf("Blue Button has been pressed, toggling LED state\r\n"); // prints the statement when the blue button has been pressed.
        }   
    }              
}       
        
    
