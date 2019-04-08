#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 24, 26, 28, 30, 32);
/**
 * I2C/IIC LCD Serial Adapter Module Example
 * Tutorial by http://mklec.com
 * 
 * Instructions at http://blog.mklec.com/how-to-use-iici2c-serial-interface-module-for-1602-lcd-display
 *
 * This uses the Liquid Crystal library from https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads GNU General Public License, version 3 (GPL-3.0)
 * Pin Connections: 
 *      SCL = A5
 *      SDA = A4
 *      VCC = 5V
 *      GND = GND
 */
 #include <Keypad.h>
#include <Wire.h>
//#include <LCD.h>
//#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified module


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'?','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


int locker1 = 0;        //initialize lockers to be locked
int locker2 = 0;
int locker3 = 0;
int locker4 = 0;
int locker5 = 0;



const int limit_switch1_pin = 10;      // the number of the limit_switch1 pin  
const int limit_switch2_pin = 11;      // Active Low
const int limit_switch3_pin = 12; 
const int limit_switch4_pin = 13; 
const int limit_switch5_pin = 14; 


int limit_switch1;                     // variable to read
int limit_switch2;
int limit_switch3;
int limit_switch4;
int limit_switch5;

const int solenoid1_N1 = 40;          // the number of the solenoid1 pin (locks @ low) 
const int solenoid1_N2 = 41;

const int solenoid2_N3 = 42;          //outputs
const int solenoid2_N4 = 43;

const int solenoid3_N5 = 44;          //outputs
const int solenoid3_N6 = 45;

const int solenoid4_N7 = 46;          //outputs
const int solenoid4_N8 = 47;

const int solenoid5_N9 = 48;          //outputs
const int solenoid5_N10 = 49;


int counter = 0;

char locker1_pass[4] = {'0','0','0','0'};             /////these cant be in void loop because every time they will be null
char locker2_pass[4] = {'0','0','0','0'};
char locker3_pass[4] = {'0','0','0','0'};
char locker4_pass[4] = {'0','0','0','0'};
char locker5_pass[4] = {'0','0','0','0'};

char locker1_pass_admin[4] = {'1','9','7','3'};
char locker2_pass_admin[4] = {'2','9','7','3'};
char locker3_pass_admin[4] = {'3','9','7','3'};
char locker4_pass_admin[4] = {'4','9','7','3'};
char locker5_pass_admin[4] = {'5','9','7','3'};
////////////////////////////////////////////////////ZzZ/////////////////////////////////////////////////////////ana hoooooon

void lock1(){
  lcd.clear();
  limit_switch1 = digitalRead(limit_switch1_pin);
  if(limit_switch1==LOW){
     digitalWrite(solenoid1_N1,HIGH);
     digitalWrite(solenoid1_N2,LOW);
     delay(200);
     digitalWrite(solenoid1_N1,LOW);
     digitalWrite(solenoid1_N2,LOW);
    
     locker1 = 0;
    lcd.setCursor(0,0);
    lcd.print("Locked           ");
    delay(200);
  }else{
    if(limit_switch1==HIGH)
    lcd.setCursor(0,0);
    lcd.print("Close the locker");
    lcd.setCursor(0,1);
    lcd.print("and press A     ");
    }
}
  
void lock2(){
  lcd.clear();
  limit_switch2 = digitalRead(limit_switch2_pin);
  if(limit_switch2==LOW){
     digitalWrite(solenoid2_N3,HIGH);
     digitalWrite(solenoid2_N4,LOW);
     delay(200);
     digitalWrite(solenoid2_N3,LOW);
     digitalWrite(solenoid2_N4,LOW);
    
     locker2 = 0;
    lcd.setCursor(0,0);
    lcd.print("Locked           ");
    delay(200);
  }else{
    if(limit_switch2==HIGH)
    lcd.setCursor(0,0);
    lcd.print("Close the locker");
    lcd.setCursor(0,1);
    lcd.print("and press A     ");
    }
}

