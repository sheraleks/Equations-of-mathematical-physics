#include <vector>
#include <string>
#include <fstream>
#include <cmath>
class Grid
{
private:
	// subregion borders by x
	int n_x_borders;
	std::vector<int> x_borders;
	std::vector<double> q_x_borders;
	std::vector<int> n_x_interval;
	// subregion borders by y
	int n_y_borders;
	std::vector<int> y_borders;
	std::vector<double> q_y_borders;
	std::vector<int> n_y_interval;
	// loading from file
	void load(std::string filename);
	double calculate_h0(int a, int b, double q, int n);
	void split_intervals(int n_borders, std::vector<int> &borders, std::vector<double> &q_borders, 
		std::vector<int> &n_interval, std::vector<double> &axis);
public:
	std::vector<double> x;
	std::vector<double> y;
	Grid(std::string filename);
};