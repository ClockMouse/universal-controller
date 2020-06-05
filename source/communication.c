#include "communication.h"

void setupCommunication() {
    Serial_Init(9600, false);
    Serial_CreateStream(&gl_USARTStream);
}
