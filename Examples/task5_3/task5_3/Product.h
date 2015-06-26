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
static const StringType kDefaultProductNames[kDefaultProductNamesCount] = {
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
	~Product();

	void getProductName(StringType outName) const;
	void setProductName(const StringType newName);

	ProductPriceType getProductPrice() const;
	void setProductPrice(const ProductPriceType newPrice);

	ProductAmountType getProductAmount() const;
	void setProductAmount(const ProductAmountType newProductAmount);

private:
	StringType			_productName;
	ProductPriceType	_productPrice;
	ProductAmountType	_productAmount;
};

#endif