#include <fstream>
#include <iostream>
#include <vector>

std::vector<double> temper_read(std::string file);
double maximum(std::vector<double> temp);
double average(std::vector<double> temp);

int main(){

	std::ifstream in_file("temperatures.txt");

	if (!in_file){

		std::cerr << "Error: sample.txt could not be opened for reading!\n";
		return 1;

	}
	std::vector<double> temperatures = temper_read("temperatures.txt");

	std::cout << "Number of Data Values: " << temperatures.size() << std::endl;
	std::cout << "Maximum Value: " << maximum(temperatures) << std::endl;
	std::cout << "Average: " << average(temperatures) << std::endl;

	return 0;
}

std::vector<double> temper_read(std::string file){

	double test_line;
	std::ifstream in_file(file);
        std::vector<double> temperatures;

        while (in_file >> test_line){
                temperatures.push_back(test_line);
        }

	return temperatures;
}

double maximum(std::vector<double> temp){

	double maxim = 0;

	for (auto a : temp){
		if(a > maxim){
			maxim = a;
		}
	}
	return maxim;
}

double average(std::vector<double> temp){

        double average = 0;
	int i = 1;

	for (auto a : temp){
		average = average + (a - average)/i;
	}

	return average;
}
