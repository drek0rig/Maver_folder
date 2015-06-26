#include "Store.h"
#include <string.h>

#ifdef SHOW_DEBUG_MESSAGES
#include <stdio.h>
#endif

// ****************************************************************************
// ***  Local constants and types
// ****************************************************************************

const int kMinRandomValueForProductCountInStore = 3;
const int kMaxRandomValueForProductCountInStore = 6;
const ProductCountInStoreType kUndefinedProductIndex = UINT_MAX;

// ****************************************************************************
// ***  Implementation of public methods of class
// ****************************************************************************

Store::Store()
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("Store::Store() - called\n");
#endif
	SetupRandomFunctionality();
	_storeName = new char[kMaxNameLength];
	_storeName[0] = '\0';
	_productCount = 0;
}

Store::Store(ProductCountInStoreType productCount)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("Store::Store(ProductCountInStoreType productCount) - called\n");
#endif
	SetupRandomFunctionality();
	_storeName = new char[kMaxNameLength];
	_storeName[0] = '\0';
	/*if (productCount > kMaxCountOfProductInStore)
		productCount = kMaxCountOfProductInStore;
	_productCount = productCount; */

	for (ProductCountInStoreType i = 0; i < _productCount; i++)
	{
		_showcase[i] = *getRandomProduct();
	}
}

Store::Store(const Store& rhs)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("Store::Store(const Store&) - called\n");
#endif
	_storeName = new char[kMaxNameLength];
	_storeName = rhs.getStoreName();
	_productCount = rhs.getProductCount();
	_showcase = rhs._showcase;
}

Store& Store::operator=(const Store& rhs)
{
	if (this == &rhs)
		return *this;
	_storeName = new char[kMaxNameLength];
	_storeName = rhs.getStoreName();
	_productCount = rhs.getProductCount();
	_showcase = rhs._showcase;
	return *this;
}

Store::~Store()
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("Store::~Store() - called\n");
#endif
	delete[] _storeName;
	_storeName = 0;
}

char* Store::getStoreName() const
{
	return _storeName;
}

void Store::setStoreName(char* const newName)
{
	if (strlen(newName) < kMaxNameLength)
	{
		_storeName = newName;
	}
	else 
	{
		_storeName = newName;
		_storeName[kMaxStringLength - 1] = '\0';
	}
}

ProductCountInStoreType Store::getProductCount() const
{
	return _productCount;
}

bool Store::addProduct(Product* const newProduct)
{
	/*if (_productCount >= kMaxCountOfProductInStore)
		return false;*/

	_showcase[_productCount] = *newProduct;
	_productCount++;
	return true;
}

void Store::removeProductAtIndex(const ProductCountInStoreType index)
{
	if (index >= _productCount)
		return;

	for (ProductCountInStoreType iter = index; iter < _productCount - 1; iter++)
	{
		_showcase[iter] = _showcase[iter + 1];
	}
	_productCount--;
}

void Store::replaceProductAtIndex(const Product newProduct, const ProductCountInStoreType index)
{
	if (index >= _productCount)
		return;

	_showcase[index] = newProduct;
}

Product* Store::getProductAtIndex(const ProductCountInStoreType index) const
{
	// Here we return empty class calling default constructor
	// This code is iqual to:
	// Product pr;		-- here compilator called default constructor and setup variable pr
	// return pr;
	if (index >= _productCount)
		return &Product();		
								
	return &_showcase[index];
}

Product* Store::getRandomProduct()
{
	Product* result;
	
	char* productName;
	getRandomProductName(productName);
	result->setProductName(productName);

	ProductPriceType productPrice = rand() % (kMaxRandomValueForProductPrice - kMinRandomValueForProductPrice + 1);
	productPrice += kMinRandomValueForProductPrice;
	result->setProductPrice(productPrice);

	ProductAmountType productAmount = rand() % (kMaxRandomValueForProductAmount - kMinRandomValueForProductAmount + 1);
	productAmount += kMinRandomValueForProductAmount;
	result->setProductAmount(productAmount);

	return result;
}

bool Store::canAddProductWithName(const char* const productName)
{
	bool result = true;
	for (ProductCountInStoreType i = 0; i < _productCount; i++)
	{
		char* localProductName;
		localProductName = _showcase[i].getProductName();
		if (strcmp(productName, localProductName) == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}

ProductCountInStoreType Store::getProductIndexByName(char* const productName)
{
	char* searchName;
	strcpy(searchName, productName);
	MakeStingLowerCase(searchName);

	ProductCountInStoreType result = kUndefinedProductIndex;
	ProductCountInStoreType productCount = getProductCount();
	for (ProductCountInStoreType productIndex = 0; productIndex < productCount; productIndex++)
	{
		char* tempProductName;
		tempProductName = _showcase[productIndex].getProductName();
		MakeStingLowerCase(tempProductName);

		if (strcmp(searchName, tempProductName) == 0)
		{
			result = productIndex;
			break;
		}
	}

	return result;
}

ProductCountInStoreType Store::getProductIndexByPrice(const ProductPriceType productPrice)
{
	ProductCountInStoreType result = kUndefinedProductIndex;
	ProductCountInStoreType productCount = getProductCount();
	for (ProductCountInStoreType productIndex = 0; productIndex < productCount; productIndex++)
	{
		if (_showcase[productIndex].getProductPrice() == productPrice)
		{
			result = productIndex;
			break;
		}
	}

	return result;
}

ProductCountInStoreType Store::getProductIndexByAmount(const ProductAmountType productAmount)
{
	ProductCountInStoreType result = kUndefinedProductIndex;
	ProductCountInStoreType productCount = getProductCount();
	for (ProductCountInStoreType productIndex = 0; productIndex < productCount; productIndex++)
	{
		if (_showcase[productIndex].getProductAmount() == productAmount)
		{
			result = productIndex;
			break;
		}
	}

	return result;
}

// ****************************************************************************
// ***  Implementation of private methods of class
// ****************************************************************************

void Store::getRandomProductName(char* outProductName)
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
	strcpy(outProductName, result);
}