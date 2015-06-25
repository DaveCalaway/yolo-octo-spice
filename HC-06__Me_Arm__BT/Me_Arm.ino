// Conversione in pulsazioni per servo

void Me_Arm(int motor,int target){

    if( target == 'j' )
        passi=passi+400;
    else 
        passi=passi-400;
    mySerial.println(passi);
      
    if( (passi >= 4000) && (passi <= 8000) ){
      maestro.setTarget( (motor-48), passi);
      // visualizza posizione instantanea 
      mySerial.print("motore 0: ");
      mySerial.println(passi0);
      mySerial.print("motore 1: ");
      mySerial.println(passi1);
      mySerial.print("motore 2: ");
      mySerial.println(passi2);
      
    }
    if(passi < 4000){  // fine corsa minimo
      mySerial.println("Fine corsa");
      passi=4000;
    }
    if(passi > 8000){  // fine corsa massimo
      mySerial.println("Fine corsa");
      passi=8000;
    }
    
}


