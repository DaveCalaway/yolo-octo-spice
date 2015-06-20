// Conversione in pulsazioni per servo

void Me_Arm(int motor,int target){
    //stateold=target;
    
    if( target == 'j' )
        passi=passi+400;
    else 
        passi=passi-400;
  
      
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
