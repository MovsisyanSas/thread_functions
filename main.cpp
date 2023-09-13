#include <iostream>
#include <thread>

int fibonacci(int n) {
	if (n == 1 || n == 2) { return 1; }
	else { return fibonacci(n - 1) + fibonacci(n - 2); }
}

int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int main() {
	int n = 10;
	std::thread td1([&]() {int result = factorial(n); std::cout << "factorial: " << result << std::endl; });//we must use 2 int results, unless threads will disturb each others processing
	std::thread td2([n]() {int result = fibonacci(n); std::cout << "fibonacci: " << result << std::endl; });
	td1.join();
	td2.join();
}