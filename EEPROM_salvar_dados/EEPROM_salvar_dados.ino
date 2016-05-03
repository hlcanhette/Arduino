/*
 * Henrique Lagamba Canhette - hlcanhette@gmail.com
 * 
 * Programa que salva dados na EEPROM flash do Arduino ler valor salvo.
 * Quando o dado é salvo na EEPROM ele fica salvo mesmo se o Arduino for desligado.
 * Para o Arduino Uno a EEPROM é de 1k byte de 8 bits, ou seja 1024 endereços de memória podendo armazenar 8 bits (até 255) em cada um 
 */

#include<EEPROM.h> //biblioteca para trabalhar com a EEPROM

/*
 * Função para zerar toda a EEPROM
 */
void limpar(){
  int a = 0;
  for(int i=0 ;i<1024;i++){
    EEPROM.write(i, a); //i=endereço da EEPROM, a = valor entre 0 e 255 a ser salvo na EEPROM
    Serial.println(i);
    }
  }

void setup(){
  Serial.begin(9600);
  limpar(); //chamr função para zerar EEPROM
  }

void loop() {
  Serial.println("*------------------INICIO--------------------*");
  for(int i=0 ;i<=1024;i++){
    Serial.println(EEPROM.read(i)); //endereco da EEPROM a ser lido
    }
  Serial.println("*------------------FIM--------------------*");
  Serial.println("*------------------Casos Especiais--------------------*");
  int b = 1563; //valor acima de 255
  int c = -100; //valor negativo
  EEPROM.write(10, b); //salvará na EEPROM os 8 bits menos significativos
  EEPROM.write(11, c); //salvará na EEPROM como se fosse um número positivo
  Serial.println(EEPROM.read(10));
  Serial.println(EEPROM.read(11));
  Serial.println(EEPROM.read(1304)); //endereço de memória fora do range da EEPROM - imprimirá o endereço referente aos bits menos significativos igual o caso da variável "b"
  Serial.println("*------------------FIM - Casos Especiais--------------------*");
}
