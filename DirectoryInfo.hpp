#ifndef DIRECTORY_INFO_HPP
#define DIRECTORY_INFO_HPP
#include <experimental/filesystem>
#include <cstdint>
#include <iostream>

namespace fs = std::experimental::filesystem;

class DirectoryInfo {
public:
	DirectoryInfo(char* inputName);

	const char* getNameOfDir();
	void incrementNumOfFiles();
	uint32_t getNumOfFiles();
	void fillStatistic();
	void displayStatistic();
private:
	const char* nameDir;
	uint32_t numOfFiles;
	uint32_t totalNumOfLines;
	uint32_t numOfNonEmptyLines;
	uint32_t numOfEmptyLines;
};

#endif /* DIRECTORY_INFO_HPP */
