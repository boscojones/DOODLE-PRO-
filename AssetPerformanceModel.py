import coremltools
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
import numpy as np

# Construir e treinar o modelo no TensorFlow (como mostrado anteriormente)
model = Sequential([
    Dense(10, input_dim=2, activation='relu'),
    Dense(1)  # Saída para o retorno anual
])

model.compile(loss='mse', optimizer='adam')

# Dados fictícios
X = np.array([
    [1, 0],  # Ação XYZ
    [2, 1],  # Fundo Imobiliário ABC
])

y = np.array([12.0, 8.0])

model.fit(X, y, epochs=200, verbose=0)

# Converter para o formato Core ML
coreml_model = coremltools.convert(model)
coreml_model.save('AssetPerformanceModel.mlmodel')
