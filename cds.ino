const int CDS_PORT = A0;  // CdSセンサー入力ポート
const int LED_PORT = 9;   // LED出力ポート
const boolean SERIAL_OUTPUT = true; // 輝度のシリアル出力
const int LOOP_DELAY = 200; // ループ周期(ms)


void setup() {
  pinMode(LED_PORT, OUTPUT);  // LEDポートを出力ポートにセット

  if(SERIAL_OUTPUT){
    Serial.begin(9600);
  }
}

void loop() {
  int brightness = analogRead(CDS_PORT);  // センサーからのアナログデータを取得
  int luminance = map(brightness, 0, 1023, 255, 0);

  analogWrite(LED_PORT, luminance);
  
  if(SERIAL_OUTPUT){
    Serial.begin(9600);
    Serial.print(luminance);
    Serial.println("");
  }
  
  delay(LOOP_DELAY);
}
