#include "MenuSupport.h"
#include <iostream>

using namespace std;

// ****************************************************************************
// ***  Local constants and types
// ****************************************************************************

typedef enum
{
	kFirstMainMenuTag			= 1,
	kSecondMainMenuTag			= 2,
	kShowInfomationSubMenuTag	= 3,
	kAddingProductSubMenuTag	= 4
} MenuTags;

typedef enum
{
	kCreateDataBaseRandomFirstMainMenuTypes		= 1,
	kCreateDataBaseManualyFirstMainMenuTypes	= 2,
	kCountOfFirstMainMenuTypes					= kCreateDataBaseManualyFirstMainMenuTypes
} FirstMainMenuTypes;

typedef enum
{
	kShowInformationSecondMainMenuTypes			= 1,
	kAddStoreSecondMainMenuTypes				= 2,
	kRemoveStoreSecondMainMenuTypes				= 3,
	kAddProductSecondMainMenuTypes				= 4,
	kRemoveProductSecondMainMenuTypes			= 5,
	kExitProgramSecondMainMenuTypes				= 6,
	kCountOfSecondMainMenuTypes					= kExitProgramSecondMainMenuTypes
} SecondMainMenuTypes;

typedef enum
{
	kShowListOfStoresSubMenuTypes				= 1,
	kShowProductsForStoreSubMenuTypes			= 2,
	kShowAllDataSubMenuTypes					= 3,
	kShowClearScreenSubMenuTypes				= 4,
	kShowPreviousMenuSubMenuTypes				= 5,
	kCountOfInformationSubMenuTypes				= kShowPreviousMenuSubMenuTypes
} InformationSubMenuTypes;

typedef enum
{
	kAddProductToAllStoresSubMenuTypes			= 1,
	kAddProductToOneStoreSubMenuTypes			= 2,
	kAddProductGoToPreviousSubMenuTypes			= 3,
	kCountOfAddProductSubMenuTypes				= kAddProductGoToPreviousSubMenuTypes
} AddProductSubMenuTypes;

static const char kInputSymbolMessage[]				= ">> ";
static const char kDisableStateSymbolMessage[]		= "-- ";
static const char kProductStringFormatMessage[]		= "        %i. pruct name - \"%s\"; price - %u; amount - %u;\n";
static const char kNoProductsStringMessage[]		= "        There is no products in current store\n";
static const char kInputStoreCountMessage[]			= "Input store count in store list (1-%i):\n";
static const char kInputStoreNameMessage[]			= "Input store name:\n";
static const char kInputStoreDataMessage[]			= "\nInput store data for index = %i:\n";

static const char kInputProductCountMessage[]		= "Input product count in store (1-%i):\n";
static const char kInputProductDataMessage[]		= "\nInput product data for index = %i:\n";
static const char kInputProductNameMessage[]		= "Input product name:\n";
static const char kInputProductPriceMessage[]		= "Input product price (>=1):\n";
static const char kInputProductAmountMessage[]		= "Input product amount (>=1):\n";

// Messages of first main menu
static const char kFirstMainMenuMessage[]			= "\nHow to create data base of shopping stores?\n"
													  "1. Random option;\n"
													  "2. Manualy option;\n";

// Messages of second main menu
static const char kSecondMainMenuTitleMessage[]		= "\nChoose option:\n";
static const char kShowInformationMessage[]			= "1. Show information ...\n";
static const char kAddStoreMainMenuMessage[]		= "2. Add store\n";
static const char kRemoveStoreMainMenuMessage[]		= "3. Remove store\n";
static const char kAddProductMainMenuMessage[]		= "4. Add product ...\n";
static const char kRemoveProductMainMenuMessage[]	= "5. Remove product\n";
static const char kExitProgramMessage[]				= "6. Exit\n";

// Messages of sub menu 1
static const char kShowInformationSubMenuMessage[]	= "\nChoose \"Show information ...\" option:\n"
													  "1. Show list for shopping stores;\n"
													  "2. Show products information for one store;\n"
													  "3. Show all data;\n"
													  "4. Clear screen;\n"
													  "5. Go back\n";
