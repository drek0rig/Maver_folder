#ifndef MENU_SUPPORT_H
#define MENU_SUPPORT_H
#pragma once

#include "ProjectSupport.h"
#include "ShoppingStores.h"

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

class MenuSupport
{
public:
	MenuSupport();
	~MenuSupport();
	int runMenu();

private:
	void runFirstMainMenu();
	void runSecondMainMenu();
	void runShowInformationSubMenu();

	void createDataBaseRandomly();
	void createDataBaseManualy();

	void showCurrentMenuMessage() const;
	void showShoppingStoreList() const;
	void showProductsForOneStore();
	void showAllData() const;
	void showProdutcsForStoreIndex(StoreCountType index) const;

	void addOneStore();

	void removeOneStore();

	void runAddProductSubMenu();
	Product* getProductWithUserChoise();
	void addProductToAllStores();
	void addProductToOneStore();

	void removeProductSubMenu();
	void removeProductFromAllStores();
	void removeProductFromOneStore();

	bool isEnableMainMenuItem(int mainMenuItemType) const;
	bool getUserChoise(const int countOfAvailableUserCoises);
	StoreCountType getStoreIndexFromUserChoise();
	Store* inputStoreData();
	Product* inputUniqueProductDataForStore(Store* inStore);
	Product* inputUniqueProductDataForAllStores();
	char* inputProductName();
	ProductPriceType inputProductPrice() const;
	ProductAmountType inputProductAmount() const;

	int					_userChoise;
	ShoppingStores*		_shoppingStores;
	int					_currentMenuTag;
};

#endif