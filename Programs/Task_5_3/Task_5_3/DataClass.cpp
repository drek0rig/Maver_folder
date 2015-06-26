#include "DataClass.h"

// #define LOG_PRINT

static const char kHeadStringMessage[]		= "ShopID\tShopName\n";

static const char kMarketAddedMessage[]		= "\nMarket added!\n";
static const char kMarketRemovedMessage[]	= "\nMarket removed!\n";
static const char kMarketReplacesMessage[]	= "\nMarket replace!\n";
//  *****************************************************
//  *** Implementation of public methods of class
//  *****************************************************

Data::Data()
{
}

Data::~Data()
{
}

int Data::getShopsAmount() const
{
	return _shopsAmount;
}

void Data::addNewMarket(Market Market)
{
	_shops[_shopsAmount] = Market;
	_shopsAmount += 1;
#ifdef LOG_PRINT
	printf(kMarketAddedMessage);
#endif
}

void Data::removeMarketByNumber(int removedShopNumber)
{
	if (_shopsAmount < removedShopNumber || removedShopNumber < 0)
		return;

	for (int i = removedShopNumber; i < _shopsAmount; i++)
		_shops[i] = _shops[i+1];
	_shopsAmount -=1;
#ifdef LOG_PRINT
	printf(kMarketRemovedMessage);
#endif
}

void Data::removeMarketByName(StringType shopName)
{
	int index = 0;
	StringType currentShopName;
	do 
	{
		_shops[index].getShopName(currentShopName);
		index++;
		if (index > _shopsAmount)
		{
			index = 0;
			break;
		}
	} while (strcmp(currentShopName, shopName));
		
	removeMarketByNumber(--index);
}

void Data::replaceMarket(Market Market, int numberOfReplacedShop)
{
	_shops[numberOfReplacedShop] = Market;
#ifdef LOG_PRINT
	printf(kMarketReplacesMessage);
#endif
}

bool Data::findMarketByName(StringType shopName)
{
	bool exist = false;

	StringType compareShopName;
	TolowerString(shopName, compareShopName);
	
	StringType currentShopName;
	for (int i = 0; i < _shopsAmount; i++)
	{
		_shops[i].getShopName(currentShopName);
		TolowerString(currentShopName, currentShopName);

		if (!strcmp(currentShopName, compareShopName))
		{
			exist = true;
		}
	}
	return exist;
}

void Data::addProductByMarketNumber(Product product, int number)
{
	_shops[number].addProduct(product);
}

void Data::addProductByMarketName(Product product, StringType shopName)
{
	int index = 0;
	
	StringType compareShopName;
	TolowerString(shopName, compareShopName);

	StringType currentShopName;
	do 
	{
		_shops[index].getShopName(currentShopName);
		index++;
		TolowerString(currentShopName, currentShopName);		
	}
	while (strcmp(currentShopName, compareShopName));

	addProductByMarketNumber(product, --index);
}

void Data::addProductToAllMarkets(Product product)
{
	for (int i = 0; i < _shopsAmount; i++)
		addProductByMarketNumber(product, i);
}

void Data::removeProductByTitleFromMarketNumber(StringType productTitle, int number)
{
	if (_shopsAmount < number)
		return;
	_shops[number].removeProductByTitle(productTitle);
}

void Data::removeProductByTitleFromMarketName(StringType productTitle, StringType shopName)
{
	int index = 0;
	StringType compareShopName;
	TolowerString(shopName, compareShopName);

	StringType currentShopName;
	do 
	{
		_shops[index].getShopName(currentShopName);
		index++;
		TolowerString(currentShopName, currentShopName);
	}
	while (strcmp(currentShopName, compareShopName));

	removeProductByTitleFromMarketNumber(productTitle, --index);
}

void Data::removeProductByTitleFromAllMarkets(StringType productTitle)
{
	for (int i = 0; i < _shopsAmount; i++)
		removeProductByTitleFromMarketNumber(productTitle, i);
}

void Data::removeProductByPriceFromMarketNumber(int price, int number)
{
	_shops[number].removeProductByPrice(price);
}

void Data::removeProductByPriceFromMarketName(int price, StringType shopName)
{
	int index = 0;
	StringType compareShopName;
	TolowerString(shopName, compareShopName);

	StringType currentShopName;
	do 
	{
		_shops[index].getShopName(currentShopName);
		index++;
		TolowerString(currentShopName, currentShopName);
	}
	while (strcmp(currentShopName, compareShopName));

	removeProductByPriceFromMarketNumber(price, --index);
}

void Data::removeProductByPriceFromAllMarkets(int price)
{
	for (int i = 0; i < _shopsAmount; i++)
		removeProductByPriceFromMarketNumber(price, i);
}

void Data::removeProductByAmountFromMarketNumber(int amount, int number)
{
	_shops[number].removeProductByAmount(amount);
}

void Data::removeProductByAmountFromMarketName(int amount, StringType shopName)
{
	int index = 0;
	StringType compareShopName;
	TolowerString(shopName, compareShopName);

	StringType currentShopName;
	do 
	{
		_shops[index].getShopName(currentShopName);
		index++;
		TolowerString(currentShopName, currentShopName);
	}
	while (strcmp(currentShopName, compareShopName));

	removeProductByAmountFromMarketNumber(amount, --index);
}

void Data::removeProductByAmountFromAllMarkets(int amount)
{
	for (int i = 0; i < _shopsAmount; i++)
		removeProductByAmountFromMarketNumber(amount, i);
}

Market Data::getMarketByIndex(int index)
{
	return _shops[index];
}