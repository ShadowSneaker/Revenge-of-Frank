#include "FileReader.h"


CFileReader::CFileReader()
{}


std::vector<std::string> CFileReader::ReadFileContents(const std::string FileName)
{
	std::vector < std::string> FileContents;

	std::ifstream OpenFile;
	OpenFile.open(FileName.c_str());

	if (!OpenFile.good())
	{
		return FileContents;
	}

	while (!OpenFile.eof())
	{
		std::string Line;
		std::getline(OpenFile, Line);

		FileContents.push_back(Line);
	}

	OpenFile.close();
	return FileContents;
}