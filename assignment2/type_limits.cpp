# include <iostream>
# include <limits> // For std :: numeric_limits

int main(){

// char
std::cout << "char min : " << static_cast <int>( std::numeric_limits <char>::min() ) << '\n';
std::cout << "char max : " << static_cast <int>( std::numeric_limits <char>::max() ) << "\n\n";

// short
std::cout << "short min : " << static_cast<int>(std::numeric_limits<short>::min()) << '\n';
std::cout << "short max : " << static_cast<int>(std::numeric_limits<short>::max()) << "\n\n";

// int
std::cout << "int min : " << static_cast<int>(std::numeric_limits<int>::min()) << '\n';
std::cout << "int max : " << static_cast<int>(std::numeric_limits<int>::max()) << "\n\n";

// long
std::cout << "long min : " << static_cast<int>(std::numeric_limits<long>::min()) << '\n';
std::cout << "long max : " << static_cast<int>(std::numeric_limits<long>::max()) << "\n\n";

// long long
std::cout << "long long min : " << static_cast<int>(std::numeric_limits<long long>::min()) << '\n';
std::cout << "long long max : " << static_cast<int>(std::numeric_limits<long long>::max()) << "\n\n";

// float
std::cout << "float min : " << static_cast<int>(std::numeric_limits<float>::min()) << '\n';
std::cout << "float max : " << static_cast<int>(std::numeric_limits<float>::max()) << "\n\n";

// double
std::cout << "double min : " << static_cast<int>(std::numeric_limits<double>::min()) << '\n';
std::cout << "double max : " << static_cast<int>(std::numeric_limits<double>::max()) << "\n\n";

// long double
std::cout << "long double min : " << static_cast<int>(std::numeric_limits<long double>::min()) << '\n';
std::cout << "long double max : " << static_cast<int>(std::numeric_limits<long double>::max()) << "\n\n";

// unsigned int
std::cout << "unsigned int min : " << static_cast<int>(std::numeric_limits<unsigned int>::min()) << '\n';
std::cout << "unsigned int max : " << static_cast<int>(std::numeric_limits<unsigned int>::max()) << "\n\n";

return 0;
}
