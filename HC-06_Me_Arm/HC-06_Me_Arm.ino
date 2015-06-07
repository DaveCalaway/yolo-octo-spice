/* Il programma collega un terminale Bluetooth al modulo Maestro per comandare i motori del Me Arm.
Alla pressione del tasto 'a' comunica un avviso del progetto. 
Alla pressione d'un numero da 1 a 3 seleziona uno dei tre motori.
Nel caso non venga selezionato un altro motore, con 'j' e 'l' si incrementa/decrementa lo stato del Servo.
*/
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
char state=0;
char pos=0;
//int passi=4000;
int motor=1;
int passi=4000;


void setup() {
    Serial.begin(9600); // Default connection rate for my BT module
    maestroSerial.begin(9600);  // Default connection rate for Maestro module
}

void loop() {
  
  if(Serial.available() > 0){
      
      state = Serial.read();
      
      if (state == 'a') 
        Serial.println("Benveuto nel programma di prova MeArm del FabLab di Modena\n");
      
      if(state =='1' || state == '2' || state == '3'){
          Serial.println("Hai selezionato il motore");
	  state=motor;
	}
      if(state == 'j' || state == 'l'){
          Serial.println(state);
          Me_Arm(motor,state);
       }  
    }
}

// Conversione in pulsazioni per servo
void Me_Arm(int motor,char target){
    
    if( target == 'j' )
        passi=passi+200;
    else 
        passi=passi-200;
        
    if(passi > 4000 && passi < 8000 ){
      maestro.setTarget(motor, target);
      delay(1000);
    }
    if(passi < 4000){  // fine corsa minimo
      Serial.println("Fine corsa");
      passi=400;
    }
    if(passi > 8000){  // fine corsa massimo
      Serial.println("Fine corsa");
      passi=8000;
    }
}
