#include <stdlib.h>
#include <stdio.h>
#include "vstock/impl/finance/CTaxFormula.h"

int main(int argc, char const *argv[])
{
    printf("Testing VStock\r\n");
    ITaxFormula* pT = new CTaxFormula();

    double amount= 31990000;
    double allReduce = 3100000;
    double d = pT->calcTax(amount, 1, allReduce);
    printf("Tax for Amount(%f)-Reduce(%f) is %f\r\n", amount, allReduce, d);

    delete pT;
    return 0;
}
