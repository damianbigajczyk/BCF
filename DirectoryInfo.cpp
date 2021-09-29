#include "DirectoryInfo.hpp"

namespace fs = std::experimental::filesystem;

DirectoryInfo::DirectoryInfo(char* inputName) : nameDir(inputName) {
	numOfFiles = 0;
	totalNumOfLines = 0;
	numOfNonEmptyLines = 0;
	numOfEmptyLines = 0;
}

const char* DirectoryInfo::getNameOfDir() {
	return nameDir;
}

void DirectoryInfo::incrementNumOfFiles() {
	++numOfFiles;
}

uint32_t DirectoryInfo::getNumOfFiles() {
	return numOfFiles;
}
void DirectoryInfo::fillStatistic() {
	for (auto const& dir_entry: fs::recursive_directory_iterator{nameDir}) {
		if (fs::is_regular_file(dir_entry.path())) {
			std::cout << "file\t";
			incrementNumOfFiles();
		} else if (fs::is_directory(dir_entry.path()))
			std::cout << "directory\t";
		else
			std::cout << "\t" << dir_entry.path();
		std::cout << dir_entry << std::endl;
	}
}
void DirectoryInfo::displayStatistic() {
	std::cout << "Number of files: " << getNumOfFiles() << std::endl;
}
