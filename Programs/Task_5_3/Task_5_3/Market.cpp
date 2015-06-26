#include "Market.h"
#include <cstring>

// #define LOG_PRINT

static const char kMarketMessage[]				= " market %s.\n";
static const char kListOfProductMessage[]		= "List of products.\n";
static const char kHeadProductStringMessage[]	= "Shop Title\tPrise\tAmount\n";

static const char kProductAddedMessage[]		= "\nProduct added!\n";
static const char kProductRemovedMessage[]		= "\nProduct removed!\n";

//  *****************************************************
//  *** Implementation of public methods of class
//  *****************************************************

Market::Market()
{
	_shopName[0] = '\0';
	_productAmount = 0;
}

Market::~Market()
{
}

void Market::setShopName(const StringType shopName)
{
	strcpy(_shopName, shopName);
}

void Market::getShopName(StringType outputString) const
{
	strcpy(outputString, _shopName);
}

void Market::setProductAmount(const int productAmount)
{
	_productAmount = productAmount;
}

int Market::getProductAmount() const
{
	return _productAmount;
}

void Market::addProduct(Product Product)
{
	_showcase[_productAmount] = Product;
	_productAmount += 1;
	printf(kProductAddedMessage);
}

void Market::removeProductByIndex(int index)
{
	if (index > _productAmount )
		return;

	for (int i = index; i < _productAmount; i++)
		_showcase[i] = _showcase[i+1];
	_productAmount -= 1;
#ifdef LOG_PRINT
	printf(kProductRemovedMessage);
#endif
}

void Market::removeProductByTitle(StringType productTitle)
{
	int index = 0;
	StringType currentProductTitle;
	do { 
	_showcase[index].getTitle(currentProductTitle);
	index++;
	if (index > _productAmount)
	{
		index = 0;
		break;
	}	
	} while (strcmp(currentProductTitle, productTitle));

	if (index != 0)
		removeProductByIndex(--index);
}

void Market::removeProductByPrice(int price)
{
	int index = -1;
	for (int i = 0; i < _productAmount; i++)
	{
		if (price == _showcase[i].getPrice())
			index = i;
			break;
	}

	if (index != -1)
		removeProductByIndex(index);
}

void Market::removeProductByAmount(int amount)
{
	int index = -1;
	for (int i = 0; i < _productAmount; i++)
	{
		if (amount == _showcase[i].getAmount())
			index = i;
			break;
	}

	if (index != -1)
		removeProductByIndex(index);
}

Product Market::getProductByIndex(int index)
{
	return _showcase[index];
}