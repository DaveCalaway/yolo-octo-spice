// RX arduino --> TX HC-06
// TX arduino --> RX HC-06 con voltage divider

#include <PololuMaestro.h>

#ifdef SERIAL_PORT_HARDWARE_OPEN
  #define maestroSerial SERIAL_PORT_HARDWARE_OPEN
#else
  #include <SoftwareSerial.h>
  SoftwareSerial maestroSerial(10, 11); //maestro's communication ports 
#endif

MicroMaestro maestro(maestroSerial);
int state=0;
char pos=0;
int passi=4000;


void setup() {
    Serial.begin(9600); // Default connection rate for my BT module
    maestroSerial.begin(9600);
}

void loop() {
  
  if(Serial.available() > 0){
      
      state = Serial.read();
      
      if (state == 'a') 
        Serial.println("Benveuto nel programma di prova MeArm del FabLab di Modena\n");
      
      if(state =='1' || state == '2' || state == '3'){
          Serial.print("Hai selezionato il motore"); // qui si blocca terminale
          pos = Serial.read();
          Serial.print(pos);
          while(pos != 'j' || pos != 'l'){
             Me_Arm(state,pos);
             pos = Serial.read();
          }
       }  
    }
}


void Me_Arm(int motor,char target){
    if( target == 'j' )
        passi=passi+200;
    else 
        passi=passi-200;
        
    if(passi > 4000 && passi < 8000 ){
      maestro.setTarget(motor, target);
      delay(1000);
    }
    if(passi < 4000)
      passi=400;
    if(passi > 8000)
      passi=8000;
}
