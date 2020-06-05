#include "watchdog.h"

void disableWatchdog() {
    MCUSR &= ~(1 << WDRF);
	wdt_disable();
}