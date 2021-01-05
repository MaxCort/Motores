int Pin1 = 9;       // Define el pin L293D
int Pin2 = 10;
int Rin = 11;

int a = 0;  // a= Direccion y b= Velocidad
int b = 0;

void setup()
{
  pinMode(Pin1, OUTPUT);  // Definiendo pins
  pinMode(Pin2, OUTPUT);
  pinMode(Rin, OUTPUT);
}

void loop() {
  int potencia = analogRead(A0);  // Leer Valores de Potenciometro
  b = map(abs(potencia), 0, 1023, 0, 255); // Calcula la velocidad de motor y regresa al punto medio
  driveMotor(); 
}

void driveMotor() 
{
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin1, HIGH);
  analogWrite(Rin, b);
}