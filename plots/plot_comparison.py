import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../results/results_multi_thresholds4.csv")
df.columns = df.columns.str.strip()

n = df["n"]
standard = df["standard"]
s16 = df["strassen_16"]
s32 = df["strassen_32"]
s64 = df["strassen_64"]

plt.style.use("seaborn-v0_8-whitegrid")
plt.figure(figsize=(10, 6))

plt.plot(n, standard, marker="+", linewidth=2, label="Standard")
plt.plot(n, s16, marker="x", linewidth=1.8, label="Strassen (t=16)")
plt.plot(n, s32, marker="x", linewidth=1.8, label="Strassen (t=32)")
plt.plot(n, s64, marker="x", linewidth=1.8, label="Strassen (t=64)")

plt.yscale("log")
plt.xscale("linear")

plt.xticks(n, n)

plt.axvline(x=512, linestyle="--", linewidth=1.2, label="n₀ ≈ 512")

plt.title("Comparación de tiempos: Standard vs Strassen")
plt.xlabel("Tamaño de matriz (n)")
plt.ylabel("Tiempo de ejecución")
plt.legend()
plt.grid(True, linestyle="--", linewidth=0.5)

plt.tight_layout()
plt.savefig("grafico_comparacion.png", dpi=300)
