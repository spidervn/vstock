#include <stdlib.h>
#include <stdio.h>
#include "vstock/impl/finance/CTaxFormula.h"

int main(int argc, char const *argv[])
{
    printf("Testing VStock\r\n");
    ITaxFormula* pT = new CTaxFormula();

    double d = pT->calcTax(40000000, 1);
    printf("%f\r\n", d);

    delete pT;
    return 0;
}
