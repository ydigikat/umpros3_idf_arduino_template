// ----------------------------------------------------------------------------
// (c) Jason Wilden 2026.
// Template for using ESP32 UM-PROS3 with IDF + Arduino as component.
// ----------------------------------------------------------------------------

#define ARDUINO_PROS3       // Not set apparently by variant.
#include "um3.h"

UMS3 ums3;

extern "C" void app_main(void)
{
    initArduino();

    ums3.begin();

    // Brightness is 0-255. We set it to 1/3 brightness here
    ums3.setPixelBrightness(255 / 3);

    // Enable the power to the RGB LED.
    // Off by default so it doesn't use current when the LED is not required.
    ums3.setPixelPower(true);

    int color = 0;

    while (1)
    {
        // colorWheel cycles red, orange, ..., back to red at 256
        ums3.setPixelColor(UMS3::colorWheel(color));
        color++;
        delay(30);
    }
}
