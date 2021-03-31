#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char** argv)	
{
	std::cout << std::endl << "Part 2:" << std::endl;

	std::string filename;
	int size;

	if (argc == 1)
	{
		filename = "single_row.txt";
		size = 10;
	}
	else
	{
		filename = argv[1];
		size = std::stoi(argv[2]);
	}
	std::ifstream in(filename);
	
	if(!in)
	{
		std::cout << "Couldn't open file " << filename << std::endl;
	}
	
	int *values = new int[size];
	int n_read = 0;
	for (int i=0; i<size; ++i)
	{
		in >> values[i];
		if(in)
		{
			++n_read;
		}
		else
		{
			break;
		}
	}
	in.close();
	float avg = 0.0;
	for (int i=0; i < n_read; ++i)
	{
		avg+= values[i];
	}
	std::cout << "The Average value of " << filename << " is: " << (avg/(float)n_read) << std:: endl;
	delete [] values;
	return 0;
}
