#pragma once
#include <fstream>
class ClassUtils
{
public:
	static void serializeString(std::string value, std::ofstream& file);
	static std::string deserializeString(std::ifstream& file);
};

