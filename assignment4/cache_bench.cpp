#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
   std::vector<size_t> matrix_sizes = {500, 1000, 2000, 4000, 8000};// Add sizes HERE
    std::ofstream csv("cache_benchmark.csv");
    csv << "matrix_size,row_time,col_time\n";

    for (auto N : matrix_sizes) {
        std::vector<std::vector<double>> b(N, std::vector<double>(N, 1.0));
        std::vector<double> column_sum(N, 0.0);

        // Column-wise benchmark
        auto start = std::chrono::high_resolution_clock::now();
        for (size_t j = 0; j < N; ++j) {
            column_sum[j] = 0.0;
            // Add loop co compute colum_sum here:
	    for (size_t i = 0; i < N; ++i)
	    {
	    	column_sum[j] += b[i][j];
	    }
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_col = end - start;

        // Row-wise benchmark
        std::fill(column_sum.begin(), column_sum.end(), 0.0);
        start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < N; ++i) {
            // Add loop co compute colum_sum here:
	    for (size_t j = 0; j < N; ++j)
	    {
		column_sum[j] += b[i][j];
	    }
        }
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_row = end - start;

        // Write results to CSV HERE
	csv << N << "," << elapsed_row.count() << "," << elapsed_col.count() << "\n";

        std::cout << "Matrix size: " << N
                  << " Row-wise: " << elapsed_row.count()
                  << " s, Column-wise: " << elapsed_col.count() << " s\n";
    }

    csv.close();
    return 0;
}
