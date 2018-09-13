/*
 * Juda Alector, 6/ Sep/ 18
 * Semaforo con semaforo peatonal
*/

//Let que definen el semaforo
#define LET_RED 4
#define LET_YELLOW 5
#define LET_GREEN 6
//Lets que definen el semaforo peatonal
#define PASS 7
#define NOPASS 8

#define BUTTON 3
#define pot A0

int valorPot = 0;
boolean pressed = false;

void setup() {
  Serial.begin(9600);
  
  pinMode( LET_RED, OUTPUT );
  pinMode( LET_GREEN, OUTPUT );
  pinMode( LET_YELLOW, OUTPUT );
  pinMode( BUTTON, INPUT_PULLUP );
  pinMode( PASS, OUTPUT);
  pinMode( NOPASS, OUTPUT);
}

void loop() {
  valorPot = analogRead( pot );
  Serial.println( valorPot );
  boolean flag = false;  
  digitalWrite( LET_GREEN, HIGH );
  digitalWrite( LET_YELLOW, LOW );
  digitalWrite( LET_RED, LOW );
  digitalWrite( PASS, LOW );
  digitalWrite( NOPASS, HIGH);

  if(pressed){
    delay(10000);
    pressed = false;
  }
  
  while( digitalRead( BUTTON ) == LOW ){
    flag = true;
  }
  
  
  if( flag ){ peaton( 500 ); }
}

void peaton( int time ){  
  pressed = true;
  beatGreen( time );
  digitalWrite( LET_GREEN, LOW );
  digitalWrite( LET_YELLOW, HIGH);
  delay(2000);
  digitalWrite( LET_YELLOW, LOW);
  digitalWrite( LET_RED, HIGH );  
  
  pass( time );  
}

void beatGreen( int time ){
  for(int i = 0; i < 5; i++){
    digitalWrite( LET_GREEN, HIGH );
    delay( time );
    digitalWrite( LET_GREEN, LOW);
    delay( time );  
  }  
}

void pass( int time){
  digitalWrite( NOPASS, LOW );
  digitalWrite( PASS, HIGH );  
  delay(2000);
  beatPass( time );
  digitalWrite( NOPASS, HIGH );
}

void beatPass( int time ) {
   for(int i = 0; i < 5; i++){
    digitalWrite( PASS, HIGH );
    delay( time );
    digitalWrite( PASS, LOW );
    delay( time );
   }   
}
