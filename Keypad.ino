void readkeypad() {
  key = keypad.getKey();
        //untuk serial print
  if (key){          
    if(key == 'D'){
      Serial.println(".");
    } else {
      Serial.println(key);
    }     
    if(key == '*') {
      if (num_string == ""){
        Serial.println("Belum ada input angka");  
      } else {
        Sp = num_string.toFloat();
        Serial.print("Koefisien berhasil disimpan, setpoint = ");
        Serial.println(Sp);
        
        printPIDtoLCD(Sp,kp,ki,kd);
        
        pos_pid.tune(kp, ki, kd); //kp, ki, kd  
        pos_pid.setpoint(Sp);
        motor_value = pos_pid.compute(pos);
        num_string = "";
        isKoma = 0;
        Serial.println("Masukkan angka diikuti A untuk Kp, B untuk Ki, C untuk Kd, dan * untuk setpoint");
        Serial.println("Tekan # untuk menampilkan parameter pada serial. D digunakan untuk koma.");
      }
    } else if(key == 'A') {
      if (num_string == ""){
        Serial.println("Belum ada input angka");  
      } else {
        kp = num_string.toFloat();
        Serial.print("Koefisien berhasil disimpan, kp = ");
        Serial.println(kp);
        printPIDtoLCD(Sp,kp,ki,kd);
        pos_pid.tune(kp, ki, kd); //kp, ki, kd  
        pos_pid.setpoint(Sp);
        motor_value = pos_pid.compute(pos);
        num_string = "";
        isKoma = 0;
        Serial.println("Masukkan angka diikuti A untuk Kp, B untuk Ki, C untuk Kd, dan * untuk setpoint");
        Serial.println("Tekan # untuk menampilkan parameter pada serial. D digunakan untuk koma.");
      }
    } else if(key == 'B') {
      if (num_string == ""){
        Serial.println("Belum ada input angka");  
      } else {
        ki = num_string.toFloat();
        Serial.print("Koefisien berhasil disimpan, ki = ");
        Serial.println(ki);
        printPIDtoLCD(Sp,kp,ki,kd);
        pos_pid.tune(kp, ki, kd); //kp, ki, kd  
        pos_pid.setpoint(Sp);
        motor_value = pos_pid.compute(pos);
        num_string = "";
        isKoma = 0;
        Serial.println("Masukkan angka diikuti A untuk Kp, B untuk Ki, C untuk Kd, dan * untuk setpoint");
        Serial.println("Tekan # untuk menampilkan parameter pada serial. D digunakan untuk koma.");
      }
    } else if(key == 'C') {
      if (num_string == ""){
        Serial.println("Belum ada input angka");  
      } else {
        kd = num_string.toFloat();
        Serial.print("Koefisien berhasil disimpan, kd = ");
        Serial.println(kd);
        printPIDtoLCD(Sp,kp,ki,kd);
        pos_pid.tune(kp, ki, kd); //kp, ki, kd  
        pos_pid.setpoint(Sp);
        motor_value = pos_pid.compute(pos);
        num_string = "";
        isKoma = 0;
        Serial.println("Masukkan angka diikuti A untuk Kp, B untuk Ki, C untuk Kd, dan * untuk setpoint");
        Serial.println("Tekan # untuk menampilkan parameter pada serial. D digunakan untuk koma.");
      }
    } else if(key == 'D') {
      if(isKoma == 0){
        num_string += '.';
        isKoma = 1;
      } else {
        Serial.println("Sudah ada koma");
      }
    } else if(key == '#') {
      Serial.print("Kp = ");
      Serial.println(kp);
      Serial.print("Ki = ");
      Serial.println(ki);
      Serial.print("Kd = ");
      Serial.println(kd);
      Serial.print("setpoint = ");
      Serial.println(Sp);
      pos_pid.tune(kp, ki, kd); //kp, ki, kd  
      pos_pid.setpoint(Sp);
      motor_value = pos_pid.compute(pos);
      Serial.println("Masukkan angka diikuti A untuk Kp, B untuk Ki, C untuk Kd, dan * untuk setpoint");
      Serial.println("Tekan # untuk menampilkan parameter pada serial. D digunakan untuk koma.");
      num_string = ""; // reset input
      isKoma = 0;
    } else {
      num_string += key; // append new character to input string
    }
  }
}
