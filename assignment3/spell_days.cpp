# include <iostream>
# include <vector>
using namespace std;

int main()
{
    while(true)
    {
        std::vector<std::string> v {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        std::string val;

        std::cout << "Enter a number (0-6) or a spelled-out day (Sunday-Saturday): ";
        std::cin >> val;

        if(isdigit(val[0]))
        {
            int val_int = std::stoi(val);
            std::cout << "Day of the week: " << v[val_int] << std::endl;
        }
        else
        {
            int count = 0;

            for(std::string x : v)
            {
                if(x == val)
                {
                    break;
                }
                else
                {
                    count++;
                }
            }

            std::cout << "Day number: " << count << std::endl;
        }
    }
    return 0;
}
