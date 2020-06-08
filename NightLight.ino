#define AVG_SIZE 3
#define SENSOR_PIN A7
#define INDICATOR_PIN 2
#define LOOP_DELAY_MS 200
#define THRES 220

void setup() {
  // put your setup code here, to run once:
  pinMode(INDICATOR_PIN, OUTPUT);
  //Feature 1: Serial init
  Serial.begin(9600);
  Serial.println("hello NightLight");

}

long lightValAvgHist[AVG_SIZE] = {0,0,0};
int avgIdx=0;

void loop() {
  // put your main code here, to run repeatedly:
  long lightValRaw;
  long lightValAvg;

  //Feature 3: delay
  delay(LOOP_DELAY_MS);
  //Feature 4: Read analog value
  lightValRaw = analogRead(SENSOR_PIN);
  //Serial.print("RAW=");
  //Serial.println(lightValRaw);

  //Feature 6: averaging
  lightValAvgHist[avgIdx] = lightValRaw;
  avgIdx++;
  if(avgIdx>=AVG_SIZE){
    avgIdx=0;
  }

  Serial.print("AVG=");
  //Feature 6: averaging
  for(int i=0;i<AVG_SIZE;i++){
    lightValAvg += lightValAvgHist[i];
    //Serial.print(lightValAvgHist[i]);
    //Serial.print(",");
  }
  lightValAvg /= AVG_SIZE;
  Serial.print(lightValAvg);
  Serial.println("");

  //Feature 5: thresholding
  if(lightValAvg<THRES){
    //Feature 2: blink LED
    digitalWrite(INDICATOR_PIN,HIGH);
  } else if(lightValAvg>THRES) {
    //Feature 2: blink LED
    digitalWrite(INDICATOR_PIN,LOW);
  }
}
