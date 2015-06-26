#include "ShoppingStores.h"
#include <string.h>

#ifdef SHOW_DEBUG_MESSAGES
#include <stdio.h>
#endif

// ****************************************************************************
// ***  Local constants and types
// ****************************************************************************

const StoreCountType kMinRandomValueForCountOfStores = 3;
const StoreCountType kMaxRandomValueForCountOfStores = 6;
const StoreCountType kUndefinedStoreIndex = UINT_MAX;

// ****************************************************************************
// ***  Implementation of public methods of class
// ****************************************************************************

ShoppingStores::ShoppingStores()
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("ShoppingStores::ShoppingStores() - called\n");
#endif
	SetupRandomFunctionality();
	_storeCount = 0;
}

ShoppingStores::~ShoppingStores()
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("ShoppingStores::~ShoppingStores() - called\n");
#endif
}

StoreCountType ShoppingStores::getStoreCount() const
{
	return _storeCount;
}

bool ShoppingStores::addStore(Store* const newStore)
{
	/*if (_storeCount >= kMaxStoreCount)
		return false;*/

	_storeList[_storeCount] = *newStore;
	_storeCount++;
	return true;
}

void ShoppingStores::removeStoreAtIndex(const StoreCountType index)
{
	if (index >= _storeCount)
		return;

	for (StoreCountType iter = index; iter < _storeCount - 1; iter++)
	{
		_storeList[iter] = _storeList[iter + 1];
	}
	_storeCount--;
}

void ShoppingStores::replaceStoreAtIndex(Store* const newStore, const StoreCountType index)
{
	if (index >= _storeCount)
		return;

	_storeList[index] = *newStore;
}

Store* ShoppingStores::getStoreAtIndex(const StoreCountType index) const
{
	if (index >= _storeCount)
		return &Store();		
								
	return _storeList + index;
}

StoreCountType ShoppingStores::getStoreIndexByName(char* const storeName)
{
	char* searchName;
	strcpy(searchName, storeName);
	MakeStingLowerCase(searchName);

	StoreCountType result = kUndefinedStoreIndex;
	StoreCountType storeCount = getStoreCount();
	for (StoreCountType storeIndex = 0; storeIndex < storeCount; storeIndex++)
	{
		char* tempStoreName;
		tempStoreName = _storeList[storeIndex].getStoreName();
		MakeStingLowerCase(tempStoreName);

		if (strcmp(searchName, tempStoreName) == 0)
		{
			result = storeIndex;
			break;
		}
	}

	return result;
}

Store* ShoppingStores::getRandomStore()
{
	int productCount = rand() % (kMaxRandomValueForProductCountInStore - kMinRandomValueForProductCountInStore + 1);
	productCount += kMinRandomValueForProductCountInStore;
	Store result(productCount);

	char* storeName;
	storeName = getRandomStoreName();
	result.setStoreName(storeName);

	return &result;
}

bool ShoppingStores::canAddStoreWithName(char* const storeName)
{
	bool result = true;
	for (StoreCountType i = 0; i < _storeCount; i++)
	{
		char* localStoreName;
		localStoreName = _storeList[i].getStoreName();
		if (strcmp(storeName, localStoreName) == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}

char* ShoppingStores::getRandomStoreName()
{
	char* result;
	int storeNamesCount = rand() % kDefaultStoreNamesCount;
	char* randomName;
	strcpy(randomName, kDefaultStoreNames[storeNamesCount]);
	strcpy(result, randomName);
	bool isValidName = false;
	int nameCount = 1;
	do
	{
		if (canAddStoreWithName(result))
		{
			isValidName = true;
		}
		else 
		{
			strcpy(result, randomName);
			strcat(result, " ");
			char* nameNumberStringValue;
			itoa(nameCount, nameNumberStringValue, 10);
			strcat(result, nameNumberStringValue);
			nameCount++;
		}
	}
	while (!isValidName);
	return result;
}

Product* ShoppingStores::getRandomProduct()
{
	Product* result = getRandomStore()->getRandomProduct();
	char* newProductName ;
	newProductName = getRandomProductName();
	result->setProductName(newProductName);
	return result;
}

bool ShoppingStores::canAddProductWithName(char* const productName)
{
	bool result = true;
	for (StoreCountType storeIndex = 0; storeIndex < _storeCount; storeIndex++)
	{
		Store* localStore = _storeList + storeIndex;
		ProductCountInStoreType productCount = localStore->getProductCount();
		for (ProductCountInStoreType productIndex = 0; productIndex < productCount; productIndex++)
		{
			char* localProductName;
			localProductName = localStore->getProductAtIndex(productIndex)->getProductName();
			if (strcmp(productName, localProductName) == 0)
			{
				result = false;
				break;
			}
		}
		if (!result)
			break;
	}
	return result;
}

char* ShoppingStores::getRandomProductName()
{
	char* result;
	int productNamesCount = rand() % kDefaultProductNamesCount;
	char* randomName;
	strcpy(randomName, kDefaultProductNames[productNamesCount]);
	strcpy(result, randomName);
	bool isValidName = false;
	int nameCount = 1;
	do
	{
		if (canAddProductWithName(result))
		{
			isValidName = true;
		}
		else 
		{
			strcpy(result, randomName);
			strcat(result, " ");
			char* nameNumberStringValue;
			itoa(nameCount, nameNumberStringValue, 10);
			strcat(result, nameNumberStringValue);
			nameCount++;
		}
	}
	while (!isValidName);
	return result;
}

