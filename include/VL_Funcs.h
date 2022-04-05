#include "Adafruit_VL53L0X.h"

#define VL_ADDRES01 0X30
#define VL_ADDRES02 0X31
#define VL_ADDRES03 0X32
#define VL_ADDRES04 0X33
#define VL_ADDRES05 0X34

#define VL_PIN01 18
#define VL_PIN02 5
#define VL_PIN03 17
#define VL_PIN04 16
#define VL_PIN05 4

Adafruit_VL53L0X VL01 = Adafruit_VL53L0X();
Adafruit_VL53L0X VL02 = Adafruit_VL53L0X();
Adafruit_VL53L0X VL03 = Adafruit_VL53L0X();
Adafruit_VL53L0X VL04 = Adafruit_VL53L0X();
Adafruit_VL53L0X VL05 = Adafruit_VL53L0X();



VL53L0X_RangingMeasurementData_t measure1;
VL53L0X_RangingMeasurementData_t measure2;
VL53L0X_RangingMeasurementData_t measure3;
VL53L0X_RangingMeasurementData_t measure4;
VL53L0X_RangingMeasurementData_t measure5;

void setID() {
  // all reset
  digitalWrite(VL_PIN01, LOW); 
  digitalWrite(VL_PIN02, LOW); 
  digitalWrite(VL_PIN03, LOW); 
  digitalWrite(VL_PIN04, LOW); 
  digitalWrite(VL_PIN05, LOW); 
  vTaskDelay(10);
  // all unreset
  digitalWrite(VL_PIN01, HIGH); 
  digitalWrite(VL_PIN02, HIGH); 
  digitalWrite(VL_PIN03, HIGH); 
  digitalWrite(VL_PIN04, HIGH); 
  digitalWrite(VL_PIN05, HIGH); 
  vTaskDelay(10);

  // activating LOX1 and resetting LOX2
  digitalWrite(VL_PIN01, HIGH); 
  digitalWrite(VL_PIN02, LOW ); 
  digitalWrite(VL_PIN03, LOW ); 
  digitalWrite(VL_PIN04, LOW ); 
  digitalWrite(VL_PIN05, LOW ); 

  // initing LOX1
  if(!VL01.begin(VL_ADDRES01)) {
    Serial.println(F("Failed to boot first VL53L0X"));
    while(1);
  }
  vTaskDelay(10);
 
  digitalWrite(VL_PIN02, HIGH);
  vTaskDelay(10); 
  if(!VL02.begin(VL_ADDRES02)) {
    Serial.println(F("Failed to boot second VL53L0X"));
    while(1);
  }

  digitalWrite(VL_PIN03, HIGH);
  vTaskDelay(10); 
  if(!VL03.begin(VL_ADDRES03)) {
    Serial.println(F("Failed to boot second VL53L0X"));
    while(1);
  }

  digitalWrite(VL_PIN04, HIGH);
  vTaskDelay(10); 
  if(!VL04.begin(VL_ADDRES04)) {
    Serial.println(F("Failed to boot second VL53L0X"));
    while(1);
  }

  digitalWrite(VL_PIN05, HIGH);
  vTaskDelay(10); 
  if(!VL04.begin(VL_ADDRES05)) {
    Serial.println(F("Failed to boot second VL53L0X"));
    while(1);
  } 
} 