static const char kShowShoppingStoreListMessage[]	= "\n    Available shoping stores:\n";
static const char kShowProductsForStoreMessage[]	= "\nShow store information:\n"
													  "1. by number from list for shopping stores;\n"
													  "2. by name of store;\n";
static const char kInputNumberOfStoreMessage[]		= "Input number of store(1-%i): ";
static const char kInputNameOfStoreMessage[]		= "Input name of store:\n";

static const char kShowAllDataMessage[]				= "\nAll shoping stores data:\n";

// Messages of sub menu 2
static const char kAddStoreByOptionMessage[]		= "\nAdd one store:\n"
													  "1. Random option;\n"
													  "2. Manualy option;\n";
// Messages of sub menu 3
static const char kRemoveStoreByOptionMessage[]		= "\nRemove one store:\n"
													  "1. by number from list for shopping stores;\n"
													  "2. by name of store;\n";

// Messages of sub menu 4
static const char kAddProductSubMenuMessage[]		= "\nAdding product:\n"
													  "1. To all stores;\n"
													  "2. To one store;\n"
													  "3. Go back\n";

static const char kAddProductToOneStoreByOptionMessage[] =  "\nChoose one store for adding product:\n"
															"1. by number from list for shopping stores;\n"
															"2. by name of store;\n";

static const char kAddProductByOptionMessage[]		= "\nAdd one product:\n"
													  "1. Random option;\n"
													  "2. Manualy option;\n";

// Messages of sub menu 5
static const char kRemoveProductSubMenuMessage[]	= "\nRemoving product:\n"
													  "1. From all stores;\n"
													  "2. From one store;\n";

static const char kRemoveProductFromOneStoreByOptionMessage[] = "\nChoose one store in which will be removed product:\n"
																"1. by number from list for shopping stores;\n"
																"2. by name of store;\n";

static const char kRemoveProductByOptionMessage[]	= "\nRemoving product:\n"
													  "1. by name;\n"
													  "2. by price;\n"
													  "3. by amount;\n";

// Messages of sub menu 6
static const char kConfirmExitMessage[]				= "Are you sure?\n";

// Error messages
static const char kDisabledItemChoosedErrorMessage[]			= "This option is unavailable now!\n";
static const char kEnterCorretChoiseValueErrorMessage[]			= "Please enter corret choise value!\n";
static const char kIncorrectRangeValueErrorMessage[]			= "You should input value in range (1-%i)!\n";
static const char kEnterCorretIntValueErrorMessage[]			= "Please enter an integer value!\n";
static const char kThereIsNoSeachableStoreMessage[]				= "There is no searchable store for input value \"%s\"!\n";
static const char kWrongProductPriceErrorMessage[]				= "You should input product price >=1!\n";
static const char kWrongProductAmountErrorMessage[]				= "You should input product amount >=1!\n";
static const char kWrongProductNameErrorMessage[]				= "You can not use this name for a product. Try input again!\n";
static const char kThisNameOfStoreIsUsedErrorMessage[]			= "You can not use this name for a store. This name of store is used. Try input again!\n";

// ****************************************************************************
// ***  Interface of local fuctions
// ****************************************************************************

bool MakeCheckForNumberInputFromCin();

// ****************************************************************************
// ***  Implementation of public methods of class
// ****************************************************************************

MenuSupport::MenuSupport()
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("MenuSupport::MenuSupport() - called\n");
#endif
    SetupRandomFunctionality();
}

MenuSupport::~MenuSupport()
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("MenuSupport::~MenuSupport() - called\n");
#endif
}

int MenuSupport::runMenu()
{
	runFirstMainMenu();
	runSecondMainMenu();
	return 0;
}

// ****************************************************************************
// ***  Implementation of private methods of class
// ****************************************************************************

void MenuSupport::runFirstMainMenu()
{
	_currentMenuTag = kFirstMainMenuTag;
	bool canStop = false;
	while (!canStop)
	{
		showCurrentMenuMessage();
		canStop = getUserChoise(kCountOfFirstMainMenuTypes);
	}

	switch (_userChoise)
	{
		case kCreateDataBaseRandomFirstMainMenuTypes:
		{
			createDataBaseRandomly();
			break;
		}
		case kCreateDataBaseManualyFirstMainMenuTypes:
		{
			createDataBaseManualy();
			break;
		}
		default:
			break;
	}
}

