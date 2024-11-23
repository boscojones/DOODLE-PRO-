#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_DATA_LENGTH 100

const char *validUser = "admin";
const char *validPassword = "password123";

// Função para inicializar a transmissão WPS-B
void initializeWPSB() {
    printf("Transmissão WPS-B inicializada.\n");
}

// Função para transmitir dados
void transmitData(const char *data) {
    printf("Transmitindo dados via WPS-B: %s\n", data);
}

// Função para transmitir dados com Two-PiX Key
void transmitDataWithTwoPix(const char *data) {
    printf("Transmitindo com Two-PiX Key: %s\n", data);
}

// Função para autenticar usuário
int authenticateUser(const char *username, const char *password) {
    return strcmp(username, validUser) == 0 && strcmp(password, validPassword) == 0;
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char dataToTransmit[MAX_DATA_LENGTH] = "Hello, HoloNet 7G!";

    initializeWPSB();

    // Solicita os dados do usuário
    printf("Digite o nome de usuário: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;  // Remove a nova linha

    printf("Digite a senha: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;  // Remove a nova linha

    // Autentica o usuário
    if (authenticateUser(username, password)) {
        printf("Autenticação bem-sucedida!\n");

        // Transmitir dados usando WPS-B
        transmitData(dataToTransmit);

        // Transmitir dados usando Two-PiX Key
        transmitDataWithTwoPix(dataToTransmit);
    } else {
        printf("Falha na autenticação. Verifique seu nome de usuário e senha.\n");
    }

    return 0;
}
