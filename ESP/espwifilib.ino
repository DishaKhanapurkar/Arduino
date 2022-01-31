#include <WiFi.h>
#include<EEPROM.h>
#define EEPROM_SIZE 100

# define keypress 2
int key=0;
String ssid="abc";
String passw="pass";
int ssid_add=10;
int passw_add=40;
 void initWiFi();
void setup() {
  Serial.begin(115200);
   EEPROM.begin(EEPROM_SIZE);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  //WiFi.mode(WIFI_STA);
  //WiFi.disconnect();
  //delay(100);
  pinMode(keypress, INPUT);
  //Serial.println("Setup done");
  initWiFi();
  Serial.print(EEPROM.read(0));
  if(EEPROM.read(0)==1)
  {
    
    EEPROM.write(0,key);
    EEPROM.commit();
     ssid="raj";
    passw="1234567890";
    EEPROM.writeString(ssid_add,ssid); 
    EEPROM.writeString(passw_add,passw);
    EEPROM.commit();
    Serial.print("ssid");
    Serial.println(ssid);
     Serial.print("passw");
    Serial.println(passw);
  }
  else
  {
   

    ssid="abc";
    passw="pass";
   EEPROM.writeString(ssid_add,ssid); 
    EEPROM.writeString(passw_add,passw);
    EEPROM.commit();
     Serial.print("ssid");
    Serial.println(ssid);
     Serial.print("passw");
    Serial.println(passw);
    
    
  }
}

void loop() {
  //println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  /*int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
      Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");

  // Wait a bit before scanning again*/
  
  if(digitalRead(keypress)==HIGH)
  {
    key=1;
    ssid="raj";
    passw="1234567890";
    EEPROM.writeString(ssid_add,ssid); 
    EEPROM.writeString(passw_add,passw);
    delay(10);
    EEPROM.commit();
    Serial.print("keypressed");
    //Serial.print(EEPROM.read(0));
    
  }
  else
  {
  key=0;
  }
}
void initWiFi() {
  String t_ssid=EEPROM.readString(ssid_add);
    String t_passw=EEPROM.readString(passw_add);
    char buf3[t_ssid.length()+1];
    ssid.toCharArray(buf3,sizeof(buf3));
    char*ssid_point=buf3;
    
    char buf4[t_passw.length()+1];
    ssid.toCharArray(buf4,sizeof(buf4));
     char*passw_point=buf4;
     Serial.print("ssideeprom");
     Serial.println(t_ssid);
      Serial.print("passweeprom");
     Serial.println(t_passw);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid_point, passw_point);
  //EEPROM.readString(ssid_add,passw_add);
  Serial.print("Connecting to WiFi ..");
  /*while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }*/
  delay(5000);
  Serial.println(WiFi.localIP());
  
}
