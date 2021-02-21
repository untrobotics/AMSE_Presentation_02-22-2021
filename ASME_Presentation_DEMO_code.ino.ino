/*
 * Created: Tyler A. Martinez
 * For: ASME Ardiuno Presentations Mon Feb 22, 2021 6:30PM (CST)
 * List of Required Material(s): Ardiuno IDE or Access to online
 * List of Recommeded Material(s): Arduino MEGA, Brushless Motor and Electronic Speed Control (ESC) Pair, Battery at the same voltage as the motor, Breadboard, Wires
 * For more info on what the Arduino Mega Borad Can do: https://www.arduino.cc/en/pmwiki.php?n=Main/ArduinoBoardMega
 * For more info on programming your Ardiuno Borad: https://www.arduino.cc/reference/en/
 */

#define ESC_CONTROLLER_PIN 13
#define BAUD_RATE 9600

/* 
 *  Note: The Arduino Mega can haves 4 Serial port (Serial, Serial1, Serial2, Serial3) running simutaneously
 *        The board has 11 PWM pins (2 - 13), the function to use PWM is analogWrite(pin, value) *value ranges from 0 to 255* [8-bit PWM]
 */

void setup() {
  Serial.begin(BAUD_RATE); // Opens serial port up for Serial Monitor, using the UART portical, sets data rate to 9600bps (baud rate) *The default rate for the arduino board*
  Serial.println("COMM PORT : <ENTER THE PORT NUM HERE>");

  pinMode( ESC_CONTROLLER_PIN, OUTPUT);

}

void loop() {
  moveMotor(1000);
  stopMotor(1000);
  moveMotor_PWM(1500, 200);
  stopMotor(1000);

}


void moveMotor(int length_of_time) {
  digitalWrite(ESC_CONTROLLER_PIN, HIGH);
  delay(length_of_time);
  String output_str = String("Brushless Motor is moving at full speed for " + String(length_of_time) + "ms");
  Serial.println(output_str);
}


void stopMotor(int length_of_time) {
  digitalWrite(ESC_CONTROLLER_PIN, LOW);
  delay(length_of_time);
  String output_str = String("Brushless Motor is is not moving for " + String(length_of_time) + "ms");
  Serial.println(output_str);
}


void moveMotor_PWM( int length_of_time, double duty_cycle) {
  analogWrite(ESC_CONTROLLER_PIN, duty_cycle);
  delay(length_of_time);
  String output_str = String("Brushless Motor is moving at " + String(duty_cycle) + " for " + String(length_of_time) + "ms");
  Serial.println(output_str);
}
