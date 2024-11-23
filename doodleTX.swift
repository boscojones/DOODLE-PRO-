import UIKit
import CoreML

class InvestmentPredictor {
    
    // Função para carregar o modelo ML e fazer uma previsão
    func predictAssetPerformance(assetName: String) {
        // Carregar o modelo Core ML
        guard let model = try? AssetPerformanceModel(configuration: MLModelConfiguration()) else {
            print("Erro ao carregar o modelo Core ML")
            return
        }
        
        // Definir características do ativo (por exemplo, [ano, tipo])
        let assetFeatures: [Double]
        
        switch assetName {
        case "Ação XYZ":
            assetFeatures = [1.0, 0.0]  // Exemplo de características para Ação XYZ
        case "Fundo Imobiliário ABC":
            assetFeatures = [2.0, 1.0]  // Exemplo de características para Fundo Imobiliário ABC
        default:
            print("Ativo não reconhecido")
            return
        }
        
        // Criar um objeto para passar as características ao modelo
        guard let input = try? MLMultiArray(shape: [1, 2], dataType: .double) else {
            print("Erro ao criar o array de entrada para o modelo")
            return
        }
        
        input[0] = assetFeatures[0] as NSNumber
        input[1] = assetFeatures[1] as NSNumber
        
        // Fazer a previsão
        do {
            let prediction = try model.prediction(input: input)
            if let predictedValue = prediction.featureValue(for: "output")?.doubleValue {
                print("Retorno previsto para \(assetName): \(predictedValue)%")
            }
        } catch {
            print("Erro ao fazer a previsão: \(error.localizedDescription)")
        }
    }
}

// Exemplo de uso:
let predictor = InvestmentPredictor()
predictor.predictAssetPerformance(assetName: "Ação XYZ")
