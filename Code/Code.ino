// ###############################################################################################################################
// #
// # Code for the printables "Music reactive matrix LED cube" project: https://www.printables.com/de/model/296022-music-reactive-matrix-led-cube
// #
// # Code by https://github.com/AWSW-de with the use of some code from Adafruit examples. See notes at the end of the code too
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/Music-reactive-matrix-LED-cube/blob/main/LICENSE
// #
// ###############################################################################################################################
/*
      ___           ___           ___                       ___                    ___           ___           ___           ___           ___                       ___           ___              
     /\__\         /\__\         /\  \          ___        /\  \                  /\  \         /\  \         /\  \         /\  \         /\  \          ___        /\__\         /\  \             
    /::|  |       /:/  /        /::\  \        /\  \      /::\  \                /::\  \       /::\  \       /::\  \       /::\  \        \:\  \        /\  \      /:/  /        /::\  \            
   /:|:|  |      /:/  /        /:/\ \  \       \:\  \    /:/\:\  \              /:/\:\  \     /:/\:\  \     /:/\:\  \     /:/\:\  \        \:\  \       \:\  \    /:/  /        /:/\:\  \           
  /:/|:|__|__   /:/  /  ___   _\:\~\ \  \      /::\__\  /:/  \:\  \            /::\~\:\  \   /::\~\:\  \   /::\~\:\  \   /:/  \:\  \       /::\  \      /::\__\  /:/__/  ___   /::\~\:\  \          
 /:/ |::::\__\ /:/__/  /\__\ /\ \:\ \ \__\  __/:/\/__/ /:/__/ \:\__\          /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\ /:/__/ \:\__\     /:/\:\__\  __/:/\/__/  |:|  | /\__\ /:/\:\ \:\__\         
 \/__/~~/:/  / \:\  \ /:/  / \:\ \:\ \/__/ /\/:/  /    \:\  \  \/__/          \/_|::\/:/  / \:\~\:\ \/__/ \/__\:\/:/  / \:\  \  \/__/    /:/  \/__/ /\/:/  /     |:|  |/:/  / \:\~\:\ \/__/         
       /:/  /   \:\  /:/  /   \:\ \:\__\   \::/__/      \:\  \                   |:|::/  /   \:\ \:\__\        \::/  /   \:\  \         /:/  /      \::/__/      |:|__/:/  /   \:\ \:\__\           
      /:/  /     \:\/:/  /     \:\/:/  /    \:\__\       \:\  \                  |:|\/__/     \:\ \/__/        /:/  /     \:\  \        \/__/        \:\__\       \::::/__/     \:\ \/__/           
     /:/  /       \::/  /       \::/  /      \/__/        \:\__\                 |:|  |        \:\__\         /:/  /       \:\__\                     \/__/        ~~~~          \:\__\             
     \/__/         \/__/         \/__/                     \/__/                  \|__|         \/__/         \/__/         \/__/                                                 \/__/             
      ___           ___           ___           ___                       ___                    ___       ___           ___                    ___           ___           ___           ___       
     /\__\         /\  \         /\  \         /\  \          ___        |\__\                  /\__\     /\  \         /\  \                  /\  \         /\__\         /\  \         /\  \      
    /::|  |       /::\  \        \:\  \       /::\  \        /\  \       |:|  |                /:/  /    /::\  \       /::\  \                /::\  \       /:/  /        /::\  \       /::\  \     
   /:|:|  |      /:/\:\  \        \:\  \     /:/\:\  \       \:\  \      |:|  |               /:/  /    /:/\:\  \     /:/\:\  \              /:/\:\  \     /:/  /        /:/\:\  \     /:/\:\  \    
  /:/|:|__|__   /::\~\:\  \       /::\  \   /::\~\:\  \      /::\__\     |:|__|__            /:/  /    /::\~\:\  \   /:/  \:\__\            /:/  \:\  \   /:/  /  ___   /::\~\:\__\   /::\~\:\  \   
 /:/ |::::\__\ /:/\:\ \:\__\     /:/\:\__\ /:/\:\ \:\__\  __/:/\/__/ ____/::::\__\          /:/__/    /:/\:\ \:\__\ /:/__/ \:|__|          /:/__/ \:\__\ /:/__/  /\__\ /:/\:\ \:|__| /:/\:\ \:\__\  
 \/__/~~/:/  / \/__\:\/:/  /    /:/  \/__/ \/_|::\/:/  / /\/:/  /    \::::/~~/~             \:\  \    \:\~\:\ \/__/ \:\  \ /:/  /          \:\  \  \/__/ \:\  \ /:/  / \:\~\:\/:/  / \:\~\:\ \/__/  
       /:/  /       \::/  /    /:/  /         |:|::/  /  \::/__/      ~~|:|~~|               \:\  \    \:\ \:\__\    \:\  /:/  /            \:\  \        \:\  /:/  /   \:\ \::/  /   \:\ \:\__\    
      /:/  /        /:/  /     \/__/          |:|\/__/    \:\__\        |:|  |                \:\  \    \:\ \/__/     \:\/:/  /              \:\  \        \:\/:/  /     \:\/:/  /     \:\ \/__/    
     /:/  /        /:/  /                     |:|  |       \/__/        |:|  |                 \:\__\    \:\__\        \::/__/                \:\__\        \::/  /       \::/__/       \:\__\      
     \/__/         \/__/                       \|__|                     \|__|                  \/__/     \/__/         ~~                     \/__/         \/__/         ~~            \/__/      
*/


// ###############################################################################################################################
// #
// # Code version:
// #
// ###############################################################################################################################
String code_version = "V1.0.2";


// ###############################################################################################################################
// # Includes:
// #
// # You will need to add the following libraries to your Arduino IDE to use the project:
// # - Adafruit NeoPixel              // by Adafruit:                     https://github.com/adafruit/Adafruit_NeoPixel
// # - WiFiManager                    // by tablatronix / tzapu:          https://github.com/tzapu/WiFiManager
// #
// ###############################################################################################################################
#include <ESP8266WiFi.h>              // Used to connect the ESP8266 NODE MCU to your WiFi
#include <DNSServer.h>                // Used for name resolution for the internal webserver
#include <ESP8266WebServer.h>         // Used for the internal webserver
#include <WiFiManager.h>              // Used for the WiFi Manager option to be able to connect the ESP to your WiFi without code changes
#include <EEPROM.h>                   // Used to store the in the internal configuration page set configuration on the ESP internal storage
#include <Adafruit_NeoPixel.h>        // Used to drive the NeoPixel LEDs
#include <ESP8266mDNS.h>              // Used for the internal update function
#include <ESP8266HTTPUpdateServer.h>  // Used for the internal update function
#include "languages.h"                // Language translations


// ###############################################################################################################################
// # Hardware settings:
// ###############################################################################################################################
#define N_PIXELS 128       // Number of pixels in strand
#define MIC_PIN A0         // Microphone is attached to this analog pin
#define LED_PIN D6         // NeoPixel LED strand is connected to this pin
#define DC_OFFSET 30       // DC offset in mic signal - if unusure, leave 0 --> Set mic level to 0 if no sound shoule be made visible
const int buttonPin = 14;  // The number of the pushbutton pin --> 14 = D5 on the NodeMCU


// ###############################################################################################################################
// # Default VU meter function settings:
// ###############################################################################################################################
#define NOISE 10        // Noise/hum/interference in mic signal
#define SAMPLES 60      // Length of buffer for dynamic level adjustment
#define TOP (N_PIXELS)  // Allow dot to go slightly off scale
#define PEAK_FALL 40    // Rate of peak falling dot


// ###############################################################################################################################
// # LED default settings:
// ###############################################################################################################################
int redVal = 0;      // Default color RED
int greenVal = 255;  // Default color GREEN
int blueVal = 0;     // Default color BLUE
int intensity = 15;  // Default LED intensity (0..255) - Important note: Check power consumption and used power supply capabilities!


// ###############################################################################################################################
// # Function select settings:
// ###############################################################################################################################
String header;            // Variable to store the HTTP request
int useledtest = 1;       // Show start animation and display test at boot
int buttonCountMAX = 12;  // Max number of switchable functions
int buttonState = 0;      // Variable for reading the pushbutton status
int buttonCount = 0;      // Variable for the button presses to switch between the modes
int switchLangWeb = 0;    // Language default setting (0 = german, 1 = english, 2...x = for future use)

int  // VU meters animation activation default
  useVUA1 = 1,
  useVUA2 = 1,
  useVUA3 = 1,
  useVUA4 = 1,
  useVUA5 = 1,
  useVUA6 = 1,
  useVUA7 = 1,
  useVUA8 = 1,
  useVUA9 = 1,
  useVUA10 = 1,
  useVUA11 = 1,
  useVUA12 = 1,
  useVUA13 = 1,
  useVUA14 = 1,
  useVUA15 = 1,
  useVUA16 = 1,
  useVUA17 = 1,
  useVUA18 = 1,
  useVUA19 = 1,
  useVUA20 = 1;

byte
  peak = 0,      // Used for falling dot
  dotCount = 0,  // Frame counter for delaying dot-falling speed
  volCount = 0;  // Frame counter for storing past volume data

int
  vol[SAMPLES],   // Collection of prior volume samples
  lvl = 10,       // Current "dampened" audio level
  minLvlAvg = 0,  // For dynamic adjustment of graph low & high
  maxLvlAvg = 512;

Adafruit_NeoPixel matrix = Adafruit_NeoPixel(N_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);


// ###############################################################################################################################
// # WiFi and http server settings:
// ###############################################################################################################################
ESP8266HTTPUpdateServer httpUpdater;        // Update server
ESP8266WebServer httpServer(2022);          // Update server port
WiFiServer server(80);                      // Set web server port number to 80
String UpdatePath = "-";                    // Update via Hostname
String UpdatePathIP = "-";                  // Update via IP-address
#define DEFAULT_AP_NAME "RGBLEDCUBE"        // WiFi access point name of the ESP8266
#define AP_TIMEOUT 240                      // Timeout in seconds for AP / WLAN config
std::unique_ptr<ESP8266WebServer> server1;  // REST function web server


