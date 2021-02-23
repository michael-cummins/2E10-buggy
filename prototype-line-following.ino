const int LEYE = 15; //left eye
const int REYE = 14; //right  
const int l_backward = 12;
const int l_forward = 16;
const int r_forward = 17;
const int r_backward = 19;

void move_forward()
{
  digitalWrite(r_forward, HIGH);
  digitalWrite(r_backward, LOW);  
  digitalWrite(l_forward, HIGH);
  digitalWrite(l_backward, LOW); 
}

void move_right()
{
  digitalWrite(r_forward, LOW);
  digitalWrite(r_backward, HIGH);  
  digitalWrite(l_forward, HIGH);
  digitalWrite(l_backward, LOW); 
}

/*void reverse(){
  digitalWrite(r_forward, LOW);
  digitalWrite(r_backward, HIGH);  
  digitalWrite(l_forward, LOW);
  digitalWrite(l_backward, LOW); 
}*/

void move_left()
{
  digitalWrite(r_forward, HIGH);
  digitalWrite(r_backward, LOW);  
  digitalWrite(l_forward, LOW);
  digitalWrite(l_backward, LOW); 
}

void stop_(){
  digitalWrite(r_forward, LOW);
  digitalWrite(r_backward, HIGH);  
  digitalWrite(l_forward, LOW);
  digitalWrite(l_backward, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode( l_forward, OUTPUT );
  pinMode( r_backward, OUTPUT );
  pinMode( l_backward, OUTPUT );
  pinMode( l_forward, OUTPUT );
  pinMode( LEYE, INPUT );
  pinMode( REYE, INPUT );
  stop_();
  delay(5000);
  move_forward();
}

void loop() {
  if((digitalRead( REYE ) != HIGH) || (digitalRead( LEYE ) != HIGH)){
    if((digitalRead( REYE ) != HIGH) && (digitalRead( LEYE ) != HIGH)){
      stop_();
    }
    else if(digitalRead( REYE ) != HIGH){
      Serial.println("working");
      move_right();
    }
    else{
      move_left();
    }
  } 
  else{
    move_forward();
  }
  //delay(30);
  /*if((digitalRead( REYE ) != HIGH) && (digitalRead( LEYE ) != HIGH)){
      stop_();
    }
    else{
      move_forward();
    }*/
  //move_forward();
}
