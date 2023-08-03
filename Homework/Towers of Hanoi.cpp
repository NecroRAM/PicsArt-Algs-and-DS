#include <iostream>

void Hanoi(char a, char b, char c, int n)
{
	if (n == 0) return;
	Hanoi(a, c, b, n - 1);
	std::cout << a << "->" << c << '\n';
	Hanoi(b, a, c, n - 1);
}

int main()
{
	Hanoi('a', 'b', 'c', 3);
}