void lock3(){
  lcd.clear();
  limit_switch3 = digitalRead(limit_switch2_pin);
  if(limit_switch3==LOW){
     digitalWrite(solenoid3_N5,HIGH);
     digitalWrite(solenoid3_N6,LOW);
     delay(200);
     digitalWrite(solenoid3_N5,LOW);
     digitalWrite(solenoid3_N6,LOW);
    
     locker3 = 0;
    lcd.setCursor(0,0);
    lcd.print("Locked           ");
    delay(200);
  }else{
    if(limit_switch3==HIGH)
    lcd.setCursor(0,0);
    lcd.print("Close the locker");
    lcd.setCursor(0,1);
    lcd.print("and press A     ");
    }
}

void lock4(){
  lcd.clear();
  limit_switch4 = digitalRead(limit_switch4_pin);
  if(limit_switch2==LOW){
     digitalWrite(solenoid4_N7,HIGH);
     digitalWrite(solenoid4_N8,LOW);
     delay(200);
     digitalWrite(solenoid4_N7,LOW);
     digitalWrite(solenoid4_N8,LOW);
    
     locker4 = 0;
    lcd.setCursor(0,0);
    lcd.print("Locked           ");
    delay(200);
  }else{
    if(limit_switch4==HIGH)
    lcd.setCursor(0,0);
    lcd.print("Close the locker");
    lcd.setCursor(0,1);
    lcd.print("and press A     ");
    }
}

void lock5(){
  lcd.clear();
  limit_switch5 = digitalRead(limit_switch5_pin);
  if(limit_switch5==LOW){
     digitalWrite(solenoid5_N9,HIGH);
     digitalWrite(solenoid5_N10,LOW);
     delay(200);
     digitalWrite(solenoid5_N9,LOW);
     digitalWrite(solenoid5_N10,LOW);
    
     locker5 = 0;
    lcd.setCursor(0,0);
    lcd.print("Locked           ");
    delay(200);
  }else{
    if(limit_switch5==HIGH)
    lcd.setCursor(0,0);
    lcd.print("Close the locker");
    lcd.setCursor(0,1);
    lcd.print("and press A     ");
    }
}
///////////////////////////////////////////////////////////////////

void unlock1(){
    digitalWrite(solenoid1_N1,LOW);
     digitalWrite(solenoid1_N2,HIGH);
     delay(200);
     digitalWrite(solenoid1_N1,LOW);
     digitalWrite(solenoid1_N2,LOW);
    locker1 = 1;
}

void unlock2(){
    digitalWrite(solenoid2_N3,LOW);
     digitalWrite(solenoid2_N4,HIGH);
     delay(200);
     digitalWrite(solenoid2_N3,LOW);
     digitalWrite(solenoid2_N4,LOW);
    locker2 = 1;
}

void unlock3(){
    digitalWrite(solenoid3_N5,LOW);
     digitalWrite(solenoid3_N6,HIGH);
     delay(200);
     digitalWrite(solenoid3_N5,LOW);
     digitalWrite(solenoid3_N6,LOW);
    locker3 = 1;
}

void unlock4(){
    digitalWrite(solenoid4_N7,LOW);
     digitalWrite(solenoid4_N8,HIGH);
     delay(200);
     digitalWrite(solenoid4_N7,LOW);
     digitalWrite(solenoid4_N8,LOW);
    locker4 = 1;
}
void unlock5(){
    digitalWrite(solenoid5_N9,LOW);
     digitalWrite(solenoid5_N10,HIGH);
     delay(200);
     digitalWrite(solenoid5_N9,LOW);
     digitalWrite(solenoid5_N10,LOW);
    locker5 = 1;
}
void setup()
{
    pinMode(limit_switch1, INPUT);
    pinMode(limit_switch2, INPUT);
    pinMode(limit_switch3, INPUT);
    pinMode(limit_switch4, INPUT);
    pinMode(limit_switch5, INPUT);

    
    pinMode(solenoid1_N1,OUTPUT);
    pinMode(solenoid1_N2,OUTPUT);
    
    pinMode(solenoid2_N3,OUTPUT);
    pinMode(solenoid2_N4,OUTPUT);

    pinMode(solenoid3_N5,OUTPUT);
    pinMode(solenoid3_N6,OUTPUT);

    pinMode(solenoid4_N7,OUTPUT);
    pinMode(solenoid4_N8,OUTPUT);

    pinMode(solenoid5_N9,OUTPUT);
    pinMode(solenoid5_N10,OUTPUT);
//    lcd.setBacklightPin(3,POSITIVE);
//    lcd.setBacklight(HIGH); // NOTE: You can turn the backlight off by setting it to LOW instead of HIGH
    lcd.begin(16, 2);
    lcd.clear();

    Serial.begin(9600);
}

