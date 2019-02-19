#ifndef VSTOCK_INTERFACE_ISTOCKTOOLKIT_H_
#define VSTOCK_INTERFACE_ISTOCKTOOLKIT_H_

struct Capital
{
    double marketCap;
    int volume;
};

class IStockToolkit
{
public:
    virtual ~IStockToolkit();
    virtual double stockPrice(Capital cap) = 0;
    virtual int income(Capital cap, double newIncome, Capital& capNew) = 0;
};


#endif