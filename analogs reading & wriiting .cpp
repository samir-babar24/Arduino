void setup(){
  
  //beginning with setting up usb 
  Serial.begin(1600);
}

void loop() {
  
  // initially reading the value at A0 which is analog port
  int val= analogRead(A0);
  
  //simply printing it 
  Serial.println(val);
  
  //adjusting and writing value at pin6 (0-255)
  analogWrite(6,200);
  
}