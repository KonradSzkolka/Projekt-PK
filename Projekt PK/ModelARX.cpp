#include "ModelARX.h"


double ModelARX::symuluj(double sym)
{
	double odchyl = 0;
	if (m_opuznienie > 0)
		odchyl = G(generuj);

	aktulizujbufor(v_U, sym, m_opuznienie + v_B.size());

	double ksym = 0;
	for (size_t i : v_B)
		ksym += v_B[i] * v_U[v_U.size() - 1 - i];

	for (size_t i : v_A)
		ksym -= v_A[i] * v_Y[v_Y.size() - 1 - i];

	ksym += odchyl;

	aktulizujbufor(v_Y, ksym, v_A.size());

	return ksym;
}
