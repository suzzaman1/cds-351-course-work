# include <iostream>

using std::cout;

int main ()
{
cout << "Hello world!\n";

return 0;
}

/*
Using `namespace std;` pulls every name from the C++ standard library into the global scope, 
which can cause naming conflicts if your code or another library defines something with the same name.
It also reduces clarity, since you can’t easily see which identifiers come from the standard library.
*/
