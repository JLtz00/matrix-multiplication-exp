import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../results/results_multi_thresholds_padding.csv")
df.columns = df.columns.str.strip()

n = df["n"]

standard = df["standard"]
s16 = df["strassen_padding_16"]
s32 = df["strassen_padding_32"]
s64 = df["strassen_padding_64"]

plt.style.use("default")
plt.figure(figsize=(16, 5))

plt.plot(n, standard, marker="+", linewidth=2, label="Standard")

plt.plot(n, s16, marker="x", linewidth=1.5, label="Strassen Padding (t=16)")

plt.plot(n, s32, marker="x", linewidth=1.5, label="Strassen Padding (t=32)")

plt.plot(n, s64, marker="x", linewidth=1.5, label="Strassen Padding (t=64)")

plt.xscale("log")
plt.yscale("log")

plt.xticks(n, n, rotation=45)

for val in n:
    if val >= 128:
        plt.axvline(x=val, linestyle=":", linewidth=0.6, color="gray", alpha=0.5)

plt.axvline(x=1024, linestyle="--", linewidth=1.2, color="black")

plt.title("Standard vs Strassen con Padding")
plt.xlabel("n")
plt.ylabel("Tiempo de ejecución")

plt.grid(True, axis="y", linestyle="--", linewidth=0.5)

plt.legend(frameon=False)

plt.tight_layout()
plt.savefig("grafico_padding_comparison.png", dpi=300)
