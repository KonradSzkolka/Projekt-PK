#pragma once

#include "Projekt PK.h"

class ModelARX
{
private:
	vector<double> v_A;
	vector<double> v_B;
	vector<double> v_U;
	vector<double> v_Y;
	size_t m_opuznienie;
	double m_odchylenieSzumu;
	//default_random_engine generuj;
	//normal_distribution<double>;

	void aktulizujbufor(vector<double>& bufor, double nowa, size_t rozmiar)
	{
		if (bufor.size() == rozmiar)
		{
			bufor.erase(bufor.end());
			bufor.push_back(nowa);
		}
		else
			bufor.push_back(nowa);
	}

public:

	ModelARX(const vector<double>& a){}
	~ModelARX(){}



};
