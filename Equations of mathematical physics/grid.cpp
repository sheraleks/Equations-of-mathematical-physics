#include "grid.h"

void Grid::load(std::string filename)
{
	std::ifstream fin(filename);

	// by x
	fin >> n_x_borders;
	x_borders.resize(n_x_borders);
	// subregion borders by x
	for (int i = 0; i < n_x_borders; i++)
	{
		fin >> x_borders[i];
	}
	q_x_borders.resize(n_x_borders - 1);
	for (int i = 0; i < q_x_borders.size(); i++)
	{
		fin >> q_x_borders[i];
	}
	// interval
	n_x_interval.resize(n_x_borders - 1);
	for (int i = 0; i < n_x_interval.size(); i++)
	{
		fin >> n_x_interval[i];
	}

	// y
	fin >> n_y_borders;
	y_borders.resize(n_y_borders);
	// subregion borders by y
	for (int i = 0; i < n_y_borders; i++)
	{
		fin >> y_borders[i];
	}
	q_y_borders.resize(n_y_borders - 1);
	for (int i = 0; i < q_y_borders.size(); i++)
	{
		fin >> q_y_borders[i];
	}
	// interval
	n_y_interval.resize(n_y_borders - 1);
	for (int i = 0; i < n_y_interval.size(); i++)
	{
		fin >> n_y_interval[i];
	}
	fin.close();
}

double Grid::calculate_h0(int a, int b, double q, int n)
{
	return (b - a) * (1 - q) / (1 - pow(q, n));
}

void Grid::split_intervals(int n_borders, std::vector<int>& borders, std::vector<double>& q_borders,
	std::vector<int>& n_interval, std::vector<double>& axis)
{
	double h = calculate_h0(borders[0], borders[1],
		q_borders[0], n_interval[0]);
	for (int i = 0; i < n_borders; i++)
	{
		axis.push_back(borders[i]);
		int start_index = axis.size() - 1;
		int end_index = i != n_interval.size() ? n_interval[i] + start_index - 1 : start_index;
		for (int j = start_index; j < end_index; j++)
		{
			axis.push_back(axis[j] + h);
			h *= q_borders[i];
		}
	}
}

Grid::Grid(std::string filename)
{
	load(filename);
	split_intervals(n_x_borders, x_borders, q_x_borders, n_x_interval, x);
	split_intervals(n_y_borders, y_borders, q_y_borders, n_y_interval, y);
}