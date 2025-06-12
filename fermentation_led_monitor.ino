/*
  LED Fermentation Monitor
  Simulates yeast activity by shifting LED colors over time.
  - Use a common RGB LED (common cathode or anode, adjust logic as needed)
  - Connect R, G, B pins to PWM-capable pins on Arduino
*/

const int RED_PIN = 9;    // PWM pin for Red
const int GREEN_PIN = 10; // PWM pin for Green
const int BLUE_PIN = 11;  // PWM pin for Blue

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // Simulate yeast activity: slow color shifts, pulsing, and random flickers
  unsigned long t = millis();
  float phase = t / 5000.0; // Slow cycle

  // Color shifts: from blue (start) to green/yellow (active) to red (end)
  int r = (int)(128 + 127 * sin(phase + 2));
  int g = (int)(128 + 127 * sin(phase + 0));
  int b = (int)(128 + 127 * sin(phase + 4));

  // Simulate random "bubbles" (brief flashes)
  if (random(0, 1000) < 5) {
    r = 255;
    g = 255;
    b = 255;
    delay(30);
  }

  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);

  delay(30); // Smooth animation
}
