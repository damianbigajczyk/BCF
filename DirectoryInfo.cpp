#include "DirectoryInfo.hpp"

namespace fs = std::experimental::filesystem;

DirectoryInfo::DirectoryInfo(char* inputName) : nameDir(inputName) {
	numOfFiles = 0;
	numOfNonEmptyLines = 0;
	numOfEmptyLines = 0;
}

void DirectoryInfo::fillStatistic() {
	for (auto const& dir_entry: fs::recursive_directory_iterator{nameDir}) {
		if (fs::is_regular_file(dir_entry.path())) {
			std::cout << "file\t";
			std::ifstream currentFile {dir_entry.path()};
			if (currentFile.is_open()) {
				std::string data;
				while (getline(currentFile, data)) {
					if (data == "")
						incrementNumOfEmptyLines();
					else
						incrementNumOfNonEmptyLines();
				}
			}
			else
				std::cout << "Couldn't open file: "\
				       << dir_entry.path() << std::endl;
			incrementNumOfFiles();
		} else if (fs::is_directory(dir_entry.path()))
			std::cout << "directory\t";
		else
			std::cout << "\t" << dir_entry.path();
		std::cout << dir_entry << std::endl;
	}
}

void DirectoryInfo::incrementNumOfFiles() {
	++numOfFiles;
}

void DirectoryInfo::incrementNumOfEmptyLines() {
	++numOfEmptyLines;
}

void DirectoryInfo::incrementNumOfNonEmptyLines() {
	++numOfNonEmptyLines;
}

void DirectoryInfo::displayStatistic() {
	std::cout << "Number of files: " << getNumOfFiles() << std::endl;
	std::cout << "Number of empty lines: " << getNumOfEmptyLines() << std::endl;
	std::cout << "Number of non-empty lines:: " << getNumOfNonEmptyLines() << std::endl;
	std::cout << "Total number of lines:: " << getTotalNumOfLines() << std::endl;
	
}

const char* DirectoryInfo::getNameOfDir() {
	return nameDir;
}

uint32_t DirectoryInfo::getNumOfFiles() {
	return numOfFiles;
}

uint32_t DirectoryInfo::getNumOfEmptyLines() {
	return numOfEmptyLines;
}

uint32_t DirectoryInfo::getNumOfNonEmptyLines() {
	return numOfNonEmptyLines;
}

uint32_t DirectoryInfo::getTotalNumOfLines() {
	return getNumOfEmptyLines() + getNumOfNonEmptyLines();
}

