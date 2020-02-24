#include "grid.h"

void Grid::load(std::string filename)
{
	std::ifstream fin(filename);
	fin >> n_x_borders;
	// по х
	x_borders.resize(n_x_borders);
	// границы подобластей по х
	for (int i = 0; i < n_x_borders; i++)
	{
		fin >> x_borders[i];
	}
	// 
	q_x_borders.resize(n_x_borders);
	for (int i = 0; i < n_x_borders; i++)
	{
		fin >> q_x_borders[i];
	}
	// дробление интервала
	n_x_interval.resize(n_x_borders);
	for (int i = 0; i < n_x_borders; i++)
	{
		fin >> n_x_interval[i];
	}

	// по у
	fin >> n_y_borders;
	y_borders.resize(n_y_borders);
	// границы подобластей по у
	for (int i = 0; i < n_y_borders; i++)
	{
		fin >> y_borders[i];
	}
	// 
	q_y_borders.resize(n_y_borders);
	for (int i = 0; i < n_y_borders; i++)
	{
		fin >> q_y_borders[i];
	}
	// дробление интервала
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