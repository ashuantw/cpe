//24931:Extend to Palindromes
#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string input, addition;
	char buffer;
	bool palindrome;
	int half, index;
	while (cin >> input) {
		index = input.size() - 1, buffer = input[index], addition = "";
		for (int i = input.size() - 2; i >= 0; --i) 
			if (input[i] == buffer) {
				half = ((input.size() - i) >> 1) - 1, palindrome = true;
				for (int j = i + 1; j <= i + half; ++j)
					if (input[j] != input[input.size() - j + i - 1]) {
						palindrome = false;
						break;
					}
				if (palindrome)
					index = i;
			}
		for (int i = index - 1; i >= 0; --i)
			addition += input[i];
		cout << input + addition << '\n';
	}
}