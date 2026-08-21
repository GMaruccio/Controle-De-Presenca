#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Keypad.h>

// Credenciais da rede Wi-Fi virtual do Wokwi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// IMPORTANTE: Coloque o IPv4 da sua máquina e a rota do seu Node-RED
const char* serverName = "http://192.168.102.23:1880/presenca"; 

// --- Configuração do Teclado Matricial 4x4 ---
const byte ROWS = 4; // 4 linhas
const byte COLS = 4; // 4 colunas

// Mapa de caracteres do teclado
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Pinos do ESP32 conectados às Linhas (R1, R2, R3, R4)
byte rowPins[ROWS] = {19, 18, 5, 17}; 
// Pinos do ESP32 conectados às Colunas (C1, C2, C3, C4)
byte colPins[COLS] = {16, 4, 2, 15}; 

// Cria o objeto do teclado
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Variável que vai "acumulando" os números digitados
String raAcumulado = ""; 

void enviarPresenca(String ra) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");
    
    // Monta o payload JSON
    String httpRequestData = "{\"ra\":\"" + ra + "\"}";
    
    Serial.println("\n[HTTP] Disparando POST...");
    int httpResponseCode = http.POST(httpRequestData);
    
    if (httpResponseCode > 0) {
      Serial.print("[Sucesso] Código HTTP: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("[Erro] Código HTTP: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("\nErro: WiFi Desconectado!");
  }
}

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi Wokwi-GUEST");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\n--- SISTEMA DE PRESENÇA INICIADO ---");
  Serial.println("-> Digite o RA do aluno no teclado.");
  Serial.println("-> Pressione '#' para CONFIRMAR.");
  Serial.println("-> Pressione '*' para APAGAR TUDO.");
  Serial.println("------------------------------------");
}

void loop() {
  // Lê a tecla pressionada naquele exato milissegundo
  char key = keypad.getKey();

  if (key) {
    // Se a tecla pressionada for o jogo da velha (#) -> ENVIAR
    if (key == '#') {
      if (raAcumulado.length() > 0) {
        Serial.println("\nFinalizado! Enviando RA: " + raAcumulado);
        enviarPresenca(raAcumulado);
        
        // Limpa a variável para o próximo aluno
        raAcumulado = ""; 
        Serial.println("\nPronto para o próximo RA...");
      } else {
        Serial.println("\nNenhum RA digitado! Digite algo antes de apertar #.");
      }
    } 
    // Se a tecla for o asterisco (*) -> APAGAR/CANCELAR
    else if (key == '*') {
      raAcumulado = "";
      Serial.println("\n[RA Apagado] Comece a digitar novamente.");
    } 
    // Qualquer outra tecla (Números ou Letras ABCD) -> ACUMULAR
    else {
      raAcumulado += key;
      // Mostra a tecla sendo digitada na mesma linha do terminal
      Serial.print(key); 
    }
  }
}