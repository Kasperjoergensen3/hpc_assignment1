import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

plt.style.use("seaborn-whitegrid")

# import dat file
data_soa = pd.read_csv("soa.gcc.dat", sep="\s+")
data_aos = pd.read_csv("aos.gcc.dat", sep="\s+")
# add column names
data_soa.columns = [
    "memory",
    "Mfolps of distance",
    "Mflops of distcheck",
    "total program",
    "time",
]
data_aos.columns = [
    "memory",
    "Mfolps of distance",
    "Mflops of distcheck",
    "total program",
    "time",
]
# plot
print("Plotting...")
print(data_soa.head())

fig, ax = plt.subplots(4, 1, figsize=(8, 6), sharex=True)

for data, label in zip([data_soa, data_aos], ["soa", "aos"]):
    ax[0].plot(
        data["memory"],
        data["Mfolps of distance"],
        label=label,
        linestyle="-",
        marker="o",
    )
    ax[1].plot(
        data["memory"],
        data["Mflops of distcheck"],
        label=label,
        linestyle="-",
        marker="o",
    )
    ax[2].plot(
        data["memory"],
        data["total program"],
        label=label,
        linestyle="-",
        marker="o",
    )
    ax[3].plot(
        data["memory"],
        data["time"],
        label=label,
        linestyle="-",
        marker="o",
    )
ax[3].legend()
# add vertival lines at
for i in range(4):
    ax[i].axvline(x=768, color="r", linestyle="--")
    ax[i].axvline(x=6 * 1024, color="r", linestyle="--")
    ax[i].axvline(x=60 * 1024, color="r", linestyle="--")


ax[0].set_ylabel("Mfolps of distance")
ax[1].set_ylabel("Mflops of distcheck")
ax[2].set_ylabel("total program")
ax[3].set_ylabel("time")
ax[3].set_xlabel("memory (kB)")

# make log2 x axis
ax[0].set_xscale("log", base=2)
plt.tight_layout()

plt.savefig("plot.png", dpi=300)
