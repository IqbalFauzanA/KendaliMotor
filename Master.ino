#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <PIDController.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

//Variabel Potensio
int potensio = A0; 
double val = 0;

//Variabel Encoder
#define enc1 A1
#define enc2 2

//Variabel Motor
#define enA 3
#define in1 12
#define in2 13
volatile long int pos = 0;
PIDController pos_pid;
int motor_value = 255;

//Variabel Keypad
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
char key;
byte pin_rows[ROW_NUM] = {5,4,6,7}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {8,9,10,11}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

//PID Control
String num_string;
float kp = 0;
float ki = 0;
float kd = 0;
int isKoma = 0;

//Variabel Serial Communication
int state = 3;
String input;
int x;
float Sp = 0;

//Variabel lcd
int r;

void setup() {
  //Setup Serial
  Serial.begin(9600);

  //Setup LCD
  lcd.init ();
  lcd.backlight();
  lcd.clear();
  lcd.print("KENDALI MOTOR DC");

  //Setup Keypad
  num_string.reserve(7); // maximum input characters is 8, change if needed

  pinMode(potensio,INPUT);
  pinMode(enc1, INPUT);
  pinMode(enc2, INPUT);
  attachInterrupt(digitalPinToInterrupt(enc2), encoder, RISING);

  //PID Control
  pos_pid.begin();
  pos_pid.tune(kp, ki, kd);     
  pos_pid.limit(-255, 255);

  //Setup Task
  printPIDtoLCD(Sp,kp,ki,kd);
  Wire.begin();
}

void loop() {
//  Serial.println("KENDALI MOTOR DC");
//  Serial.println("Masukkan 1, 2, atau 3!");
  while (Serial.available()>0){
    state = Serial.readString().toInt();
//UNTUK VERIFIKASI PEMBACAAN SERIAL
//Serial.println(isSerial);
    if(state==1){
      Serial.println("State : Input Serial");
      SerialRead();
    } 
    else if (state==2){
      Serial.println("State : Input Keypad");
      Serial.println("Masukkan angka diikuti A untuk Kp, B untuk Ki, C untuk Kd, dan * untuk setpoint");
      Serial.println("Tekan # untuk menampilkan parameter pada serial. D digunakan untuk koma.");
      while (!Serial.available()){
        readkeypad();
        kendaliPosisi();
      }
    }
    else if (state==3){
      Serial.println("State : Input Keypad");
      while (!Serial.available()){
        val = analogRead(potensio);
        Sp = map(val,0,1024,0,374);
        
//        printParameter(Sp,kp,ki,kd);
        printPIDtoLCD(Sp,kp,ki,kd);
        
        kendaliPosisi();
        Serial.println(pos);
      }
    }
  }
}
