#include <vector>
#include <string>
#include <fstream>
class Grid
{
private:
	void load(std::string filename);
public:
	// ������� ����������� �� x
	int n_x_borders;
	std::vector<int> x_borders;
	std::vector<double> q_x_borders;
	std::vector<int> n_x_interval;
	// ������� ����������� �� y
	int n_y_borders;
	std::vector<int> y_borders;
	std::vector<double> q_y_borders;
	std::vector<int> n_y_interval;
	Grid(std::string filename);
};