long ms = 0;   
void del(long d){                       //delay with millis 
        while(millis()<=d+ms){           //if you want arduino to do smth. while delay put it in "code"
        //code 
    char customKey = customKeypad.getKey();
    if(customKey ){
    Serial.println(customKey);
            }
        }
      ms=millis();
    
}

void loop()
{  
    int show = 0;
    
    char enter[4];

    int Pass1;
    int Pass2;
    int Pass3;
    int Pass4;
    int Pass5;

    int Pass1_admin;
    int Pass2_admin;
    int Pass3_admin;
    int Pass4_admin;
    int Pass5_admin;

    int locker_num = 0;

    limit_switch1 = digitalRead(limit_switch1_pin);
    limit_switch2 = digitalRead(limit_switch2_pin);
    limit_switch3 = digitalRead(limit_switch3_pin);
    limit_switch4 = digitalRead(limit_switch4_pin);
    limit_switch5 = digitalRead(limit_switch5_pin);
    
    char customKey = customKeypad.getKey();
    Serial.println(customKey);
    if(counter == 0 && locker_num != 1 && locker_num != 2 && locker_num != 3 && locker_num != 4 && locker_num != 5){
    lcd.setCursor(0,0);
    lcd.print("Select a locker ");
    }
    
   while(customKey == '1' || locker_num ==1){     // all while-loop to unlock & lock locker num.1  

    
      locker_num = 1;
      customKey = customKeypad.getKey();
            if(locker1 == 0){ // if its locked
              if(counter == 0){
              lcd.setCursor(0,0);
               lcd.print("Enter the pass  ");
              }
         if(customKey){
          if(customKey != 'B' && customKey != 'D'){
            counter++;
            show = 0;
          }
          Serial.println(counter);


                if(customKey == 'C'){
                  locker_num = 0;
                  counter = 0;
                  lcd.clear();
                }

                if(customKey == 'B'){
                  show = 1;
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  if(counter>=4){
                    lcd.print("press A - unlock");
                  }else{
                    lcd.print("C-cancel B-show ");
                    lcd.setCursor(8, 1);
                    lcd.print("D-delete");
                  }
                  lcd.setCursor(0, 1);
                  for(int i = 0;i<counter;i++)
                  lcd.print(enter[i]);
                }


                if(customKey == 'D'){
                  counter--;
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(counter<0){
                    counter = 0;
                  }
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(show == 0){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print("*");
                    }
                  }
                  if(show == 1){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print(enter[i]);
                    }
                  }
                  
                }
          
                if(counter == 1 && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;
               // set the cursor to column 0, line 1
              // (note: line 1 is the second row, since counting begins with 0):
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("*");

                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  //counter++;
                 
                                 }


                                 if(counter == 2  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("**");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 3  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("***");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 4  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("press A - unlock");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("****");
                  //counter++;
                  Serial.println(customKey);

                  
                 }
                 if(counter > 4 && customKey == 'A'){

                  for(int i=0;i<4;i++){
                     Pass1 = 1;      //pass1 = 1 its TRUE
                    if(enter[i] != locker1_pass[i]){
                      Pass1 = 0;
                      break;
                    }
                  }

                  for(int i=0;i<4;i++){
                     Pass1_admin = 1;      //pass1 = 1 its TRUE
                    if(enter[i] != locker1_pass_admin[i]){
                      Pass1_admin = 0;
                      break;
                    }
                  }

                  if(Pass1 == 1 || Pass1_admin == 1){
                    lcd.clear();
                    lcd.setCursor(0,0 );
                    lcd.print("Locker unlocked");
                    unlock1();
                    counter = 0;
                    //locker1 = 0;    //remove it
                    delay(2000);
                    break;
                    locker_num = 0;
                  }else{
                    lcd.clear();
                    lcd.setCursor(0,0 );
                    lcd.print("Wrong password");
                    lcd.setCursor(0,1 );
                    lcd.print("Try again");
                    delay(2000);
                    lcd.clear();
                    counter = 0;
                  }
                  
        
      }

         
        }
      }


// / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 


      if(locker1 == 1){ // if its unlocked
              if(counter == 0){
              lcd.setCursor(0,0);
               lcd.print("choose a pass   ");
              }
         if(customKey){

          if(customKey != 'B' && customKey != 'D'){
            counter++;
          }

          if(customKey == 'C'){
                  locker_num = 0;
                  counter = 0;
                  lcd.clear();
                }

                if(customKey == 'B'){
                  show = 1;
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  if(counter>=4){
                    lcd.print("press A to lock  ");
                  }else{
                    lcd.print("C-cancel B-show ");
                    lcd.setCursor(8, 1);
                    lcd.print("D-delete");
                  }
                  lcd.setCursor(0, 1);
                  for(int i = 0;i<counter;i++)
                  lcd.print(enter[i]);
                }


                if(customKey == 'D'){
                  counter--;
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(counter<0){
                    counter = 0;
                  }
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(show == 0){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print("*");
                    }
                  }
                  if(show == 1){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print(enter[i]);
                    }
                  }
                  
                }
                
       
          Serial.println(counter);
          
                if(counter == 1 && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;
               // set the cursor to column 0, line 1
              // (note: line 1 is the second row, since counting begins with 0):
            
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("*");
                   lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                 
                                 }


                                 if(counter == 2  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("**");
                   lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 3  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("***");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 4  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("press A to lock  ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("****");
                  //counter++;
                  Serial.println(customKey);

                  
                 }
                 if(counter > 4 && customKey == 'A' ){

                  for(int i=0;i<4;i++){
                    locker1_pass[i] = enter[i];
                    }
                    
                    Pass1 = 0;
                    lock1();

                    if(locker1 == 0){
                      locker_num = 0;
                      counter = 0;
                      break;
                    }else{
                      if(locker1 == 1 && customKey == 'A'){
                        
                        lock1();
                      }
                    }
                                      
              }                                      
           }
        }      
    }
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

while(customKey == '2' || locker_num ==2){     // all while-loop to unlock & lock locker num.1  

    
      locker_num = 2;
      customKey = customKeypad.getKey();
            if(locker2 == 0){ // if its locked
              if(counter == 0){
              lcd.setCursor(0,0);
               lcd.print("Enter the pass  ");
              }
         if(customKey){
          if(customKey != 'B' && customKey != 'D'){
            counter++;
            show = 0;
          }
          Serial.println(counter);


                if(customKey == 'C'){
                  locker_num = 0;
                  counter = 0;
                  lcd.clear();
                }

                if(customKey == 'B'){
                  show = 1;
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  if(counter>=4){
                    lcd.print("press A - unlock");
                  }else{
                    lcd.print("C-cancel B-show ");
                    lcd.setCursor(8, 1);
                    lcd.print("D-delete");
                  }
                  lcd.setCursor(0, 1);
                  for(int i = 0;i<counter;i++)
                  lcd.print(enter[i]);
                }


                if(customKey == 'D'){
                  counter--;
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(counter<0){
                    counter = 0;
                  }
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(show == 0){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print("*");
                    }
                  }
                  if(show == 1){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print(enter[i]);
                    }
                  }
                  
                }
          
                if(counter == 1 && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;
               // set the cursor to column 0, line 1
              // (note: line 1 is the second row, since counting begins with 0):
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("*");

                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  //counter++;
                 
                                 }


                                 if(counter == 2  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("**");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 3  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("***");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 4  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("press A - unlock");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("****");
                  //counter++;
                  Serial.println(customKey);

                  
                 }
                 if(counter > 4 && customKey == 'A'){

                  for(int i=0;i<4;i++){
                     Pass2 = 1;      //pass1 = 1 its TRUE
                    if(enter[i] != locker2_pass[i]){
                      Pass2 = 0;
                      break;
                    }
                  }

                  for(int i=0;i<4;i++){
                     Pass2_admin = 1;      //pass1 = 1 its TRUE
                    if(enter[i] != locker2_pass_admin[i]){
                      Pass2_admin = 0;
                      break;
                    }
                  }

                  if(Pass2 == 1 || Pass2_admin == 1){
                    lcd.clear();
                    lcd.setCursor(0,0 );
                    lcd.print("Locker unlocked");
                    unlock2();
                    counter = 0;
                    //locker1 = 0;    //remove it
                    delay(2000);
                    break;
                    locker_num = 0;
                  }else{
                    lcd.clear();
                    lcd.setCursor(0,0 );
                    lcd.print("Wrong password");
                    lcd.setCursor(0,1 );
                    lcd.print("Try again");
                    delay(2000);
                    lcd.clear();
                    counter = 0;
                  }
                  
        
      }

         
        }
      }


// / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 


      if(locker2 == 1){ // if its unlocked
              if(counter == 0){
              lcd.setCursor(0,0);
               lcd.print("choose a pass   ");
              }
         if(customKey){

          if(customKey != 'B' && customKey != 'D'){
            counter++;
          }

          if(customKey == 'C'){
                  locker_num = 0;
                  counter = 0;
                  lcd.clear();
                }

                if(customKey == 'B'){
                  show = 1;
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  if(counter>=4){
                    lcd.print("press A to lock  ");
                  }else{
                    lcd.print("C-cancel B-show ");
                    lcd.setCursor(8, 1);
                    lcd.print("D-delete");
                  }
                  lcd.setCursor(0, 1);
                  for(int i = 0;i<counter;i++)
                  lcd.print(enter[i]);
                }


                if(customKey == 'D'){
                  counter--;
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(counter<0){
                    counter = 0;
                  }
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(show == 0){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print("*");
                    }
                  }
                  if(show == 1){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print(enter[i]);
                    }
                  }
                  
                }
                
       
          Serial.println(counter);
          
                if(counter == 1 && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;
               // set the cursor to column 0, line 1
              // (note: line 1 is the second row, since counting begins with 0):
            
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("*");
                   lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                 
                                 }


                                 if(counter == 2  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("**");
                   lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 3  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("***");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 4  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("press A to lock  ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("****");
                  //counter++;
                  Serial.println(customKey);

                  
                 }
                 if(counter > 4 && customKey == 'A' ){

                  for(int i=0;i<4;i++){
                    locker2_pass[i] = enter[i];
                    }
                    
                    Pass2 = 0;
                    lock2();

                    if(locker2 == 0){
                      locker_num = 0;
                      counter = 0;
                      break;
                    }else{
                      if(locker2 == 1 && customKey == 'A'){
                        
                        lock2();
                      }
                    }
                                      
              }                                      
           }
        }      
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



while(customKey == '3' || locker_num ==3){     // all while-loop to unlock & lock locker num.1  

    
      locker_num = 3;
      customKey = customKeypad.getKey();
            if(locker3 == 0){ // if its locked
              if(counter == 0){
              lcd.setCursor(0,0);
               lcd.print("Enter the pass  ");
              }
         if(customKey){
          if(customKey != 'B' && customKey != 'D'){
            counter++;
            show = 0;
          }
          Serial.println(counter);


                if(customKey == 'C'){
                  locker_num = 0;
                  counter = 0;
                  lcd.clear();
                }

                if(customKey == 'B'){
                  show = 1;
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  if(counter>=4){
                    lcd.print("press A - unlock");
                  }else{
                    lcd.print("C-cancel B-show ");
                    lcd.setCursor(8, 1);
                    lcd.print("D-delete");
                  }
                  lcd.setCursor(0, 1);
                  for(int i = 0;i<counter;i++)
                  lcd.print(enter[i]);
                }


                if(customKey == 'D'){
                  counter--;
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(counter<0){
                    counter = 0;
                  }
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(show == 0){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print("*");
                    }
                  }
                  if(show == 1){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print(enter[i]);
                    }
                  }
                  
                }
          
                if(counter == 1 && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;
               // set the cursor to column 0, line 1
              // (note: line 1 is the second row, since counting begins with 0):
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("*");

                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  //counter++;
                 
                                 }


                                 if(counter == 2  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("**");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 3  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("***");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 4  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("press A - unlock");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("****");
                  //counter++;
                  Serial.println(customKey);

                  
                 }
                 if(counter > 4 && customKey == 'A'){

                  for(int i=0;i<4;i++){
                     Pass3 = 1;      //pass1 = 1 its TRUE
                    if(enter[i] != locker3_pass[i]){
                      Pass3 = 0;
                      break;
                    }
                  }

                  for(int i=0;i<4;i++){
                     Pass3_admin = 1;      //pass1 = 1 its TRUE
                    if(enter[i] != locker3_pass_admin[i]){
                      Pass3_admin = 0;
                      break;
                    }
                  }

                  if(Pass3 == 1 || Pass3_admin == 1){
                    lcd.clear();
                    lcd.setCursor(0,0 );
                    lcd.print("Locker unlocked");
                    unlock3();
                    counter = 0;
                    //locker1 = 0;    //remove it
                    delay(2000);
                    break;
                    locker_num = 0;
                  }else{
                    lcd.clear();
                    lcd.setCursor(0,0 );
                    lcd.print("Wrong password");
                    lcd.setCursor(0,1 );
                    lcd.print("Try again");
                    delay(2000);
                    lcd.clear();
                    counter = 0;
                  }
                  
        
      }

         
        }
      }


// / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 


      if(locker3 == 1){ // if its unlocked
              if(counter == 0){
              lcd.setCursor(0,0);
               lcd.print("choose a pass   ");
              }
         if(customKey){

          if(customKey != 'B' && customKey != 'D'){
            counter++;
          }

          if(customKey == 'C'){
                  locker_num = 0;
                  counter = 0;
                  lcd.clear();
                }

                if(customKey == 'B'){
                  show = 1;
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  if(counter>=4){
                    lcd.print("press A to lock  ");
                  }else{
                    lcd.print("C-cancel B-show ");
                    lcd.setCursor(8, 1);
                    lcd.print("D-delete");
                  }
                  lcd.setCursor(0, 1);
                  for(int i = 0;i<counter;i++)
                  lcd.print(enter[i]);
                }


                if(customKey == 'D'){
                  counter--;
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(counter<0){
                    counter = 0;
                  }
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(show == 0){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print("*");
                    }
                  }
                  if(show == 1){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print(enter[i]);
                    }
                  }
                  
                }
                
       
          Serial.println(counter);
          
                if(counter == 1 && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;
               // set the cursor to column 0, line 1
              // (note: line 1 is the second row, since counting begins with 0):
            
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("*");
                   lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                 
                                 }


                                 if(counter == 2  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("**");
                   lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 3  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("***");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 4  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("press A to lock  ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("****");
                  //counter++;
                  Serial.println(customKey);

                  
                 }
                 if(counter > 4 && customKey == 'A' ){

                  for(int i=0;i<4;i++){
                    locker3_pass[i] = enter[i];
                    }
                    
                    Pass3 = 0;
                    lock3();

                    if(locker3 == 0){
                      locker_num = 0;
                      counter = 0;
                      break;
                    }else{
                      if(locker3 == 1 && customKey == 'A'){
                        
                        lock3();
                      }
                    }
                                      
              }                                      
           }
        }      
    }

   

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
while(customKey == '4' || locker_num ==4){     // all while-loop to unlock & lock locker num.1  

  
      locker_num = 4;
      customKey = customKeypad.getKey();
            if(locker4 == 0){ // if its locked
              if(counter == 0){
              lcd.setCursor(0,0);
               lcd.print("Enter the pass  ");
              }
         if(customKey){
          if(customKey != 'B' && customKey != 'D'){
            counter++;
            show = 0;
          }
          Serial.println(counter);


                if(customKey == 'C'){
                  locker_num = 0;
                  counter = 0;
                  lcd.clear();
                }

                if(customKey == 'B'){
                  show = 1;
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  if(counter>=4){
                    lcd.print("press A - unlock");
                  }else{
                    lcd.print("C-cancel B-show ");
                    lcd.setCursor(8, 1);
                    lcd.print("D-delete");
                  }
                  lcd.setCursor(0, 1);
                  for(int i = 0;i<counter;i++)
                  lcd.print(enter[i]);
                }


                if(customKey == 'D'){
                  counter--;
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(counter<0){
                    counter = 0;
                  }
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(show == 0){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print("*");
                    }
                  }
                  if(show == 1){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print(enter[i]);
                    }
                  }
                  
                }
          
                if(counter == 1 && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;
               // set the cursor to column 0, line 1
              // (note: line 1 is the second row, since counting begins with 0):
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("*");

                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  //counter++;
                 
                                 }


                                 if(counter == 2  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("**");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 3  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("***");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 4  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("press A - unlock");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("****");
                  //counter++;
                  Serial.println(customKey);

                  
                 }
                 if(counter > 4 && customKey == 'A'){

                  for(int i=0;i<4;i++){
                     Pass4 = 1;      //pass1 = 1 its TRUE
                    if(enter[i] != locker3_pass[i]){
                      Pass4 = 0;
                      break;
                    }
                  }

                  for(int i=0;i<4;i++){
                     Pass4_admin = 1;      //pass1 = 1 its TRUE
                    if(enter[i] != locker4_pass_admin[i]){
                      Pass4_admin = 0;
                      break;
                    }
                  }

                  if(Pass4 == 1 || Pass4_admin == 1){
                    lcd.clear();
                    lcd.setCursor(0,0 );
                    lcd.print("Locker unlocked");
                    unlock4();
                    counter = 0;
                    //locker4 = 0;    //remove it
                    delay(2000);
                    break;
                    locker_num = 0;
                  }else{
                    lcd.clear();
                    lcd.setCursor(0,0 );
                    lcd.print("Wrong password");
                    lcd.setCursor(0,1 );
                    lcd.print("Try again");
                    delay(2000);
                    lcd.clear();
                    counter = 0;
                  }
                  
        
      }

         
        }
      }


                ///////////////////////////////////////////////////////////////////////////
                

       if(locker4 == 1 ){ // if its unlocked
              if(counter == 0){
              lcd.setCursor(0,0);
               lcd.print("choose a pass   ");
              }
         if(customKey){

          if(customKey != 'B' && customKey != 'D'){
            counter++;
          }

          if(customKey == 'C'){
                  locker_num = 0;
                  counter = 0;
                  lcd.clear();
                }

                if(customKey == 'B'){
                  show = 1;
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  if(counter>=4){
                    lcd.print("press A to lock  ");
                  }else{
                    lcd.print("C-cancel B-show ");
                    lcd.setCursor(8, 1);
                    lcd.print("D-delete");
                  }
                  lcd.setCursor(0, 1);
                  for(int i = 0;i<counter;i++)
                  lcd.print(enter[i]);
                }


                if(customKey == 'D'){
                  counter--;
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(counter<0){
                    counter = 0;
                  }
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(show == 0){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print("*");
                    }
                  }
                  if(show == 1){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print(enter[i]);
                    }
                  }
                  
                }
                
       
          Serial.println(counter);
          
                if(counter == 1 && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;
               // set the cursor to column 0, line 1
              // (note: line 1 is the second row, since counting begins with 0):
            
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("*");
                   lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                 
                                 }


                                 if(counter == 2  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("**");
                   lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 3  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("***");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 4  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("press A to lock  ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("****");
                  //counter++;
                  Serial.println(customKey);

                  
                 }
                 if(counter > 4 && customKey == 'A' ){

                  for(int i=0;i<4;i++){
                    locker4_pass[i] = enter[i];
                    }
                    
                    Pass4 = 0;
                    lock4();

                    if(locker4 == 0){
                      locker_num = 0;
                      counter = 0;
                      break;
                      }
                      else{
                      if(locker4 == 1 && customKey == 'A'){
                        
                        lock4();
                      }
                    }
                                      
              }                                      
           }
        }      
    }
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

