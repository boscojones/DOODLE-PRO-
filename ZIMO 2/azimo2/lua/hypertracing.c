#include <stdio.h>

void trackData(const char *data) {
    printf("Rastreamento de dados: %s\n", data);
}

int main() {
    trackData("Iniciando transmissão HoloFi.");
    return 0;
}
