void MotorCounterClockwise(int val){
  analogWrite(enA, val);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void MotorClockwise(int val){
  analogWrite(enA, val);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
}

void kendaliPosisi(){
  pos_pid.tune(kp, ki, kd); 
  pos_pid.setpoint(Sp);
  motor_value = pos_pid.compute(pos);
  
  if(motor_value > 0){
    MotorCounterClockwise(motor_value);
  }else{
    MotorClockwise(abs(motor_value));
  }
}
