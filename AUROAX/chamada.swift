import Foundation

// Definir o tipo de função da biblioteca em Assembly
typealias AssemblyFunc = @convention(c) (Int32) -> Int32

// Função principal
func main() {
    // Carregar a biblioteca compilada em Assembly (ajuste o caminho conforme necessário)
    let dylibPath: String
    #if os(macOS) || os(iOS) || os(tvOS) || os(watchOS)
    dylibPath = "/path/to/libassembly.dylib" // Caminho para a biblioteca no macOS
    #elseif os(Linux)
    dylibPath = "/path/to/libassembly.so" // Caminho para a biblioteca no Linux
    #elseif os(Windows)
    dylibPath = "C:\\path\\to\\libassembly.dll" // Caminho para a biblioteca no Windows
    #else
    fatalError("Sistema operacional não suportado")
    #endif
    
    // Tentar carregar a biblioteca
    guard let dylib = dlopen(dylibPath, RTLD_LAZY) else {
        print("Erro ao carregar a biblioteca: \(String(cString: dlerror()))")
        return
    }
    
    // Obter a referência para a função Assembly
    let assemblyFunction: AssemblyFunc = unsafeBitCast(dlsym(dylib, "assembly_function"), to: AssemblyFunc.self)
    
    // Chamar a função Assembly com o valor desejado
    let result = assemblyFunction(10) // Exemplo de entrada
    print("Resultado da função Assembly: \(result)")
    
    // Fechar a biblioteca
    dlclose(dylib)
}

// Chamar a função principal
main()
