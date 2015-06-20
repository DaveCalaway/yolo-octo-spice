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
  SoftwareSerial mySerial(6,7);//RX, TX rivece da BT
  SoftwareSerial maestroSerial(10, 11); //maestro's communication ports 
#endif

MicroMaestro maestro(maestroSerial);

char state=0;
int motor=0;
int passi=4000;
int stateold=0;


void setup() {
    maestroSerial.begin(9600);  // Default connection rate for Maestro module
    mySerial.begin(19200); // Default connection rate for my BT module    
}

void loop() {
  
  if(mySerial.available() > 0){
      
      state = mySerial.read();      
      
      if (state == 'a') 
        mySerial.println("Benveuto nel programma di prova MeArm del FabLab di Modena\n");
      
      if(state =='0' || state == '1' || state == '2'){
                
          mySerial.print("Hai selezionato il motore:");
          mySerial.println(state);
          motor=state;
 //ricordo vecchia posizione
          if(motor =! motorold){
             if(state == '0' ){
                int motor0=motor;
                int passi0=passi;
             }
             if(state == '1' ){
                int motor1=motor;
                int passi1=passi;
             }
             if(state == '2' ){
                int motor2=motor;
                int passi2=passi;
             }
          }
      }
      
      if(state == 'j' || state == 'l'){
          mySerial.println(state);
          Me_Arm(motor,state);
       }  
    }
}


