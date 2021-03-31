#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char** argv)
{
	std::cout << std::endl << "Part 3: " << std::endl;
	std::string filename;
	int size;
	if (argc ==1)
	{
		filename = "2D.txt";
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

	int **rows = new int *[size];
	float sumAverage = 0.0; // hold sum of average of each row until each row has been averaged
	for (int i=0; i<size; ++i)
	{
		int *values = new int[size];
		int n_read = 0;
		float rowAverage = 0.0;
		for (int j=0;j<size; ++j)
		{
			in >> values[j];
			if(in)
			{
				++n_read;
			}
			else
			{
				break;
			}
		}
		std::cout << std::endl;
		rows[i] = values;
		for (int k=0; k<n_read ; ++k)
		{
			std::cout << values[k] << " ";
			rowAverage+= values[k];
		}	
		std::cout << std::endl;
		delete [] values;
		sumAverage+= (rowAverage/(float)n_read);
	}
	std::cout << "The Average across all the rows of " << filename << " is: " << (sumAverage/(float)size) <<std::endl;
	delete [] rows;
	return 0;

}

