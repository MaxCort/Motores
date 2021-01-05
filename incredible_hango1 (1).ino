int Pin1 = 9;       // Pone las pins para el sensor L293D
int Pin2 = 10;
int Rin = 11;

int a = 0;  // Define variables de velocidad y posicion
int b = 0;

void setup()
{
  pinMode(Pin1, OUTPUT);  //Seleccionamos Pins
  pinMode(Pin2, OUTPUT);
  pinMode(Rin, OUTPUT);
}

void loop() {
  int potencia = analogRead(A0);  // Lee valor de Potenciometro
  b = map(abs(potencia - 512), 0, 512, 0, 255); // Calcula la velocidad con respecto al punto medio
  if (potencia > 512) // Comparacion del potenciometro
    {
      a = 0;
    }
  else
  {
    a = 1;
  } 
  MovMotor(); //Llama funcion para la direccion
}

void MovMotor() 
{
  if (a)
  {
    digitalWrite(Pin2, HIGH);
    digitalWrite(Pin1, LOW);
  }
  else
  {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin1, HIGH);
  }
  analogWrite(Rin, b);
}