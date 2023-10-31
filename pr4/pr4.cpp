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
	cout << "Monobit: " << Tester::monobit<N>(bits) << endl;
	cout << "Maximum series length: " << Tester::long_runs<N>(bits) << endl;
	cout << "Poker: " << Tester::poker<N>(bits) << endl;
	cout << "Series length: " << Tester::runs<N>(bits) << endl;
}
