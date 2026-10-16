#include <Arduino.h>

#define LORA_RX 16  // Conectado al TXD del LoRa
#define LORA_TX 17  // Conectado al RXD del LoRa
#define LORA_AUX 15 // Conectado al AUX del LoRa

int contador = 0;

void setup() {
  // Inicializa el monitor serie de la PC
  Serial.begin(115200);
  
  // Inicializa el puerto Serial2 para el LoRa (9600 baudios por defecto)
  Serial2.begin(9600, SERIAL_8N1, LORA_RX, LORA_TX);
  
  // Configura el pin AUX como entrada
  pinMode(LORA_AUX, INPUT);
  
  Serial.println("--- EMISOR LORA E220 INICIADO ---");
}

void loop() {
  // Esperar a que el pin AUX esté en HIGH (Módulo listo y libre)
  while (digitalRead(LORA_AUX) == LOW) {
    delay(1); 
  }
  
  // Construye el mensaje
  String mensaje = "HOLA LORA [" + String(contador) + "]";
  
  // Envía el mensaje al módulo LoRa
  Serial2.println(mensaje);
  
  // Muestra en el monitor serie lo que se acaba de enviar
  Serial.print("Enviando: ");
  Serial.println(mensaje);
  
  contador++;
    delay(1000); // Envía un paquete cada segundo
}


