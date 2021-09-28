#ifndef DIRECTORY_INFO_HPP
#define DIRECTORY_INFO_HPP
#include <cstdint>
#include <string>

class DirectoryInfo {
public:
	DirectoryInfo();

	void incrementNumOfFiles();
	uint32_t getNumOfFiles();

private:
	uint32_t numOfFiles;
	uint32_t totalNumOfLines;
	uint32_t numOfNonEmptyLines;
	uint32_t numOfEmptyLines;
};

#endif /* DIRECTORY_INFO_HPP */
