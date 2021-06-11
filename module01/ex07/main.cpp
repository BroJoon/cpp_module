#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>

void copyFile(std::ifstream& ifs, std::string& input)
{
	std::string line;
	while (std::getline(ifs, line))
	{
		input.append(line);
		if (!ifs.eof())
			input.append("\n");
	}
}

int replace(std::string file, std::string s1, std::string s2)
{
	if (file.empty() || s1.empty() || s2.empty())
	{
		std::cerr << "arguments are empty!" << std::endl;
		return 1;
	}

	std::string input;
	std::string output;
	std::ifstream ifs(file);

	if (errno)
	{
		std::cerr << file << ": " << std::strerror(errno) << std::endl;
		return errno;
	}
	copyFile(ifs, input);
	ifs.close();

	if (s1 == s2)
		output = input;
	else
	{
		size_t start = 0;
		size_t cur;
		while (1)
		{
			if ((cur = input.find(s1, start)) == std::string::npos)
			{
				output.append(input, start, input.length());
				break;
			}
			output.append(input, start, cur - start);
			output.append(s2);
			start = cur + s1.length();
		}
	}
	std::ofstream ofs;
	ofs.open(file + ".replace");
	if (errno)
	{
		std::cerr << file << ": " << std::strerror(errno) << std::endl;
		return errno;
	}
	ofs << output;
	ofs.close();

	return 0;
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: wrong argument!!" << std::endl;
		return 1;
	}
	return replace(argv[1], argv[2], argv[3]);
}
