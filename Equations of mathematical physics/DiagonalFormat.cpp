#include "DiagonalFormat.h"

DiagonalFormat::DiagonalFormat(int n, int diagonalsCount)
{
	this->n = n;
	this->diagonalsCount = diagonalsCount;
	this->offsets.resize(diagonalsCount);
	this->diagonals = std::vector<std::vector<double>>(diagonalsCount, std::vector<double>(n));
}

void DiagonalFormat::multByVector(std::vector<double> &vector, std::vector<double>& resultVector)
{
	for (int i = 0; i < this->n; i++)
	{
		double sum = 0;
		for (int diagonalIndex = 0; diagonalIndex < this->diagonalsCount; diagonalIndex++)
		{
			int offset = this->offsets[diagonalIndex];
			int j = i + offset;
			if (j < 0 || j >= this->n) continue;
			sum += this->diagonals[diagonalIndex][i] * vector[j];
		}
		resultVector[i] = sum;
	}
}

void DiagonalFormat::load(std::string filename)
{
	std::ifstream file(filename);
	for (int diagonalIndex = 0; diagonalIndex < this->diagonalsCount; diagonalIndex++)
	{
		file >> this->offsets[diagonalIndex];
		for (int elementIndex = 0; elementIndex < this->n; elementIndex++)
		{
			file >> this->diagonals[diagonalIndex][elementIndex];
		}
	}
	file.close();
}