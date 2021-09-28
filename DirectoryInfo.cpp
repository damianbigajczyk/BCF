#include "DirectoryInfo.hpp"


DirectoryInfo::DirectoryInfo() {
	numOfFiles = 0;
	totalNumOfLines = 0;
	numOfNonEmptyLines = 0;
	numOfEmptyLines = 0;
}


void DirectoryInfo::incrementNumOfFiles() {
	++numOfFiles;
}
uint32_t DirectoryInfo::getNumOfFiles() {
	return numOfFiles;
}
