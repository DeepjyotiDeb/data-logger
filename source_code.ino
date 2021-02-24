#include<FS.h>

String x;
int i;
int IRSensor =13; // connect ir sensor to arduino pin d7
int val=0;
 
void setup() {
    Serial.begin(115200);
    pinMode(IRSensor, INPUT);
    Serial.println("begin sensor");
    Serial.println("type print to see result");

    bool success=SPIFFS.begin();
    if(!success) {
      Serial.println("error mounting file");
      return;
    } 
}
 
 
 
void loop() {
  val=digitalRead(IRSensor);
  if(val==LOW)
  {
    delay(1000);
    i++;
    File file=SPIFFS.open("/sensor_dat.txt","w");
    int bytesWritten=file.print(i);
    file.close();    
  }
    if(Serial.available()){
        x = Serial.readStringUntil('\n');
        if(x="print")
        {
          File file2=SPIFFS.open("/sensor_dat.txt","r");
          if(!file2) {
          Serial.println("failed to open file");
          return;
        }
        Serial.println("content:");
        while(file2.available()) {
          Serial.write(file2.read());
        }
        file2.close();
    }
    }}
