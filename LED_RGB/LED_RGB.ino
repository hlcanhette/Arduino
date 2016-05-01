/*
 * Henrique Lagamba Canhette - hlcanhette@gmail.com
 * 
 * Programa para acender e apagar um LED RGB de 5 mm em cores aleatórias.
 */

#define R 11  //porta digital (PWM)
#define G 10  //porta digital (PWM)
#define B 12  //porta digital (PWM)

void setup() {
  pinMode(R,OUTPUT); //define o pino 11 como saída
  pinMode(G,OUTPUT); //define o pino 10 como saída
  pinMode(B,OUTPUT); //define o pino 12 como saída
}

void loop() {
  /*
   * Função random gera um número aleatório entre 0 e 255 (valor máximo passado como parâmetro)
   * Função analogWrite gera PWM no valor aleatório gerado
   */
  analogWrite(R,random(255));
  analogWrite(G,random(255));
  analogWrite(B,random(255));
  delay(1000); //aguarda 1000 milesegundos = 1 segundo
}
