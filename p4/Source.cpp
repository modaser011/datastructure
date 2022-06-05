#include<iostream>
using namespace std;
long long power1( long long a,  long long n)
{
	 if (n == 0)
		return 1;
	 else if (a == 0)
		return 0;
	else
		return a * power1(a, n - 1);
};
long long power2( long long a,  long long n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
	{	
		return power2(a, n / 2) * power2(a, n / 2);
	}
	else
	{
		return  a * power2(a, n / 2) * power2(a, n / 2);
	}
};
void chek( long long i, long long j) {
	cout << "Input:" << endl;
	cout << i << endl;
	cout << j << endl<<endl;
	cout << "Output:" << endl;
	cout << "first function: " << power1(i, j) << endl;
	cout << "second function: " << power2(i, j) << endl;
		
		cout << "____________________________________________________________________________________________________________________\n";
	}
int main()
{
	chek(2, 3);
	chek(3, 2);
	chek(2, 4);
}