while(customKey == '5' || locker_num ==5){     // all while-loop to unlock & lock locker num.1  

  
      locker_num = 5;
      customKey = customKeypad.getKey();
            if(locker5 == 0){ // if its locked
              if(counter == 0){
              lcd.setCursor(0,0);
               lcd.print("Enter the pass  ");
              }
         if(customKey){
          if(customKey != 'B' && customKey != 'D'){
            counter++;
            show = 0;
          }
          Serial.println(counter);


                if(customKey == 'C'){
                  locker_num = 0;
                  counter = 0;
                  lcd.clear();
                }

                if(customKey == 'B'){
                  show = 1;
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  if(counter>=4){
                    lcd.print("press A - unlock");
                  }else{
                    lcd.print("C-cancel B-show ");
                    lcd.setCursor(8, 1);
                    lcd.print("D-delete");
                  }
                  lcd.setCursor(0, 1);
                  for(int i = 0;i<counter;i++)
                  lcd.print(enter[i]);
                }


                if(customKey == 'D'){
                  counter--;
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(counter<0){
                    counter = 0;
                  }
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(show == 0){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print("*");
                    }
                  }
                  if(show == 1){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print(enter[i]);
                    }
                  }
                  
                }
          
                if(counter == 1 && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;
               // set the cursor to column 0, line 1
              // (note: line 1 is the second row, since counting begins with 0):
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("*");

                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  //counter++;
                 
                                 }


                                 if(counter == 2  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("**");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 3  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("***");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 4  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("press A - unlock");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("****");
                  //counter++;
                  Serial.println(customKey);

                  
                 }
                 if(counter > 4 && customKey == 'A'){

                  for(int i=0;i<4;i++){
                     Pass5 = 1;      //pass1 = 1 its TRUE
                    if(enter[i] != locker5_pass[i]){
                      Pass5 = 0;
                      break;
                    }
                  }

                  for(int i=0;i<4;i++){
                     Pass5_admin = 1;      //pass1 = 1 its TRUE
                    if(enter[i] != locker5_pass_admin[i]){
                      Pass5_admin = 0;
                      break;
                    }
                  }

                  if(Pass5 == 1 || Pass5_admin == 1){
                    lcd.clear();
                    lcd.setCursor(0,0 );
                    lcd.print("Locker unlocked");
                    unlock5();
                    counter = 0;
                    //locker5 = 0;    //remove it
                    delay(2000);
                    break;
                    locker_num = 0;
                  }else{
                    lcd.clear();
                    lcd.setCursor(0,0 );
                    lcd.print("Wrong password");
                    lcd.setCursor(0,1 );
                    lcd.print("Try again");
                    delay(2000);
                    lcd.clear();
                    counter = 0;
                  }
                  
        
      }

         
        }
      }


                ///////////////////////////////////////////////////////////////////////////
                

       if(locker5 == 1 ){ // if its unlocked
              if(counter == 0){
              lcd.setCursor(0,0);
               lcd.print("choose a pass   ");
              }
         if(customKey){

          if(customKey != 'B' && customKey != 'D'){
            counter++;
          }

          if(customKey == 'C'){
                  locker_num = 0;
                  counter = 0;
                  lcd.clear();
                }

                if(customKey == 'B'){
                  show = 1;
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  if(counter>=4){
                    lcd.print("press A to lock  ");
                  }else{
                    lcd.print("C-cancel B-show ");
                    lcd.setCursor(8, 1);
                    lcd.print("D-delete");
                  }
                  lcd.setCursor(0, 1);
                  for(int i = 0;i<counter;i++)
                  lcd.print(enter[i]);
                }


                if(customKey == 'D'){
                  counter--;
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(counter<0){
                    counter = 0;
                  }
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show ");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  
                  if(counter == 0){
                    lcd.clear();
                  }
                  if(show == 0){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print("*");
                    }
                  }
                  if(show == 1){
                    lcd.setCursor(0, 1);
                    for(int i=0;i<counter;i++){
                      lcd.print(enter[i]);
                    }
                  }
                  
                }
                
       
          Serial.println(counter);
          
                if(counter == 1 && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;
               // set the cursor to column 0, line 1
              // (note: line 1 is the second row, since counting begins with 0):
            
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("*");
                   lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                 
                                 }


                                 if(counter == 2  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("**");
                   lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 3  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("C-cancel B-show");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("***");
                  lcd.setCursor(8, 1);
                  lcd.print("D-delete");
                  //counter++;
                  
                                  }
                                  if(counter == 4  && customKey != 'B' && customKey != 'D'){
                  enter[counter-1] = customKey;          
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("press A to lock  ");
                  
                  lcd.setCursor(0, 1);
                  
                  lcd.print("****");
                  //counter++;
                  Serial.println(customKey);

                  
                 }
                 if(counter > 4 && customKey == 'A' ){

                  for(int i=0;i<4;i++){
                    locker5_pass[i] = enter[i];
                    }
                    
                    Pass5 = 0;
                    lock5();

                    if(locker5 == 0){
                      locker_num = 0;
                      counter = 0;
                      break;
                      }
                      else{
                      if(locker5 == 1 && customKey == 'A'){
                        
                        lock5();
                      }
                    }
                                      
              }                                      
           }
        }      
    }

}
