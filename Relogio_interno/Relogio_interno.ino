/*
 * Henrique Lagamba Canhette - hlcanhette@gmail.com
 * 
 * Contador com horas, minutos e segundo utilizando o cristal interno do arduino.
 * Não é preciso mas serve de base para a maioria das aplicações.
 */

int hr=0, mi=0, se=0; //variáveis globais
  
void setup() {
  Serial.begin(9600);
  Serial.println("Iniciar contador:");
  }

void loop() {
  /*
   * Imprimir o tempo decorrido no serial monitor
  */
  Serial.print("Tempo decorrido: ");
  Serial.print(hr);
  Serial.print("h ");
  Serial.print(mi);
  Serial.print("min ");
  Serial.print(se);
  Serial.println("s");
  
  delay(1000); //atraso de 1000 milisegundos = 1 segundo

  /*
   * Atualizar variáveis de acordo com a relação 60 segundo = 1 min e 60 min = 1 hora
   */
  if (se<60){
    se = se + 1;
    }
  else{
    se = 0;
    if(mi<60){
      mi = mi + 1;
      }
    else{
      mi = 0;
      hr = hr + 1;
      }
    }
  }
    


