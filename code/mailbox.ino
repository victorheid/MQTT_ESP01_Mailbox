/**********************************************************************
 *  MQTT Message + Deep Sleep for ESP8266 chips                    
 *  
 *  By Victor Heid (https://victorheid.com)
 *  
 *  Highly inspired by
 *  https://github.com/witnessmenow/push-notifications-arduino-esp8266/
 ************************************************************************/


#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//------- WiFi Settings -------
char ssid[] = "WIFI_SSID";       // your network SSID (name)
char password[] = "WIFI_PSW";  // your network key

IPAddress mqtt_server(192,168,1,4);

const char* mqtt_username = "YOUR_MQTT_USERNAME";
const char* mqtt_password = "YOUR_MQTT_PASSWORD";

WiFiClient espClient;
PubSubClient client(espClient);


void setup() {

  Serial.begin(115200);

  setup_wifi();

  client.setServer(mqtt_server, 1883);
  client.connect("MailBox", mqtt_username, mqtt_password);
  client.publish("MailBox/latch", "1");

  ESP.deepSleep(10e6);

}

void setup_wifi(){

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}




void loop() {
}
