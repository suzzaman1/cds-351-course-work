# include <iostream>
using namespace std;

int main()
{
        int square;
        long long grain_count;

        for(long long x : {1000, 1000000, 1000000000})
        {
            square = 1;
            grain_count = 1;

            while(grain_count < x)
            {
                square++;
                grain_count *= 2;
            }

            std::cout << "Grain Count: " << grain_count << "---> Square: " << square << std::endl;
        }

        return 0;
}
