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
	q_x_borders.resize(n_x_borders);
	for (int i = 0; i < n_x_borders; i++)
	{
		fin >> q_x_borders[i];
	}
	// interval
	n_x_interval.resize(n_x_borders);
	for (int i = 0; i < n_x_borders; i++)
	{
		fin >> n_x_interval[i];
	}

	// x
	fin >> n_y_borders;
	y_borders.resize(n_y_borders);
	// subregion borders by y
	for (int i = 0; i < n_y_borders; i++)
	{
		fin >> y_borders[i];
	}
	q_y_borders.resize(n_y_borders);
	for (int i = 0; i < n_y_borders; i++)
	{
		fin >> q_y_borders[i];
	}
	// interval
	n_y_interval.resize(n_y_borders);
	for (int i = 0; i < n_y_borders; i++)
	{
		fin >> n_y_interval[i];
	}
	fin.close();
}

Grid::Grid(std::string filename)
{
	load(filename);
}