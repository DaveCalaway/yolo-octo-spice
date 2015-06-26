/* Il programma collega il terminale USB d'Arduino per comandare i motori del Me Arm.
Alla pressione del tasto 'a' comunica un avviso del progetto. 
Alla pressione d'un numero da 0 a 2 seleziona uno dei tre motori.
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
int passi=5500;
int passi0=5500;
int passi1=5500;
int passi2=5500;
int oldm=0;

void setup() {
    Serial.begin(115200); // Default USB
    maestroSerial.begin(9600);  // Default connection rate for Maestro module
}

void loop() {
  
  if(Serial.available() > 0){
      
      state = Serial.read();      
      
      if (state == 'a') 
        Serial.println("Benveuto nel programma di prova MeArm USB\n");
      
      if(state =='0' || state == '1' || state == '2'){
          Serial.print("Hai selezionato il motore:");
          Serial.println(state);
          motor=state;

          if(motor == '0' && oldm != motor )  // passagli l'ultima posizione motore
                 passi=passi0;   
                 
          if(state == '1' && oldm != motor )
                 passi=passi1;
          
          if(state == '2' && oldm != motor)
                 passi=passi2;
      }
      
      if(state == 'j' || state == 'l'){
          Serial.println(state);
          Me_Arm(motor,state);

          oldm=motor;         // salva posizione del motore
          if(motor == '0')
              passi0=passi;
          if(motor=='1')
              passi1=passi;
          if(motor=='2')
              passi2=passi;
       }  
    }
}


