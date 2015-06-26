#ifndef STORE_H
#define STORE_H
#pragma once

#include "Product.h"

// ****************************************************************************
// ***  Constants and types
// ****************************************************************************

typedef		unsigned int	ProductCountInStoreType;
static const ProductCountInStoreType kMaxCountOfProductInStore = 20;

static const unsigned int kDefaultStoreNamesCount = 6;
static const char* kDefaultStoreNames[kDefaultStoreNamesCount] = {
			"Silpo", "Mega market", "Furshet",
			"Fora", "Ashan", "Koshik"};



extern const int kMinRandomValueForProductCountInStore;
extern const int kMaxRandomValueForProductCountInStore;
extern const ProductCountInStoreType kUndefinedProductIndex;

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

class Store
{
public:
	Store();
	Store(ProductCountInStoreType productCount);	// create store object with productCount random products
	Store(const Store&);
	Store& operator=(const Store&);
	~Store();

	char* getStoreName() const;
	void setStoreName(char* const newName);

	ProductCountInStoreType getProductCount() const;
	bool addProduct(Product* const newProduct);   
	void removeProductAtIndex(const ProductCountInStoreType index); //******************************** тут
	void replaceProductAtIndex(const Product newProduct, const ProductCountInStoreType index);
	Product* getProductAtIndex(const ProductCountInStoreType index) const;

	Product* getRandomProduct();
	bool canAddProductWithName(const char* const productName);

	ProductCountInStoreType getProductIndexByName(char* const productName);
	ProductCountInStoreType getProductIndexByPrice(const ProductPriceType productPrice);
	ProductCountInStoreType getProductIndexByAmount(const ProductAmountType productAmount);

private:
	void getRandomProductName(char* outProductName);

	char*					_storeName;
	ProductCountInStoreType	_productCount;
	Product*				_showcase;
};

#endif