#include "DirectoryInfo.hpp"

void displayInfoDir(char *inputName);

int main( int argc, char **argv ) {
	if (argc < 2)
		return 0;

	for (int i = 1; i < argc; ++i) {
		displayInfoDir( argv[i] );
	}

	return 0;
}

void displayInfoDir(char *inputName) {
	if (fs::is_regular_file( inputName ))
		std::cout << inputName << " is a regular file\n";
	else if (fs::is_directory( inputName )) {

		DirectoryInfo nextDir{inputName};

		nextDir.fillStatistic();
		nextDir.displayStatistic();
	} else
		std::cout << "neither\n";
}
