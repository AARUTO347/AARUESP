// ============================================================
//  AARUESP MPU6050 IMU Example
//  MADE BY AARUTO
// ============================================================
#include <AARUESP.h>

void setup() {
  Serial.begin(115200);
  AARUESP.begin();
  AARUESP.mpu6050(0x68);
}

void loop() {
  float ax, ay, az, gx, gy, gz;
  if (AARUESP.readAccel(ax, ay, az) && AARUESP.readGyro(gx, gy, gz)) {
    Serial.print("Accel: ");
    Serial.print(ax, 2); Serial.print("g, ");
    Serial.print(ay, 2); Serial.print("g, ");
    Serial.print(az, 2); Serial.println("g");
    Serial.print("Gyro:  ");
    Serial.print(gx, 1); Serial.print("d/s, ");
    Serial.print(gy, 1); Serial.print("d/s, ");
    Serial.print(gz, 1); Serial.println("d/s");
    Serial.print("Temp: ");
    Serial.print(AARUESP.readIMUTemp(), 1);
    Serial.println(" C");
  } else {
    Serial.print("MPU Error: ");
    Serial.println(AARUESP.errorString());
  }
  Serial.println("---");
  delay(500);
}