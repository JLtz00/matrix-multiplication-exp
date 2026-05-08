import pandas as pd
import matplotlib.pyplot as plt

df_o0 = pd.read_csv("../results/results_multi_thresholds_O0.csv")
df_o3 = pd.read_csv("../results/results_multi_thresholds_O3.csv")

df_o0.columns = df_o0.columns.str.strip()
df_o3.columns = df_o3.columns.str.strip()

n = df_o0["n"]

standard_o0 = df_o0["standard"]
strassen_o0 = df_o0["strassen_64"]

standard_o3 = df_o3["standard"]
strassen_o3 = df_o3["strassen_64"]

plt.style.use("default")
plt.figure(figsize=(16, 5))

plt.plot(
    n, standard_o0, marker="+", linewidth=2, linestyle="--", label="Standard (-O0)"
)

plt.plot(n, standard_o3, marker="+", linewidth=2, label="Standard (-O3)")

plt.plot(
    n, strassen_o0, marker="x", linewidth=2, linestyle="--", label="Strassen64 (-O0)"
)

plt.plot(n, strassen_o3, marker="x", linewidth=2, label="Strassen64 (-O3)")

plt.xscale("log")
plt.yscale("linear")

plt.xticks(n, n)

for val in n:
    if val >= 128:
        plt.axvline(x=val, linestyle=":", linewidth=0.6, color="gray", alpha=0.5)

plt.title("Impacto de las optimizaciones del compilador")
plt.xlabel("n")
plt.ylabel("Tiempo de ejecución")

plt.grid(True, axis="y", linestyle="--", linewidth=0.5)

plt.legend(frameon=False)

plt.tight_layout()
plt.savefig("grafico_optimizaciones.png", dpi=300)
