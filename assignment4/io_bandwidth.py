import matplotlib.pyplot as plt

# Load data
x = [256, 512, 1024]
read = [7492.87, 7061.72, 7425.22]
write = [4852.83, 1323.37, 1752.95]

# Plot results
plt.figure(figsize=(8, 5))
plt.plot(x, write, marker='o', label='Write Bandwidth')
plt.plot(x, read, marker='s', label='Read Bandwidth')

# Add labels and title
plt.title("I/O Bandwidth vs File Size")
plt.xlabel("File Size (MB)")
plt.ylabel("Bandwidth (MB/s)")
plt.legend()
plt.grid(True)
plt.tight_layout()

# Show plot
plt.show()
