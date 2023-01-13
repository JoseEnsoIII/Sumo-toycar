#include <Servo.h>

// Define pins for sensor, motors and servo
#define IR_SENSOR_PIN A0
#define LEFT_MOTOR_PIN 5
#define RIGHT_MOTOR_PIN 6
#define SERVO_PIN 9

// Create Servo object
Servo servo;

// Create variables to store sensor data
int ir_sensor_data = 0;

// Create variables to store motor speed
int left_motor_speed = 0;
int right_motor_speed = 0;

// Create variable to store servo position
int servo_position = 0;

void setup() {
  // Initialize sensor and motors
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LEFT_MOTOR_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);
  
  // Attach the servo to the servo pin
  servo.attach(SERVO_PIN);
}

void loop() {
  // Read sensor data
  ir_sensor_data = analogRead(IR_SENSOR_PIN);
  
  // Check if sensor data indicates an enemy robot is present
  if (ir_sensor_data > 200) {
    // Set motors to rotate in opposite directions
    left_motor_speed = -255;
    right_motor_speed = 255;
    
    // Move servo to push enemy robot
    servo_position = 90;
    servo.write(servo_position);
  } else {
    // Set motors to move forward
    left_motor_speed = 255;
    right_motor_speed = 255;
    
    // Move servo back to neutral position
    servo_position = 0;
    servo.write(servo_position);
  }
  
  // Control motors
  analogWrite(LEFT_MOTOR_PIN, left_motor_speed);
  analogWrite(RIGHT_MOTOR_PIN, right_motor_speed);
  
  // Wait for a bit before reading sensor again
  delay(50);
}
