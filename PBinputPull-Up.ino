// Define pin numbers
const int buttonPin = 2;   // Pin connected to the push button
const int redPin = 9;      // Pin connected to the red component of the RGB LED
const int greenPin = 10;   // Pin connected to the green component of the RGB LED
const int bluePin = 11;    // Pin connected to the blue component of the RGB LED

// Variables to hold button state and color index
int buttonState = 0;       // Current state of the button
int lastButtonState = 0;   // Previous state of the button
int colorIndex = 0;        // Index for the current color

// Array to hold RGB color values
int colors[7][3] = {
  {255, 0, 0},    // Red
  {0, 255, 0},    // Green
  {0, 0, 255},    // Blue
  {255, 255, 0},  // Yellow
  {0, 255, 255},  // Cyan
  {255, 0, 255},  // Magenta
  {255, 255, 255} // White
};

void setup() {
  // Initialize the button pin as an input
  pinMode(buttonPin, INPUT);
  
  // Initialize the RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Start with the RGB LED off
  setColor(0, 0, 0);
}

void loop() {
  // Read the state of the push button
  buttonState = digitalRead(buttonPin);

  // Check if the button was pressed (detecting a change from LOW to HIGH)
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Change color when the button is pressed
    colorIndex = (colorIndex + 1) % 7; // Cycle through the 7 colors
    changeColor(colorIndex); // Change the RGB LED color
  }

  // Update the last button state for the next loop iteration
  lastButtonState = buttonState;

  // Small delay to debounce the button
  delay(50); // 50 ms delay to prevent false triggers
}

// Function to change the color of the RGB LED based on the color index
void changeColor(int index) {
  setColor(colors[index][0], colors[index][1], colors[index][2]); // Set the RGB LED color
}

// Function to set the RGB LED color using PWM
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);   // Set the red component of the RGB LED
  analogWrite(greenPin, green); // Set the green component of the RGB LED
  analogWrite(bluePin, blue);  // Set the blue component of the RGB LED
}