// ###########################################################################################################################################
// # Parameter record to store to the EEPROM of the ESP:
// ###########################################################################################################################################
struct parmRec {
  int pRed;
  int pGreen;
  int pBlue;
  int pIntensity;
  int puseledtest;
  int puseVUA1;
  int puseVUA2;
  int puseVUA3;
  int puseVUA4;
  int puseVUA5;
  int puseVUA6;
  int puseVUA7;
  int puseVUA8;
  int puseVUA9;
  int puseVUA10;
  int puseVUA11;
  int puseVUA12;
  int puseVUA13;
  int puseVUA14;
  int puseVUA15;
  int puseVUA16;
  int puseVUA17;
  int puseVUA18;
  int puseVUA19;
  int puseVUA20;
  int pswitchLangWeb;
  int pCheckSum;
} parameter;


// ###############################################################################################################################
// # Setup function to run at startup:
// ###############################################################################################################################
void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(buttonPin, INPUT_PULLUP);  // pinMode(buttonPin, INPUT with PULLUP resistor integrated in the ESP);
  digitalWrite(buttonPin, HIGH);     // initialize the buttonPin as output
  analogReference(EXTERNAL);
  memset(vol, 0, sizeof(vol));
  readEEPROM();  // get persistent data from EEPROM
  matrix.begin();
  Serial.println("#########################################");
  Serial.print("# Music reactive LED cube - Version: ");
  Serial.print(code_version);
  Serial.println(" #");
  Serial.println("#########################################");

  // Test the LEDs:
  if (useledtest == 1) LEDTEST();

  // WiFiManager:
  show_wifi(matrix.Color(0, 0, 255));
  delay(1500);
  bool WiFires;
  WiFiManager wifiManager;
  wifiManager.setConfigPortalTimeout(AP_TIMEOUT);  // Max wait for 3 minutes
  WiFires = wifiManager.autoConnect(DEFAULT_AP_NAME);
  if (!WiFires) {
    Serial.println("Failed to connect to WiFi");
    show_wifi(matrix.Color(255, 0, 0));
    delay(1500);
  } else {
    Serial.println("Connected to WiFi.");
    show_wifi(matrix.Color(0, 255, 0));
    delay(1500);
  }
  colorWipe(matrix.Color(0, 0, 0), 0);  // LEDs off

  // Web update function setup:
  MDNS.begin(WiFi.getHostname());
  httpUpdater.setup(&httpServer);
  httpServer.begin();
  MDNS.addService("http", "tcp", 2022);
  MDNS.addService("http", "tcp", 80);
  Serial.println("##################################################################################");
  Serial.print("Hostname: ");
  Serial.println(WiFi.getHostname());
  Serial.print("IP-address: ");
  Serial.println(WiFi.localIP().toString());
  UpdatePath = "http://" + String(WiFi.getHostname()) + ".local:2022/update";
  UpdatePathIP = "http://" + WiFi.localIP().toString() + ":2022/update";
  Serial.print("Web Update Link: ");
  Serial.println(UpdatePath);
  Serial.print("Web Update Link: ");
  Serial.println(UpdatePathIP);
  Serial.print("Web Config Link: ");
  Serial.println("http://" + String(WiFi.getHostname()));
  Serial.print("Web Config Link: ");
  Serial.println("http://" + WiFi.localIP().toString());
  Serial.println("Web server for configuration and update online...");
  Serial.println("##################################################################################");
  server.begin();

  // REST URL server:
  server1.reset(new ESP8266WebServer(WiFi.localIP(), 55555));
  server1->on("/", handleRoot);
  server1->on("/esprestart", ESPRestart);
  server1->on("/espwifireset", ESPWifiReset);
  server1->begin();

  // Load set language:
  setLanguage(switchLangWeb);
}


// ###############################################################################################################################
// # Loop funtion to run all the time:
// ###############################################################################################################################
void loop() {
  ESP.wdtFeed();  // Reset watchdog timer

  matrix.setBrightness(intensity);

  switch (buttonCount) {
    case 0:
      if (useledtest == 1) {
        rainbow(10);
      }
      buttonCount = 1;  // Switch to default vu-meter or animation
      break;
    case 1:
      buttonCount = 1;
      if (useVUA1) {
        vu_meter7();  // VU meter 7 - Lines Coloured
      } else {
        buttonCount = buttonCount + 1;
      }
      break;
    case 2:
      buttonCount = 2;
      if (useVUA2) {
        vu_meter8();  // VU meter 8 - Lines White
      } else {
        buttonCount = buttonCount + 1;
      }
      break;
    case 3:
      buttonCount = 3;
      if (useVUA3) {
        vu_meter6();  // VU meter 6 - Lines with user selected color
      } else {
        buttonCount = buttonCount + 1;
      }
      break;
    case 4:
      buttonCount = 4;
      if (useVUA4) {
        vu_meter9();  // VU meter 9 - Random LED
      } else {
        buttonCount = buttonCount + 1;
      }
      break;
    case 5:
      buttonCount = 5;
      if (useVUA5) {
        vu_meter11();  // VU meter 11 - Cube Coloured
      } else {
        buttonCount = buttonCount + 1;
      }
      break;
    case 6:
      buttonCount = 6;
      if (useVUA6) {
        vu_meter10();  // VU meter 10 - cube White
      } else {
        buttonCount = buttonCount + 1;
      }
      break;
    case 7:
      buttonCount = 7;
      if (useVUA7) {
        vu_meter1();  // VU meter 1 - White peak dot
      } else {
        buttonCount = buttonCount + 1;
      }
      break;
    case 8:
      buttonCount = 8;
      if (useVUA8) {
        vu_meter2();  // VU meter 2 - Coloured peak dot
      } else {
        buttonCount = buttonCount + 1;
      }
      break;
    case 9:
      buttonCount = 9;
      if (useVUA9) {
        vu_meter3();  // VU meter 3 - No peak dot
      } else {
        buttonCount = buttonCount + 1;
      }
      break;

    case 10:
      buttonCount = 10;
      if (useVUA17) {
        theaterChase(matrix.Color(127, 127, 127), 50);  // White flickering LED function (Adafruit NeoPixel demo)
      } else {
        buttonCount = buttonCount + 1;
      }
      break;
    case 11:
      buttonCount = 11;
      if (useVUA18) {
        rainbow(10);  // Rainbow LED function (Adafruit NeoPixel demo)
      } else {
        buttonCount = buttonCount + 1;
      }
      break;
    case 12:
      buttonCount = 12;
      if (useVUA19) {
        theaterChaseRainbow(50);  // Flickering rainbow LED function (Adafruit NeoPixel demo)
      } else {
        buttonCount = buttonCount + 1;
      }
      break;
  }

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // Serial.println("button not pushed");
  } else {
    // turn LED on, or do whatever else you want when your button is pushed
    Serial.println("Button pushed");
    colorWipe(matrix.Color(0, 0, 0), 0);
    delay(1000);
    buttonState = digitalRead(buttonPin);
    if (buttonState != HIGH) {
      Serial.println("Button long pushed - go to buttonCount 1");
      uint32_t color(matrix.Color(255, 0, 0));
      matrix.setPixelColor(0, color);
      matrix.setPixelColor(7, color);
      matrix.setPixelColor(56, color);
      matrix.setPixelColor(63, color);
      matrix.show();
      delay(1500);
      buttonCount = 1;
    } else {
      Serial.println("Button shortly pushed - go 1 animation forward");
      uint32_t color(matrix.Color(0, 255, 0));
      matrix.setPixelColor(0, color);
      matrix.setPixelColor(7, color);
      matrix.setPixelColor(56, color);
      matrix.setPixelColor(63, color);
      matrix.show();
      delay(1500);
      buttonCount = buttonCount + 1;
    }
    if (buttonCount > buttonCountMAX) {
      buttonCount = 1;
    }
    Serial.print("Button press count = ");
    Serial.println(buttonCount);
  }

  // Check, whether something has been entered on Config Page
  checkClient();

  // Web update start:
  httpServer.handleClient();
  MDNS.update();

  // REST function web server:
  server1->handleClient();
}


// ###########################################################################################################################################
// # Try to read settings from FLASH - initialize if WLAN ID read from flash is invalid:
// ###########################################################################################################################################
void readEEPROM() {
  Serial.print("Copy ");
  Serial.print(sizeof(parameter));
  Serial.println(" bytes from flash memory to EPROM buffer: ");

  // initialize space to read parameter
  EEPROM.begin(sizeof(parameter));
  delay(10);

  // Copy bytes from EEPROM
  byte* p = (byte*)(void*)&parameter;

  int check = 0;
  for (int L = 0; L < sizeof(parameter); ++L) {
    byte b = EEPROM.read(L);

    // Don't take the checkSum itself into account
    if (L < sizeof(parameter) - sizeof(parameter.pCheckSum))
      check = check + b;

    *p++ = b;
    /* Serial.print("Read FLASH Byte ");
      Serial.print(L);
      Serial.print(" = ");
      Serial.println(b); */
  }

  // Check checksum
  Serial.print("Compare checksums: ");
  Serial.print(check);
  Serial.print("/");
  Serial.println(parameter.pCheckSum);

  if (check == parameter.pCheckSum) {
    Serial.println("Checksum match! set parameter from EEPROM");
    redVal = parameter.pRed;
    greenVal = parameter.pGreen;
    blueVal = parameter.pBlue;
    useledtest = parameter.puseledtest;
    useVUA1 = parameter.puseVUA1;
    useVUA2 = parameter.puseVUA2;
    useVUA3 = parameter.puseVUA3;
    useVUA4 = parameter.puseVUA4;
    useVUA5 = parameter.puseVUA5;
    useVUA6 = parameter.puseVUA6;
    useVUA7 = parameter.puseVUA7;
    useVUA8 = parameter.puseVUA8;
    useVUA9 = parameter.puseVUA9;
    useVUA10 = parameter.puseVUA10;
    useVUA11 = parameter.puseVUA11;
    useVUA12 = parameter.puseVUA12;
    useVUA13 = parameter.puseVUA13;
    useVUA14 = parameter.puseVUA14;
    useVUA15 = parameter.puseVUA15;
    useVUA16 = parameter.puseVUA16;
    useVUA17 = parameter.puseVUA17;
    useVUA18 = parameter.puseVUA18;
    useVUA19 = parameter.puseVUA19;
    useVUA20 = parameter.puseVUA20;
    switchLangWeb = parameter.pswitchLangWeb;
    intensity = parameter.pIntensity;
  }
}