void MenuSupport::runSecondMainMenu()
{
	_currentMenuTag = kSecondMainMenuTag;
	bool canExit = false;
	while (!canExit)
	{
		showCurrentMenuMessage();
		if (!getUserChoise(kCountOfSecondMainMenuTypes))
			continue;

		if (!isEnableMainMenuItem(_userChoise))
		{
			printf(kDisabledItemChoosedErrorMessage);
			continue;
		}

		switch (_userChoise)
		{
			case kShowInformationSecondMainMenuTypes:
			{
				runShowInformationSubMenu();
				_currentMenuTag = kSecondMainMenuTag;
				break;
			}
			case kAddStoreSecondMainMenuTypes:
			{
				addOneStore();
				break;
			}
			case kRemoveStoreSecondMainMenuTypes:
			{
				removeOneStore();
				break;
			}
			case kAddProductSecondMainMenuTypes:
			{
				runAddProductSubMenu();
				_currentMenuTag = kSecondMainMenuTag;
				break;
			}
			case kRemoveProductSecondMainMenuTypes:
			{
				removeProductSubMenu();
				break;
			}
			case kExitProgramSecondMainMenuTypes:
			{
				printf(kConfirmExitMessage);
				printf(kInputSymbolMessage);
				StringType answerString;
				gets_s(answerString);

				MakeStingLowerCase(answerString);
				
				if (strcmp(answerString, "y") == 0 || strcmp(answerString, "yes") == 0)
					canExit = true;

				break;
			}
			default:
				break;
		}
	}
}

void MenuSupport::runShowInformationSubMenu()
{
	_currentMenuTag = kShowInfomationSubMenuTag;
	bool canStop = false;
	while (!canStop)
	{
		showCurrentMenuMessage();
		if (!getUserChoise(kCountOfInformationSubMenuTypes))
			continue;

		switch (_userChoise)
		{
			case kShowListOfStoresSubMenuTypes:
			{
				showShoppingStoreList();
				break;
			}
			case kShowProductsForStoreSubMenuTypes:
			{
				showProductsForOneStore();
				break;
			}
			case kShowAllDataSubMenuTypes:
			{
				showAllData();
				break;
			}
			case kShowClearScreenSubMenuTypes:
			{
				system("cls");
				break;
			}
			case kShowPreviousMenuSubMenuTypes:
			{
				canStop = true;
				break;
			}
			default:
				break;
		}
	}
}

void MenuSupport::createDataBaseRandomly()
{
	int storeCount = rand() % (kMaxRandomValueForCountOfStores - kMinRandomValueForCountOfStores + 1);
	storeCount += kMinRandomValueForCountOfStores;
	for (int i = 0; i < storeCount; i++)
	{
		_shoppingStores.addStore(_shoppingStores.getRandomStore());
	}
}

void MenuSupport::createDataBaseManualy()
{
	while (true)
	{
		printf(kInputStoreCountMessage, kMaxStoreCount);
		printf(kInputSymbolMessage);
		StoreCountType storeCount;
		cin >> storeCount;
		if (!MakeCheckForNumberInputFromCin())
		{
			continue;
		}
		if (storeCount <= 0 || storeCount > kMaxStoreCount)
		{
			printf(kIncorrectRangeValueErrorMessage, kMaxStoreCount);
			continue;
		}

		for (StoreCountType i = 0; i < storeCount; i++)
		{
			printf(kInputStoreDataMessage, i + 1);
			_shoppingStores.addStore(inputStoreData());
		}

		break;
	}
}

