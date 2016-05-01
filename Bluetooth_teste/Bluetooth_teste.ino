/*
 * Henrique Lagamba Canhette - hlcanhette@gmail.com
 * 
 * Programa para testar os módulos bluetooth HC-05 e HC-06.
 * Envia e recebe dados por bluetooth e serial monitor.
 * Para detalhes de como conectar ver o diagrama.
 * É necessário utilizar um terminal bluetooth no PC ou num smartphone para receber e enviar as informações.
 * Pc:
 * Android:
 */
 
#include <SoftwareSerial.h> //permite comunicação serial em outros pinos do arduino além dos TX/RX

SoftwareSerial bt(4, 5); // RX | TX - O RX do arduino (pin 4) deve ser conectado ao TX do bluetooth e o TX do arduino no Rx do bluetooth 
 
char c=' ';
 
void setup(){
  Serial.begin(9600); //comunicação serial com o PC
  Serial.println("Teste de comunicação HC-0x");
 
  bt.begin(9600); //comunicação bluetooth com dispositivo(Android ou PC)
  }
 
void loop(){
  if (bt.available()){ //verificar se existe dado bluetooth para receber
    c = bt.read(); //ler dado
    Serial.write(c); //enviar dado via serial ao PC(serial monitor)
    }
 
  if (Serial.available()){ //verificar se existe dado serial para receber
    c = Serial.read(); //ler dado
    bt.write(c); //enviar dado via bluetooth ao bluetooh terminal (Android ou PC)
    }
  }