// ###########################################################################################################################################
// # Write current parameter settings to flash:
// ###########################################################################################################################################
void writeEEPROM() {
  Serial.println("Write parameter into EEPRom");
  parameter.pRed = redVal;
  parameter.pGreen = greenVal;
  parameter.pBlue = blueVal;
  parameter.pIntensity = intensity;
  parameter.puseledtest = useledtest;
  parameter.puseVUA1 = useVUA1;
  parameter.puseVUA2 = useVUA2;
  parameter.puseVUA3 = useVUA3;
  parameter.puseVUA4 = useVUA4;
  parameter.puseVUA5 = useVUA5;
  parameter.puseVUA6 = useVUA6;
  parameter.puseVUA7 = useVUA7;
  parameter.puseVUA8 = useVUA8;
  parameter.puseVUA9 = useVUA9;
  parameter.puseVUA10 = useVUA10;
  parameter.puseVUA11 = useVUA11;
  parameter.puseVUA12 = useVUA12;
  parameter.puseVUA13 = useVUA13;
  parameter.puseVUA14 = useVUA14;
  parameter.puseVUA15 = useVUA15;
  parameter.puseVUA16 = useVUA16;
  parameter.puseVUA17 = useVUA17;
  parameter.puseVUA18 = useVUA18;
  parameter.puseVUA19 = useVUA19;
  parameter.puseVUA20 = useVUA20;
  parameter.pswitchLangWeb = switchLangWeb;

  // calculate checksum
  byte* p = (byte*)(void*)&parameter;
  parameter.pCheckSum = 0;
  for (int L = 0; L < sizeof(parameter) - sizeof(parameter.pCheckSum); ++L) {
    byte b = *p++;
    parameter.pCheckSum = parameter.pCheckSum + b;
  }
  // Write data to EEPROM
  p = (byte*)(void*)&parameter;
  for (int L = 0; L < sizeof(parameter); ++L) {
    byte b = *p++;
    EEPROM.write(L, b);
    // Serial.print("Write FLASH Byte ");
    // Serial.print(L);
    // Serial.print(" = ");
    // Serial.println(b);
  }
  EEPROM.commit();
}