void MenuSupport::showCurrentMenuMessage() const
{
	switch (_currentMenuTag)
	{
		case kFirstMainMenuTag:
		{
			printf(kFirstMainMenuMessage);
			break;
		}
		case kSecondMainMenuTag:
		{
			printf(kSecondMainMenuTitleMessage);
			if (!isEnableMainMenuItem(kShowInformationSecondMainMenuTypes))
				printf(kDisableStateSymbolMessage);
			printf(kShowInformationMessage);

			if (!isEnableMainMenuItem(kAddStoreSecondMainMenuTypes))
				printf(kDisableStateSymbolMessage);
			printf(kAddStoreMainMenuMessage);

			if (!isEnableMainMenuItem(kRemoveStoreSecondMainMenuTypes))
				printf(kDisableStateSymbolMessage);
			printf(kRemoveStoreMainMenuMessage);

			if (!isEnableMainMenuItem(kAddProductSecondMainMenuTypes))
				printf(kDisableStateSymbolMessage);
			printf(kAddProductMainMenuMessage);

			if (!isEnableMainMenuItem(kRemoveProductSecondMainMenuTypes))
				printf(kDisableStateSymbolMessage);
			printf(kRemoveProductMainMenuMessage);
			printf(kExitProgramMessage);
			break;
		}
		case kShowInfomationSubMenuTag:
		{
			printf(kShowInformationSubMenuMessage);
			break;
		}
		case kAddingProductSubMenuTag:
		{
			printf(kAddProductSubMenuMessage);
			break;
		}
		default:
			break;
	}

	printf(kInputSymbolMessage);
}

void MenuSupport::showShoppingStoreList() const
{
	printf(kShowShoppingStoreListMessage);
	StoreCountType storeCount = _shoppingStores.getStoreCount();
	for (StoreCountType i = 0; i < storeCount; i++)
	{
		StringType storeName = "";
		_shoppingStores.getStoreAtIndex(i).getStoreName(storeName);
		printf("        %i. %s\n", i + 1, storeName);
	}
}

void MenuSupport::showProductsForOneStore()
{
	printf(kShowProductsForStoreMessage);
	printf(kInputSymbolMessage);

	StoreCountType storeIndex = getStoreIndexFromUserChoise();
	if (kUndefinedStoreIndex != storeIndex)
		showProdutcsForStoreIndex(storeIndex);
}

void MenuSupport::showAllData() const
{
	printf(kShowAllDataMessage);
	for (StoreCountType i = 0; i < _shoppingStores.getStoreCount(); i++)
		showProdutcsForStoreIndex(i);
}

void MenuSupport::showProdutcsForStoreIndex(StoreCountType index) const
{
	if (_shoppingStores.getStoreCount() <= index)
		return;
	Store store = _shoppingStores.getStoreAtIndex(index);
	StringType string = "";
	store.getStoreName(string);
	printf("    %s:\n", string);

	ProductCountInStoreType productCount = store.getProductCount();
	if (0 == productCount)
		printf(kNoProductsStringMessage);
	for (ProductCountInStoreType i = 0; i < productCount; i++)
	{
		Product product = store.getProductAtIndex(i);
		product.getProductName(string);
		printf(kProductStringFormatMessage, i + 1, string, product.getProductPrice(), product.getProductAmount());
	}
}

void MenuSupport::addOneStore()
{
	printf(kAddStoreByOptionMessage);
	printf(kInputSymbolMessage);
	if (!getUserChoise(2))
		return;

	if (1 == _userChoise)
	{
		_shoppingStores.addStore(_shoppingStores.getRandomStore());
	}
	else if (2 == _userChoise)
	{
		_shoppingStores.addStore(inputStoreData());
	}
}

void MenuSupport::removeOneStore()
{
	printf(kRemoveStoreByOptionMessage);
	printf(kInputSymbolMessage);

	StoreCountType storeIndex = getStoreIndexFromUserChoise();
	if (kUndefinedStoreIndex != storeIndex)
		_shoppingStores.removeStoreAtIndex(storeIndex);
}

void MenuSupport::runAddProductSubMenu()
{
	_currentMenuTag = kAddingProductSubMenuTag;
	bool canStop = false;
	while (!canStop)
	{
		showCurrentMenuMessage();
		if (!getUserChoise(kCountOfAddProductSubMenuTypes))
			continue;

		switch (_userChoise)
		{
			case kAddProductToAllStoresSubMenuTypes:
			{
				addProductToAllStores();
				break;
			}
			case kAddProductToOneStoreSubMenuTypes:
			{
				addProductToOneStore();
				break;
			}
			case kAddProductGoToPreviousSubMenuTypes:
			{
				canStop = true;
				break;
			}
			default:
				break;
		}
	}
}

