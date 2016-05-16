/*
 * Henrique Lagamba Canhette - hlcanhette@gmail.com
 * 
 * Programa que lê sensor LDR e aciona LED caso valor reduza 70% em relação a luminosidade inicial.
 */

#define LED 10 //definir pino digital 10 como LED
#define LDR A0 //definir pino analógico A0 como LDR

float luz = 0; //iniciar variável luz de referência

void setup() {
  pinMode(LED, OUTPUT); //definir pino 10 como saída
  digitalWrite(LED, LOW); //iniciar pino 10 com zero
  for (int i=0;i<100;i++){ //loop para calcular a luminosidade de referência
    luz = luz + analogRead(LDR); //ler porta analógica
    }
  luz = luz/100; //calcular a média
  luz = luz*0.7; //aplicar coeficiente de tolerância para acionamento do LED
}

void loop() {
  float luz_atual = 0; //zerar luz atual
  for (int i=0;i<100;i++){ //loop para eleminar ruído na medida da luminosidade atual
    luz_atual = luz_atual + analogRead(LDR); //ler porta analógica
    }
  luz_atual = luz_atual/100; //calcular média
  if (luz_atual<=luz){ //comparar se valor da luminosidade está ao menos 70% menor
    digitalWrite(LED, HIGH); //caso sim acender o LED
    }
  else{
    digitalWrite(LED, LOW); //caso não apagar LED
    }
}