// ###############################################################################################################################
// # HTTP server configuration:
// ###############################################################################################################################
void checkClient() {
  //Serial.println("check for client");
  WiFiClient client = server.available();  // Listen for incoming clients // @suppress("Abstract class cannot be instantiated")

  if (client) {                     // If a new client connects,
    Serial.println("New Client.");  // print a message out in the serial port
    String currentLine = "";        // make a String to hold incoming data from the client
    while (client.connected()) {    // loop while the client's connected
      if (client.available()) {     // if there's bytes to read from the client,
        char c = client.read();     // read a byte, then
        Serial.write(c);            // print it out the serial monitor
        header += c;
        if (c == '\n') {  // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // Display the HTML web page:
            // ##########################
            client.println("<!DOCTYPE html><html>");
            client.println("<head><title>" + ProjectName + " - " + String(WiFi.getHostname()) + "</title><meta charset=\"utf-8\" name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");


            // Web Page Heading:
            // #################
            String title = "<body><h1>" + ProjectNameLong + " - " + txtSettings + ": ";
            title = title + code_version;
            title = title + "</h1>";
            client.println(title);
            client.println("<form action=\"/setWC.php\">");


            // Convert color into hex settings:
            // ################################
            char hex_main[7] = { 0 };
            sprintf(hex_main, "#%02X%02X%02X", redVal, greenVal, blueVal);
            // Main color select:
            client.println("<hr><h2>" + txtLEDsettings + ":</h2><br>");
            client.println("<label for=\"favcolor\">" + txtLEDcolor + ": </label>");
            client.print("<input type=\"color\" id=\"favcolor\" name=\"favcolor\" value=\"");
            client.print(hex_main);
            client.print("\"><br><br>");


            // Intensity:
            // ##############
            client.print("<label for=\"intensity\">" + txtIntensity + ": </label>");
            client.print("<input type='range' min='1' max='255' name='intensity' value=");
            client.print(intensity);                                                               //set the value of the slider based upon the previous page load value
            client.println(" style='height:30px; width:200px' oninput='showValue(this.value)'>");  //was onchange event
            client.print("<span id='valrange'>");
            client.print(intensity);  //set the javascript initial value
            client.println("</span>");
            client.println("<script type='text/javascript'>\r\nfunction showValue(newValue)\r\n{\r\ndocument.getElementById('valrange').innerHTML=newValue;\r\n}\r\n</script>\r\n");
            client.println("</label><br><hr>");


            // LED display and startup:
            // ########################
            client.println("<h2>" + txtContentStartup + ":</h2>");
            client.println("<label for=\"useledtest\">" + txtUseLEDtest + " </label>");
            client.print("<input type=\"checkbox\" id=\"useledtest\" name=\"useledtest\"");
            if (useledtest) {
              client.print(" checked");
              client.print("><br><br><hr>");
            } else {
              client.print("><br><br><hr>");
            }


            // VU meter and animations:
            // ########################
            client.println("<h2>" + txtVUandAnm + ":</h2>");
            client.println("<label for=\"useVUA1\">" + txtVU1 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA1\" name=\"useVUA1\"");
            if (useVUA1) {
              client.print(" checked");
              client.print("> " + txtVU1lbl + "<br><br>");
            } else {
              client.print("> " + txtVU1lbl + "<br><br>");
            }

            client.println("<label for=\"useVUA2\">" + txtVU2 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA2\" name=\"useVUA2\"");
            if (useVUA2) {
              client.print(" checked");
              client.print("> " + txtVU2lbl + "<br><br>");
            } else {
              client.print("> " + txtVU2lbl + "<br><br>");
            }

            client.println("<label for=\"useVUA3\">" + txtVU3 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA3\" name=\"useVUA3\"");
            if (useVUA3) {
              client.print(" checked");
              client.print("> " + txtVU3lbl + "<br><br>");
            } else {
              client.print("> " + txtVU3lbl + "<br><br>");
            }

            client.println("<label for=\"useVUA4\">" + txtVU4 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA4\" name=\"useVUA4\"");
            if (useVUA4) {
              client.print(" checked");
              client.print("> " + txtVU4lbl + "<br><br>");
            } else {
              client.print("> " + txtVU4lbl + "<br><br>");
            }

            client.println("<label for=\"useVUA5\">" + txtVU5 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA5\" name=\"useVUA5\"");
            if (useVUA5) {
              client.print(" checked");
              client.print("> " + txtVU5lbl + "<br><br>");
            } else {
              client.print("> " + txtVU5lbl + "<br><br>");
            }

            client.println("<label for=\"useVUA6\">" + txtVU6 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA6\" name=\"useVUA6\"");
            if (useVUA6) {
              client.print(" checked");
              client.print("> " + txtVU6lbl + "<br><br>");
            } else {
              client.print("> " + txtVU6lbl + "<br><br>");
            }

            client.println("<label for=\"useVUA7\">" + txtVU7 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA7\" name=\"useVUA7\"");
            if (useVUA7) {
              client.print(" checked");
              client.print("> " + txtVU7lbl + "<br><br>");
            } else {
              client.print("> " + txtVU7lbl + "<br><br>");
            }

            client.println("<label for=\"useVUA8\">" + txtVU8 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA8\" name=\"useVUA8\"");
            if (useVUA8) {
              client.print(" checked");
              client.print("> " + txtVU8lbl + "<br><br>");
            } else {
              client.print("> " + txtVU8lbl + "<br><br>");
            }

            client.println("<label for=\"useVUA9\">" + txtVU9 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA9\" name=\"useVUA9\"");
            if (useVUA9) {
              client.print(" checked");
              client.print("> " + txtVU9lbl + "<br><br>");
            } else {
              client.print("> " + txtVU9lbl + "<br><br>");
            }

            client.println("<label for=\"useVUA17\">" + txtAnm1 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA17\" name=\"useVUA17\"");
            if (useVUA17) {
              client.print(" checked");
              client.print("> " + txtAnm1lbl + "<br><br>");
            } else {
              client.print("> " + txtAnm1lbl + "<br><br>");
            }

            client.println("<label for=\"useVUA18\">" + txtAnm2 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA18\" name=\"useVUA18\"");
            if (useVUA18) {
              client.print(" checked");
              client.print("> " + txtAnm2lbl + "<br><br>");
            } else {
              client.print("> " + txtAnm2lbl + "<br><br>");
            }

            client.println("<label for=\"useVUA19\">" + txtAnm3 + ": </label>");
            client.print("<input type=\"checkbox\" id=\"useVUA19\" name=\"useVUA19\"");
            if (useVUA19) {
              client.print(" checked");
              client.print("> " + txtAnm3lbl + "<br><br>");
            } else {
              client.print("> " + txtAnm3lbl + "<br><br>");
            }
            client.print("<hr>");

            // Update function:
            // ################
            client.println("<h2>" + txtUpdate0 + ":</h2>");
            client.println("<label>" + txtUpdate2 + ":</label><br><br>");
            client.println("<a href=" + UpdatePath + " target='_blank'>" + UpdatePath + "</a><br><br>");
            client.println("<a href=" + UpdatePathIP + " target='_blank'>" + UpdatePathIP + "</a><br><br>");
            client.println("<label>" + txtUpdate3 + "</label><br>");
            client.println("<br><br><label>" + txtUpdate4 + ":</label>");
            client.println("<a href='https://github.com/AWSW-de/Music-reactive-matrix-LED-cube' target='_blank'>" + txtUpdate5 + "</a><br><hr>");

            // Language selection:
            // ###################
            client.println("<br><label for=\"switchLangWeb\"><h2>" + languageSelect + ":</h2></label>");
            client.println("<fieldset>");
            client.println("<div>");
            client.println("<input type='radio' id='idlang0' name='switchLangWeb' value='0'");
            if (switchLangWeb == 0) {
              client.print(" checked");
              client.print(">");
            } else {
              client.print(">");
            }
            client.println("<label for='idlang0'>" + languageInt0 + "</label>");
            client.println("</div>");
            client.println("<div>");
            client.println("<input type='radio' id='idlang1' name='switchLangWeb' value='1'");
            if (switchLangWeb == 1) {
              client.print(" checked");
              client.print(">");
            } else {
              client.print(">");
            }
            client.println("<label for='idlang1'>" + languageInt1 + "</label>");
            client.println("</div>");
            client.println("</fieldset>");
            client.println("<br><br><hr>");

            // ESP restart:
            // ############
            client.println("<h2>" + txtRestart0 + ":</h2><br>");
            client.println("<label>" + txtRestart1 + "</label><br>");
            client.println("<br><a href= http://" + WiFi.localIP().toString() + ":55555/esprestart target='_blank'>" + txtRestart0 + "</a><br>");
            client.println("<br>! " + txtRestart2 + " !<br><br><hr>");

            // Reset WiFi configuration:
            // #########################
            client.println("<h2>" + txtWiFi0 + ":</h2><br>");
            client.println("<label>" + txtWiFi1 + "</label><br>");
            client.println("<br><a href= http://" + WiFi.localIP().toString() + ":55555/espwifireset target='_blank'>" + txtWiFi0 + "</a><br>");
            client.println("<br>! " + txtWiFi2 + " !<br><br><hr>");

            // Save settings button:
            // #####################
            client.println("<br><br><input type='submit' value='" + txtSaveSettings + "'>");
            client.print("<br><br><br><hr><br>");
            client.println("</form>");
            client.println("</body></html>");
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else {  // if you got a newline, then clear currentLine
            if (currentLine.startsWith("GET /setWC.php?")) {
              Serial.print("Current request: ");
              Serial.println(currentLine);

              buttonCount = 1;
              colorWipe(matrix.Color(0, 0, 0), 0);  // LEDs off

              // Check for color settings:
              // #########################
              int pos = currentLine.indexOf("favcolor=%23");
              if (pos >= 0) {
                char* succ;
                String newColStr = currentLine.substring(pos + 12, pos + 18);
                String newRed = newColStr.substring(0, 2);
                redVal = strtol(newRed.begin(), &succ, 16);
                String newGreen = newColStr.substring(2, 4);
                greenVal = strtol(newGreen.begin(), &succ, 16);
                String newBlue = newColStr.substring(4, 6);
                blueVal = strtol(newBlue.begin(), &succ, 16);
              }

              // Check for Use LED test switch:
              // ##############################
              if (currentLine.indexOf("&useledtest=on") >= 0) {
                useledtest = 1;
              } else {
                useledtest = 0;
              }

              // Check for useVUA1:
              // ##################
              if (currentLine.indexOf("&useVUA1=on") >= 0) {
                useVUA1 = 1;
              } else {
                useVUA1 = 0;
              }

              // Check for useVUA2:
              // ##################
              if (currentLine.indexOf("&useVUA2=on") >= 0) {
                useVUA2 = 1;
              } else {
                useVUA2 = 0;
              }

              // Check for useVUA3:
              // ##################
              if (currentLine.indexOf("&useVUA3=on") >= 0) {
                useVUA3 = 1;
              } else {
                useVUA3 = 0;
              }

              // Check for useVUA4:
              // ##################
              if (currentLine.indexOf("&useVUA4=on") >= 0) {
                useVUA4 = 1;
              } else {
                useVUA4 = 0;
              }

              // Check for useVUA5:
              // ##################
              if (currentLine.indexOf("&useVUA5=on") >= 0) {
                useVUA5 = 1;
              } else {
                useVUA5 = 0;
              }

              // Check for useVUA6:
              // ##################
              if (currentLine.indexOf("&useVUA6=on") >= 0) {
                useVUA6 = 1;
              } else {
                useVUA6 = 0;
              }

              // Check for useVUA7:
              // ##################
              if (currentLine.indexOf("&useVUA7=on") >= 0) {
                useVUA7 = 1;
              } else {
                useVUA7 = 0;
              }

              // Check for useVUA8:
              // ##################
              if (currentLine.indexOf("&useVUA8=on") >= 0) {
                useVUA8 = 1;
              } else {
                useVUA8 = 0;
              }

              // Check for useVUA9:
              // ##################
              if (currentLine.indexOf("&useVUA9=on") >= 0) {
                useVUA9 = 1;
              } else {
                useVUA9 = 0;
              }

              // Check for useVUA10:
              // ##################
              if (currentLine.indexOf("&useVUA10=on") >= 0) {
                useVUA10 = 1;
              } else {
                useVUA10 = 0;
              }

              // Check for useVUA11:
              // ##################
              if (currentLine.indexOf("&useVUA11=on") >= 0) {
                useVUA11 = 1;
              } else {
                useVUA11 = 0;
              }

              // Check for useVUA12:
              // ##################
              if (currentLine.indexOf("&useVUA12=on") >= 0) {
                useVUA12 = 1;
              } else {
                useVUA12 = 0;
              }

              // Check for useVUA13:
              // ##################
              if (currentLine.indexOf("&useVUA13=on") >= 0) {
                useVUA13 = 1;
              } else {
                useVUA13 = 0;
              }

              // Check for useVUA14:
              // ##################
              if (currentLine.indexOf("&useVUA14=on") >= 0) {
                useVUA14 = 1;
              } else {
                useVUA14 = 0;
              }

              // Check for useVUA15:
              // ##################
              if (currentLine.indexOf("&useVUA15=on") >= 0) {
                useVUA15 = 1;
              } else {
                useVUA15 = 0;
              }

              // Check for useVUA16:
              // ##################
              if (currentLine.indexOf("&useVUA16=on") >= 0) {
                useVUA16 = 1;
              } else {
                useVUA16 = 0;
              }

              // Check for useVUA17:
              // ##################
              if (currentLine.indexOf("&useVUA17=on") >= 0) {
                useVUA17 = 1;
              } else {
                useVUA17 = 0;
              }

              // Check for useVUA18:
              // ##################
              if (currentLine.indexOf("&useVUA18=on") >= 0) {
                useVUA18 = 1;
              } else {
                useVUA18 = 0;
              }

              // Check for useVUA19:
              // ##################
              if (currentLine.indexOf("&useVUA19=on") >= 0) {
                useVUA19 = 1;
              } else {
                useVUA19 = 0;
              }

              // Check for useVUA20:
              // ##################
              if (currentLine.indexOf("&useVUA20=on") >= 0) {
                useVUA20 = 1;
              } else {
                useVUA20 = 0;
              }


              // Check for language setting:
              // ###########################
              pos = currentLine.indexOf("&switchLangWeb=");
              if (pos >= 0) {
                String LangWebStr = currentLine.substring(pos + 15);
                pos = LangWebStr.indexOf("&");
                if (pos > 0)
                  LangWebStr = LangWebStr.substring(0, pos);
                switchLangWeb = LangWebStr.toInt();
                setLanguage(switchLangWeb);
              }


              // Get intensity:
              // ##############
              pos = currentLine.indexOf("&intensity=");
              if (pos >= 0) {
                String intStr = currentLine.substring(pos + 11, pos + 14);
                pos = intStr.indexOf(" ");  // " " instead of "&" !!!
                if (pos > 0)
                  intStr = intStr.substring(0, pos);
                intensity = intStr.toInt();
              }


              // Save data to EEPROM:
              // ####################
              writeEEPROM();  // save DATA to EEPROM
            }
            currentLine = "";  // Clear the current command line
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    header = "";    // Clear the header variable
    client.stop();  // Close the connection
    Serial.println("Web client disconnected.");
    Serial.println("######################################################################################################");
  }
}


// ###############################################################################################################################
// # VU meter 1 - White peak dot
// ###############################################################################################################################
void vu_meter1() {
  uint8_t i;
  uint16_t minLvl, maxLvl;
  int n, height;

  n = analogRead(MIC_PIN);             // Raw reading from mic
  n = abs(n - 512 - DC_OFFSET);        // Center on zero
  n = (n <= NOISE) ? 0 : (n - NOISE);  // Remove noise/hum
  lvl = ((lvl * 7) + n) >> 3;          // "Dampened" reading (else looks twitchy)

  // Calculate bar height based on dynamic min/max levels (fixed point):
  height = TOP * (lvl - minLvlAvg) / (long)(maxLvlAvg - minLvlAvg);

  if (height < 0L) height = 0;  // Clip output
  else if (height > TOP) height = TOP;
  if (height > peak) peak = height;  // Keep 'peak' dot at top


  // Color pixels based on rainbow gradient
  for (i = 0; i < N_PIXELS; i++) {
    if (i >= height) matrix.setPixelColor(i, 0, 0, 0);
    else matrix.setPixelColor(i, Wheel(map(i, 0, matrix.numPixels() - 1, 30, 150)));
  }

  // Draw peak dot
  // if (peak > 0 && peak <= N_PIXELS - 1) matrix.setPixelColor(peak, Wheel(map(peak, 0, matrix.numPixels() - 1, 30, 150)));
  if (peak > 0 && peak <= N_PIXELS - 1) matrix.setPixelColor(peak, 255, 255, 255);  // White peak dot

  matrix.show();  // Update matrix

  // Every few frames, make the peak pixel drop by 1:

  if (++dotCount >= PEAK_FALL) {  //fall rate

    if (peak > 0) peak--;
    dotCount = 0;
  }

  vol[volCount] = n;                        // Save sample for dynamic leveling
  if (++volCount >= SAMPLES) volCount = 0;  // Advance/rollover sample counter

  // Get volume range of prior frames
  minLvl = maxLvl = vol[0];
  for (i = 1; i < SAMPLES; i++) {
    if (vol[i] < minLvl) minLvl = vol[i];
    else if (vol[i] > maxLvl) maxLvl = vol[i];
  }
  // minLvl and maxLvl indicate the volume range over prior frames, used
  // for vertically scaling the output graph (so it looks interesting
  // regardless of volume level).  If they're too close together though
  // (e.g. at very low volume levels) the graph becomes super coarse
  // and 'jumpy'...so keep some minimum distance between them (this
  // also lets the graph go to zero when no sound is playing):
  if ((maxLvl - minLvl) < TOP) maxLvl = minLvl + TOP;
  minLvlAvg = (minLvlAvg * 63 + minLvl) >> 6;  // Dampen min/max levels
  maxLvlAvg = (maxLvlAvg * 63 + maxLvl) >> 6;  // (fake rolling average)
}


// ###############################################################################################################################
// # VU meter 2 - Coloured peak dot
// ###############################################################################################################################
void vu_meter2() {
  uint8_t i;
  uint16_t minLvl, maxLvl;
  int n, height;

  n = analogRead(MIC_PIN);             // Raw reading from mic
  n = abs(n - 512 - DC_OFFSET);        // Center on zero
  n = (n <= NOISE) ? 0 : (n - NOISE);  // Remove noise/hum
  lvl = ((lvl * 7) + n) >> 3;          // "Dampened" reading (else looks twitchy)

  // Calculate bar height based on dynamic min/max levels (fixed point):
  height = TOP * (lvl - minLvlAvg) / (long)(maxLvlAvg - minLvlAvg);

  if (height < 0L) height = 0;  // Clip output
  else if (height > TOP) height = TOP;
  if (height > peak) peak = height;  // Keep 'peak' dot at top


  // Color pixels based on rainbow gradient
  for (i = 0; i < N_PIXELS; i++) {
    if (i >= height) matrix.setPixelColor(i, 0, 0, 0);
    else matrix.setPixelColor(i, Wheel(map(i, 0, matrix.numPixels() - 1, 30, 150)));
  }

  // Draw peak dot
  if (peak > 0 && peak <= N_PIXELS - 1) matrix.setPixelColor(peak, Wheel(map(peak, 0, matrix.numPixels() - 1, 30, 150)));

  matrix.show();  // Update matrix

  // Every few frames, make the peak pixel drop by 1:

  if (++dotCount >= PEAK_FALL) {  //fall rate

    if (peak > 0) peak--;
    dotCount = 0;
  }

  vol[volCount] = n;                        // Save sample for dynamic leveling
  if (++volCount >= SAMPLES) volCount = 0;  // Advance/rollover sample counter

  // Get volume range of prior frames
  minLvl = maxLvl = vol[0];
  for (i = 1; i < SAMPLES; i++) {
    if (vol[i] < minLvl) minLvl = vol[i];
    else if (vol[i] > maxLvl) maxLvl = vol[i];
  }
  // minLvl and maxLvl indicate the volume range over prior frames, used
  // for vertically scaling the output graph (so it looks interesting
  // regardless of volume level).  If they're too close together though
  // (e.g. at very low volume levels) the graph becomes super coarse
  // and 'jumpy'...so keep some minimum distance between them (this
  // also lets the graph go to zero when no sound is playing):
  if ((maxLvl - minLvl) < TOP) maxLvl = minLvl + TOP;
  minLvlAvg = (minLvlAvg * 63 + minLvl) >> 6;  // Dampen min/max levels
  maxLvlAvg = (maxLvlAvg * 63 + maxLvl) >> 6;  // (fake rolling average)
}


// ###############################################################################################################################
// # VU meter 3 - No peak dot
// ###############################################################################################################################
void vu_meter3() {
  uint8_t i;
  uint16_t minLvl, maxLvl;
  int n, height;

  n = analogRead(MIC_PIN);             // Raw reading from mic
  n = abs(n - 512 - DC_OFFSET);        // Center on zero
  n = (n <= NOISE) ? 0 : (n - NOISE);  // Remove noise/hum
  lvl = ((lvl * 7) + n) >> 3;          // "Dampened" reading (else looks twitchy)

  // Calculate bar height based on dynamic min/max levels (fixed point):
  height = TOP * (lvl - minLvlAvg) / (long)(maxLvlAvg - minLvlAvg);

  if (height < 0L) height = 0;  // Clip output
  else if (height > TOP) height = TOP;
  if (height > peak) peak = height;  // Keep 'peak' dot at top


  // Color pixels based on rainbow gradient
  for (i = 0; i < N_PIXELS; i++) {
    if (i >= height) matrix.setPixelColor(i, 0, 0, 0);
    else matrix.setPixelColor(i, Wheel(map(i, 0, matrix.numPixels() - 1, 30, 150)));
  }

  // Draw peak dot
  // if (peak > 0 && peak <= N_PIXELS - 1) matrix.setPixelColor(peak, Wheel(map(peak, 0, matrix.numPixels() - 1, 30, 150)));

  matrix.show();  // Update matrix

  // Every few frames, make the peak pixel drop by 1:

  /* if (++dotCount >= PEAK_FALL) { //fall rate

     if (peak > 0) peak--;
     dotCount = 0;
    } */

  vol[volCount] = n;                        // Save sample for dynamic leveling
  if (++volCount >= SAMPLES) volCount = 0;  // Advance/rollover sample counter

  // Get volume range of prior frames
  minLvl = maxLvl = vol[0];
  for (i = 1; i < SAMPLES; i++) {
    if (vol[i] < minLvl) minLvl = vol[i];
    else if (vol[i] > maxLvl) maxLvl = vol[i];
  }
  // minLvl and maxLvl indicate the volume range over prior frames, used
  // for vertically scaling the output graph (so it looks interesting
  // regardless of volume level).  If they're too close together though
  // (e.g. at very low volume levels) the graph becomes super coarse
  // and 'jumpy'...so keep some minimum distance between them (this
  // also lets the graph go to zero when no sound is playing):
  if ((maxLvl - minLvl) < TOP) maxLvl = minLvl + TOP;
  minLvlAvg = (minLvlAvg * 63 + minLvl) >> 6;  // Dampen min/max levels
  maxLvlAvg = (maxLvlAvg * 63 + maxLvl) >> 6;  // (fake rolling average)
}


// ###############################################################################################################################
// # VU meter 6 - Lines with user selected color
// ###############################################################################################################################
void vu_meter6() {
  uint8_t i;
  uint16_t minLvl, maxLvl;
  int n, height;

  n = analogRead(MIC_PIN);             // Raw reading from mic
  n = abs(n - 512 - DC_OFFSET);        // Center on zero
  n = (n <= NOISE) ? 0 : (n - NOISE);  // Remove noise/hum
  lvl = ((lvl * 7) + n) >> 3;          // "Dampened" reading (else looks twitchy)

  // Calculate bar height based on dynamic min/max levels (fixed point):
  height = TOP * (lvl - minLvlAvg) / (long)(maxLvlAvg - minLvlAvg);

  if (height < 0L) height = 0;  // Clip output
  else if (height > TOP) height = TOP;
  if (height > peak) peak = height;  // Keep 'peak' dot at top


  // Color pixels based on rainbow gradient
  for (i = 0; i < N_PIXELS; i++) {
    if (i >= height) matrix.setPixelColor(i, 0, 0, 0);
    else matrix.setPixelColor(i, 0, 0, 0);
  }

  if (height < 0) {
    // I'm guessing this is an error
  } else if (height >= 0 && height <= 6) {
    show_lines(1, matrix.Color(redVal, greenVal, blueVal), 0);
  } else if (height >= 7 && height <= 13) {
    show_lines(2, matrix.Color(redVal, greenVal, blueVal), 0);
  } else if (height >= 14 && height <= 20) {
    show_lines(3, matrix.Color(redVal, greenVal, blueVal), 0);
  } else if (height >= 21 && height <= 27) {
    show_lines(4, matrix.Color(redVal, greenVal, blueVal), 0);
  } else if (height >= 28 && height <= 34) {
    show_lines(5, matrix.Color(redVal, greenVal, blueVal), 0);
  } else if (height >= 35 && height <= 41) {
    show_lines(6, matrix.Color(redVal, greenVal, blueVal), 0);
  } else if (height >= 42 && height <= 48) {
    show_lines(7, matrix.Color(redVal, greenVal, blueVal), 0);
  } else if (height >= 49 && height <= 55) {
    show_lines(8, matrix.Color(redVal, greenVal, blueVal), 0);
  } else if (height >= 56 && height <= 62) {
    show_lines(9, matrix.Color(redVal, greenVal, blueVal), 0);
  } else if (height >= 63 && height <= 69) {
    show_lines(10, matrix.Color(redVal, greenVal, blueVal), 0);
  } else if (height >= 70 && height <= 76) {
    show_lines(11, matrix.Color(redVal, greenVal, blueVal), 0);
  } else if (height >= 77) {
    show_lines(12, matrix.Color(redVal, greenVal, blueVal), 0);
  }

  vol[volCount] = n;                        // Save sample for dynamic leveling
  if (++volCount >= SAMPLES) volCount = 0;  // Advance/rollover sample counter

  // Get volume range of prior frames
  minLvl = maxLvl = vol[0];
  for (i = 1; i < SAMPLES; i++) {
    if (vol[i] < minLvl) minLvl = vol[i];
    else if (vol[i] > maxLvl) maxLvl = vol[i];
  }
  // minLvl and maxLvl indicate the volume range over prior frames, used
  // for vertically scaling the output graph (so it looks interesting
  // regardless of volume level).  If they're too close together though
  // (e.g. at very low volume levels) the graph becomes super coarse
  // and 'jumpy'...so keep some minimum distance between them (this
  // also lets the graph go to zero when no sound is playing):
  if ((maxLvl - minLvl) < TOP) maxLvl = minLvl + TOP;
  minLvlAvg = (minLvlAvg * 63 + minLvl) >> 6;  // Dampen min/max levels
  maxLvlAvg = (maxLvlAvg * 63 + maxLvl) >> 6;  // (fake rolling average)
}


// ###############################################################################################################################
// # VU meter 7 - Lines
// ###############################################################################################################################
void vu_meter7() {
  uint8_t i;
  uint16_t minLvl, maxLvl;
  int n, height;

  n = analogRead(MIC_PIN);             // Raw reading from mic
  n = abs(n - 512 - DC_OFFSET);        // Center on zero
  n = (n <= NOISE) ? 0 : (n - NOISE);  // Remove noise/hum
  lvl = ((lvl * 7) + n) >> 3;          // "Dampened" reading (else looks twitchy)

  // Calculate bar height based on dynamic min/max levels (fixed point):
  height = TOP * (lvl - minLvlAvg) / (long)(maxLvlAvg - minLvlAvg);

  if (height < 0L) height = 0;  // Clip output
  else if (height > TOP) height = TOP;
  if (height > peak) peak = height;  // Keep 'peak' dot at top


  // Color pixels based on rainbow gradient
  for (i = 0; i < N_PIXELS; i++) {
    if (i >= height) matrix.setPixelColor(i, 0, 0, 0);
    else matrix.setPixelColor(i, 0, 0, 0);
  }

  if (height < 0) {
    // I'm guessing this is an error
  } else if (height >= 0 && height <= 6) {
    show_lines(1, matrix.Color(0, 255, 0), 0);
  } else if (height >= 7 && height <= 13) {
    show_lines(2, matrix.Color(0, 255, 0), 0);
  } else if (height >= 14 && height <= 20) {
    show_lines(3, matrix.Color(0, 255, 0), 0);
  } else if (height >= 21 && height <= 27) {
    show_lines(4, matrix.Color(0, 255, 0), 0);
  } else if (height >= 28 && height <= 34) {
    show_lines(5, matrix.Color(255, 255, 0), 0);
  } else if (height >= 35 && height <= 41) {
    show_lines(6, matrix.Color(255, 255, 0), 0);
  } else if (height >= 42 && height <= 48) {
    show_lines(7, matrix.Color(255, 255, 0), 0);
  } else if (height >= 49 && height <= 55) {
    show_lines(8, matrix.Color(255, 255, 0), 0);
  } else if (height >= 56 && height <= 62) {
    show_lines(9, matrix.Color(255, 0, 0), 0);
  } else if (height >= 63 && height <= 69) {
    show_lines(10, matrix.Color(255, 0, 0), 0);
  } else if (height >= 70 && height <= 76) {
    show_lines(11, matrix.Color(255, 0, 0), 0);
  } else if (height >= 77) {
    show_lines(12, matrix.Color(255, 0, 0), 0);
  }

  vol[volCount] = n;                        // Save sample for dynamic leveling
  if (++volCount >= SAMPLES) volCount = 0;  // Advance/rollover sample counter

  // Get volume range of prior frames
  minLvl = maxLvl = vol[0];
  for (i = 1; i < SAMPLES; i++) {
    if (vol[i] < minLvl) minLvl = vol[i];
    else if (vol[i] > maxLvl) maxLvl = vol[i];
  }
  // minLvl and maxLvl indicate the volume range over prior frames, used
  // for vertically scaling the output graph (so it looks interesting
  // regardless of volume level).  If they're too close together though
  // (e.g. at very low volume levels) the graph becomes super coarse
  // and 'jumpy'...so keep some minimum distance between them (this
  // also lets the graph go to zero when no sound is playing):
  if ((maxLvl - minLvl) < TOP) maxLvl = minLvl + TOP;
  minLvlAvg = (minLvlAvg * 63 + minLvl) >> 6;  // Dampen min/max levels
  maxLvlAvg = (maxLvlAvg * 63 + maxLvl) >> 6;  // (fake rolling average)
}


// ###############################################################################################################################
// # VU meter 8 - Lines
// ###############################################################################################################################
void vu_meter8() {
  uint8_t i;
  uint16_t minLvl, maxLvl;
  int n, height;

  n = analogRead(MIC_PIN);             // Raw reading from mic
  n = abs(n - 512 - DC_OFFSET);        // Center on zero
  n = (n <= NOISE) ? 0 : (n - NOISE);  // Remove noise/hum
  lvl = ((lvl * 7) + n) >> 3;          // "Dampened" reading (else looks twitchy)

  // Calculate bar height based on dynamic min/max levels (fixed point):
  height = TOP * (lvl - minLvlAvg) / (long)(maxLvlAvg - minLvlAvg);

  if (height < 0L) height = 0;  // Clip output
  else if (height > TOP) height = TOP;
  if (height > peak) peak = height;  // Keep 'peak' dot at top


  // Color pixels based on rainbow gradient
  for (i = 0; i < N_PIXELS; i++) {
    if (i >= height) matrix.setPixelColor(i, 0, 0, 0);
    else matrix.setPixelColor(i, 0, 0, 0);
  }

  if (height < 0) {
    // I'm guessing this is an error
  } else if (height >= 0 && height <= 6) {
    show_lines(1, matrix.Color(255, 255, 255), 0);
  } else if (height >= 7 && height <= 13) {
    show_lines(2, matrix.Color(255, 255, 255), 0);
  } else if (height >= 14 && height <= 20) {
    show_lines(3, matrix.Color(255, 255, 255), 0);
  } else if (height >= 21 && height <= 27) {
    show_lines(4, matrix.Color(255, 255, 255), 0);
  } else if (height >= 28 && height <= 34) {
    show_lines(5, matrix.Color(255, 255, 255), 0);
  } else if (height >= 35 && height <= 41) {
    show_lines(6, matrix.Color(255, 255, 255), 0);
  } else if (height >= 42 && height <= 48) {
    show_lines(7, matrix.Color(255, 255, 255), 0);
  } else if (height >= 49 && height <= 55) {
    show_lines(8, matrix.Color(255, 255, 255), 0);
  } else if (height >= 56 && height <= 62) {
    show_lines(9, matrix.Color(255, 255, 255), 0);
  } else if (height >= 63 && height <= 69) {
    show_lines(10, matrix.Color(255, 255, 255), 0);
  } else if (height >= 70 && height <= 76) {
    show_lines(11, matrix.Color(255, 255, 255), 0);
  } else if (height >= 77) {
    show_lines(12, matrix.Color(255, 255, 255), 0);
  }

  vol[volCount] = n;                        // Save sample for dynamic leveling
  if (++volCount >= SAMPLES) volCount = 0;  // Advance/rollover sample counter

  // Get volume range of prior frames
  minLvl = maxLvl = vol[0];
  for (i = 1; i < SAMPLES; i++) {
    if (vol[i] < minLvl) minLvl = vol[i];
    else if (vol[i] > maxLvl) maxLvl = vol[i];
  }
  // minLvl and maxLvl indicate the volume range over prior frames, used
  // for vertically scaling the output graph (so it looks interesting
  // regardless of volume level).  If they're too close together though
  // (e.g. at very low volume levels) the graph becomes super coarse
  // and 'jumpy'...so keep some minimum distance between them (this
  // also lets the graph go to zero when no sound is playing):
  if ((maxLvl - minLvl) < TOP) maxLvl = minLvl + TOP;
  minLvlAvg = (minLvlAvg * 63 + minLvl) >> 6;  // Dampen min/max levels
  maxLvlAvg = (maxLvlAvg * 63 + maxLvl) >> 6;  // (fake rolling average)
}


// ###############################################################################################################################
// # VU meter 9 - Random LEDs VU meter
// ###############################################################################################################################
void vu_meter9() {
  uint8_t i;
  uint16_t minLvl, maxLvl;
  int n, height;

  n = analogRead(MIC_PIN);             // Raw reading from mic
  n = abs(n - 512 - DC_OFFSET);        // Center on zero
  n = (n <= NOISE) ? 0 : (n - NOISE);  // Remove noise/hum
  lvl = ((lvl * 7) + n) >> 3;          // "Dampened" reading (else looks twitchy)

  // Calculate bar height based on dynamic min/max levels (fixed point):
  height = TOP * (lvl - minLvlAvg) / (long)(maxLvlAvg - minLvlAvg);

  if (height < 0L) height = 0;  // Clip output
  else if (height > TOP) height = TOP;
  if (height > peak) peak = height;  // Keep 'peak' dot at top

  if (height < 0) {
    // I'm guessing this is an error
  } else if (height >= 0 && height <= 6) {
    RandomLED(50);
  } else if (height >= 7 && height <= 13) {
    RandomLED(50);
  } else if (height >= 14 && height <= 20) {
    RandomLED(50);
  } else if (height >= 21 && height <= 27) {
    RandomLED(50);
  } else if (height >= 28 && height <= 34) {
    RandomLED(15);
  } else if (height >= 35 && height <= 41) {
    RandomLED(15);
  } else if (height >= 42 && height <= 48) {
    RandomLED(15);
  } else if (height >= 49 && height <= 55) {
    RandomLED(15);
  } else if (height >= 56 && height <= 62) {
    RandomLED(2);
  } else if (height >= 63 && height <= 69) {
    RandomLED(2);
  } else if (height >= 70 && height <= 76) {
    RandomLED(2);
  } else if (height >= 77) {
    RandomLED(2);
  }

  vol[volCount] = n;                        // Save sample for dynamic leveling
  if (++volCount >= SAMPLES) volCount = 0;  // Advance/rollover sample counter

  // Get volume range of prior frames
  minLvl = maxLvl = vol[0];
  for (i = 1; i < SAMPLES; i++) {
    if (vol[i] < minLvl) minLvl = vol[i];
    else if (vol[i] > maxLvl) maxLvl = vol[i];
  }
  // minLvl and maxLvl indicate the volume range over prior frames, used
  // for vertically scaling the output graph (so it looks interesting
  // regardless of volume level).  If they're too close together though
  // (e.g. at very low volume levels) the graph becomes super coarse
  // and 'jumpy'...so keep some minimum distance between them (this
  // also lets the graph go to zero when no sound is playing):
  if ((maxLvl - minLvl) < TOP) maxLvl = minLvl + TOP;
  minLvlAvg = (minLvlAvg * 63 + minLvl) >> 6;  // Dampen min/max levels
  maxLvlAvg = (maxLvlAvg * 63 + maxLvl) >> 6;  // (fake rolling average)
}


// ###############################################################################################################################
// # VU meter 10 - VU meter 10 - Cube White
// ###############################################################################################################################
void vu_meter10() {
  uint8_t i;
  uint16_t minLvl, maxLvl;
  int n, height;

  n = analogRead(MIC_PIN);             // Raw reading from mic
  n = abs(n - 512 - DC_OFFSET);        // Center on zero
  n = (n <= NOISE) ? 0 : (n - NOISE);  // Remove noise/hum
  lvl = ((lvl * 7) + n) >> 3;          // "Dampened" reading (else looks twitchy)

  // Calculate bar height based on dynamic min/max levels (fixed point):
  height = TOP * (lvl - minLvlAvg) / (long)(maxLvlAvg - minLvlAvg);

  if (height < 0L) height = 0;  // Clip output
  else if (height > TOP) height = TOP;
  if (height > peak) peak = height;  // Keep 'peak' dot at top

  if (height < 0) {
    // I'm guessing this is an error
  } else if (height >= 0 && height <= 6) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 7 && height <= 13) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 14 && height <= 20) {
    show_Cube(matrix.Color(255, 255, 255), 0);
  } else if (height >= 21 && height <= 27) {
    show_Cube(matrix.Color(255, 255, 255), 0);
  } else if (height >= 28 && height <= 34) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 35 && height <= 41) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 42 && height <= 48) {
    show_Cube(matrix.Color(255, 255, 255), 0);
  } else if (height >= 49 && height <= 55) {
    show_Cube(matrix.Color(255, 255, 255), 0);
  } else if (height >= 56 && height <= 62) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 63 && height <= 69) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 70 && height <= 76) {
    show_Cube(matrix.Color(255, 255, 255), 0);
  } else if (height >= 77) {
    show_Cube(matrix.Color(255, 255, 255), 0);
  }

  vol[volCount] = n;                        // Save sample for dynamic leveling
  if (++volCount >= SAMPLES) volCount = 0;  // Advance/rollover sample counter

  // Get volume range of prior frames
  minLvl = maxLvl = vol[0];
  for (i = 1; i < SAMPLES; i++) {
    if (vol[i] < minLvl) minLvl = vol[i];
    else if (vol[i] > maxLvl) maxLvl = vol[i];
  }
  // minLvl and maxLvl indicate the volume range over prior frames, used
  // for vertically scaling the output graph (so it looks interesting
  // regardless of volume level).  If they're too close together though
  // (e.g. at very low volume levels) the graph becomes super coarse
  // and 'jumpy'...so keep some minimum distance between them (this
  // also lets the graph go to zero when no sound is playing):
  if ((maxLvl - minLvl) < TOP) maxLvl = minLvl + TOP;
  minLvlAvg = (minLvlAvg * 63 + minLvl) >> 6;  // Dampen min/max levels
  maxLvlAvg = (maxLvlAvg * 63 + maxLvl) >> 6;  // (fake rolling average)
}