Product MenuSupport::getProductWithUserChoise()
{
	Product result;
	printf(kAddProductByOptionMessage);
	printf(kInputSymbolMessage);
	if (!getUserChoise(2))
		return result;

	if (1 == _userChoise)
	{
		result = _shoppingStores.getRandomProduct();
	}
	else if (2 == _userChoise)
	{
		result = inputUniqueProductDataForAllStores();
	}
	return result;
}

void MenuSupport::addProductToAllStores()
{
	Product localProduct = getProductWithUserChoise();
	StringType productName = "";
	localProduct.getProductName(productName);
	if (0 == strcmp(productName, ""))
		return;

	StoreCountType storeCount = _shoppingStores.getStoreCount();
	for (StoreCountType i = 0; i < storeCount; i++)
	{
		Store store = _shoppingStores.getStoreAtIndex(i);
		store.addProduct(localProduct);
		_shoppingStores.replaceStoreAtIndex(store, i);
	}
}

void MenuSupport::addProductToOneStore()
{
	printf(kAddProductToOneStoreByOptionMessage);
	printf(kInputSymbolMessage);
	StoreCountType storeIndex = getStoreIndexFromUserChoise();
	if (kUndefinedStoreIndex == storeIndex)
		return;

	Product localProduct = getProductWithUserChoise();
	StringType productName = "";
	localProduct.getProductName(productName);
	if (0 == strcmp(productName, ""))
		return;

	Store store = _shoppingStores.getStoreAtIndex(storeIndex);
	store.addProduct(localProduct);
	_shoppingStores.replaceStoreAtIndex(store, storeIndex);
}

void MenuSupport::removeProductSubMenu()
{
	printf(kRemoveProductSubMenuMessage);
	printf(kInputSymbolMessage);
	if (!getUserChoise(2))
		return;

	if (1 == _userChoise)
	{
		removeProductFromAllStores();
	}
	else if (2 == _userChoise)
	{
		removeProductFromOneStore();
	}
}

void MenuSupport::removeProductFromAllStores()
{
	printf(kRemoveProductByOptionMessage);
	printf(kInputSymbolMessage);
	if (!getUserChoise(3))
		return;

	if (1 == _userChoise)
	{
		StringType productName = "";
		inputProductName(productName);
		StoreCountType storeCount = _shoppingStores.getStoreCount();
		for (StoreCountType i = 0; i < storeCount; i++)
		{
			Store store = _shoppingStores.getStoreAtIndex(i);
			ProductCountInStoreType productIndex = kUndefinedProductIndex;
			while (kUndefinedProductIndex != (productIndex = store.getProductIndexByName(productName)))
			{
				store.removeProductAtIndex(productIndex);
			}

			_shoppingStores.replaceStoreAtIndex(store, i);
		}
	}
	else if (2 == _userChoise)
	{
		ProductPriceType productPrice = inputProductPrice();
		StoreCountType storeCount = _shoppingStores.getStoreCount();
		for (StoreCountType i = 0; i < storeCount; i++)
		{
			Store store = _shoppingStores.getStoreAtIndex(i);
			ProductCountInStoreType productIndex = kUndefinedProductIndex;
			while (kUndefinedProductIndex != (productIndex = store.getProductIndexByPrice(productPrice)))
			{
				store.removeProductAtIndex(productIndex);
			}

			_shoppingStores.replaceStoreAtIndex(store, i);
		}
	}
	else if (3 == _userChoise)
	{
		ProductAmountType productAmount = inputProductAmount();
		StoreCountType storeCount = _shoppingStores.getStoreCount();
		for (StoreCountType i = 0; i < storeCount; i++)
		{
			Store store = _shoppingStores.getStoreAtIndex(i);
			ProductCountInStoreType productIndex = kUndefinedProductIndex;
			while (kUndefinedProductIndex != (productIndex = store.getProductIndexByAmount(productAmount)))
			{
				store.removeProductAtIndex(productIndex);
			}

			_shoppingStores.replaceStoreAtIndex(store, i);
		}
	}
}

