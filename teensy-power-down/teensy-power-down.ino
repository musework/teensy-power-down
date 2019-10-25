/* Makes a WinPC power-down button with Teensy
 *  
 *  NOTE! MUST BE IN "USB-KEYBOARD" mode in the arduino IDE
 */

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 10);

// 10ms bounce time, increase if button is too sensitive

void setup()
{
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.
  pinMode(0, INPUT_PULLUP);
}

void loop() 
{
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
 
  // Check each button for "falling" edge.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (button0.fallingEdge()) 
  {
    Keyboard.press(KEY_SYSTEM_POWER_DOWN);
    Keyboard.release(KEY_SYSTEM_POWER_DOWN);
  }
}
