import Foundation

// Definição da classe NSCABC
class NSCABC {
    let modelName: String
    let version: String
    
    // Construtor para inicializar o modelo
    init(modelName: String, version: String) {
        self.modelName = modelName
        self.version = version
    }
    
    // Método para gerar saída baseada em uma string de entrada
    func generate(input: String) {
        let output = "Generated output based on: \(input)"
        print(output)
    }
    
    // Método para exibir o diálogo com o modelo
    func dialog() {
        print("Dialog with NSC_ABC model \(modelName) version \(version)")
    }
}

// Método principal para executar o código
func main() {
    // Inicializando o modelo NSC_ABC
    let nscModel = NSCABC(modelName: "NSC-ABC", version: "1.0")
    
    // Exibindo o diálogo
    nscModel.dialog()
    
    // Gerando saída
    nscModel.generate(input: "Teste de entrada")
}

// Executar a função principal
main()
