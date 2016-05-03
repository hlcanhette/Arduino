/*
 * Henrique Lagamba Canhette - hlcanhette@gmail.com
 * 
 * Programa com protocolo de comunicação bluetooth.
 * Envia e recebe dados por bluetooth e imprimi no serial monitor para monitoramento.
 * Para detalhes de como conectar o bluetooth ver o diagrama.
 * É necessário ter o espelho do protocolo implementado no dispositivo que receberá os dados
 */

#include <SoftwareSerial.h> //permite comunicação serial em outros pinos do arduino além dos TX/RX

SoftwareSerial bt (4,5); //RX | TX - O RX do arduino (pin 4) deve ser conectado ao TX do bluetooth e o TX do arduino no Rx do bluetooth 

char flag; //variável auxiliar de seleção

void setup() {
  bt.begin(9600); //comunicação bluetooth
  Serial.begin(9600); //comunicação serial monitor (USB)
}

void loop() {
  if(bt.available()){ //caso tenha dado a receber
    flag = bt.read(); //ler dado bluetooth
    Serial.println(flag); //imprimir valor lido no serial monitor
    if (flag == '#'){ //verificar se valor lido não é lixo (garante a veracidade dos dados lido - protocolo de comunicação)
      for(int i=0; i<28; i++){ //laço para envio dos dados
        bt.write("#"); //defini início do envio
        bt.print(i); //dado
        bt.write("#"); //defini fim do envio
        Serial.println(i); //imprimir no serial monitor valor enviado
        }
      bt.write("!"); //defini fim do envio de dados
      flag=bt.read(); //ler dado bluetooth
      if(flag='!'){ //verificar valor lido
        Serial.println("OK"); //envio de dados finalizado corretamente
        }
      else{
        Serial.println("ERRO"); //envio de dados finalizado incorretamente
        }
      }
    }
}

/*
 * Na outra plataforma a receber os dados enviado por bluetooth é necessário implementar o espelho desde protocolo.
 * Assim, transmitirá as informações corretamente, evitando a interferência de outros dispositivos e a leitura de lixo como dado.
 */