// ###############################################################################################################################
// # VU meter 11 - VU meter 11 - Cube Coloured
// ###############################################################################################################################
void vu_meter11() {
  uint8_t i;
  uint16_t minLvl, maxLvl;
  int n, height;

  n = analogRead(MIC_PIN);             // Raw reading from mic
  n = abs(n - 512 - DC_OFFSET);        // Center on zero
  n = (n <= NOISE) ? 0 : (n - NOISE);  // Remove noise/hum
  lvl = ((lvl * 7) + n) >> 3;          // "Dampened" reading (else looks twitchy)

  // Calculate bar height based on dynamic min/max levels (fixed point):
  height = TOP * (lvl - minLvlAvg) / (long)(maxLvlAvg - minLvlAvg);

  if (height < 0L) height = 0;  // Clip output
  else if (height > TOP) height = TOP;
  if (height > peak) peak = height;  // Keep 'peak' dot at top

  if (height < 0) {
    // I'm guessing this is an error
  } else if (height >= 0 && height <= 6) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 7 && height <= 13) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 14 && height <= 20) {
    show_Cube(matrix.Color(0, 255, 0), 0);
  } else if (height >= 21 && height <= 27) {
    show_Cube(matrix.Color(0, 255, 0), 0);
  } else if (height >= 28 && height <= 34) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 35 && height <= 41) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 42 && height <= 48) {
    show_Cube(matrix.Color(255, 255, 0), 0);
  } else if (height >= 49 && height <= 55) {
    show_Cube(matrix.Color(255, 255, 0), 0);
  } else if (height >= 56 && height <= 62) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 63 && height <= 69) {
    show_Cube(matrix.Color(0, 0, 0), 0);
  } else if (height >= 70 && height <= 76) {
    show_Cube(matrix.Color(255, 0, 0), 0);
  } else if (height >= 77) {
    show_Cube(matrix.Color(255, 0, 0), 0);
  }

  vol[volCount] = n;                        // Save sample for dynamic leveling
  if (++volCount >= SAMPLES) volCount = 0;  // Advance/rollover sample counter

  // Get volume range of prior frames
  minLvl = maxLvl = vol[0];
  for (i = 1; i < SAMPLES; i++) {
    if (vol[i] < minLvl) minLvl = vol[i];
    else if (vol[i] > maxLvl) maxLvl = vol[i];
  }
  // minLvl and maxLvl indicate the volume range over prior frames, used
  // for vertically scaling the output graph (so it looks interesting
  // regardless of volume level).  If they're too close together though
  // (e.g. at very low volume levels) the graph becomes super coarse
  // and 'jumpy'...so keep some minimum distance between them (this
  // also lets the graph go to zero when no sound is playing):
  if ((maxLvl - minLvl) < TOP) maxLvl = minLvl + TOP;
  minLvlAvg = (minLvlAvg * 63 + minLvl) >> 6;  // Dampen min/max levels
  maxLvlAvg = (maxLvlAvg * 63 + maxLvl) >> 6;  // (fake rolling average)
}


