void SerialRead(){
  Serial.println("Masukkan nilai Kp!");
    while (!Serial.available()){}
    kp = Serial.readString().toDouble();

    Serial.println("Masukkan nilai Ki!");
    while (!Serial.available()){}
    ki = Serial.readString().toDouble();
    
    Serial.println("Masukkan nilai Kd!");
    while (!Serial.available()){}
    kd = Serial.readString().toDouble();
    
    Serial.println("Masukkan nilai set point!");
    while (!Serial.available()){}
    Sp = Serial.readString().toDouble();

    Serial.print("Kp = ");
    Serial.println(kp);
    Serial.print("Ki = ");
    Serial.println(ki);
    Serial.print("Kd = ");
    Serial.println(kd);
    Serial.print("setPoint = ");
    Serial.println(Sp);

    printPIDtoLCD(Sp,kp,ki,kd);
}
