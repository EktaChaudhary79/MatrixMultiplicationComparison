import matplotlib.pyplot as plt

# Matrix sizes
n = [64, 128, 256, 512, 1024]

# Corresponding runtimes (seconds)
traditional_runtime = [0.002, 0.015, 0.120, 1.0, 8.5]
strassen_runtime    = [0.003, 0.012, 0.095, 0.80, 6.8]

plt.figure(figsize=(8,6))

# Plotting
plt.plot(n, traditional_runtime, marker='o', label="Traditional O(n³)")
plt.plot(n, strassen_runtime, marker='s', label="Strassen O(n^2.81)")

# Labels and title
plt.xlabel("Matrix Size (n)")
plt.ylabel("Runtime (seconds)")
plt.title("Runtime Comparison: Traditional vs Strassen Multiplication")
plt.xticks(n)
plt.grid(True)
plt.legend()

# Show plot
plt.show()