// ###############################################################################################################################
// # Theater-marquee-style chasing lights:
// ###############################################################################################################################
void theaterChase(uint32_t color, int wait) {
  for (int a = 0; a < 10; a++) {   // Repeat 10 times...
    for (int b = 0; b < 3; b++) {  //  'b' counts from 0 to 2...
      matrix.clear();              //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of matrix in steps of 3...
      for (int c = b; c < matrix.numPixels(); c += 3) {
        matrix.setPixelColor(c, color);  // Set pixel 'c' to value 'color'
      }
      matrix.show();  // Update matrix with new contents
      delay(wait);    // Pause for a moment
    }
  }
}


// ###############################################################################################################################
// # Rainbow cycle along whole matrix. Pass delay time (in ms) between frames:
// ###############################################################################################################################
void rainbow(int wait) {
  // Hue of first pixel runs 3 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 3*65536. Adding 256 to firstPixelHue each time
  // means we'll make 3*65536/256 = 768 passes through this outer loop:
  for (long firstPixelHue = 0; firstPixelHue < 3 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < matrix.numPixels(); i++) {  // For each pixel in matrix...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the matrix
      // (matrix.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / matrix.numPixels());
      // matrix.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through matrix.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      matrix.setPixelColor(i, matrix.gamma32(matrix.ColorHSV(pixelHue)));
    }
    matrix.show();  // Update matrix with new contents
    delay(wait);    // Pause for a moment
  }
}


