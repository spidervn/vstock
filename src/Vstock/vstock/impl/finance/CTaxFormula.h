#ifndef VSTOCK_IMPL_FINANCE_CTAXFORMULA_H_
#define VSTOCK_IMPL_FINANCE_CTAXFORMULA_H_

#include "vstock/interface/finance/ITaxFormula.h"

struct PayInfo
{
	double total;
	double tax_you_paid;
	double insurance_you_paid;
	double actual_receive;

};

class CTaxFormula: public ITaxFormula
{
public:
	CTaxFormula();
	virtual ~CTaxFormula();
	double calcTax(double income, int numAdoptPeople=0, double AllReduce = 0, int area_number=1);

	double calcTax(double income, PayInfo& out, int numAdoptPeople=0, double AllReduce = 0);
};

#endif