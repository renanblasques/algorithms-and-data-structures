import matplotlib.pyplot as plt

# Dados
entrada = [10, 50, 100, 500, 1000, 5000, 10000]
tempo = [0.077, 0.142, 0.285, 0.976, 2.017, 9.968, 18.372]

# Gráfico
plt.plot(entrada, tempo, marker="o", linestyle="-", color="blue", label="Tempo de execução")
plt.xlabel("Entrada (n)")
plt.ylabel("Tempo (µs)")
plt.title("Inversão da ordem do vetor de entrada")
plt.grid(True)
plt.legend()
plt.show()
