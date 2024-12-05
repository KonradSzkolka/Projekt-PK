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
	default_random_engine generuj;
	normal_distribution<double> G;

	void aktulizujbufor(vector<double>& bufor, double nowa, size_t rozmiar)
	{
		if (bufor.size() == rozmiar)
		{
			bufor.erase(bufor.begin());
		}
			bufor.push_back(nowa);
	}

public:

	ModelARX(const vector<double>& a, const vector<double>& b, size_t opuznienie, double odchylenie = 0.0)
		:v_A(a), v_B(b), m_opuznienie(opuznienie),m_odchylenieSzumu(odchylenie)
	{
		v_U = vector<double>(m_opuznienie + v_B.size(), 0.0);
		v_Y = vector<double>(v_A.size(), 0.0);
	}
	~ModelARX(){}

	double symuluj(double sym);

};