// ###############################################################################################################################
// # Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames
// ###############################################################################################################################
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;           // First pixel starts at red (hue 0)
  for (int a = 0; a < 30; a++) {   // Repeat 30 times...
    for (int b = 0; b < 3; b++) {  //  'b' counts from 0 to 2...
      matrix.clear();              //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of matrix in increments of 3...
      for (int c = b; c < matrix.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the matrix (matrix.numPixels() steps):
        int hue = firstPixelHue + c * 65536L / matrix.numPixels();
        uint32_t color = matrix.gamma32(matrix.ColorHSV(hue));  // hue -> RGB
        matrix.setPixelColor(c, color);                         // Set pixel 'c' to value 'color'
      }
      matrix.show();                // Update matrix with new contents
      delay(wait);                  // Pause for a moment
      firstPixelHue += 65536 / 90;  // One cycle of color wheel over 90 frames
    }
  }
}


// ###############################################################################################################################
// # Show single lines function:
// ###############################################################################################################################
void show_lines(int line, uint32_t color, int LEDsOff) {
  int myArray[28];
  memset(myArray, 99, sizeof(myArray));

  if (line == 1) {
    int myArrayL1[] = { 0, 1, 2, 3, 4, 5, 6, 7 };  // Line 1 - BOTTOM
    memcpy(myArray, myArrayL1, sizeof(myArrayL1));
  }
  if (line == 2) {
    int myArrayL2[] = { 8, 9, 10, 11, 12, 13, 14, 15 };  // Line 2
    memcpy(myArray, myArrayL2, sizeof(myArrayL2));
  }
  if (line == 3) {
    int myArrayL3[] = { 16, 17, 18, 19, 20, 21, 22, 23 };  // Line 3
    memcpy(myArray, myArrayL3, sizeof(myArrayL3));
  }
  if (line == 4) {
    int myArrayL4[] = { 24, 25, 26, 27, 28, 29, 30, 31 };  // Line 4
    memcpy(myArray, myArrayL4, sizeof(myArrayL4));
  }
  if (line == 5) {
    int myArrayL5[] = { 32, 33, 34, 35, 36, 37, 38, 39 };  // Line 5
    memcpy(myArray, myArrayL5, sizeof(myArrayL5));
  }
  if (line == 6) {
    int myArrayL6[] = { 40, 41, 42, 43, 44, 45, 46, 47 };  // Line 6
    memcpy(myArray, myArrayL6, sizeof(myArrayL6));
  }
  if (line == 7) {
    int myArrayL7[] = { 48, 49, 50, 51, 52, 53, 54, 55 };  // Line 7
    memcpy(myArray, myArrayL7, sizeof(myArrayL7));
  }
  if (line == 8) {
    int myArrayL8[] = { 56, 57, 58, 59, 60, 61, 62, 63 };  // Line 8
    memcpy(myArray, myArrayL8, sizeof(myArrayL8));
  }
  if (line == 9) {
    int myArrayL9[] = { 64, 65, 66, 67, 68, 69, 70, 71, 72, 79, 80, 87, 88, 95, 96, 103, 104, 111, 112, 119, 120, 121, 122, 123, 124, 125, 126, 127 };  // Line 9
    memcpy(myArray, myArrayL9, sizeof(myArrayL9));
  }
  if (line == 10) {
    int myArrayL10[] = { 78, 77, 76, 75, 74, 73, 81, 86, 94, 89, 97, 102, 110, 105, 113, 114, 115, 116, 117, 118 };  // Line 10
    memcpy(myArray, myArrayL10, sizeof(myArrayL10));
  }
  if (line == 11) {
    int myArrayL11[] = { 109, 108, 107, 106, 98, 101, 93, 90, 82, 83, 84, 85 };  // Line 11
    memcpy(myArray, myArrayL11, sizeof(myArrayL11));
  }
  if (line == 12) {
    int myArrayL12[] = { 99, 100, 92, 91 };  // Line 12
    memcpy(myArray, myArrayL12, sizeof(myArrayL12));
  }

  for (int element : myArray) {
    matrix.setPixelColor(element, color);
  }
  matrix.show();
  delay(LEDsOff);
  if (LEDsOff != 0) {
    for (int element : myArray) {
      color = (0, 0, 0);
      matrix.setPixelColor(element, color);
    }
    matrix.show();
    delay(LEDsOff);
  }
}


