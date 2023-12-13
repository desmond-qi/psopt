
namespace qhx{namespace Tool{
inline void arr2ssm(double Input[3], double Output[3][3])
{
	int i, j;
	double Out[3][3] = { 0.0, -Input[2], Input[1], Input[2], 0.0, -Input[0], -Input[1], Input[0], 0.0 };
	for (i = 0; i < 3; i++)for (j = 0; j < 3; j++)Output[i][j] = Out[i][j];
}

inline double Calcu_NumPartDeriv(double f_plus, double f_minus, double delt_q)
{
	double Output;
	Output = (f_plus - f_minus) / (2.0 * delt_q);

	return Output;
}

}}
