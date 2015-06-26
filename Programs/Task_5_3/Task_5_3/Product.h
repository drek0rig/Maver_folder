#ifndef PRODUCT_H
#define PRODUCT_H
#include "SupportTools.h"

//  **************************************************************
//  *** Interface of class
//  **************************************************************


class Product
{
public:
	Product();
	~Product();

	void setTitle(const StringType title);
	void getTitle(StringType outputString) const; 

	void setPrice(const int prise);
	int getPrice() const;

	void setAmount(const int amount);
	int getAmount() const;
private:
	StringType _title;
	int _price;
	int _amount;
};

#endif