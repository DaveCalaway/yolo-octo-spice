/* Il programma collega un terminale Bluetooth al modulo Maestro per comandare i motori del Me Arm.
Alla pressione del tasto 'a' comunica un avviso del progetto. 
Alla pressione d'un numero da 0 a 2 seleziona uno dei tre motori.
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

char state=0;
int motor=0;
int passi=5500;
int passi0=5500;
int passi1=5500;
int passi2=5500;
int oldm=0;

int passo=400; //precisione minima del passo 

MicroMaestro maestro(maestroSerial);


void setup() {
    maestroSerial.begin(9600);  // Default connection rate for Maestro module
    maestro.setTarget(0, 5500);  // Posizione di riposo
    mySerial.begin(19200); // Default connection rate for my BT module    
    
}

void loop() {
  if(mySerial.available() > 0){
    
      state = mySerial.read();      
      
      if (state == 'a') 
        mySerial.println("Benveuto nel programma di prova MeArm Bluetooth\n");
      
      if(state == '0' || state == '1' || state == '2' ){    
        
          mySerial.print("Hai selezionato il motore:");
          mySerial.println(state);
          motor=state;
          
          if(motor == '0' && oldm != motor )  // passagli l'ultima posizione motore
                 passi=passi0;   
                 
          if(state == '1' && oldm != motor )
                 passi=passi1;
          
          if(state == '2' && oldm != motor)
                 passi=passi2;
          
      }
  
      if(state == 'j' || state == 'l'){
          mySerial.println(state);
          Me_Arm(motor,state);        // chiamo funzione
          
          oldm=motor;         // salva posizione del motore
          if(motor == '0')
              passi0=passi;
          if(motor=='1')
              passi1=passi;
          if(motor=='2')
              passi2=passi;
      }  
  }//serial.available
}

