/* L'esercizio mostra il movimento di 3 motori contemporanemanete, con relative accellerazioni e velocità. 
*/

#include <PololuMaestro.h>

#ifdef SERIAL_PORT_HARDWARE_OPEN
  #define maestroSerial SERIAL_PORT_HARDWARE_OPEN
#else
  #include <SoftwareSerial.h>
  SoftwareSerial maestroSerial(10, 11); //11 ricezione non necessaria qui
#endif

MicroMaestro maestro(maestroSerial);

void setup()
{
  maestroSerial.begin(9600);
}

void loop()
{
	//con la funzione setSpeed imposto il numero del motore, la sua velicità
  maestro.setSpeed(0, 20); 
  maestro.setSpeed(1, 10); 
  maestro.setSpeed(2, 10); 
	//con la funzione setAcceleration imposto il numero del motore, la sua 	accellerazione . Questo numero è compreso tra 0 ( accelerazione massima ) e 255
  maestro.setAcceleration(0, 200);
  maestro.setAcceleration(1, 200);
  maestro.setAcceleration(2, 200);

	//con la funzione setTarget imposto una posizione al motore, tipicamente tra 4000 e 8000
  maestro.setTarget(0, 6000);
  maestro.setTarget(1, 4000);
  maestro.setTarget(2, 4000);
  delay(3000); //aspetto 3 secondi prima di passare alla prossima posizione
  
  maestro.setTarget(0, 4000);
  maestro.setTarget(1, 6000);
  maestro.setTarget(2, 6000);
  delay(3000);
  

}
