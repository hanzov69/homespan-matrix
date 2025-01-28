struct DEV_MATRIX : Service::LightBulb {

  SpanCharacteristic *power;
  
  DEV_MATRIX() : Service::LightBulb(){
    power = new Characteristic::On();                 
  } 
  boolean update(){                             
    if (power->getNewVal() == 1) {
      Serial.printf("*** Light on!\n");
    } else {
      Serial.printf("*** Light off!\n");
    }
  
    return(true);                             
  
  }
};