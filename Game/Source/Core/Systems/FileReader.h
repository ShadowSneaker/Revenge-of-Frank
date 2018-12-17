#pragma once
#include <string>
#include <fstream>
#include <vector>


class CFileReader
{
public:
	CFileReader();

	std::vector<std::string> ReadFileContents(const std::string FileName);
};