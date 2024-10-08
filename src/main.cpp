#include <easydmx.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <EEPROM.h>

#define BUTTON_1 00
#define BUTTON_2 01
#define SSID "Sheesh-Knopf"
#define PASS "187doner"

EasyDMX dmx;
IPAddress local_ip(192, 168, 0, 1);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
AsyncWebServer server(80);

uint16_t startadresse1_0;
uint16_t startadresse1_1;
uint16_t startadresse1_2;
uint16_t startadresse1_3;
uint16_t startadresse1_4;
uint16_t startadresse1_5;
uint16_t startadresse1_6;
uint16_t startadresse1_7;
uint16_t startadresse1_8;
uint16_t startadresse1_9;
uint16_t startadresse2_0;
uint16_t startadresse2_1;
uint16_t startadresse2_2;
uint16_t startadresse2_3;
uint16_t startadresse2_4;
uint16_t startadresse2_5;
uint16_t startadresse2_6;
uint16_t startadresse2_7;
uint16_t startadresse2_8;
uint16_t startadresse2_9;
uint8_t chanwert1_0;
uint8_t chanwert1_1;
uint8_t chanwert1_2;
uint8_t chanwert1_3;
uint8_t chanwert1_4;
uint8_t chanwert1_5;
uint8_t chanwert1_6;
uint8_t chanwert1_7;
uint8_t chanwert1_8;
uint8_t chanwert1_9;
uint8_t chanwert2_0;
uint8_t chanwert2_1;
uint8_t chanwert2_2;
uint8_t chanwert2_3;
uint8_t chanwert2_4;
uint8_t chanwert2_5;
uint8_t chanwert2_6;
uint8_t chanwert2_7;
uint8_t chanwert2_8;
uint8_t chanwert2_9;


