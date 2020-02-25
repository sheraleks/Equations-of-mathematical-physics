#include <fstream>
#include <vector>

class DiagonalFormat
{
public:
	int n;
	int diagonalsCount;
	DiagonalFormat(int n, int diagonalsCount);
	std::vector<std::vector<double>> diagonals;
	std::vector<int> offsets;
	void multByVector(std::vector<double> &vector, std::vector<double>& resultVector);
	void load(std::string filename);
};