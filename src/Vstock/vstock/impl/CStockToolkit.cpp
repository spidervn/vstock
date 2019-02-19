#include "CStockToolkit.h"

CStockToolkit::CStockToolkit(/* args */)
{}

CStockToolkit::~CStockToolkit()
{}

double CStockToolkit::stockPrice(Capital cap)
{
    return cap.marketCap/ cap.volume;    
}

int CStockToolkit::income(Capital cap, double newIncome, Capital& capNew)
{
    capNew = cap;
    capNew.marketCap += newIncome;

    return 0;
}