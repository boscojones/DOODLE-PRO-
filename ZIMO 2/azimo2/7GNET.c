#include <stdio.h>
#include <string.h>

#define VALID_USER "admin"
#define VALID_PASSWORD "password123"

// Função para autenticar o usuário
int authenticateUser(const char *username, const char *password) {
    return strcmp(username, VALID_USER) == 0 && strcmp(password, VALID_PASSWORD) == 0;
}

// Função para inicializar a transmissão WPS-B
void initializeWPSB() {
    printf("Transmissão WPS-B inicializada.\n");
}

// Função para transmitir dados via WPS-B
void transmitData(const char *data) {
    printf("Transmitindo dados via WPS-B: %s\n", data);
}

// Função para transmitir dados utilizando Two-PiX Key
void transmitDataWithTwoPix(const char *data) {
    printf("Transmitindo com Two-PiX Key: %s\n", data);
}

// Função principal
int main() {
    // Inicialização do sistema
    initializeWPSB();

    // Dados do usuário para autenticação
    char username[50];
    char password[50];

    printf("Digite o nome de usuário: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;  // Remove a nova linha

    printf("Digite a senha: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;  // Remove a nova linha

    // Autenticar o usuário
    if (authenticateUser(username, password)) {
        printf("Autenticação bem-sucedida!\n");

        // Dados a serem transmitidos
        const char *dataToTransmit = "Hello, HoloNet 7G!";
        
        // Transmitir dados usando WPS-B
        transmitData(dataToTransmit);
        
        // Transmitir dados usando Two-PiX Key
        transmitDataWithTwoPix(dataToTransmit);
    } else {
        printf("Falha na autenticação. Verifique seu nome de usuário e senha.\n");
    }

    return 0;
}
