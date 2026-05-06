import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../results/results_multi_thresholds4.csv")
df.columns = df.columns.str.strip()

n = df["n"]
standard = df["standard"]

ratio_16 = standard / df["strassen_16"]
ratio_32 = standard / df["strassen_32"]
ratio_64 = standard / df["strassen_64"]

plt.style.use("seaborn-v0_8-whitegrid")
plt.figure(figsize=(10, 6))

plt.plot(n, ratio_16, marker="o", label="t=16")
plt.plot(n, ratio_32, marker="o", label="t=32")
plt.plot(n, ratio_64, marker="o", label="t=64")

plt.axhline(
    y=1, linestyle="--", linewidth=1.5, color="black", label="igual rendimiento"
)

plt.xscale("log")
plt.xticks(n, n)

plt.title("Ratio Standard / Strassen (Speedup)")
plt.xlabel("Tamaño de matriz (n)")
plt.ylabel("Ratio (>1 → Strassen mejor)")
plt.legend()
plt.grid(True, linestyle="--", linewidth=0.5)

plt.tight_layout()
plt.savefig("grafico_ratio.png", dpi=300)
