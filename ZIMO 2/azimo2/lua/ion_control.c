#include <stdio.h>

void startEngine() {
    printf("Motor de íons iniciado.\n");
}

void setThrust(int value) {
    printf("Empuxo definido para: %dN\n", value);
}

int main() {
    startEngine();
    setThrust(10); // exemplo de empuxo
    return 0;
}
