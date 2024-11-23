import Foundation

// MARK: - Main Active Function
func main() {
    print("Bem-vindo ao Doodle Pro com integração Sea Learning!")
    print("Digite um valor inteiro para realizar operações:")
    
    // Recebe a entrada do usuário
    guard let input = readLine(), let inputValue = Int(input) else {
        print("Entrada inválida. Encerrando o programa.")
        return
    }
    
    // Processa o valor com a operação (dobrar o valor)
    let result = processInput(inputValue)
    
    // Exibe o resultado
    print("O resultado da operação (dobrar) é: \(result)")
    
    // Integração com Doodle Pro ou IA
    activateDoodlePro(result: result)
}

// MARK: - Processamento da Entrada
func processInput(_ value: Int) -> Int {
    // Operação simples: dobrar o valor
    return value * 2
}

// MARK: - Integração com Doodle Pro
func activateDoodlePro(result: Int) {
    // Exemplo: Simula integração futura com uma engine IA
    print("Processando com Doodle Pro...")
    
    // Aqui você pode integrar lógica adicional com IA
    // Exemplo: Uma chamada a modelos de Deep Learning
    
    print("Resultado processado e pronto para uso: \(result)")
    
    // Exibição visual (mockup)
    print("🎨 Renderizando resultados no layout do Doodle Pro...")
    print("🚀 O sistema está ativo e pronto para novas interações!")
}

// MARK: - Início do Programa
main()
