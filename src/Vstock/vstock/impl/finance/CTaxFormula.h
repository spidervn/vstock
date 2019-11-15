#ifndef VSTOCK_IMPL_FINANCE_CTAXFORMULA_H_
#define VSTOCK_IMPL_FINANCE_CTAXFORMULA_H_

#include "vstock/interface/finance/ITaxFormula.h"

class CTaxFormula: public ITaxFormula
{
public:
	CTaxFormula();
	virtual ~CTaxFormula();
	double calcTax(double income, int numAdoptPeople=0, double AllReduce = 0);
};

#endif