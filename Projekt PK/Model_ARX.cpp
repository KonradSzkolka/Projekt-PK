#include "Model_ARX.h"

double ModelARX::symuluj(double symulowana)
{
	double odchyl = 0;
	if (m_opuznienie > 0)
		odchyl = G(generuj);

	aktulizujbufor(v_U, symulowana, m_opuznienie + v_B.size());

	double wyniksymulacji = 0;
	for (size_t iteracja=0; iteracja < v_B.size(); iteracja++)
		wyniksymulacji += v_B[iteracja] * v_U[v_U.size() - 1 - iteracja];

	for (size_t iteracja=0; iteracja < v_A.size(); iteracja++)
		wyniksymulacji -= v_A[iteracja] * v_Y[v_Y.size() - 1 - iteracja];

	wyniksymulacji += odchyl;

	aktulizujbufor(v_Y, wyniksymulacji, v_A.size());

	return wyniksymulacji;
}

void ModelWejscia::setChceWynik(double* w)
{
	if (w != nullptr)
	{
		if (*w >= 1)
			w_chcewynik = w;
		else
			*w_chcewynik = 1;
	}
}

double* ModelWejscia::getChceWynik() const
{
	return w_chcewynik;
}

double ModelWejscia::oblicz(double s)
{
	return modelARX.symuluj(s);
}

ModelARX* ModelWejscia::getModel()
{
	return &modelARX;
}
