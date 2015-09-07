/*************************************************************************
	> File Name: polynomial.c
	> Author: Yikang Chen
	> Mail: 472757599@qq.com
	> Created Time: Wed 02 Sep 2015 05:04:32 AM PDT
 ************************************************************************/

#include <stdio.h>
#define MaxDegree 10

typedef struct DataStrutureOfPolynomial
{
    int power_arr[MaxDegree+1];
    int HighPower;
}poly_ins,*Polynomial;

void ZeroPolynomial(Polynomial poly)
{
    for(unsigned int i=0; i <= MaxDegree;++i)
    {
	poly->power_arr[i] = 0;
    }
    poly->HighPower = 0;
}

int Max(int num1, int num2)
{return num1>num2?num1:num2;}

void AddPolynomial(Polynomial poly1, Polynomial poly2, Polynomial poly_sum)
{
    ZeroPolynomial(poly_sum);
    poly_sum->HighPower = Max(poly1->HighPower, poly2->HighPower);
    for(int i=poly_sum->HighPower; i>=0; --i)
    {
	poly_sum->power_arr[i] = poly1->power_arr[i] + poly2->power_arr[i];
    }
}

void MutiplyPolynomial(Polynomial poly1, Polynomial poly2, Polynomial poly_prod)
{
    ZeroPolynomial(poly_prod);
    poly_prod->HighPower = poly1->HighPower + poly2->HighPower;
    if(poly_prod->HighPower > MaxDegree)
    {
	printf("out of array size\n");
	return;
    }
    else
    {
	unsigned int i=0, j=0;
	for(;i<=poly1->HighPower;++i)
	    for(;j<=poly2->HighPower;++j)
		poly_prod->power_arr[i+j] += poly1->power_arr[i]*poly2->power_arr[j];
    }
}

int main()
{
    poly_ins poly1, poly2, poly_sum, poly_prod;
    Polynomial poly_ptr1 = &poly1; 
    Polynomial poly_ptr2 = &poly2;
    ZeroPolynomial(poly_ptr1);
    ZeroPolynomial(poly_ptr2);
    poly1.HighPower = 2;
    poly2.HighPower = 2;
    AddPolynomial(poly_ptr1,poly_ptr2,&poly_sum);
    MutiplyPolynomial(poly_ptr1,poly_ptr2,&poly_prod);

    return 0;
}
