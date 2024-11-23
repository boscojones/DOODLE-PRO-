import Foundation

// Estrutura para definir a tarefa de processamento (simulação de SSP - separação de dados)
struct ProcessingTask {
    var storageProvider: String
    var path: String
    var taskId: Int
}

// Função que cada thread irá executar
func processStorageTask(task: ProcessingTask) {
    print("Thread \(task.taskId): Processando dados em \(task.storageProvider) no caminho \(task.path)")
    
    // Simular uma tarefa de processamento como I/O, consulta, etc.
    sleep(2)  // Simula o tempo de processamento
    print("Thread \(task.taskId): Finalizou o processamento em \(task.storageProvider)")
}

// Função principal
func main() {
    // Definir o número de threads
    let numThreads = 4
    
    // Definir as tarefas a serem processadas
    var tasks = [ProcessingTask]()
    
    tasks.append(ProcessingTask(storageProvider: "AWS", path: "s3://my-bucket/data", taskId: 0))
    tasks.append(ProcessingTask(storageProvider: "Azure", path: "azure://my-container/data", taskId: 1))
    tasks.append(ProcessingTask(storageProvider: "Google Cloud", path: "gcs://my-bucket/data", taskId: 2))
    tasks.append(ProcessingTask(storageProvider: "Local", path: "/local/disk/path", taskId: 3))

    // Criar um DispatchQueue para processamento paralelo
    let dispatchQueue = DispatchQueue(label: "com.processing.tasks", attributes: .concurrent)
    
    // Criar threads para processar as tarefas em paralelo
    for task in tasks {
        dispatchQueue.async {
            processStorageTask(task: task)
        }
    }

    // Esperar que todas as threads finalizem o trabalho (aguardar a execução de todas as tarefas assíncronas)
    dispatchQueue.sync(flags: .barrier) {
        print("Main: Finalizou todas as threads.")
    }
}

// Executar a função principal
main()

// Aguardando a execução de tarefas assíncronas
RunLoop.main.run()
