#include "grid.h"

void Grid::load(std::ifstream &file, int& n_borders,
	std::vector<int> &borders, std::vector<double>& q_borders,
	std::vector<int>& n_interval)
{
	file >> n_borders;
	borders.resize(n_borders);
	// subregion borders
	for (int i = 0; i < n_borders; i++)
	{
		file >> borders[i];
	}
	q_borders.resize(n_borders - 1);
	for (int i = 0; i < q_borders.size(); i++)
	{
		file >> q_borders[i];
	}
	// interval
	n_interval.resize(n_borders - 1);
	for (int i = 0; i < n_interval.size(); i++)
	{
		file >> n_interval[i];
	}
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
	std::ifstream fin(filename);
	load(fin, n_x_borders, x_borders, q_x_borders, n_x_interval);
	load(fin, n_y_borders, y_borders, q_y_borders, n_y_interval);
	fin.close();
	split_intervals(n_x_borders, x_borders, q_x_borders, n_x_interval, x);
	split_intervals(n_y_borders, y_borders, q_y_borders, n_y_interval, y);
}