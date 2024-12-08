#include "ModelARX.h"


double ModelARX::symuluj(double symulowana)
{
	double odchyl = 0;
	if (m_opuznienie > 0)
		odchyl = G(generuj);

	aktulizujbufor(v_U, symulowana, m_opuznienie + v_B.size());

	double wyniksymulacji = 0;
	for (size_t i : v_B)
		wyniksymulacji += v_B[i] * v_U[v_U.size() - 1 - i];

	for (size_t i : v_A)
		wyniksymulacji -= v_A[i] * v_Y[v_Y.size() - 1 - i];

	wyniksymulacji += odchyl;

	aktulizujbufor(v_Y, wyniksymulacji, v_A.size());

	return wyniksymulacji;
}

double ModelWejscia::oblicz(double s)
{
	return modelARX.symuluj(s);
}

ModelARX* ModelWejscia::getModel()
{
	return &modelARX;
}
