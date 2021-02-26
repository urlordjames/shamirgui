#include <gtest/gtest.h>
#include <gmpxx.h>
#include "shamir.h"

TEST(shamirlib, calcShamirSmall) {
	std::vector<mpz_class> x = {1, 2};
	std::vector<mpz_class> y = {26, 30};

	EXPECT_EQ(calcShamir(x, y), "22");

	x.push_back(3);
	y.push_back(36);

	EXPECT_EQ(calcShamir(x, y), "24");
}

mpz_class calcPolynomial(mpz_class x, std::vector<mpz_class> coefs) {
	mpz_class total = 0;

	for (int i = 0; i < coefs.size(); i++) {
		if (i == 0) {
			total += coefs.at(0);
			continue;
		}
		mpz_class temp;
		mpz_pow_ui(temp.get_mpz_t(), x.get_mpz_t(), i);
		total += temp * coefs.at(i);
	}

	return total;
}

TEST(shamirlib, calcShamirLarge) {
	mpz_class secret = 1234;
	std::vector<mpz_class> coefs = {secret, 3546453, 36434552, 645654546, -43534534};

	ASSERT_EQ(calcPolynomial(0, coefs).get_str(), secret.get_str());

	std::vector<mpz_class> x;

	for (int i = 1; i <= coefs.size(); i++) {
		x.push_back(i);
	}

	std::vector<mpz_class> y;

	for (int i = 0; i < x.size(); i++) {
		mpz_class result = calcPolynomial(x.at(i), coefs);
		y.push_back(result);
	}

	ASSERT_EQ(x.size(), y.size());

	EXPECT_EQ(calcShamir(x, y), secret.get_str());
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
