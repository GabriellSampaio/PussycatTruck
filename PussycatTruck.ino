float sensorCentro = A1;
float sensorPontaD = A0;
float sensorPontaE = A2;
int centro;
int direita;
int esquerda;

int n1 = 6;
int n2 = 3;
int n3 = 5;
int n4 = 9;

int pwm = 100;
int nulo = 0;


void setup() {

 
  Serial.begin(9600);

  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);



}
void loop() {
  
  centro = analogRead(sensorCentro);
  direita = analogRead(sensorPontaD);
  esquerda = analogRead(sensorPontaE);

  //Serial.print ("Centro ");
  //Serial.print (centro);
  //Serial.print (" Direita ");
  //Serial.print (direita);
  //Serial.print (" Esquerda ");
  //Serial.println (esquerda);
  //delay(400);


     
    if ((centro > 100) && (esquerda < 100) && (direita < 100)){
     frente();
    }else if((centro < 100 && esquerda < 100 && direita > 100) || (centro > 100 && esquerda < 100 && direita > 100)) {
     virarDireita();
    }else if((centro < 100 && esquerda > 100 && direita < 100) || (centro > 100 && esquerda > 100 && direita < 100)) {
     virarEsquerda();
    }
      
 
}

  void frente(){
   analogWrite(n1, pwm); //motor A para frente
   analogWrite(n2, nulo); //motor B para frente
   analogWrite(n3, pwm); // motor A para tras
   analogWrite(n4, nulo); //motor B para trás

  }
  void virarDireita(){

   analogWrite(n1, pwm); //motor A para frente
   analogWrite(n2, nulo); //motor B para frente
   analogWrite(n3, nulo); // motor A para tras
   analogWrite(n4, pwm); //motor B para trás
  
  }

  void virarEsquerda(){
    
   analogWrite(n1, nulo); //motor A para frente
   analogWrite(n2, pwm); //motor B para frente
   analogWrite(n3, pwm); // motor A para tras
   analogWrite(n4, nulo); //motor B para trás

  }
  
  void parar(){
  analogWrite(n1, nulo); //parada 
  analogWrite(n2, nulo); //parada
  analogWrite(n3, nulo); // parada
  analogWrite(n4, nulo); //parada
  }
