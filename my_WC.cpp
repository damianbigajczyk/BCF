#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <experimental/filesystem>
#include "DirectoryInfo.hpp"

namespace fs = std::experimental::filesystem;

	
void state(DirectoryInfo& dir, const fs::path& p) {
	if (fs::is_regular_file(p)) {
		std::cout << "file\t";
		dir.incrementNumOfFiles();
	} else if (fs::is_directory(p))
		std::cout << "directory\t";
	else
		std::cout << "\t" << p;
}

int main( int argc, char **argv ) {
	if (argc < 2)
		return 0;

	std::vector<DirectoryInfo> directoryStorage;
	directoryStorage.reserve(argc-1);

	for (int i = 1; i < argc; ++i) {
		if (fs::is_regular_file( argv[i] ))
			std::cout << argv[i] << " is a regular file\n";

		else if (fs::is_directory( argv[i] )) {

			DirectoryInfo nextDir{};

			for (auto const& dir_entry: fs::recursive_directory_iterator{argv[i]}) {
				state(directoryStorage[i], dir_entry.path());
				std::cout << dir_entry << std::endl;
			}

		} else
			std::cout << "neither\n";

		std::cout << "Number of files: " << directoryStorage[i].getNumOfFiles();
		std::cout << std::endl;
	}

	return 0;
}