void setup()
{
    LittleFS.begin(true);
    dmx.begin(DMXMode::Both, 20, 21);
    EEPROM.begin(7);
    startadresse1_0 = EEPROM.read(0) | (EEPROM.read(1) << 8);
    startadresse1_1 = EEPROM.read(0) | (EEPROM.read(1) << 8);    
    startadresse1_2 = EEPROM.read(0) | (EEPROM.read(1) << 8);
    startadresse1_3 = EEPROM.read(0) | (EEPROM.read(1) << 8);
    startadresse1_4 = EEPROM.read(0) | (EEPROM.read(1) << 8);
    startadresse1_5 = EEPROM.read(0) | (EEPROM.read(1) << 8);
    startadresse1_6 = EEPROM.read(0) | (EEPROM.read(1) << 8);
    startadresse1_7 = EEPROM.read(0) | (EEPROM.read(1) << 8);
    startadresse1_8	= EEPROM.read(0) | (EEPROM.read(1) << 8);
    startadresse1_9 = EEPROM.read(0) | (EEPROM.read(1) << 8);
    startadresse2_0 = EEPROM.read(2) | (EEPROM.read(3) << 8);
    startadresse2_1 = EEPROM.read(2) | (EEPROM.read(3) << 8);
    startadresse2_2 = EEPROM.read(2) | (EEPROM.read(3) << 8);
    startadresse2_3 = EEPROM.read(2) | (EEPROM.read(3) << 8);
    startadresse2_4 = EEPROM.read(2) | (EEPROM.read(3) << 8);
    startadresse2_5 = EEPROM.read(2) | (EEPROM.read(3) << 8);
    startadresse2_6 = EEPROM.read(2) | (EEPROM.read(3) << 8);
    startadresse2_7 = EEPROM.read(2) | (EEPROM.read(3) << 8);
    startadresse2_8 = EEPROM.read(2) | (EEPROM.read(3) << 8);
    startadresse2_9 = EEPROM.read(2) | (EEPROM.read(3) << 8);
    chanwert1_0 = EEPROM.read(4) | (EEPROM.read(5) << 8);
    chanwert1_1 = EEPROM.read(4) | (EEPROM.read(5) << 8);
    chanwert1_2 = EEPROM.read(4) | (EEPROM.read(5) << 8);
    chanwert1_3 = EEPROM.read(4) | (EEPROM.read(5) << 8);
    chanwert1_4 = EEPROM.read(4) | (EEPROM.read(5) << 8);
    chanwert1_5 = EEPROM.read(4) | (EEPROM.read(5) << 8);
    chanwert1_6 = EEPROM.read(4) | (EEPROM.read(5) << 8);
    chanwert1_7 = EEPROM.read(4) | (EEPROM.read(5) << 8);
    chanwert1_8 = EEPROM.read(4) | (EEPROM.read(5) << 8);
    chanwert1_9 = EEPROM.read(4) | (EEPROM.read(5) << 8);
    chanwert2_0 = EEPROM.read(6) | (EEPROM.read(7) << 8);
    chanwert2_1 = EEPROM.read(6) | (EEPROM.read(7) << 8);
    chanwert2_2 = EEPROM.read(6) | (EEPROM.read(7) << 8);
    chanwert2_3 = EEPROM.read(6) | (EEPROM.read(7) << 8);
    chanwert2_4 = EEPROM.read(6) | (EEPROM.read(7) << 8);
    chanwert2_5 = EEPROM.read(6) | (EEPROM.read(7) << 8);
    chanwert2_6 = EEPROM.read(6) | (EEPROM.read(7) << 8);
    chanwert2_7 = EEPROM.read(6) | (EEPROM.read(7) << 8);
    chanwert2_8 = EEPROM.read(6) | (EEPROM.read(7) << 8);
    chanwert2_9 = EEPROM.read(6) | (EEPROM.read(7) << 8);

    pinMode(BUTTON_1, INPUT_PULLUP);
    pinMode(BUTTON_2, INPUT_PULLUP);

    WiFi.softAPConfig(local_ip, gateway, subnet);
    WiFi.softAP(SSID, PASS);

    server.on("/werte_bekommen", HTTP_GET, [](AsyncWebServerRequest *request)
              {
        JsonDocument doc;
        doc["startadresse1_0"] = startadresse1_0;
        doc["startadresse1_1"] = startadresse1_1;
        doc["startadresse1_2"] = startadresse1_2;
        doc["startadresse1_3"] = startadresse1_3;
        doc["startadresse1_4"] = startadresse1_4;
        doc["startadresse1_5"] = startadresse1_5;
        doc["startadresse1_6"] = startadresse1_6;
        doc["startadresse1_7"] = startadresse1_7;
        doc["startadresse1_8"] = startadresse1_8;
        doc["startadresse1_9"] = startadresse1_9;
        doc["startadresse2_0"] = startadresse2_0;
        doc["startadresse2_1"] = startadresse2_1;
        doc["startadresse2_2"] = startadresse2_2;
        doc["startadresse2_3"] = startadresse2_3;
        doc["startadresse2_4"] = startadresse2_4;
        doc["startadresse2_5"] = startadresse2_5;
        doc["startadresse2_6"] = startadresse2_6;
        doc["startadresse2_7"] = startadresse2_7;
        doc["startadresse2_8"] = startadresse2_8;
        doc["startadresse2_9"] = startadresse2_9;
        doc["chanwert1_0"] = chanwert1_0;
        doc["chanwert1_1"] = chanwert1_1;
        doc["chanwert1_2"] = chanwert1_2;
        doc["chanwert1_3"] = chanwert1_3;
        doc["chanwert1_4"] = chanwert1_4;
        doc["chanwert1_5"] = chanwert1_5;
        doc["chanwert1_6"] = chanwert1_6;
        doc["chanwert1_7"] = chanwert1_7;
        doc["chanwert1_8"] = chanwert1_8;
        doc["chanwert1_9"] = chanwert1_9;
        doc["chanwert2_0"] = chanwert2_0;
        doc["chanwert2_1"] = chanwert2_1;
        doc["chanwert2_2"] = chanwert2_2;
        doc["chanwert2_3"] = chanwert2_3;
        doc["chanwert2_4"] = chanwert2_4;
        doc["chanwert2_5"] = chanwert2_5;
        doc["chanwert2_6"] = chanwert2_6;
        doc["chanwert2_7"] = chanwert2_7;
        doc["chanwert2_8"] = chanwert2_8;
        doc["chanwert2_9"] = chanwert2_9;
        String output;
        serializeJson(doc, output);
        request->send(200, "application/json", output); });

    server.on("/werte_setzen", HTTP_GET, [](AsyncWebServerRequest *request)
              {
        if (request->hasParam("startadresse1_0", false)) {
            startadresse1_0 = request->getParam("startadresse1_0", false)->value().toInt();
            EEPROM.write(0, startadresse1_0 & 0xFF);
            EEPROM.write(1, (startadresse1_0 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse1_1", false)) {
            startadresse1_1 = request->getParam("startadresse1_1", false)->value().toInt();
            EEPROM.write(0, startadresse1_1 & 0xFF);
            EEPROM.write(1, (startadresse1_1 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse1_2", false)) {
            startadresse1_2 = request->getParam("startadresse1_2", false)->value().toInt();
            EEPROM.write(0, startadresse1_2 & 0xFF);
            EEPROM.write(1, (startadresse1_2 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse1_3", false)) {
            startadresse1_3 = request->getParam("startadresse1_3", false)->value().toInt();
            EEPROM.write(0, startadresse1_3 & 0xFF);
            EEPROM.write(1, (startadresse1_3 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse1_4", false)) {
            startadresse1_4 = request->getParam("startadresse1_4", false)->value().toInt();
            EEPROM.write(0, startadresse1_4 & 0xFF);
            EEPROM.write(1, (startadresse1_4 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse1_5", false)) {
            startadresse1_5 = request->getParam("startadresse1_5", false)->value().toInt();
            EEPROM.write(0, startadresse1_5 & 0xFF);
            EEPROM.write(1, (startadresse1_5 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse1_6", false)) {
            startadresse1_6 = request->getParam("startadresse1_6", false)->value().toInt();
            EEPROM.write(0, startadresse1_6 & 0xFF);
            EEPROM.write(1, (startadresse1_6 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse1_7", false)) {
            startadresse1_7 = request->getParam("startadresse1_7", false)->value().toInt();
            EEPROM.write(0, startadresse1_7 & 0xFF);
            EEPROM.write(1, (startadresse1_7 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse1_8", false)) {
            startadresse1_8 = request->getParam("startadresse1_8", false)->value().toInt();
            EEPROM.write(0, startadresse1_8 & 0xFF);
            EEPROM.write(1, (startadresse1_8 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse1_9", false)) {
            startadresse1_9 = request->getParam("startadresse1_9", false)->value().toInt();
            EEPROM.write(0, startadresse1_9 & 0xFF);
            EEPROM.write(1, (startadresse1_9 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse2_0", false)) {
            startadresse2_0 = request->getParam("startadresse2_0", false)->value().toInt();
            EEPROM.write(2, startadresse2_0 & 0xFF);
            EEPROM.write(3, (startadresse2_0 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse2_1", false)) {
            startadresse2_1 = request->getParam("startadresse2_1", false)->value().toInt();
            EEPROM.write(2, startadresse2_1 & 0xFF);
            EEPROM.write(3, (startadresse2_1 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse2_2", false)) {
            startadresse2_2 = request->getParam("startadresse2_2", false)->value().toInt();
            EEPROM.write(2, startadresse2_2 & 0xFF);
            EEPROM.write(3, (startadresse2_2 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse2_3", false)) {
            startadresse2_3 = request->getParam("startadresse2_3", false)->value().toInt();
            EEPROM.write(2, startadresse2_3 & 0xFF);
            EEPROM.write(3, (startadresse2_3 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse2_4", false)) {
            startadresse2_4 = request->getParam("startadresse2_4", false)->value().toInt();
            EEPROM.write(2, startadresse2_4 & 0xFF);
            EEPROM.write(3, (startadresse2_4 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse2_5", false)) {
            startadresse2_5 = request->getParam("startadresse2_5", false)->value().toInt();
            EEPROM.write(2, startadresse2_5 & 0xFF);
            EEPROM.write(3, (startadresse2_5 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse2_6", false)) {
            startadresse2_6 = request->getParam("startadresse2_6", false)->value().toInt();
            EEPROM.write(2, startadresse2_6 & 0xFF);
            EEPROM.write(3, (startadresse2_6 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse2_7", false)) {
            startadresse2_7 = request->getParam("startadresse2_7", false)->value().toInt();
            EEPROM.write(2, startadresse2_7 & 0xFF);
            EEPROM.write(3, (startadresse2_7 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse2_8", false)) {
            startadresse2_8 = request->getParam("startadresse2_8", false)->value().toInt();
            EEPROM.write(2, startadresse2_8 & 0xFF);
            EEPROM.write(3, (startadresse2_8 >> 8) & 0xFF);
        }
        if (request->hasParam("startadresse2_9", false)) {
            startadresse2_9 = request->getParam("startadresse2_9", false)->value().toInt();
            EEPROM.write(2, startadresse2_9 & 0xFF);
            EEPROM.write(3, (startadresse2_9 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert1_0", false)) {
            chanwert1_0 = request->getParam("chanwert1_0", false)->value().toInt();
            EEPROM.write(4, chanwert1_0 & 0xFF);
            EEPROM.write(5, (chanwert1_0 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert1_1", false)) {
            chanwert1_1 = request->getParam("chanwert1_1", false)->value().toInt();
            EEPROM.write(4, chanwert1_1 & 0xFF);
            EEPROM.write(5, (chanwert1_1 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert1_2", false)) {
            chanwert1_2 = request->getParam("chanwert1_2", false)->value().toInt();
            EEPROM.write(4, chanwert1_2 & 0xFF);
            EEPROM.write(5, (chanwert1_2 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert1_3", false)) {
            chanwert1_3 = request->getParam("chanwert1_3", false)->value().toInt();
            EEPROM.write(4, chanwert1_3 & 0xFF);
            EEPROM.write(5, (chanwert1_3 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert1_4", false)) {
            chanwert1_4 = request->getParam("chanwert1_4", false)->value().toInt();
            EEPROM.write(4, chanwert1_4 & 0xFF);
            EEPROM.write(5, (chanwert1_4 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert1_5", false)) {
            chanwert1_5 = request->getParam("chanwert1_5", false)->value().toInt();
            EEPROM.write(4, chanwert1_5 & 0xFF);
            EEPROM.write(5, (chanwert1_5 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert1_6", false)) {
            chanwert1_6 = request->getParam("chanwert1_6", false)->value().toInt();
            EEPROM.write(4, chanwert1_6 & 0xFF);
            EEPROM.write(5, (chanwert1_6 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert1_7", false)) {
            chanwert1_7 = request->getParam("chanwert1_7", false)->value().toInt();
            EEPROM.write(4, chanwert1_7 & 0xFF);
            EEPROM.write(5, (chanwert1_7 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert1_8", false)) {
            chanwert1_8 = request->getParam("chanwert1_8", false)->value().toInt();
            EEPROM.write(4, chanwert1_8 & 0xFF);
            EEPROM.write(5, (chanwert1_8 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert1_9", false)) {
            chanwert1_9 = request->getParam("chanwert1_9", false)->value().toInt();
            EEPROM.write(4, chanwert1_9 & 0xFF);
            EEPROM.write(5, (chanwert1_9 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert2_0", false)) {
            chanwert2_0 = request->getParam("chanwert2_0", false)->value().toInt();
            EEPROM.write(6, chanwert2_0 & 0xFF);
            EEPROM.write(7, (chanwert2_0 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert2_1", false)) {
            chanwert2_1 = request->getParam("chanwert2_1", false)->value().toInt();
            EEPROM.write(6, chanwert2_1 & 0xFF);
            EEPROM.write(7, (chanwert2_1 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert2_2", false)) {
            chanwert2_2 = request->getParam("chanwert2_2", false)->value().toInt();
            EEPROM.write(6, chanwert2_2 & 0xFF);
            EEPROM.write(7, (chanwert2_2 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert2_3", false)) {
            chanwert2_3 = request->getParam("chanwert2_3", false)->value().toInt();
            EEPROM.write(6, chanwert2_3 & 0xFF);
            EEPROM.write(7, (chanwert2_3 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert2_4", false)) {
            chanwert2_4 = request->getParam("chanwert2_4", false)->value().toInt();
            EEPROM.write(6, chanwert2_4 & 0xFF);
            EEPROM.write(7, (chanwert2_4 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert2_5", false)) {
            chanwert2_5 = request->getParam("chanwert2_5", false)->value().toInt();
            EEPROM.write(6, chanwert2_5 & 0xFF);
            EEPROM.write(7, (chanwert2_5 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert2_6", false)) {
            chanwert2_6 = request->getParam("chanwert2_6", false)->value().toInt();
            EEPROM.write(6, chanwert2_6 & 0xFF);
            EEPROM.write(7, (chanwert2_6 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert2_7", false)) {
            chanwert2_7 = request->getParam("chanwert2_7", false)->value().toInt();
            EEPROM.write(6, chanwert2_7 & 0xFF);
            EEPROM.write(7, (chanwert2_7 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert2_8", false)) {
            chanwert2_8 = request->getParam("chanwert2_8", false)->value().toInt();
            EEPROM.write(6, chanwert2_8 & 0xFF);
            EEPROM.write(7, (chanwert2_8 >> 8) & 0xFF);
        }
        if (request->hasParam("chanwert2_9", false)) {
            chanwert2_9 = request->getParam("chanwert2_9", false)->value().toInt();
            EEPROM.write(6, chanwert2_9 & 0xFF);
            EEPROM.write(7, (chanwert2_9 >> 8) & 0xFF);
        }
        EEPROM.commit();

        request->send(200, "text/plain", "success"); });

    server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");

    server.begin();
}

void loop()
{
    for (int i = 1; i <= 512; i++)
    {
        
        if (digitalRead(BUTTON_1) == LOW)
        {
            dmx.setChannel(startadresse1_0, chanwert1_0);
            dmx.setChannel(startadresse1_1, chanwert1_1);
            dmx.setChannel(startadresse1_2, chanwert1_2);
            dmx.setChannel(startadresse1_3, chanwert1_3);
            dmx.setChannel(startadresse1_4, chanwert1_4);
            dmx.setChannel(startadresse1_5, chanwert1_5);
            dmx.setChannel(startadresse1_6, chanwert1_6);
            dmx.setChannel(startadresse1_7, chanwert1_7);
            dmx.setChannel(startadresse1_8, chanwert1_8);
            dmx.setChannel(startadresse1_9, chanwert1_9);
        }
        else
        {
            dmx.setChannel(i, dmx.getChannel(i));
        }
        if (digitalRead(BUTTON_2) == LOW)
        {
            dmx.setChannel(startadresse2_0, chanwert2_0);
            dmx.setChannel(startadresse2_1, chanwert2_1);
            dmx.setChannel(startadresse2_2, chanwert2_2);
            dmx.setChannel(startadresse2_3, chanwert2_3);
            dmx.setChannel(startadresse2_4, chanwert2_4);
            dmx.setChannel(startadresse2_5, chanwert2_5);
            dmx.setChannel(startadresse2_6, chanwert2_6);
            dmx.setChannel(startadresse2_7, chanwert2_7);
            dmx.setChannel(startadresse2_8, chanwert2_8);
            dmx.setChannel(startadresse2_9, chanwert2_9);
        }
        else
        {
            dmx.setChannel(i, dmx.getChannel(i));
        }
    }
}