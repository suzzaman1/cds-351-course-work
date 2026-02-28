#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
    // File sizes to test (in MB)
    std::vector<size_t> file_sizes_MB = {256, 512, 1024};

    // Open CSV for results
    std::ofstream csv("io_bandwidth.csv");
    csv << "file_size_MB,write_bandwidth_MBps,read_bandwidth_MBps\n";

    for (auto size_MB : file_sizes_MB) {
        size_t data_size = size_MB * 1024ULL * 1024ULL;
        std::vector<char> data(data_size, 'A');

        std::cout << "Testing file size: " << size_MB << " MB\n";

        // ---------------- Write Test ----------------
        auto start = std::chrono::high_resolution_clock::now();
        std::ofstream outFile("test.bin", std::ios::binary);
        if (!outFile) {
            std::cerr << "Error opening file for writing!\n";
            return 1;
        }
        outFile.write(data.data(), data_size);
        outFile.flush();
        outFile.close();
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> write_duration = end - start;
        double write_bandwidth = static_cast<double>(size_MB) / write_duration.count();// Compute HERE. Hint denominator s = write_duration.count()
        std::cout << "Write bandwidth: " << write_bandwidth << " MB/s\n";

        // ---------------- Read Test ----------------
        start = std::chrono::high_resolution_clock::now();
        std::ifstream inFile("test.bin", std::ios::binary);
        if (!inFile) {
            std::cerr << "Error opening file for reading!\n";
            return 1;
        }
        inFile.read(data.data(), data_size);
        inFile.close();
        end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> read_duration = end - start;
        double read_bandwidth = static_cast<double>(size_MB) / read_duration.count();// Compute HERE. Hint denominator s = read_duration.count()
        std::cout << "Read bandwidth: " << read_bandwidth << " MB/s\n\n";

        // Write to CSV HERE. Hint: it's 3 values!        
	csv << size_MB << "," << write_bandwidth << "," << read_bandwidth << "\n";

    }

    csv.close();
    std::cout << "Results saved to io_bandwidth.csv\n";
    return 0;
}
