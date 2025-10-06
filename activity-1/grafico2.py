import matplotlib.pyplot as plt

# Dados
entrada = [10, 50, 100, 500, 1000, 5000, 10000]
tempo = [0.027, 0.118, 0.259, 0.962, 2.088, 10.248, 18.781]

# Gráfico
plt.plot(entrada, tempo, marker="o", linestyle="-", color="green", label="Tempo de execução")
plt.xlabel("Entrada (n)")
plt.ylabel("Tempo (µs)")
plt.title("Busca Sequencial — pior caso")
plt.grid(True)
plt.legend()
plt.show()
