#ifndef SHOPPING_STORES_H
#define SHOPPING_STORES_H
#pragma once

#include "Store.h"

// ****************************************************************************
// ***  Constants and types
// ****************************************************************************

typedef		unsigned int	StoreCountType;
static const StoreCountType kMaxStoreCount = 15;

extern const StoreCountType kMinRandomValueForCountOfStores;
extern const StoreCountType kMaxRandomValueForCountOfStores;
extern const StoreCountType kUndefinedStoreIndex;

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

class ShoppingStores
{
public:
	ShoppingStores();
	~ShoppingStores();

	StoreCountType getStoreCount() const;
	bool addStore(Store* const newStore);
	void removeStoreAtIndex(const StoreCountType index);
	void replaceStoreAtIndex(Store* const newStore, const StoreCountType index);
	Store* getStoreAtIndex(const StoreCountType index) const;
	StoreCountType getStoreIndexByName(char* const storeName);

	Store* getRandomStore();
	bool canAddStoreWithName(char* const storeName);
	char* getRandomStoreName();

	Product* getRandomProduct();
	bool canAddProductWithName(char* const productName);
	char* getRandomProductName();

private:
	StoreCountType  _storeCount;
	Store*			_storeList;
};

#endif