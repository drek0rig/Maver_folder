#include "Product.h"
#include <string.h>

#ifdef SHOW_DEBUG_MESSAGES
#include <stdio.h>
#endif

// ****************************************************************************
// ***  Local constants and types
// ****************************************************************************

const ProductPriceType kMinRandomValueForProductPrice = 5;
const ProductPriceType kMaxRandomValueForProductPrice = 10;

const ProductAmountType kMinRandomValueForProductAmount = 4;
const ProductAmountType kMaxRandomValueForProductAmount = 8;

// ****************************************************************************
// ***  Implementation of public methods of class
// ****************************************************************************

Product::Product()
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("Product::Product() - called\n");
#endif
	_productPrice = 0;
	_productAmount = 0;
	_productName[0] = '\0';
}

Product::~Product()
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("Product::~Product() - called\n");
#endif
}

void Product::getProductName(StringType outName) const
{
	strcpy(outName, _productName);
}

void Product::setProductName(const StringType newName)
{
	if (strlen(newName) < kMaxStringLength)
	{
		strcpy_s(_productName, newName);
	}
	else 
	{
		strncpy_s(_productName, newName, kMaxStringLength - 1);
		_productName[kMaxStringLength - 1] = '\0';
	}
}

ProductPriceType Product::getProductPrice() const
{
	return _productPrice;
}

void Product::setProductPrice(ProductPriceType newPrice)
{
	_productPrice = newPrice;
}

ProductAmountType Product::getProductAmount() const
{
	return _productAmount;
}

void Product::setProductAmount(const ProductAmountType newProductAmount)
{
	_productAmount = newProductAmount;
}


