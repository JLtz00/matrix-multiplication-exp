import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../results/results_multi_thresholds_combined.csv")
df.columns = df.columns.str.strip()

n = df["n"]
standard = df["standard"]
s16 = df["strassen_16"]
s32 = df["strassen_32"]
s64 = df["strassen_64"]

plt.style.use("default")

plt.figure(figsize=(15, 7))

plt.plot(n, standard, marker="+", linewidth=2, label="Standard")
plt.plot(n, s16, marker="x", linewidth=1.5, label="Strassen (t=16)")
plt.plot(n, s32, marker="x", linewidth=1.5, label="Strassen (t=32)")
plt.plot(n, s64, marker="x", linewidth=1.5, label="Strassen (t=64)")

plt.yscale("log")
plt.xscale("linear")

plt.xticks(n, n, rotation=45)

plt.axvline(x=512, linestyle="--", linewidth=1, color="gray")

plt.title("Standard vs Strassen")
plt.xlabel("n")
plt.ylabel("Tiempo")

plt.grid(True, axis="y", linestyle="--", linewidth=0.4)

plt.legend(frameon=False)

for val in n:
    if val >= 128:
        plt.axvline(x=val, linestyle=":", linewidth=0.6, color="gray", alpha=0.5)

plt.tight_layout()
plt.savefig("grafico_comparacion_combined.png", dpi=300)
