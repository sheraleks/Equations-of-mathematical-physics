#include "grid.h"
#include "DiagonalFormat.h"
#include <vector>
using std::vector;

double lambda = 1, gamma = 2, v;

double u(double x, double y) //аналитическая функция u; используется для граничных
{
	return x * x + y * y;
}

double func(double x, double y) //f-используется для внутренних точек
{
	return gamma * u(x, y) - lambda * v;
}

//void ravnomer() 
//{
//	auto grid = new Grid("grid1.txt");
//	int n = grid->x.size() * grid->y.size();
//	auto matrix = new DiagonalFormat(n, 5);
//	double hy = grid->y[1] - grid->y[0];
//	double hx = grid->x[1] - grid->x[0];
//	matrix->offsets[0] = -((int)grid->x.size() - 2);
//	matrix->offsets[1] = -1;
//	matrix->offsets[3] = 1;
//	matrix->offsets[4] = grid->x.size() - 2;
//	for (int i = 0; i < n; i++)
//	{
//		int index = grid->x.size() + i;
//		if (i < n - grid->x.size())
//			matrix->diagonals[0][index] = -lambda / (hy * hy);
//		if (i < n - 1)
//			matrix->diagonals[1][1 + i] = -lambda / (hx * hx);
//		matrix->diagonals[2][i] = lambda * (2 / (hy * hy) + 2 / (hx * hx)) + gamma;
//		if (i < n - 1)
//			matrix->diagonals[3][i] = -lambda / (hx * hx);
//		if (i < n - grid->x.size())
//			matrix->diagonals[4][i] = -lambda / (hy * hy);
//	}
//}

void neravn() //для внутренних точек
{
	auto grid = new Grid("grid1.txt");
	int n = grid->x.size() * grid->y.size();
	auto matrix = new DiagonalFormat(n, 5);
	double lambda = 1, gamma = 2;
	matrix->offsets[0] = -((int)grid->x.size() - 2);
	matrix->offsets[1] = -1;
	matrix->offsets[3] = 1;
	matrix->offsets[4] = grid->x.size() - 2;
	vector<double> f(n);
	int count = 0;
	for (int i = 1; i < grid->x.size()-1; i++)
		for (int j = 1; j < grid->y.size() - 1; j++)
		{
			double hy1 = grid->y[j] - grid->y[j - 1];
			double hx1 = grid->x[i] - grid->x[i - 1];
			double hy2 = grid->y[j + 1] - grid->y[j];
			double hx2 = grid->x[i + 1] - grid->x[i];
			int index = grid->x.size() + count;
			if (count < n - grid->x.size())
				matrix->diagonals[0][index] = -lambda / hy1 * (hy1 + hy2);
			if (count < n - 1)
				matrix->diagonals[1][1 + count] = -lambda / hx1 * (hx1 * hx2);
			matrix->diagonals[2][count] = lambda * (2 / (hy1 * hy2) + 2 / (hx1 * hx2)) + gamma;
			if (count < n - 1)
				matrix->diagonals[3][count] = -lambda / hx2 * (hx1 * hx1);
			if (count < n - grid->x.size())
				matrix->diagonals[4][count] = -lambda / hy2 * (hy1 * hy2);
			f[count] = func(grid->x[i], grid->y[j]);
			count++;
		}
}

void main()
{
	neravn();
}