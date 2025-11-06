import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Read csv data
df = pd.read_csv("thread_pi_results.csv")
t1 = df.loc[df["threads"] == 1, "time_seconds"].values[0]

# Compute measured speedup
df["measured_speedup"] = t1 / df["time_seconds"]

# Compute theoretical Amdahl curve
P = 0.95
threads = np.array(df["threads"])
theoretical = 1.0 / ((1 - P) + P / threads)

fig, ax = plt.subplots()
ax.plot(threads, df["measured_speedup"], "o-", label="Measured Speedup")
ax.plot(threads, theoretical, "s--", label=f"Theoretical (P={P})")

ax.set_title("Amdahl's Law Demonstration")
ax.set_xlabel("Number of threads")
ax.set_ylabel("Speedup (T1 / TN)")
ax.set_xticks(threads)
ax.grid(True, linestyle="--", alpha=0.6)
ax.legend()
plt.tight_layout()
#plt.show()

# Save to a file
plt.savefig("amdahl.png")
