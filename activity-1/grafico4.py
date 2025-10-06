import matplotlib.pyplot as plt

# Dados
entrada = [10, 50, 100, 500, 1000, 5000, 10000]
tempo = [0.010, 0.015, 0.019, 0.024, 0.035, 0.050, 0.053]

# Gráfico
plt.plot(entrada, tempo, marker="o", linestyle="-", color="purple", label="Tempo de execução")
plt.xlabel("Entrada (n)")
plt.ylabel("Tempo (µs)")
plt.title("Busca Binária Recursiva — pior caso")
plt.grid(True)
plt.legend()
plt.show()
