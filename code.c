#include <WiFi.h>

const char* ssid = "POCOM2";
const char* password = "123456789";
WiFiServer server(80);      // Start server on port 80
int ledPin = 5;             // LED connected to GPIO5

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  WiFi.begin(ssid, password);

  // Wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.readStringUntil('\n');

    // Simple LED control
    if (request.indexOf("/ON") != -1) {
      digitalWrite(ledPin, HIGH);
    } else if (request.indexOf("/OFF") != -1) {
      digitalWrite(ledPin, LOW);
    }

    // Create HTML page
    String webpage = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    webpage += "<html><head><title>LED Control by PCS</title></head><body>";
    webpage += "<h1>LED Control by PCS</h1>";
    webpage += "<p><a href=\"/ON\">Turn ON</a></p>";
    webpage += "<p><a href=\"/OFF\">Turn OFF</a></p>";
    webpage += "</body></html>";

    client.print(webpage);
    delay(1);
    client.stop();
  }
}   
