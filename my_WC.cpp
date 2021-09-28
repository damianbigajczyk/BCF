#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main( int argc, char **argv ) {
	if (argc < 2)
		return 0;

	while (argc-- > 1 ) {
		ifstream ist {argv[argc]};
		if (!ist) {
			cout << "Can't open file\n";
		}
		char c;
		while (ist >> c)
			cout << c;
	}

	return 0;
}
