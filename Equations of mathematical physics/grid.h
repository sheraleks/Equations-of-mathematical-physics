#include <vector>
#include <string>
#include <fstream>
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
public:
	Grid(std::string filename);
};