/* Il programma collega il terminale USB d'Arduino per comandare i motori del Me Arm.
Alla pressione del tasto 'a' comunica un avviso del progetto. 
Alla pressione d'un numero da 1 a 3 seleziona uno dei tre motori.
Nel caso non venga selezionato un altro motore, con 'j' e 'l' si incrementa/decrementa lo stato del Servo.
*/

#include <PololuMaestro.h>

#ifdef SERIAL_PORT_HARDWARE_OPEN
  #define maestroSerial SERIAL_PORT_HARDWARE_OPEN
#else
  #include <SoftwareSerial.h>
  SoftwareSerial maestroSerial(10, 11); //maestro's communication ports 
#endif

MicroMaestro maestro(maestroSerial);

char state=0;
int motor=0;
int passi=4000;


void setup() {
    Serial.begin(115200); // Default USB
    maestroSerial.begin(9600);  // Default connection rate for Maestro module
}

void loop() {
  
  if(Serial.available() > 0){
      
      state = Serial.read();      
      
      if (state == 'a') 
        Serial.println("Benveuto nel programma di prova MeArm del FabLab di Modena\n");
      
      if(state =='0' || state == '1' || state == '2'){
          Serial.print("Hai selezionato il motore:");
          Serial.println(state);
          motor=state;
      }
      
      if(state == 'j' || state == 'l'){
          Serial.println(state);
          Me_Arm(motor,state);
       }  
    }
}


