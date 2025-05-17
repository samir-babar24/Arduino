#include
int samir[] = {100, 200, 300, 400, 500, 800};
const int NUM_READINGS = sizeof(samir) / sizeof(samir[0]);

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  for (int i = 0; i < NUM_READINGS; i++) {
    int temp = samir[i];
    Serial.print("Loop #");
    Serial.print(i);
    Serial.print(": Temperature = ");
    Serial.println(temp);

    if (temp < 500) {
      Serial.println("  -> Below 500, pulsing port 4");
      digitalWrite(4, HIGH);
      delay(1000);
      digitalWrite(4, LOW);
    }
    else if (temp > 500) {
      Serial.println("  -> Above 500, pulsing port 5");
      digitalWrite(5, HIGH);
      delay(1000);
      digitalWrite(5, LOW);
    }
    else {
      Serial.println("  -> Equal to 500, pulsing port 6");
      digitalWrite(6, HIGH);
      delay(1000);
      digitalWrite(6, LOW);
    }

    delay(500);
  }

  Serial.println("=== End of sequence ===");
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(2000);
}
