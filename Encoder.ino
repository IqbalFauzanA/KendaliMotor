void encoder(){
  if (digitalRead(enc1)>0){
    pos++;
  }else{
    pos--;
  }
}
