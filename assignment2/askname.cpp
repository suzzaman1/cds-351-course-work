# include <iostream>

int main(){

//Initializing Variables
std::string first_name;
std::string last_name;
std::string full_name;
std::string replace_vowels(std::string line);

//Asking for first and last name
std::cout << "First Name: " << std::endl;
std::cin >> first_name;

std::cout << "Last Name: " << std::endl;
std::cin >> last_name;

//Printing out full name
full_name = first_name + " " + last_name;
std::cout << full_name << std::endl;

//Printing out altered name

std::cout << "\nAltered Name:\n" + replace_vowels(full_name) << std::endl;

return 0;
}

std::string replace_vowels(std::string line) {
    std::string result = line;
    for (char &c : result) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            c = '1';
        }
    }
    return result;
}
