#define sync_pin D2 // GPIO4 or D2 on the ESP8266
#define data_pin D3 // GPIO0 or D3 on the ESP8266
#define clock_pin D4 // GPIO2 or D4 on the ESP8266 

int led_cmd[10] =  {0,0,1,0,0,0,0,1,0,0}; //Activates/initialises the LEDs, leaving the center LED lit.
int anim_cmd[10] = {0,0,1,0,0,0,0,1,0,1}; //Makes the startup animation on the ring of light.
int sync_cmd[10] = {0,0,0,0,0,0,0,1,0,0}; //Initiates the sync process.
volatile boolean sync_enable = 0;

void sendData(int cmd_do[]) {
  pinMode(data_pin, OUTPUT);
  digitalWrite(data_pin, LOW);    //start sending data.
  int prev = 1;
  for(int i = 0; i < 10; i++){

    while (prev == digitalRead(clock_pin)){} //detects change in clock
    prev = digitalRead(clock_pin);
    // should be after downward edge of clock, so send bit of data now
    digitalWrite(data_pin, cmd_do[i]);

    while (prev == digitalRead(clock_pin)){} //detects upward edge of clock
    prev = digitalRead(clock_pin);
  }
  digitalWrite(data_pin, HIGH);
  pinMode(data_pin, INPUT);
}

void initLEDs(){
  sendData(led_cmd);
  delay(50);
  sendData(anim_cmd);
  delay(50);
}

void ICACHE_RAM_ATTR wakeUp(){
  sync_enable = 1;
}

void sleepNow() {
  ESP.deepSleep(0); // Sleep indefinitely until an external interrupt wakes it up
}

void setup() {
  Serial.begin(9600);
  pinMode(sync_pin, INPUT_PULLUP);  // Internal pull-up
  pinMode(data_pin, INPUT);
  pinMode(clock_pin, INPUT);
  delay(2000);

  initLEDs();
  // sendData(sync_cmd);

  attachInterrupt(digitalPinToInterrupt(sync_pin), wakeUp, FALLING);
}

void loop(){
  Serial.println("Sleeping.");
  sleepNow();
  delay(200);
  if(sync_enable == 1) {
    Serial.println("Syncing.");
    sendData(sync_cmd);
    sync_enable = 0;
  }
}
