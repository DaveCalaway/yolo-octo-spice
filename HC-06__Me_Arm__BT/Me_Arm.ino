// Conversione in pulsazioni per servo

void Me_Arm(int motor,int target){
  
    /*Serial.print("chiamata funzione con:");
    Serial.print(motor);
    Serial.print("--");
    Serial.println(target);
    */
    
    if( target == 'j' )
        passi=passi+400;
    else 
        passi=passi-400;
        
    mySerial.println((motor-48));
    mySerial.println(passi);
    //maestro.setTarget((motor-48), passi);
      
    if( (passi > 4000) && (passi < 8000) ){
      maestro.setTarget( (motor-48), passi);
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
