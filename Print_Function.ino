//Print to LCD
void printPIDtoLCD(float setPoint, float KP, float KI, float KD){
      lcd.clear();
      lcd.print("SP:" + String(setPoint));
      lcd.setCursor (8,0);
      lcd.print ("Kp:" + String(KP));
      lcd.setCursor (0,1);
      lcd.print ("Ki:" + String(KI));
      lcd.setCursor (8,1);
      lcd.print ("Kd:" + String(KD));
}

//Print to Serial Monitor
void printParameter(float setPoint, float KP, float KI, float KD){
  Serial.println("====================");
  Serial.println("Kp = "+String(KP));
  Serial.println("Ki = "+String(KI));
  Serial.println("Kd = "+String(KD));
  Serial.println("Set Point = "+String(setPoint));
  Serial.println("====================");
}
