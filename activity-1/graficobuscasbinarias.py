import matplotlib.pyplot as plt

# Dados
entrada = [10, 50, 100, 500, 1000, 5000, 10000]

tempo_binaria_iter = [0.013, 0.020, 0.025, 0.033, 0.036, 0.051, 0.052]
tempo_binaria_rec = [0.010, 0.015, 0.019, 0.024, 0.035, 0.050, 0.053]

# Gráfico comparativo
plt.plot(entrada, tempo_binaria_iter, marker="^", linestyle="-.", color="red", label="Busca Binária Iterativa")
plt.plot(entrada, tempo_binaria_rec, marker="d", linestyle=":", color="purple", label="Busca Binária Recursiva")

plt.xlabel("Entrada (n)")
plt.ylabel("Tempo (µs)")
plt.title("Comparação — Busca Binária Iterativa vs Recursiva (pior caso)")
plt.grid(True)
plt.legend()
plt.show()
