#ifndef VSTOCK_INTERFACE_FINANCE_ITAXFORMULA_H_
#define VSTOCK_INTERFACE_FINANCE_ITAXFORMULA_H_

class ITaxFormula
{
public:
	virtual ~ITaxFormula() {}
	virtual double calcTax(double , int numAdoptPeople=0, double AllReduce = 0) = 0;
};

#endif