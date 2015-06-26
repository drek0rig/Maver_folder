#ifndef PRODUCT_H
#define PRODUCT_H
#pragma once

#include "ProjectSupport.h"

// ****************************************************************************
// ***  Constants and types
// ****************************************************************************

typedef		unsigned int	ProductPriceType;
typedef		unsigned int	ProductAmountType;

static const unsigned int kDefaultProductNamesCount = 6;
static const char* kDefaultProductNames[kDefaultProductNamesCount] = {
			"milk", "bread", "meat",
			"cookies", "potatoes", "juice"};

extern const ProductPriceType kMinRandomValueForProductPrice;
extern const ProductPriceType kMaxRandomValueForProductPrice;

extern const ProductAmountType kMinRandomValueForProductAmount;
extern const ProductAmountType kMaxRandomValueForProductAmount;

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

class Product
{
public:
	Product();
	Product(const Product&);
	Product& operator=(const Product&);
	~Product();

	char* getProductName() const;
	void setProductName(char* const newName);

	ProductPriceType getProductPrice() const;
	void setProductPrice(const ProductPriceType newPrice);

	ProductAmountType getProductAmount() const;
	void setProductAmount(const ProductAmountType newProductAmount);

private:
	char*				_productName;
	ProductPriceType	_productPrice;
	ProductAmountType	_productAmount;
};

#endif