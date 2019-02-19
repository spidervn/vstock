#ifndef VSTOCK_IMPL_CSTOCKTOOLKIT_H_
#define VSTOCK_IMPL_CSTOCKTOOLKIT_H_

#include "vstock/interface/IStockToolkit.h"

class CStockToolkit : public IStockToolkit
{
private:
    /* data */
public:
    CStockToolkit(/* args */);
    ~CStockToolkit();

    double stockPrice(Capital cap);
    int income(Capital cap, double newIncome, Capital& capNew);
};


#endif