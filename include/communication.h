#pragma once

#include <inttypes.h>
#include <stdbool.h>

#include <avr/io.h>

#include <LUFA/Drivers/Peripheral/Serial.h>

FILE gl_USARTStream;

void setupCommunication();