#ifndef DIRECTORY_INFO_HPP
#define DIRECTORY_INFO_HPP
#include <experimental/filesystem>
#include <cstdint>
#include <iostream>
#include <fstream>

namespace fs = std::experimental::filesystem;

class DirectoryInfo {
public:
	DirectoryInfo(char* inputName);


	void fillStatistic();
	void incrementNumOfFiles();
	void incrementNumOfNonEmptyLines();
	void incrementNumOfEmptyLines();
	void displayStatistic();

	const char* getNameOfDir();
	uint32_t getNumOfFiles();
	uint32_t getNumOfNonEmptyLines();
	uint32_t getNumOfEmptyLines();
	uint32_t getTotalNumOfLines();
private:
	const char* nameDir;
	uint32_t numOfFiles;
	uint32_t numOfNonEmptyLines;
	uint32_t numOfEmptyLines;
};

#endif /* DIRECTORY_INFO_HPP */
