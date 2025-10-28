import matplotlib.pyplot as plt

# Load data
matrix_size = [500, 1000, 2000, 4000, 8000]
row_time = [0.000764178, 0.00270019, 0.0107212, 0.0449062, 0.176878]
col_time = [0.00225759, 0.00324379, 0.0213087, 0.102641, 0.285465]

# Plot results
plt.figure(figsize=(8, 5))
plt.plot(matrix_size, row_time, marker='o', label='Row Time (Efficient)')
plt.plot(matrix_size, col_time, marker='s', label='Column Time (Inefficient)')

# Add labels and title
plt.title("Time for Row vs Column")
plt.xlabel("Matrix Size (N)")
plt.ylabel("Time (seconds)")
plt.legend()
plt.grid(True)
plt.tight_layout()

# Show plot
plt.show()
