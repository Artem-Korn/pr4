#pragma once
#include <iostream>
#include <bitset>
#include <random>
#define M 4
#define P 16
using namespace std;

class Tester {
	// constraint constants for testing
	static const unsigned MAX_RUNS = 36;
	static const float POKER[2];
	static const unsigned MONOBIT[2];
	static const unsigned RUNS_COUNT[2][6];

public:
	// 2.1 Implementation of a monobit test
	template <size_t size>
	static bool monobit(bitset<size> &arr) {
		unsigned counter = 0;
		for (int i = 0; i < size; i++) {
			counter += arr[i];
		}

		return counter > MONOBIT[0] && counter < MONOBIT[1];
	}

	// 2.4 Implementation of the series length test
	template <size_t bit_size>
	static bool runs(bitset<bit_size>& arr) {
		int j = 0;
		unsigned runs[2][6]{};

		for (int i = 0; i < bit_size - 1; i++) {
			if (arr[i] == arr[i + 1]) {
				j++;
			}
			else {
				runs[arr[i]][j > 5 ? 5 : j]++;
				j = 0;
			}
		}
		runs[arr[bit_size - 1]][j > 5 ? 5 : j]++;

		bool res = true;
		for (int i = 0; i < size(runs) && res; i++) {
			for (int k = 0; k < size(RUNS_COUNT[j]) && res; k++) {
				res = runs[i][k] > RUNS_COUNT[0][k] && runs[i][k] < RUNS_COUNT[1][k];
			}
		}

		return res;
	}

	// 2.3 Implementation of the poker test
	template <size_t size>
	static bool poker(bitset<size>& arr) {
		unsigned counter[P]{};
		bitset<M> runs[P];
		bool equal = false;
		double sum = 0, res = 0, k = size / M;

		for (int i = 0; i < P; i++) {
			runs[i] = i;
		}

		for (int i = 0; i <= size - M; i += M) {
			for (int j = 0; j < P; j++) {
				for (int k = 0; k < M; k++) {
					if (runs[j][k] == arr[i + k]) {
						equal = true;
					}
					else {
						equal = false;
						break;
					}
				}
				if (equal) {
					counter[j]++;
					break;
				}
			}
		}

		for (int j = 0; j < P; j++) {
			sum += pow(counter[j], 2);
		}

		res = P / k * sum - k;
		return  res > POKER[0] && res < POKER[1];
	}

	// 2.2 Implementation of the maximum series length test
	template <size_t size>
	static bool long_runs(bitset<size>& arr) {
		int j = 0, max_run = 1;

		for (int i = 0; i < size - 1; i++) {
			if (arr[i] == arr[i + 1]) {
				j++;
			}
			else {
				max_run = max(j, max_run);
				j = 0;
			}
		}
		max_run = max(j, max_run);

		return max_run < MAX_RUNS;
	}
};