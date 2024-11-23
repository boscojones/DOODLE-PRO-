import Foundation

// Parâmetros da rede
let NUM_INPUT = 10   // Número de entradas
let NUM_HIDDEN = 20  // Número de neurônios na camada oculta
let NUM_OUTPUT = 3   // Número de saídas para multi-label
let MAX_EPOCHS = 1000
let LEARNING_RATE = 0.01

// Funções de ativação
func sigmoid(_ x: [Double]) -> [Double] {
    return x.map { 1 / (1 + exp(-$0)) }
}

func sigmoid_derivative(_ x: [Double]) -> [Double] {
    return x.map { $0 * (1 - $0) }
}

// Inicializa a rede neural com pesos aleatórios
func initializeNetwork() -> ([Double], [Double]) {
    let weightsInputHidden = (0..<NUM_INPUT * NUM_HIDDEN).map { _ in Double.random(in: -1...1) }
    let weightsHiddenOutput = (0..<NUM_HIDDEN * NUM_OUTPUT).map { _ in Double.random(in: -1...1) }
    return (weightsInputHidden, weightsHiddenOutput)
}

// Feedforward
func feedforward(inputData: [Double], weightsInputHidden: [Double], weightsHiddenOutput: [Double]) -> ([Double], [Double]) {
    var hiddenLayer = [Double](repeating: 0.0, count: NUM_HIDDEN)
    var outputLayer = [Double](repeating: 0.0, count: NUM_OUTPUT)

    // Calcula a camada oculta
    for i in 0..<NUM_HIDDEN {
        hiddenLayer[i] = sigmoid([Double](weightsInputHidden[i*NUM_INPUT..<(i+1)*NUM_INPUT]).reduce(0, +))[0]
    }

    // Calcula a camada de saída
    for i in 0..<NUM_OUTPUT {
        outputLayer[i] = sigmoid([Double](weightsHiddenOutput[i*NUM_HIDDEN..<(i+1)*NUM_HIDDEN]).reduce(0, +))[0]
    }

    return (hiddenLayer, outputLayer)
}

// Treinamento da rede neural
func train(inputData: [[Double]], outputData: [[Double]]) -> ([Double], [Double]) {
    var (weightsInputHidden, weightsHiddenOutput) = initializeNetwork()
    
    for epoch in 0..<MAX_EPOCHS {
        for i in 0..<inputData.count {
            let (hiddenLayer, outputLayer) = feedforward(inputData: inputData[i], weightsInputHidden: weightsInputHidden, weightsHiddenOutput: weightsHiddenOutput)

            // Backpropagation
            let error = zip(outputData[i], outputLayer).map { $0 - $1 }
            let outputDelta = zip(error, sigmoid_derivative(outputLayer)).map { $0 * $1 }
            
            // Atualizando os pesos
            for i in 0..<NUM_HIDDEN {
                for j in 0..<NUM_OUTPUT {
                    weightsHiddenOutput[i*NUM_OUTPUT+j] += LEARNING_RATE * hiddenLayer[i] * outputDelta[j]
                }
            }

            let hiddenDelta = zip(outputDelta, weightsHiddenOutput).map { $0 * $1 }.enumerated().map { $0.element * sigmoid_derivative(hiddenLayer[$0.offset]) }
            for i in 0..<NUM_INPUT {
                for j in 0..<NUM_HIDDEN {
                    weightsInputHidden[i*NUM_HIDDEN+j] += LEARNING_RATE * inputData[i][i] * hiddenDelta[j]
                }
            }
        }
    }
    return (weightsInputHidden, weightsHiddenOutput)
}

// Dados fictícios de treinamento para multi-label
let inputData: [[Double]] = [
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 1, 0, 0, 0, 0, 0, 0, 0, 0]
]

let outputData: [[Double]] = [
    [1, 0, 1],
    [0, 1, 0],
    [1, 1, 0]
]

// Treinando a rede neural
let (weightsInputHidden, weightsHiddenOutput) = train(inputData: inputData, outputData: outputData)

// Previsão de um novo dado
let newInput: [Double] = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]
let (_, outputLayer) = feedforward(inputData: newInput, weightsInputHidden: weightsInputHidden, weightsHiddenOutput: weightsHiddenOutput)
print("Previsão: \(outputLayer)")
import CoreML
import Vision
import UIKit

// Carregar o modelo CoreML treinado (modelo MNIST convertido)
guard let model = try? VNCoreMLModel(for: MNISTModel().model) else {
    fatalError("Erro ao carregar o modelo CoreML")
}

// Carregar uma imagem de entrada (por exemplo, a imagem MNIST que você deseja testar)
guard let image = UIImage(named: "digit.png") else {
    fatalError("Erro ao carregar a imagem")
}

guard let ciImage = CIImage(image: image) else {
    fatalError("Erro ao converter imagem para CIImage")
}

// Configurar a requisição do modelo
let request = VNCoreMLRequest(model: model) { request, error in
    guard let results = request.results as? [VNClassificationObservation],
          let topResult = results.first else {
        fatalError("Erro na classificação da imagem")
    }
    print("Previsão: \(topResult.identifier) com confiança \(topResult.confidence)")
}

// Executar a requisição do modelo
let handler = VNImageRequestHandler(ciImage: ciImage, options: [:])
try? handler.perform([request])
