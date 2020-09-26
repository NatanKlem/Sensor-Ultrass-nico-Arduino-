int sinal=3;
float distancia;

int vermelho = 13;
int azul= 11;
int verde= 10;

void leitura();

void vermelhoFuncao()
{
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);
}

void verdeFuncao()
{
  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);
}

void amareloFuncao()
{
  digitalWrite(azul, 0);
  digitalWrite(verde, 50);
  digitalWrite(vermelho, 255);
}

void setup ()
{
  Serial.begin(9600);
  pinMode(sinal, OUTPUT);
  digitalWrite(sinal, LOW);
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop()
{
  leitura();
  distancia=distancia/2;
  distancia=distancia*0.034029;
  
  Serial.println(distancia);
  delay(100);
  if (distancia>=3 && distancia<100)
    vermelhoFuncao();
  else if(distancia>=110 && distancia<220)
    amareloFuncao();
    else 
    verdeFuncao();
}

void leitura()
{
  pinMode(sinal, OUTPUT);
  digitalWrite(sinal, HIGH);
  delayMicroseconds(5);
  digitalWrite(sinal, LOW); 
  
  pinMode(sinal, INPUT);
  distancia=pulseIn(sinal, HIGH);
}