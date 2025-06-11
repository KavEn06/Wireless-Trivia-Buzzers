// include libraries
#include <esp_now.h>
#include <WiFi.h>
#include <LiquidCrystal_PCF8574.h>
#include <FS.h>
#include <SD.h>
#include <SPI.h>
#include <AudioFileSourceSD.h>
#include <AudioGeneratorMP3.h>
#include <AudioOutputI2S.h>

// setting up the variables for reset button
#define reset 16

// SD card chip pin 
#define SD_CS_PIN 5  

AudioGeneratorMP3 *mp3;
AudioFileSourceSD *file;
AudioOutputI2S *out;

// variable for storing the button status
int statereset = 0;
int ind = 0; 
String buttons[4]; 
bool Apress = false; 
bool Bpress = false; 
bool Cpress = false; 
bool Dpress = false; 

// MAC address' of buzzers
uint8_t teamA[] = { 0xA8, 0x42, 0xE3, 0xBC, 0x72, 0xF8 };
uint8_t teamB[] = { 0xE4, 0x65, 0xB8, 0x79, 0x78, 0xB0 };
uint8_t teamC[] = { 0xA0, 0xA3, 0xB3, 0xAB, 0x84, 0x24 };
uint8_t teamD[] = { 0xE4, 0x65, 0xB8, 0x79, 0x82, 0xD0 };

// define I2C address for 16x2 LCD
#define I2C_ADDR 0x27
LiquidCrystal_PCF8574 lcd(I2C_ADDR);

// data structure
typedef struct buttonpress {
  String button;
} buttonpress;

// create a structured object
buttonpress myData;

// peer info
esp_now_peer_info_t peerInfo;

// callback function when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
// callback functions when data is received
void OnDataRecv(const esp_now_recv_info *recv_info, const uint8_t *incomingData, int len) {
  const uint8_t* mac = recv_info->src_addr; 
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Data received: ");
  Serial.println(len);
  Serial.println("Button: ");
  Serial.println(myData.button);
  buttonSelect(myData.button); 
}

// buzzed button void method 
void buttonSelect(String button) {
  if (button[0] == 'A' && !Apress) {
    Apress = true; 
    buttons[ind] = button; 
    ind++;
  } 
  else if (button[0] == 'B' && !Bpress) {
    Bpress = true;
    buttons[ind] = button;
    ind++;
  }
  else if (button[0] == 'C' && !Cpress) {
    Cpress = true;
    buttons[ind] = button;
    ind++;
  }
  else if (button[0] == 'D' && !Dpress) {
    Dpress = true;
    buttons[ind] = button;
    ind++;
  }
  playMP3("/buzz.mp3");
}

// audio void method 
void playMP3(const char* filename) {
  // stop playing mp3 if there is one playing currently 
   if (mp3->isRunning()) {
    mp3->stop();
  }

  // delete whatever file was used previously 
  if (file) {
    delete file;
    file = nullptr;
  }

  // create new file for the current audio 
  file = new AudioFileSourceSD(filename);
  if (!file || !file->isOpen()) {
    Serial.println("Failed to open file!");
    return;
  }

  // play current audio
  if (!mp3->begin(file, out)) {
    Serial.println("Failed to begin MP3 playback.");
  } else {
    Serial.println("Playback started.");
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  Wire.begin();

  // initialize the LCD
  lcd.begin(16, 2);
  lcd.setBacklight(255); 

  // initializing the button pins as input
  pinMode(reset, INPUT);

  // initilize esp-now
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP_NOW");
    return;
  }

  // register received callback
  esp_now_register_recv_cb(OnDataRecv);

  // register send callback
  esp_now_register_send_cb(OnDataSent);

  // register peer
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // add buzzer A as peer 
  memcpy(peerInfo.peer_addr, teamA, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  // add buzzer B as peer 
  memcpy(peerInfo.peer_addr, teamB, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  // add buzzer C as peer 
  memcpy(peerInfo.peer_addr, teamC, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  // add buzzer D as peer 
  memcpy(peerInfo.peer_addr, teamD, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

   // Mount SD card
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card mount failed!");
    while (1);
  }
  Serial.println("SD card initialized.");

  // Set up I2S for MAX98357A
  out = new AudioOutputI2S();
  out->SetPinout(26, 25, 17);  // BCLK, LRC, DIN
  out->SetGain(1.0);           // Max volume

  // Open MP3 and play as a test for startup 
  mp3 = new AudioGeneratorMP3(); // just once in setup
  playMP3("/buzz.mp3");
}

void loop() {
  statereset = digitalRead(reset);

  lcd.setCursor(0, 0);
  lcd.print("Buttons:");

  String displayText = "";
  for (int i = 0; i < ind; i++) {
    displayText += buttons[i] + " ";
  }
  lcd.setCursor(0, 1);
  lcd.print(displayText); 

  if (statereset == HIGH) {
    myData.button = "clear";
    esp_now_send(0, (uint8_t *)&myData, sizeof(myData));
    ind = 0; 

    Apress = false; 
    Bpress = false; 
    Cpress = false; 
    Dpress = false; 

    for (int i = 0; i < 4; i++) {
      buttons[i] = "";
    }
  }

  delay(500);
  lcd.clear();
}