// ###############################################################################################################################
// # Multiple Cube function:
// ###############################################################################################################################
void show__multi_Cube(int Cube, uint32_t color, int LEDsOff) {
  int myArray[99];
  memset(myArray, 99, sizeof(myArray));

  if (Cube == 1) {
    int myArrayT1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 23, 24, 31, 32, 39, 40, 47, 48, 55, 56, 57, 58, 59, 60, 61, 62, 63 };  // Line 1 - Outside
    memcpy(myArray, myArrayT1, sizeof(myArrayT1));
  }
  if (Cube == 2) {
    int myArrayT2[] = { 1 };  // Line 2
    memcpy(myArray, myArrayT2, sizeof(myArrayT2));
  }
  if (Cube == 3) {
    int myArrayT3[] = { 1 };  // Line 3
    memcpy(myArray, myArrayT3, sizeof(myArrayT3));
  }
  if (Cube == 4) {
    int myArrayT4[] = { 1 };  // Line 4 - Inside
    memcpy(myArray, myArrayT4, sizeof(myArrayT4));
  }

  for (int element : myArray) {
    matrix.setPixelColor(element, color);
  }
  matrix.show();
  delay(LEDsOff);
  if (LEDsOff != 0) {
    for (int element : myArray) {
      color = (0, 0, 0);
      matrix.setPixelColor(element, color);
    }
    matrix.show();
    delay(LEDsOff);
  }
}


// ###############################################################################################################################
// # Outside Cube function:
// ###############################################################################################################################
void show_Cube(uint32_t color, int LEDsOff) {
  int myArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 23, 24, 31, 32, 39, 40, 47, 48, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 79, 80, 87, 88, 95, 96, 103, 104, 111, 112, 119, 120, 121, 122, 123, 124, 125, 126, 127 };
  for (int element : myArray) {
    matrix.setPixelColor(element, color);
  }
  matrix.show();
  delay(LEDsOff);
  if (LEDsOff != 0) {
    for (int element : myArray) {
      color = (0, 0, 0);
      matrix.setPixelColor(element, color);
    }
    matrix.show();
    delay(LEDsOff);
  }
}


// ###############################################################################################################################
// # Random LED function:
// ###############################################################################################################################
float redCol[N_PIXELS];
float blueCol[N_PIXELS];
float greenCol[N_PIXELS];
unsigned int sample;
void RandomLED(int RandomNumber) {
  if (random(RandomNumber) == 1) {
    uint16_t i = random(N_PIXELS);
    if (redCol[i] < 1 && greenCol[i] < 1 && blueCol[i] < 1) {
      redCol[i] = random(256);
      greenCol[i] = random(256);
      blueCol[i] = random(256);
    }
  }
  for (uint16_t l = 0; l < N_PIXELS; l++) {
    if (redCol[l] > 1 || greenCol[l] > 1 || blueCol[l] > 1) {
      matrix.setPixelColor(l, redCol[l], greenCol[l], blueCol[l]);
      if (redCol[l] > 1) {
        redCol[l] = redCol[l] * 0.96;
      } else {
        redCol[l] = 0;
      }
      if (greenCol[l] > 1) {
        greenCol[l] = greenCol[l] * 0.96;
      } else {
        greenCol[l] = 0;
      }
      if (blueCol[l] > 1) {
        blueCol[l] = blueCol[l] * 0.96;
      } else {
        blueCol[l] = 0;
      }
    } else {
      matrix.setPixelColor(l, 0, 0, 0);
    }
  }
  matrix.show();
  //delay(5);
}


// ###############################################################################################################################
// # Show WiFi status icon:
// ###############################################################################################################################
void show_wifi(uint32_t color) {
  matrix.setBrightness(15);
  int myArray[] = { 0, 7, 56, 63, 64, 71, 120, 127 };
  for (int element : myArray) {
    matrix.setPixelColor(element, color);
  }
  matrix.show();
}


// ###############################################################################################################################
// # Color wheel function:
// ###############################################################################################################################
// Input a value 0 to 255 to get a color value.
// The colors are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return matrix.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return matrix.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return matrix.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}


// ###############################################################################################################################
// # Color Wipe function:
// ###############################################################################################################################
void colorWipe(uint32_t color, uint8_t wait) {
  for (uint16_t i = 0; i < matrix.numPixels(); i++) {
    matrix.setPixelColor(i, color);
  }
  matrix.show();
}


// ###########################################################################################################################################
// # REST command function: ROOT
// ###########################################################################################################################################
void handleRoot() {
  WiFiClient client = server.available();
  server1->send(200, "text/plain", "REST web server active");
  Serial.print("REST web server active on port: ");
  Serial.println(55555);
  client.stop();
}


// ###########################################################################################################################################
// # Restart the ESP:
// ###########################################################################################################################################
void ESPRestart() {
  WiFiClient client = server.available();
  server1->send(200, "text/plain", "ESP WILL RESTART IN 3 SECONDS...");
  colorWipe(matrix.Color(0, 0, 0), 0);  // LEDs off
  for (int i = 8; i > 0; i--) {
    show_lines(i, matrix.Color(255, 255, 255), 50);
  }
  delay(5000);
  client.stop();
  Serial.println("####################################");
  Serial.println("# ESP WILL RESTART IN 3 SECONDS... #");
  Serial.println("####################################");
  delay(3000);
  ESP.restart();
}


// ###########################################################################################################################################
// # Reset the WiFi configuration:
// ###########################################################################################################################################
void ESPWifiReset() {
  WiFiClient client = server.available();
  server1->send(200, "text/plain", "WIFI SETTING WERE SET TO DEFAULT... ESP WILL NOW RESTART... PLEASE CONFIGURE WIFI AGAIN...");
  delay(5000);
  client.stop();
  WiFi.disconnect(true);
  delay(1500);
  WiFiManager wifiManager;
  delay(1500);
  wifiManager.resetSettings();
  delay(1500);
  Serial.println("################################################################################################");
  Serial.println("# WIFI SETTING WERE SET TO DEFAULT... ESP WILL NOW RESTART... PLEASE CONFIGURE WIFI AGAIN...   #");
  Serial.println("################################################################################################");
  delay(3000);
  ESP.restart();
}


// ###############################################################################################################################
// # LED test funtion:
// ###############################################################################################################################
void LEDTEST() {
  for (int i = 0; i < 13; i++) {
    matrix.setBrightness(15);
    show_lines(i, matrix.Color(255, 255, 255), 100);
  }
}


// ###############################################################################################################################
// # Adafruit license information:
// ###############################################################################################################################
// SPDX-FileCopyrightText: 2017 Mikey Sklar for Adafruit Industries
// SPDX-FileCopyrightText: 2019 Anne Barela for Adafruit Industries
//
// SPDX-License-Identifier: MIT
/*
  LED VU meter for Arduino and Adafruit NeoPixel matrix. More info: http://learn.adafruit.com/led-ampli-tie/
  Hardware requirements:
  - Most Arduino or Arduino-compatible boards (ATmega 328P or better).
  - Adafruit Electret Microphone Amplifier (ID: 1063)
  - Adafruit Flora RGB Smart Pixels (ID: 1260)
   OR
  - Adafruit NeoPixel Digital LED matrix (ID: 1138)
  - Optional: battery for portable use (else power through USB or adapter)
  Software requirements:
  - Adafruit NeoPixel library
  Connections:
  - 3.3V to mic amp +
  - GND to mic amp -
  - Analog pin to microphone output (configurable below)
  - Digital pin to LED data input (configurable below)
  See notes in setup() regarding 5V vs. 3.3V boards - there may be an
  extra connection to make and one line of code to enable or disable.
  Written by Adafruit Industries.  Distributed under the BSD license.
  This paragraph must be included in any redistribution.
*/


// ###############################################################################################################################
// # EOF - You have successfully reached the end of the code - well done ;-)
// ###############################################################################################################################