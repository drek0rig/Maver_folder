#ifndef DATA_CLASS_H
#define DATA_CLASS_H
#include "Market.h"
#include "SupportTools.h"

class Data
{
public:
	// Primary methods
	Data();
	~Data();

	int getShopsAmount() const;
	
	// Methods for Markets contraction
	void addNewMarket(Market Market);
	void removeMarketByNumber(int removedShopNumber);
	void removeMarketByName(StringType shopName);
	void replaceMarket(Market Market, int numberOfReplacedShop);

	// Methods for Product constraction
	void addProductByMarketNumber(Product product, int number);
	void addProductByMarketName(Product product, StringType shopName);
	void addProductToAllMarkets(Product product);
	void removeProductByTitleFromMarketNumber(StringType productTitle, int number);
	void removeProductByTitleFromMarketName(StringType productTitle, StringType shopName);
	void removeProductByTitleFromAllMarkets(StringType productTitle);
	void removeProductByPriceFromMarketNumber(int price, int number);
	void removeProductByPriceFromMarketName(int price, StringType shopName);
	void removeProductByPriceFromAllMarkets(int price);
	void removeProductByAmountFromMarketNumber(int amount, int number);
	void removeProductByAmountFromMarketName(int amount, StringType shopName);
	void removeProductByAmountFromAllMarkets(int amount);

	// Support methods
	bool findMarketByName(StringType shopName);

	Market getMarketByIndex(int index);
private:
	int _shopsAmount;
	Market _shops[kMaxShopRange];
};

#endif