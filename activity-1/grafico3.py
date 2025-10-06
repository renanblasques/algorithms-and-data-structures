import matplotlib.pyplot as plt

# Dados
entrada = [10, 50, 100, 500, 1000, 5000, 10000]
tempo = [0.013, 0.020, 0.025, 0.033, 0.036, 0.051, 0.052]

# Gráfico
plt.plot(entrada, tempo, marker="o", linestyle="-", color="red", label="Tempo de execução")
plt.xlabel("Entrada (n)")
plt.ylabel("Tempo (µs)")
plt.title("Busca Binária Iterativa — pior caso")
plt.grid(True)
plt.legend()
plt.show()
