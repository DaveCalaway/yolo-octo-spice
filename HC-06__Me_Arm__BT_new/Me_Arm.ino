// Conversione in pulsazioni per servo

void Me_Arm(int motor,int target){

    if( target == 'j' )
        passi=passi+passo;
    else 
        passi=passi-passo;
    //mySerial.println(passi);
    
    if(motor=='3'){
      if(passi <= 6000){  // fine corsa minimo
      mySerial.println("Fine corsa min");
      passi=6000;
      }
      if(passi > 7000){  // fine corsa massimo
      mySerial.println("Fine corsa max");
      passi=7000;
      }
      maestro.setTarget( (motor-48), passi);
      
    }
    
    else{
      if(passi < 4500){  // fine corsa minimo
        mySerial.println("Fine corsa min");
        passi=4500;
      }
      if(passi > 7000){  // fine corsa massimo
        mySerial.println("Fine corsa max");
        passi=7000;
      }
      maestro.setTarget( (motor-48), passi);
   }
   
   // visualizza posizione instantanea 
      mySerial.print("motore 0: ");
      mySerial.println(passi0);
      mySerial.print("motore 1: ");
      mySerial.println(passi1);
      mySerial.print("motore 2: ");
      mySerial.println(passi2);
      mySerial.print("motore 3: ");
      mySerial.println(passi3);
}


