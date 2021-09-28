#include <iostream>
#include <string>
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main( int argc, char **argv ) {
	if (argc < 2) {
		const auto dir = fs::current_path();
		std::cout << "Current dir: " << dir << std::endl;
		return 0;
	}
	while (argc-- > 1) {
		if (fs::is_regular_file(argv[argc]))
			std::cout << argv[argc] << " is a regular file\n";
		else if (fs::is_directory(argv[argc])) {
			std::cout << argv[argc] << " is a directory\n";
			for (auto const& dir_entry: fs::recursive_directory_iterator{argv[argc]})
				std::cout << dir_entry << std::endl;
		} else
			std::cout << "neither\n";
	}


	


	return 0;
}
