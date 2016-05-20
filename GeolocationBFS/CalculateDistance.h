#include <iostream>

#include "CSVparser.hpp"

using namespace std;

class CalculateDistance {
private:
	int provinceCode;
	int cityregCode;
	int districtCode;
public:
	double CalculateDistance::provinceDistance(double lat, double lon, int log);
	double CalculateDistance::cityregDistance(double lat, double lon, int log);
	double CalculateDistance::districtDistance(double lat, double lon, int log);
	string CalculateDistance::getProvinceName();
	string CalculateDistance::getCityregName();
	string CalculateDistance::getDistrictName();
};