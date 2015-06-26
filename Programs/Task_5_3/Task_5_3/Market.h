#ifndef MARKET_H
#define MARKET_H
#include "SupportTools.h"
#include "Product.h"

class Market
{
public:
	Market();
	~Market();

	void setShopName(const StringType shopName);
	void getShopName(StringType outputString) const;

	int getProductAmount() const;
	void setProductAmount(const int productAmount);

	void addProduct(Product Product);
	void removeProductByIndex(int index);
	void removeProductByTitle(StringType productTitle);
	void removeProductByPrice(int price);
	void removeProductByAmount(int amount);

	Product getProductByIndex(int index);
private:
	StringType _shopName;
	int _productAmount;
	Product _showcase[kMaxProductRange];
};

#endif