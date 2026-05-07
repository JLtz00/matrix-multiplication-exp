import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../results/results_multi_thresholds_padding.csv")
df.columns = df.columns.str.strip()

n = df["n"]

standard = df["standard"]

ratio_16 = standard / df["strassen_padding_16"]
ratio_32 = standard / df["strassen_padding_32"]
ratio_64 = standard / df["strassen_padding_64"]

plt.style.use("default")
plt.figure(figsize=(16, 5))

plt.plot(n, ratio_16, marker="o", linewidth=1.8, label="t = 16")

plt.plot(n, ratio_32, marker="o", linewidth=1.8, label="t = 32")

plt.plot(n, ratio_64, marker="o", linewidth=1.8, label="t = 64")

plt.axhline(
    y=1, linestyle="--", linewidth=1.2, color="black", label="igual rendimiento"
)

for val in n:
    if val >= 128:
        plt.axvline(x=val, linestyle=":", linewidth=0.6, color="gray", alpha=0.5)

plt.xscale("log")
plt.xticks(n, n, rotation=45)

plt.title("Ratio Standard / Strassen con Padding")
plt.xlabel("n")
plt.ylabel("Ratio (>1 → Strassen mejor)")

plt.grid(True, axis="y", linestyle="--", linewidth=0.5)

plt.legend(frameon=False)
plt.savefig("grafico_padding_ratio.png", dpi=300)
