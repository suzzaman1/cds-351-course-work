#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <cmath>

// Function that each thread will execute
void partial_sum(long start, long end, double& result) {
    double local_sum = 0.0;
    double factor = (start % 2 == 0) ? 1.0 : -1.0;

    for (long i = start; i < end; ++i) {
        local_sum += factor / (2.0 * i + 1.0);
        factor = -factor; // alternate sign
    }
    result = local_sum;
}

int main(int argc, char* argv[]) {
    // EDIT HERE BEFORE COMPILING:
    long n = 1e9;             // 1e9 iterations
    // EDIT HERE BEFORE COMPILING:
    int num_threads = 16;   // set number of threads here [1,2,4,8, 16]

    if (argc == 3) {
        n = std::stol(argv[1]);
        num_threads = std::stoi(argv[2]);
    }

    std::cout << "Computing pi using " << num_threads
              << " threads and n = " << n << " terms...\n";

    // Define vector of threads here:
    std::vector<std::thread> threads(num_threads);
    // This will hold the result in each thread
    std::vector<double> partial_results(num_threads, 0.0);

    auto start_time = std::chrono::high_resolution_clock::now();

    long chunk = n / num_threads;
    for (int t = 0; t < num_threads; ++t) {
        long start = t * chunk;
        long end = (t == num_threads - 1) ? n : start + chunk;
        // fork threads here
        threads[t] = std::thread(partial_sum, start, end, std::ref(partial_results[t]));
    }

    for (auto& t : threads)
        t.join();

    double sum = 0.0;
    // COMPUTE SUM HERE (hint use partial_results):
    for (auto part : partial_results) {
	sum += part;
    }

    // Compute final result
    double pi_est = 4.0 * sum;

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "Estimated pi = " << pi_est << "\n";
    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
}
