import matplotlib.pyplot as plt

# Dados
entrada = [10, 50, 100, 500, 1000, 5000, 10000]

tempo_inversao = [0.077, 0.142, 0.285, 0.976, 2.017, 9.968, 18.372]
tempo_sequencial = [0.027, 0.118, 0.259, 0.962, 2.088, 10.248, 18.781]
tempo_binaria_iter = [0.013, 0.020, 0.025, 0.033, 0.036, 0.051, 0.052]
tempo_binaria_rec = [0.010, 0.015, 0.019, 0.024, 0.035, 0.050, 0.053]

# Gráfico comparativo
plt.plot(entrada, tempo_inversao, marker="o", linestyle="-", color="blue", label="Inversão do vetor")
plt.plot(entrada, tempo_sequencial, marker="s", linestyle="--", color="green", label="Busca Sequencial")
plt.plot(entrada, tempo_binaria_iter, marker="^", linestyle="-.", color="red", label="Busca Binária Iterativa")
plt.plot(entrada, tempo_binaria_rec, marker="d", linestyle=":", color="purple", label="Busca Binária Recursiva")

plt.xlabel("Entrada (n)")
plt.ylabel("Tempo (µs)")
plt.title("Comparação de Algoritmos — Tempo de Execução (pior caso)")
plt.grid(True)
plt.legend()
plt.show()
