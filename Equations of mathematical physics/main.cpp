#include "grid.h"
#include "DiagonalFormat.h"

void diMatrix()
{
	auto grid = new Grid("grid1.txt");
	int n = grid->x.size() * grid->y.size();
	auto matrix = new DiagonalFormat(n, 5);
	double lambda, gamma, hy, hx;
	for (int i = 0; i < n; i++)
	{
		matrix->diagonals[0][grid->x.size() + i] = -lambda / (hy * hy);
		matrix->diagonals[1][1 + i] = -lambda / (hx * hx);
		matrix->diagonals[2][i] = lambda * (2 / (hy * hy) + 2 / (hx * hx)) + gamma;
		if (i < n - 1)
			matrix->diagonals[3][i] = -lambda / (hx * hx);
		if (i < n - grid->x.size())
			matrix->diagonals[4][i] = -lambda / (hy * hy);
	}
	matrix->offsets[0] = grid->x.size() - 2;
	matrix->offsets[1] = 1;
	matrix->offsets[3] = 1;
	matrix->offsets[4] = grid->x.size() - 2;
}

void main()
{
	diMatrix();
}