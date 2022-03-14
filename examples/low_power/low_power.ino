#include <mcp9808.h>

#define SerialDebug Serial3 // Add this to print via Serial

int err = 0;

void setup(void) {
    /* Initialize serial interface */
    SerialDebug.begin(115200);

    /* Initialize MCP9808 library */
    err = mcp9808.begin();    
    if (err < 0) {
        SerialDebug.println("Error: could not start MCP9808 library");
    }
}

void loop(void) {
    SerialDebug.println("I'm awake");

    /* Shut down MCP9808 (set in low power mode) */
    err = mcp9808.shutdown();
    if (err < 0) {
        SerialDebug.println("Error: could not shutdown MCP9808");
    }

    SerialDebug.println("Sleeping zzzzZZZZZ");
    delay(500);

    /* Wake up MCP9808 */
    err = mcp9808.wake();
    if (err < 0) {
        SerialDebug.println("Error: could not wake MCP9808");
    }
}