// SMART TROLLEY STM32

#include <LiquidCrystal.h>    // to include lcd library    
#include<string.h>       // allows you to use and manipulate strings of text in more complex ways than the string character array does                               

const int rs = PB11, en = PB10, d4 = PB0, d5 = PB1, d6 = PA2, d7 = PA3;
 //  declaring pins of lcd with stm 32                                                      
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // assigning pins of lcd which we are going to use
int count = 0 ; // declaring and initialize variable count with 0 // int used for storing integer as count
char input[12]; // storing character  datatype in input variable with list

int count_prod = 0; //declaring and initialize variable count product with 0 
double total = 0; // using double data type for getting 2 numbers after decimal //total variable for storing price data


void setup() // inside this code will run only once
{
    lcd.begin(16, 2); // start lcd                 
    Serial1.begin(9600);     // opens serial port, sets data rate to 9600 bps (bits per second ) baud rate         
    pinMode(PA10,INPUT);    // pin PA10 of stm 32 connected to Tx(transmission pin) of rfid module // so it snds data to stm 32 as input 
  
    lcd.print("Smart Trolley");       //Prints at LCD display
    lcd.setCursor(0, 1);               //Set courser to second line
    lcd.print("Group 6");           //Prints at LCD display
    delay(5000);                       //Delay for 5 Seconds
    lcd.clear();                       //Clears LCD display
    lcd.setCursor(0,0);                //Sets cursor at First Line
   // lcd.print("RFID TAG NO:");         //Prints at LCD display
    //lcd.setCursor(0,1);                //Sets cursor at Second line
}

void loop() // this is void loop it will run again and again till power supply is on
{
  if(Serial.available()) // if condition to check serial monitor. i.e. to check rfid is reading or not
  {
    count=0; // count how many rfid digit has been read // RFID number is of 13 digit 
    while(Serial.available()&& count <12) // while condition if RFID number and serial available is of 13 digit
    {
      input[count] = Serial.read(); // store the number bit by bit in input  
      count++;
      delay(5); // with delay of 5 milli sec
      }
// now the RFID tag is stored in input list 
 
// if condition   
    if( input[0] == '0' && input[1] == '9' && input[2] == '0' && input[3] == '0' && 
        input[4] == '2' && input[5] == 'B' && input[6] == 'C' && input[7] == '1' && 
        input[8] == '4' && input[9] == 'D' && input[10] == 'A' && input[11] == 'E'       
      ) // using if condition to check rfid number // if that number rfid card is scanned then print the followin 09002BC14DAE
      {
        lcd.setCursor(0,0); // to set lcd cursor 
        lcd.print("Butter Added "); // to print on lcd
        lcd.setCursor(0,1); // set cursor on seccond line
        lcd.print("Price=40"); // print on second line
        total=total+40;// store total price in total variable i.e whatever the previous price + 40 rs.
        count_prod++; // to count total product i.e whatever the previous price + one more product
        }
        
        if( input[0] == '0' && input[1] == '9' && input[2] == '0' && input[3] == '0' && 
        input[4] == '2' && input[5] == 'B' && input[6] == 'B' && input[7] == '9' && 
        input[8] == '2' && input[9] == 'A' && input[10] == 'B' && input[11] == '1'       
      )
      {
        lcd.setCursor(0,0);
        lcd.print("Biscuit Added ");
        lcd.setCursor(0,1);
        lcd.print("Price=10");
        total=total+10;
        count_prod++;
        }

        if( input[0] == '0' && input[1] == '9' && input[2] == '0' && input[3] == '0' && 
        input[4] == '2' && input[5] == 'B' && input[6] == 'F' && input[7] == '0' && 
        input[8] == '0' && input[9] == '6' && input[10] == 'D' && input[11] == '4'       
      ) // condition to display total price 09002BF006D4
      {
        lcd.clear();// clear lcd
        lcd.setCursor(0,0);
        lcd.print("Total Price ");
        lcd.setCursor(0,1);
        lcd.print(total);
        delay (4000);

        lcd.setCursor(0,0);
        lcd.print("  Thanks For");
        lcd.setCursor(0,1);
        lcd.print( "   Visiting ");
        lcd.clear();
        
        
        }
    }
    
    } 
