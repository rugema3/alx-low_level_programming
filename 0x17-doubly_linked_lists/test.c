#include <stdio.h>

int isPalindrome(int num) {
	int reverse = 0;
	int original = num;

	while (num != 0) {
		int remainder = num % 10;
		reverse = reverse * 10 + remainder;
		num /= 10;
	}

	return original == reverse;
}

int main() {
	int largestPalindrome = 0;
	int i, j;

	for (i = 999; i >= 100; i--) {
		for (j = i; j >= 100; j--) {
			int product = i * j;
			if (isPalindrome(product) && product > largestPalindrome) {
				largestPalindrome = product;
			}
		}
	}

	FILE *file = fopen("102-result", "w");
	if (file != NULL) {
		fprintf(file, "%d", largestPalindrome);
		fclose(file);
	}

	return 0;
}

