import pandas as pd
import matplotlib.pyplot as plt

# =========================
# CARGAR CSVs
# =========================

df_o0 = pd.read_csv("../results/results_multi_thresholds_O0.csv")
df_o3 = pd.read_csv("../results/results_multi_thresholds_O3.csv")

df_o0.columns = df_o0.columns.str.strip()
df_o3.columns = df_o3.columns.str.strip()

n = df_o0["n"]

speedup_standard = df_o0["standard"] / df_o3["standard"]

speedup_16 = df_o0["strassen_16"] / df_o3["strassen_16"]

speedup_32 = df_o0["strassen_32"] / df_o3["strassen_32"]

speedup_64 = df_o0["strassen_64"] / df_o3["strassen_64"]

plt.style.use("default")
plt.figure(figsize=(16, 6))

plt.plot(n, speedup_standard, marker="+", linewidth=2.5, label="Standard")

plt.plot(n, speedup_16, marker="x", linewidth=2, label="Strassen (t=16)")

plt.plot(n, speedup_32, marker="x", linewidth=2, label="Strassen (t=32)")

plt.plot(n, speedup_64, marker="x", linewidth=2, label="Strassen (t=64)")

plt.xscale("log")
plt.xticks(n, n)

plt.grid(True, axis="y", linestyle="--", linewidth=0.5)

for val in n:
    if val >= 64:
        plt.axvline(x=val, linestyle=":", linewidth=0.6, color="gray", alpha=0.4)


plt.title("Factor de aceleración usando optimizaciones del compilador")
plt.xlabel("n")
plt.ylabel("Speedup (O0 / O3)")

plt.axhline(y=1, linestyle="--", linewidth=1, color="black")

plt.legend(frameon=False)

plt.tight_layout()
plt.savefig("grafico_speedup_optimization.png", dpi=300)
