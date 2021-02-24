
/*
 * Created: Tyler A. Martinez
 * For: ASME Ardiuno Presentations Mon Feb 22, 2021 6:30PM (CST)
 * List of Required Material(s): Ardiuno IDE or Access to online
 * List of Recommeded Material(s): Arduino MEGA, Brushless Motor and Electronic Speed Control (ESC) Pair, Battery at the same voltage as the motor, Breadboard, Wires
 * For more info on what the Arduino Mega Borad Can do: https://www.arduino.cc/en/pmwiki.php?n=Main/ArduinoBoardMega
 * For more info on programming your Ardiuno Borad: https://www.arduino.cc/reference/en/
 */


#define Fwd_Pin 13 
#define Bwd_Pin 12
#define BAUD_RATE 9600

/* 
 *  Note: The Arduino Mega can haves 4 Serial port (Serial, Serial1, Serial2, Serial3) running simutaneously
 *        The board has 11 PWM pins (2 - 13), the function to use PWM is analogWrite(pin, value) *value ranges from 0 to 255* [8-bit PWM]  
 */



void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD_RATE); //Serial Moniter 
  Serial.println("AMSE DEMO");

  //Define pins as OUTPUTS
  pinMode(Fwd_Pin, OUTPUT);
  pinMode(Bwd_Pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  moveFwdMotor(1000);
  stopMotor(1500);
  moveFwdMotor_PWM(1000, 150);

}

// Move Forward at Full speed
void moveFwdMotor(int length_of_time) {
  digitalWrite(Fwd_Pin, HIGH);
  digitalWrite(Bwd_Pin, LOW);
  delay(length_of_time);
  String output_str = String("Motor is moving forward for " + String(length_of_time) + "ms");
  Serial.println(output_str);
}

// Stop the Motor 
void stopMotor(int length_of_time) {
  digitalWrite(Fwd_Pin, LOW);
  digitalWrite(Bwd_Pin, LOW);
  delay(length_of_time);
  String output_str = String("Motor is stopped " + String(length_of_time) + "ms");
  Serial.println(output_str);
}


// Move Forward at speed determined by user
void moveFwdMotor_PWM(int length_of_time, double duty_cycle) {
  analogWrite(Fwd_Pin, duty_cycle);
  digitalWrite(Bwd_Pin, LOW);
  delay(length_of_time);
  String output_str = String("Motor is moving forward for " + String(length_of_time) + "ms at " + String(duty_cycle) + " speed");
  Serial.println(output_str);
}
