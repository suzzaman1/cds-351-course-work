# include <iostream>
using namespace std ;

void copy_floats(float* source, int num, float* dest)
{

        for(auto x = 0; x < num; x++)
        {
                dest[x] = source[x];
        }

}

int main ()
{
	float source[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
	float dest[6];
	int num = 6;

	copy_floats(source, num, dest);
	
	for(auto j:dest)
	{
		std::cout << j << " ";
	}
	std::cout <<"\n";
	return 0;
}
