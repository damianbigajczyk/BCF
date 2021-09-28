#include <iostream>
#include <string>
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

class DirectoryInfo {
public:
	DirectoryInfo();
	void incrementNumOfFiles();
	uint32_t getNumOfFiles();

private:
	uint32_t numOfFiles = 0;
	uint32_t totalNumOfLines = 0;
	uint32_t numOfNonEmptyLines = 0;
	uint32_t numOfEmptyLines = 0;
};
	
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
	if (argc < 2) {
		const auto dir = fs::current_path();
		std::cout << "Current dir: " << dir << std::endl;
		return 0;
	}
	DirectoryInfo firstDir{};

	while (argc-- > 1) {
		if (fs::is_regular_file(argv[argc]))
			std::cout << argv[argc] << " is a regular file\n";
		else if (fs::is_directory(argv[argc])) {
			for (auto const& dir_entry: fs::recursive_directory_iterator{argv[argc]}) {
				state(firstDir, dir_entry.path());
				std::cout << dir_entry << std::endl;
			}
		} else
			std::cout << "neither\n";
	}
	std::cout << "Number of files: " << firstDir.getNumOfFiles() << std::endl;
	return 0;
}
DirectoryInfo::DirectoryInfo() {}
void DirectoryInfo::incrementNumOfFiles() {
	++numOfFiles;
}
uint32_t DirectoryInfo::getNumOfFiles() {
	return numOfFiles;
}
