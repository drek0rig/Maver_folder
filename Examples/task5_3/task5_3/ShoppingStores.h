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
	bool addStore(const Store newStore);
	void removeStoreAtIndex(const StoreCountType index);
	void replaceStoreAtIndex(const Store newStore, const StoreCountType index);
	Store getStoreAtIndex(const StoreCountType index) const;
	StoreCountType getStoreIndexByName(const StringType storeName);

	Store getRandomStore();
	bool canAddStoreWithName(const StringType storeName);
	void getRandomStoreName(StringType outStoreName);

	Product getRandomProduct();
	bool canAddProductWithName(const StringType productName);
	void getRandomProductName(StringType outProductName);

private:
	StoreCountType  _storeCount;
	Store			_storeList[kMaxStoreCount];
};

#endif