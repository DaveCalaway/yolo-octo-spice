// Conversione in pulsazioni per servo
void Me_Arm(int motor,int target){

    if( target == 'j' )
        passi=passi+400;
    else 
        passi=passi-400;
        
    Serial.println((motor-48));
    Serial.println(passi);
      
    if( (passi >= 4000) && (passi <= 8000) ){
      maestro.setTarget( (motor-48), passi);
      
      // visualizza posizione instantanea 
      Serial.print("motore 0: ");
      Serial.println(passi0);
      Serial.print("motore 1: ");
      Serial.println(passi1);
      Serial.print("motore 2: ");
      Serial.println(passi2);
    }
    
    if(passi < 4000){  // fine corsa minimo
      Serial.println("Fine corsa");
      passi=4000;
    }
    if(passi > 8000){  // fine corsa massimo
      Serial.println("Fine corsa");
      passi=8000;
    }
    
}
