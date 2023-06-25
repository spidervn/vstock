#include <stdlib.h>
#include <stdio.h>
#include "vstock/impl/finance/CTaxFormula.h"
#include <dynsocc/fundamental/stdex/geometry.h>
#include <dynsocc/fundamental/stdex/string.hpp>
#include <dynsocc/util/Console.h>
#include <locale.h>
using namespace dynsocc;
using namespace std;

int main(int argc, char const *argv[])
{
    printf("Testing VStock\r\n");
    ITaxFormula* pT = new CTaxFormula();

    double amount= 51000000;
	double dMonthlySupport = 1230000;
	amount = 58384800;
	amount += dMonthlySupport;
	
	
	double allReduce = dMonthlySupport;
    double d = pT->calcTax(amount, 2, allReduce);
    printf("Tax for Amount(%f)-Reduce(%f) is %f\r\n", amount, allReduce, d);

	dynsocc::Rectangle r1(0, 0, 100, 100);
	dynsocc::Rectangle r2(0, 0, 100, 1000);

	printf("Intersect %d\r\n", dynsocc::GeometryUtil::intersect(r1, r2));
	
	setlocale(LC_NUMERIC, "");
	printf("%d\r\n", 554678);

	int res=0;
	Console::log(stringutil::format_number_thousand_separator(-1234.00, res));
	
	
    delete pT;
    return 0;
}
