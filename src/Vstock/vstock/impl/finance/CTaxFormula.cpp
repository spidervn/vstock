#include "CTaxFormula.h"
#include <stdio.h>
#include <stdlib.h>
#include <dynsocc/fundamental/stdex/string.hpp>

using namespace dynsocc;
using namespace std;

CTaxFormula::CTaxFormula()
{}

CTaxFormula::~CTaxFormula()
{
}

double CTaxFormula::calcTax(double income, int numAdoptPeople, double AllReduce)
{
	double ret;
	double ADOPT_UNIT = 3600000;
	double ADOPT_SELF = 9000000;
	double adoptReduce =  ADOPT_UNIT * numAdoptPeople + ADOPT_SELF;

	int METHOD = 1; 	// or 2
	int markId;	
	int markSize;
	double taxRate = 0;

	double MARK01 =  5000000;
	double MARK02 = 10000000;
	double MARK03 = 18000000;
	double MARK04 = 32000000;
	double MARK05 = 52000000;
	double MARK06 = 80000000;

	double marks[] = { MARK01, MARK02, MARK03, MARK04, MARK05, MARK06 };
	double markPer[] = { 5, 10, 15, 20, 25, 30, 35 };		// Percent on mark
	double margin1[] = { 0, 0.25, 0.75, 1.95, 4.75, 9.75, 18.15 };
	double margin2[] = { 0, 0.25, 0.75, 1.65, 3.25, 5.85, 9.85 };

	double taxedInc = (income - adoptReduce - AllReduce); 


	double UNIT_SALARY = 1490000;
	double dSocialInsurance = 0.0;
	double dMaxSocialInsurance = 20 * UNIT_SALARY;
	double dSocialEmployeePercent = 0.105; //  10.5%
	double dInsurance = 0.0;
	// Social Insurance 
	
	if (taxedInc > dMaxSocialInsurance)
	{
		dInsurance = dMaxSocialInsurance * dSocialEmployeePercent;
	}
	else
	{
		dInsurance = taxedInc * dSocialEmployeePercent;
	}

	
	taxedInc -= dInsurance;
	
	markSize = sizeof(marks)/sizeof(marks[0]);
	markId = -1;

	for (int i=1; i<markSize; ++i)
	{
		if (taxedInc > marks[i-1] && taxedInc <= marks[i])
		{
			markId = i;
		}
	}

	if (taxedInc <= marks[0])
	{
		markId = 0;
	}

	if (taxedInc > marks[markSize-1])
	{
		markId = markSize;
	}

	if (markId < 0)
	{
		printf("Invalid\r\n");
		return -1;
	}


	if (METHOD == 1)
	{
		int res = 0;
		double markSubtract = (markId  > 0) ? marks[markId-1] : 0;
		double margin = margin1[markId]*1000000;
		double part1 = ((taxedInc - markSubtract) * markPer[markId] / 100);
		printf("taxedInc = %f\r\n", taxedInc);
		printf("Tax percent=%f\r\n", markPer[markId]);
		printf("margin1 = %f\r\n", margin);
		printf("Part1 = %f\r\n", part1);
		printf("Marksubtract=%f\r\n", markSubtract);
		printf("Insurance=%s\r\n", stringutil::format_number_thousand_separator(dInsurance, res).c_str());
		ret = part1  + margin;
	}
	else if (METHOD == 2)
	{
		// Margin
		printf("taxedInc = %f\r\n", taxedInc);
		printf("taxedInc = %f\r\n", taxedInc);
		ret = taxedInc * markPer[markId]/100 - margin2[markId]*1000000;
	}

	return ret;
}