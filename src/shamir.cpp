#include "shamir.h"

mpq_class multsum(std::vector<mpq_class> values) {
	mpq_class total = 1;
	for (int i = 0; i < values.size(); i++) {
		values[i].canonicalize();
		total *= values[i];
		total.canonicalize();
	}
	return total;
}

mpz_class magic(int j, std::vector<mpz_class> x) {
	std::vector<mpq_class> fractions;
	for (int m = 0; m < x.size(); m++) {
		if (m == j) continue;

		mpz_class num = -x[m];
		mpz_class denom = x[j] - x[m];
		mpq_class frac(num, denom);
		fractions.push_back(frac);
	}

	return mpz_class(multsum(fractions));
}

std::string calcShamir(std::vector<mpz_class> x, std::vector<mpz_class> y) {
	if (x.size() != y.size()) return "x and y not same length";

	mpz_class total = 0;

	for (int j = 0; j < x.size(); j++) {
		total += y[j] * magic(j, x);
	}

	return total.get_str();
}