void MenuSupport::removeProductFromOneStore()
{
	printf(kRemoveProductFromOneStoreByOptionMessage);
	printf(kInputSymbolMessage);
	StoreCountType storeIndex = getStoreIndexFromUserChoise();
	if (kUndefinedStoreIndex == storeIndex)
		return;

	printf(kRemoveProductByOptionMessage);
	printf(kInputSymbolMessage);
	if (!getUserChoise(3))
		return;

	Store store = _shoppingStores.getStoreAtIndex(storeIndex);
	if (1 == _userChoise)
	{
		StringType productName = "";
		inputProductName(productName);
		ProductCountInStoreType productIndex = kUndefinedProductIndex;
		while (kUndefinedProductIndex != (productIndex = store.getProductIndexByName(productName)))
		{
			store.removeProductAtIndex(productIndex);
		}
	}
	else if (2 == _userChoise)
	{
		ProductPriceType productPrice = inputProductPrice();
		ProductCountInStoreType productIndex = kUndefinedProductIndex;
		while (kUndefinedProductIndex != (productIndex = store.getProductIndexByPrice(productPrice)))
		{
			store.removeProductAtIndex(productIndex);
		}
	}
	else if (3 == _userChoise)
	{
		ProductAmountType productAmount = inputProductAmount();
		ProductCountInStoreType productIndex = kUndefinedProductIndex;
		while (kUndefinedProductIndex != (productIndex = store.getProductIndexByAmount(productAmount)))
		{
			store.removeProductAtIndex(productIndex);
		}
	}
	_shoppingStores.replaceStoreAtIndex(store, storeIndex);
}

bool MenuSupport::isEnableMainMenuItem(int mainMenuItemType) const
{
	bool result = true;
	switch (mainMenuItemType)
	{
		case kShowInformationSecondMainMenuTypes:
		case kRemoveProductSecondMainMenuTypes:
		case kRemoveStoreSecondMainMenuTypes:
		case kAddProductSecondMainMenuTypes:
		{
			result = _shoppingStores.getStoreCount() != 0;
			break;
		}
		case kAddStoreSecondMainMenuTypes:
		{
			result = _shoppingStores.getStoreCount() < kMaxStoreCount;
			break;
		}
		default:
			break;
	}

	return result;
}

bool MenuSupport::getUserChoise(const int countOfAvailableUserCoises)
{
	cin >> _userChoise;
	bool result = MakeCheckForNumberInputFromCin();
	if (!result)
	{
		printf(kEnterCorretChoiseValueErrorMessage);
	}
	else if (_userChoise <= 0 || _userChoise > countOfAvailableUserCoises)
	{
		printf(kIncorrectRangeValueErrorMessage, countOfAvailableUserCoises);
		result = false;
	}
	return result;
}

StoreCountType MenuSupport::getStoreIndexFromUserChoise()
{
	StoreCountType result = kUndefinedStoreIndex;
	if (!getUserChoise(2))
			return result;

	if (1 == _userChoise)
	{
		StoreCountType storeCount = _shoppingStores.getStoreCount();
		printf(kInputNumberOfStoreMessage, storeCount);
		StoreCountType storeIndex = 0;
		cin >> storeIndex;
		bool isCorrect = MakeCheckForNumberInputFromCin();
		if (!isCorrect)
		{
			printf(kEnterCorretIntValueErrorMessage);
			return result;
		}
		if (storeIndex <= 0 || storeIndex > storeCount)
		{
			printf(kIncorrectRangeValueErrorMessage, storeCount);
			return result;
		}

		result = --storeIndex;
	}
	else if (2 == _userChoise)
	{
		printf(kInputNameOfStoreMessage);
		printf(kInputSymbolMessage);

		StringType inputName = "";
		gets_s(inputName);

		result = _shoppingStores.getStoreIndexByName(inputName);
		if (kUndefinedStoreIndex == result)
			printf(kThereIsNoSeachableStoreMessage, inputName);
	}
	return result;
}

