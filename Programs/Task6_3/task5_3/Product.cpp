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
	_productName = new char[kMaxNameLength];
	_productName[0] = '\0';
}

Product::Product(const Product& rhs)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("Product::Product(const Product& rhs) - called\n");
#endif
	_productName = new char[kMaxNameLength];
	_productName = rhs.getProductName();
	_productPrice = rhs.getProductPrice();
	_productAmount = rhs.getProductAmount();
}

Product& Product::operator=(const Product& rhs)
{
	if (this == &rhs)
		return *this;
	_productName = new char[kMaxNameLength];
	_productName = rhs.getProductName();
	_productPrice = rhs.getProductPrice();
	_productAmount = rhs.getProductAmount();
	return *this;
}

Product::~Product()
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("Product::~Product() - called\n");
#endif
	delete[] _productName;
	_productName = 0;
}

char* Product::getProductName() const
{
	return _productName;
}

void Product::setProductName(char* const newName)
{
	_productName = newName;
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


