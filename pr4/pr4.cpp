#include "Header.h"
#define N 20000

int main()
{
	// generate random bitset
	bitset<N> bits;
	random_device rd; 
	mt19937 gen(rd()); 
	bernoulli_distribution d(0.5f); 

	for (int n = 0; n < N; ++n) {
		bits[n] = d(gen);
	}

	// tests
	bool check = Tester::monobit<N>(bits);
	bool res = check;
	cout << "Monobit: " << check << endl;

	check = Tester::long_runs<N>(bits);
	res &= check;
	cout << "Maximum series length: " << check << endl;

	check = Tester::poker<N>(bits);
	res &= check;
	cout << "Poker: " << check << endl;

	check = Tester::runs<N>(bits);
	res &= check;
	cout << "Series length: " << check << endl;

	cout << "Result: ";
	if(res) cout << "20,000 bits are random enough" << endl;
	else cout << "the bit sequence is rejected" << endl;
}