Store MenuSupport::inputStoreData()
{
	Store localStore;
	StringType storeName = "";

	bool canStop = false;
	while (!canStop)
	{
		printf(kInputStoreNameMessage);
		printf(kInputSymbolMessage);
		gets_s(storeName);
		if (!_shoppingStores.canAddStoreWithName(storeName))
		{
			printf(kThisNameOfStoreIsUsedErrorMessage);
			continue;
		}
		localStore.setStoreName(storeName);
		canStop = true;
	}

	canStop = false;
	while (!canStop)
	{
		printf(kInputProductCountMessage, kMaxCountOfProductInStore);
		printf(kInputSymbolMessage);
		ProductCountInStoreType productCount;
		cin >> productCount;
		if (!MakeCheckForNumberInputFromCin())
		{
			continue;
		}
		if (productCount <= 0 || productCount > kMaxCountOfProductInStore)
		{
			printf(kIncorrectRangeValueErrorMessage, kMaxCountOfProductInStore);
			continue;
		}

		for (ProductCountInStoreType i = 0; i < productCount; i++)
		{
			printf(kInputProductDataMessage, i + 1);
			localStore.addProduct(inputUniqueProductDataForStore(localStore));
		}

		canStop = true;
	}
	return localStore;
}

Product MenuSupport::inputUniqueProductDataForStore(Store inStore)
{
	Product localProduct;
	StringType productName = "";
	while (true)
	{
		inputProductName(productName);
		if (!inStore.canAddProductWithName(productName))
		{
			printf(kWrongProductNameErrorMessage);
			continue;
		}
		break;
	}
	localProduct.setProductName(productName);
	
	localProduct.setProductPrice(inputProductPrice());

	localProduct.setProductAmount(inputProductAmount());

	return localProduct;
}

Product MenuSupport::inputUniqueProductDataForAllStores()
{
	Product localProduct;
	StringType productName = "";
	while (true)
	{
		inputProductName(productName);
		StoreCountType storeCount = _shoppingStores.getStoreCount();
		bool canAddProduct = true;
		for (StoreCountType i = 0; i < storeCount; i++)
		{
			if (!_shoppingStores.getStoreAtIndex(i).canAddProductWithName(productName))
			{
				canAddProduct = false;
				break;
			}
		}
		if (!canAddProduct)
		{
			printf(kWrongProductNameErrorMessage);
			continue;
		}
		break;
	}
	localProduct.setProductName(productName);
	
	localProduct.setProductPrice(inputProductPrice());

	localProduct.setProductAmount(inputProductAmount());
	return localProduct;
}

void MenuSupport::inputProductName(StringType outProductName)
{
	printf(kInputProductNameMessage);
	printf(kInputSymbolMessage);

	StringType productName = "";
	gets_s(productName);
	strcpy(outProductName, productName);
}

ProductPriceType MenuSupport::inputProductPrice() const
{
	ProductPriceType productPrice;
	while (true)
	{
		printf(kInputProductPriceMessage);
		printf(kInputSymbolMessage);
		cin >> productPrice;
		if (!MakeCheckForNumberInputFromCin())
		{
			continue;
		}
		if (productPrice < 1)
		{
			printf(kWrongProductPriceErrorMessage);
			continue;
		}

		break;
	}
	return productPrice;
}

ProductAmountType MenuSupport::inputProductAmount() const
{
	ProductAmountType productAmount;
	while (true)
	{
		printf(kInputProductAmountMessage);
		printf(kInputSymbolMessage);
		cin >> productAmount;
		if (!MakeCheckForNumberInputFromCin())
		{
			continue;
		}
		if (productAmount < 1)
		{
			printf(kWrongProductAmountErrorMessage);
			continue;
		}

		break;
	}
	return productAmount;
}

// ****************************************************************************
// ***  Implementation of local fuctions
// ****************************************************************************

bool MakeCheckForNumberInputFromCin()
{
	bool result = false;
	if (!cin.fail())
	{
		// If we type next '20sdfgsdsefg' string,
		// we need clear buffer that contain value after '20'
		cin.sync(); 
		result = true; // It's a normal value
	}
	else 
	{
		// Here we input something like that 'sdfgdsf20.5dsf'
		cin.clear(); // remove error flags
		cin.ignore();
		cin.sync(); 
	}
	return result;
}
