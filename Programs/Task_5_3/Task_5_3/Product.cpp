#include "Product.h"
#include <cstring>

//  *****************************************************
//  *** Implementation of public methods of class
//  *****************************************************

Product::Product()
{
	_title[0] = '\0';
	_price = 0;
	_amount = 0;
}

Product::~Product()
{
}

void Product::setTitle(const StringType title)
{
	strcpy(_title, title);
}

void Product::getTitle(StringType outputString) const
{
	strcpy(outputString, _title);
}

void Product::setPrice(const int price)
{
	_price = price;
}

int Product::getPrice() const
{
	return _price;
}

void Product::setAmount(const int amount)
{
	_amount = amount;
}

int Product::getAmount() const
{
	return _amount;
}