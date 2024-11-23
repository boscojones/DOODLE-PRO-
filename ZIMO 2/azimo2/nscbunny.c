#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_TOKEN_LENGTH 8192

typedef struct {
    char generation[MAX_TOKEN_LENGTH];
    char **tokens;
    float *logprobs;
} CompletionPrediction;

typedef struct {
    char *username;
    char *password;
    char *pixKey; // Chave Pix (ex: 16 caracteres)
} User;

typedef struct {
    User *users[MAX_USERS];
    int userCount;
} UserManager;

// Funções de gerenciamento de usuários
UserManager *createUserManager() {
    UserManager *manager = (UserManager *)malloc(sizeof(UserManager));
    manager->userCount = 0;
    return manager;
}

int addUser(UserManager *manager, const char *username, const char *password, const char *pixKey) {
    if (manager->userCount >= MAX_USERS) {
        printf("Limite de usuários atingido!\n");
        return 0; // Falha
    }
    User *newUser = (User *)malloc(sizeof(User));
    newUser->username = strdup(username);
    newUser->password = strdup(password);
    newUser->pixKey = strdup(pixKey);
    manager->users[manager->userCount++] = newUser;
    return 1; // Sucesso
}

int authenticateUser(UserManager *manager, const char *username, const char *password, const char *pixKey) {
    for (int i = 0; i < manager->userCount; i++) {
        if (strcmp(manager->users[i]->username, username) == 0 &&
            strcmp(manager->users[i]->password, password) == 0 &&
            strcmp(manager->users[i]->pixKey, pixKey) == 0) {
            return 1; // Sucesso
        }
    }
    return 0; // Falha
}

void printUsers(UserManager *manager) {
    printf("Usuários cadastrados:\n");
    for (int i = 0; i < manager->userCount; i++) {
        printf("Username: %s, Pix Key: %s\n", manager->users[i]->username, manager->users[i]->pixKey);
    }
}

void freeUserManager(UserManager *manager) {
    for (int i = 0; i < manager->userCount; i++) {
        free(manager->users[i]->username);
        free(manager->users[i]->password);
        free(manager->users[i]->pixKey);
        free(manager->users[i]);
    }
    free(manager);
}

int main() {
    UserManager *manager = createUserManager();

    // Adiciona alguns usuários de exemplo
    addUser(manager, "user1", "password1", "key1234567890123");
    addUser(manager, "user2", "password2", "key9876543210123");

    // Testa autenticação
    if (authenticateUser(manager, "user1", "password1", "key1234567890123")) {
        printf("Autenticação bem-sucedida para user1!\n");
    } else {
        printf("Falha na autenticação para user1.\n");
    }

    // Lista todos os usuários
    printUsers(manager);

    // Libera memória
    freeUserManager(manager);
    return 0;
}
