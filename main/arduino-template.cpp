// ----------------------------------------------------------------------------
// (c) Jason Wilden 2026.
// Template for using ESP32 UM-PROS3 with IDF + Arduino as component.
// ----------------------------------------------------------------------------

/* 
* Need to tell the UM3 helper which board we're using, setting the um_pros3 
* variant in config doesn't seem to do this.
*/
#ifndef ARDUINO_PROS3
#define ARDUINO_PROS3
#endif

#include <stdint.h>

#include "esp_log.h"
#include "um3.h"

static const char *TAG="arduino-template";
static void do_arduino_colour_wheel(void);

/*
* ESP-IDF code.
*/
extern "C" void app_main(void)
{
    ESP_LOGI(TAG,"ESP32 Arduino as Component template running.");

    do_arduino_colour_wheel();
    
    /* NOTREACHED*/
}


/*
* Arduino code in here.  This code blocks (superloop).
*/
void do_arduino_colour_wheel(void)
{
    UMS3 ums3;

    initArduino();

    Serial.begin(115200);
    Serial.println("ESP32 Arduino as Component template running.");    

    ums3.begin();
    ums3.setPixelBrightness(255 / 3);    
    ums3.setPixelPower(true);

    uint color = 0;

    while (1)
    {        
        ums3.setPixelColor(UMS3::colorWheel(color));
        color++;    
        delay(30);
    }

    /*NOTREACHED*/
}
