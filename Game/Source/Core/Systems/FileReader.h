#pragma once
#include <string>
#include <fstream>
#include <vector>


// A class dedicated to read files.
class CFileReader
{
public:
	// Constructor, Default
	CFileReader();

	/// Functions

	// Converts the info in the file to a Vector of strings.
	// @param FileName - The text file to be read.
	// @return - The full contents of the file.
	std::vector<std::string> ReadFileContents(const std::string FileName);
};