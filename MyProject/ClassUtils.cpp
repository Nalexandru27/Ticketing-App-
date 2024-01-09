#include "ClassUtils.h"

void ClassUtils::serializeString(std::string value, std::ofstream& file)
{
	int valueSize = strlen(value.c_str()) + 1;
	file.write((char*)&valueSize, sizeof(int));
	file.write(value.c_str(), sizeof(char) * valueSize);
}

std::string ClassUtils::deserializeString(std::ifstream& file)
{
	int valueSize = 0;
	file.read((char*)&valueSize, sizeof(int));
	char buffer[1000];
	file.read(buffer, sizeof(char) * valueSize);
	return std::string(buffer);
}

