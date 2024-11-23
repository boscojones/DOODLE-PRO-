#include "unity.h"

// Função de inicialização dos testes
void setUp(void) {
    // Código para inicializar recursos, se necessário
}

// Função de finalização dos testes
void tearDown(void) {
    // Código para liberar recursos, se necessário
}

// Teste que deve passar
void test_should_pass(void) {
    TEST_ASSERT_TRUE(1); // Verifica se é verdadeiro
}

// Teste que deve falhar
void test_should_fail(void) {
    TEST_ASSERT_FALSE(1); // Este teste falhará
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_should_pass);
    RUN_TEST(test_should_fail);

    return UNITY_END();
}
