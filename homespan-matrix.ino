#include "HomeSpan.h" 
#include "DEV_MATRIX.h" 
#include "WS_Flow.h"    

//Characteristic::On *power;

DEV_MATRIX *devMatrix;

void setup() {
  
  Serial.begin(115200);
  Matrix_Init();
  homeSpan.begin(Category::Lighting,"LED Matrix Dev");
  homeSpan.enableAutoStartAP();
  new SpanAccessory();                                                          
    new Service::AccessoryInformation();
      new Characteristic::Identify();            
    devMatrix = new DEV_MATRIX();
  homeSpan.autoPoll(); 
} 

void loop(){
  //delay(4000);
  //Serial.printf("*** Flipping power of Light!\n");
  homeSpanPAUSE;
  if(devMatrix->power->getVal()){
    char dispText[] = "<<<<";
    Text_Flow(dispText);
  } else {
    char dispText[] = "";
    Text_Flow(dispText);
  }
  delay(100);
  
} 