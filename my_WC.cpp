#include <iostream>
#include <string>
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

void state(const fs::path& p) {
	if (fs::is_regular_file(p))
		std::cout << "file\t";
	else if (fs::is_directory(p))
		std::cout << "directory\t";
	else
		std::cout << "\t" << p;
}

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
			for (auto const& dir_entry: fs::recursive_directory_iterator{argv[argc]}) {
				state(dir_entry.path());
				std::cout << dir_entry << std::endl;
			}
		} else
			std::cout << "neither\n";
	}


	


	return 0;
}
