#include "MarketMenu.h"
#include "Product.h"
#include "DataClass.h"
#include "SupportTools.h"
#include <iostream>

using namespace std;

// ****************************************************
// ***  Locale constants and types
// ****************************************************

static const char kInputSymbolMessage[]							= ">> ";
static const char kDisableStateSymbolMessage[]					= "-- ";

// Messages of market creation menu
static const char kCreationMenuMessage[]						= "*** Creation Menu ***";
static const char kChaineStoresRandomlyCreationMessage[]		= "\n1. Create chaine store randomly.\n";
static const char kChaineStoresManuallyCreationMessage[]		= "2. Create chaine store manually.\n";

// Messages of manage menu
static const char kManageMenu[]									= "*** Manage Menu ***\n";
static const char kIformationShowMessage[]						= "1. Show an information.\n";
static const char kMarketAddMessage[]							= "2. Add a new market.\n";
static const char kMarketRemoveMessage[]						= "3. Remove market.\n";
static const char kProductAddMessage[]							= "4. Add a new product.\n";
static const char kProductRemoveMessage[]						= "5. Remove product.\n";
static const char kClearManageMenuMessage[]						= "6. Clear the screan.\n";
static const char kExitProgramMessage[]							= "7. Exit from program.\n";

static const char kExitConfirmationMessage[]					= "\nA you sure?\n";

// Messages of submenu manage menu 1
static const char kMarketListMessage[]							= "1. Show market list.\n";
static const char kProductInformationForSpesificMarketMessage[]	= "2. Information about products for spesific market.\n";
static const char kAllDataMessage[]								= "3. All data.\n";
static const char kClearSubmenuManageMenu1Message[]				= "4. Clear the screan.\n";
static const char kBackSubmenuManageMenu1Message[]				= "5. Back.\n";

static const char kEnterNumberOfShopMessage[]					= "\n Enter number of the shop from the list above.\n";
static const char kEnterShopNameMessage[]						= "\n Enter shop name from the list above.\n";

// Messages of submenu manage menu 4
static const char kToAllExistingMarketsMessage[]				= "1. To all existing markets.\n";
static const char kToCertainMarketMessage[]						= "2. To certaine market.\n";
static const char kBackSubmenuManageMenu4Message[]				= "3. Back.\n";

// Messages of submenu manage menu 5
static const char kFromAllExistingMarketsMessage[]				= "1. From all existing markets.\n";
static const char kFromCertainMarketMessage[]					= "2. From certaine market.\n";

static const char kRemoveByProductTitleMessage[]				= "1. Remove by product title.\n";
static const char kRemoveByProductPriceMessage[]				= "2. Remove by price.\n";
static const char kRemoveByProductAmountMessage[]				= "3. Remove by amount.\n";

static const char kEnterProductTitleMessage[]					= "Enter a title of product will removed.\n";
static const char kEnterProductPriceMessage[]					= "Enter a price of product will removed.\n";
static const char kEnterProductAmountMessage[]					= "Enter a amount of product will removed.\n";

// Universal submenu messages
static const char kRandomMessage[]								= "1. Randomly.\n";
static const char kManualMessage[]								= "2. Manually.\n";

static const char kByNumderFromMarketListMessage[]				= "1. By number from list of markets.\n";
static const char kByShopNameMessage[]							= "2. By name of a market.\n";

// Class creation messages
static const char kShopAmountEnterMessage[]						= "\nEnter amount of shops (1-%d)";
static const char kCreateShopMessage[]							= "\nCreate %d shop in chaine store.\n";
static const char kShopNameEnterMessage[]						= "\nEnter shop name";
static const char kShopNameAlreadyExistMessage[]				= "\nSach shop name already exist. Please, enter othe shop name.";
static const char kProductAmountEnterMessage[]					= "\nEnter amount of products in this shop (1-%d)";
static const char kCreateProductMessage[]						= "\nCreate %d product in shop.\n";
static const char kProductTitleEnterMessage[]					= "\nEnter product title";
static const char kEnterPriceMessage[]							= "\nEnter price of this product";
static const char kEnterAmountMessage[]							= "\nEnter amount of this product";

// Messages for printing markets and products
static const char kMarketMessage[]								= "%d market %s.\n";
static const char kListOfProductMessage[]						= "List of products.\n";
static const char kHeadProductStringMessage[]					= "Shop Title\tPrise\tAmount\n";

// Error messages
static const char kEnterCorrectChoiseValueErrorMessage[]	= "\nPlease, enter correct choise value.\n";
static const char kNoCorrespondingOptionErrorMessage[]		= "\nThere is no corresponding option for you choise.\n";
static const char kEnterCorrectValueErrorMessage[]			= "\nPlease, enter correct value.\n";
static const char kEntarValueInRange[]						= "\nEnter value in range between 1 and %d.\n";
static const char kSuchShopNotExist[]						= "\nSuch shop name is not exist.\n";

typedef enum
{
	kRandomlyCreationChoiseType		= 1,
	kManuallyCreationChoiseType		= 2
} MarketCreationMenuChoiseType;

typedef enum
{
	kShowInformationChoiseType		= 1,
	kAddMarketChoiseType			= 2,
	kRemoveMarketChoiseType			= 3,
	kAddProductChoiseType			= 4,
	kRemoveProductChoiseType		= 5,
	kClearSreanChoiseType			= 6,
	kExitProgramChoiseType			= 7
} ManageMenuChoiseType;

typedef enum
{
	kShowMarketListChoiseType						= 1,
	kProductInformationForSpesificMarketChoiseType	= 2,
	kAllDataChoiseType								= 3,
	kClearSubmenuManageMenu1ChoiseType				= 4,
	kBackSubmenuManageMenu1ChoiseType				= 5
} SubmenuManageMenu1ChoiseType;

typedef enum
{
	kToAllExistingMarketsChoiseType					= 1,
	kToCertainMarketChoiseType						= 2,
	kBackSubmenuManageMenu4ChoiseType				= 3
} SubmenuManageMenu4ChoiseType;

typedef enum
{
	kFromAllExistingMarketsChoiseType				= 1,
	kFromCertainMarketChoiseType					= 2	
} SubmenuManageMenu5ChoiseType;

typedef enum
{
	kRemoveByProductTitleChoiseType					= 1,
	kRemoveByProductPriceChoiseType					= 2,
	kRemoveByProductAmountChoiseType				= 3
} DoubleSubmenuFiveChoiseType;
typedef enum
{
	kRandomChoiseType			= 1,
	kManualChoiseType			= 2
} RandomOrManualChoiseType;

typedef enum
{
	kNumberOfMarketChoiseType	= 1,
	kNameOfMarketChoiseType		= 2
} NumberOrNameMarketChoiseType;

typedef enum
{
	kMarketCreationMenuPrint		= 9,
	kManageMenuPrint				= 1,
	kSubmenuManageMenu1Print		= 11,
	kSubmenuManageMenu4Print		= 14,
	kSubmenuManageMenu5Print		= 15,
	kDoubleSubmenuFivePrint			= 151,
	kRandomOrManualMenuPrint		= 81,
	kNumberOrNameMarketMenuPrint	= 82
} PrintMenusChoiseType;

StringType ArrayForRandomProductTitle[matrixSize] = {"Kartoshka", "Bananu", "Limon", "Fanera", "Kurka", "Yabluko"};
StringType ArrayForRandomMarketNames[matrixSize] = {"Silpo", "ATB", "Furshet", "Ashan", "Billa", "Fora"};

// ****************************************************
// *** Interface of functions
// ****************************************************

void PrintMenu(PrintMenusChoiseType currentMenu);
bool MakeCheckForNumberInputFromCin(const char inErrorMessage[]);

void PrintMarketList(Data data);
void PrintMarketInfoByIndex(Data data, int index);
void PrintMarketInfoByName(Data data, StringType shopName);

Product DefaultProduct(StringType Array[matrixSize]);
Market DefaultMarket(Data data, StringType Array[matrixSize]);
Data DefaultData();

Data CreateNewData();
Market CreateNewShop(Data data);
Product CreateNewProduct();

// ****************************************************
// *** Implamentation of functions
// ****************************************************

int MarketMenu()
{
	bool exitMarketCreation = false;
		
	Data data;
	
	while (!exitMarketCreation)
	{
		PrintMenu(kMarketCreationMenuPrint);
		int currentChoise;

		cin >> currentChoise;
		if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
			continue;
		
		if (currentChoise != kRandomlyCreationChoiseType && currentChoise != kManuallyCreationChoiseType)
		{
			printf(kNoCorrespondingOptionErrorMessage);
			continue;
		}

		if (currentChoise == kRandomlyCreationChoiseType)
		{
			data = DefaultData();
			exitMarketCreation = true;
		}
		else
		{
			data = CreateNewData();
			exitMarketCreation = true;
		}		
	}

	bool isExit = false;
	while(!isExit)
	{
		PrintMenu(kManageMenuPrint);
		int currentChoise;

		cin >> currentChoise;
		if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
			continue;

		if(1 > currentChoise || 7 < currentChoise)
		{
			printf(kNoCorrespondingOptionErrorMessage);
			continue;
		}

		switch (currentChoise)
		{
		case kShowInformationChoiseType:
			{
				bool isSubmenuExit = false;

				while(!isSubmenuExit)
				{
					PrintMenu(kSubmenuManageMenu1Print);
					int submenuChoise;

					cin >> submenuChoise;
					if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
						continue;

					if (kShowMarketListChoiseType > submenuChoise || kBackSubmenuManageMenu1ChoiseType < submenuChoise)
					{
						printf(kNoCorrespondingOptionErrorMessage);
						continue;
					}

					switch (submenuChoise)
					{
					case kShowMarketListChoiseType:
						{
							PrintMarketList(data);
							break;
						}
					case kProductInformationForSpesificMarketChoiseType:
						{
							PrintMenu(kNumberOrNameMarketMenuPrint);
							int currentChoise;

							cin >> currentChoise;
							if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
								break;

							if (1 > currentChoise || 2 < currentChoise)
							{
								printf(kNoCorrespondingOptionErrorMessage);
								break;
							}

							if (currentChoise == kNumberOfMarketChoiseType)
							{
								printf(kEnterNumberOfShopMessage);
								int currentNumber;

								cin >> currentNumber;
								if(!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
									break;

								if(1 > currentNumber || currentNumber > data.getShopsAmount())
								{
									printf(kEntarValueInRange, data.getShopsAmount());
									break;
								}

								PrintMarketInfoByIndex(data, currentNumber);
							}
							else if (currentChoise == kNameOfMarketChoiseType)
							{
								printf(kEnterShopNameMessage);
								printf(kInputSymbolMessage);
								StringType shopName;
								gets_s(shopName);

								if(!data.findMarketByName(shopName))
								{
									printf(kSuchShopNotExist);
									break;
								}

								PrintMarketInfoByName(data, shopName);
							}
							break;
						}
					case kAllDataChoiseType:
						{
							for (int i = 0; i < data.getShopsAmount(); i++)
							{
								PrintMarketInfoByIndex(data, i);
							}
							break;
						}
					case kClearSubmenuManageMenu1ChoiseType:
						{
							system("cls");
							break;
						}
					case kBackSubmenuManageMenu1ChoiseType:
						{
							isSubmenuExit = true;
							break;
						}
					default:
						{
							printf(kNoCorrespondingOptionErrorMessage);
							break;
						}
					}
				}				
				break;
			}
		case kAddMarketChoiseType:
			{
				PrintMenu(kRandomOrManualMenuPrint);
				int currentChoise;

				cin >> currentChoise;
				if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
					break;

				if (1 > currentChoise || 2 < currentChoise)
				{
					printf(kNoCorrespondingOptionErrorMessage);
					break;
				}

				if (currentChoise == kRandomChoiseType)
				{
					data.addNewMarket(DefaultMarket(data, &ArrayForRandomMarketNames[0]));					
				}
				else
				{
					data.addNewMarket(CreateNewShop(data));
				}				
				break;
			}
		case kRemoveMarketChoiseType:
			{
				PrintMenu(kNumberOrNameMarketMenuPrint);
				int currentChoise;

				cin >> currentChoise;
				if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
					break;

				if (1 > currentChoise || 2 < currentChoise)
				{
					printf(kNoCorrespondingOptionErrorMessage);
					break;
				}

				if (currentChoise == kNumberOfMarketChoiseType)
				{
					printf(kEnterNumberOfShopMessage);
					int currentNumber;

					cin >> currentNumber;
					if(!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
						break;

					if(1 > currentNumber || currentNumber > data.getShopsAmount())
					{
						printf(kEntarValueInRange, data.getShopsAmount());
						break;
					}

					data.removeMarketByNumber(currentNumber);
				}
				else if (currentChoise == kNameOfMarketChoiseType)
				{
					printf(kEnterShopNameMessage);
					printf(kInputSymbolMessage);
					StringType shopName;
					gets_s(shopName);

					if(!data.findMarketByName(shopName))
					{
						printf(kSuchShopNotExist);
						break;
					}

					data.removeMarketByName(shopName);
				}				
				break;
			}
		case kAddProductChoiseType:
			{
				bool isSubmenuExit = false;

				while (!isSubmenuExit)
				{
					PrintMenu(kSubmenuManageMenu4Print);
					int currentChoise;

					cin >> currentChoise;
					if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
						continue;

					if (kToAllExistingMarketsChoiseType > currentChoise || kBackSubmenuManageMenu4ChoiseType < currentChoise)
					{
						printf(kNoCorrespondingOptionErrorMessage);
						continue;
					}

					if (kToAllExistingMarketsChoiseType == currentChoise)
					{
						PrintMenu(kRandomOrManualMenuPrint);
						int currentChoise;

						cin >> currentChoise;
						if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
							continue;

						if (kRandomChoiseType > currentChoise || kManualChoiseType < currentChoise)
						{
							printf(kNoCorrespondingOptionErrorMessage);
							continue;
						}

						if (currentChoise == kRandomChoiseType)
						{
							data.addProductToAllMarkets(DefaultProduct(&ArrayForRandomProductTitle[0]));
						}
						else
						{
							data.addProductToAllMarkets(CreateNewProduct());
						}	
					}
					else if (kToCertainMarketChoiseType == currentChoise)
					{
						PrintMenu(kNumberOrNameMarketMenuPrint);
						int currentChoise;

						cin >> currentChoise;
						if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
							continue;

						if (kNumberOfMarketChoiseType > currentChoise || kNameOfMarketChoiseType < currentChoise)
						{
							printf(kNoCorrespondingOptionErrorMessage);
							continue;
						}

						if (currentChoise == kNumberOfMarketChoiseType)
						{
							printf(kEnterNumberOfShopMessage);
							int currentNumber;

							cin >> currentNumber;
							if(!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
								continue;

							if(1 > currentNumber || currentNumber > data.getShopsAmount())
							{
								printf(kEntarValueInRange, data.getShopsAmount());
								continue;
							}

							PrintMenu(kRandomOrManualMenuPrint);
							int currentChoise;

							cin >> currentChoise;
							if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
								continue;

							if (kRandomChoiseType > currentChoise || kManualChoiseType < currentChoise)
							{
								printf(kNoCorrespondingOptionErrorMessage);
								continue;
							}

							if (currentChoise == kRandomChoiseType)
							{
								data.addProductByMarketNumber(DefaultProduct(&ArrayForRandomProductTitle[0]), currentNumber);
							}
							else
							{
								data.addProductByMarketNumber(CreateNewProduct(), currentNumber);
							}
						}
						else if (currentChoise == kNameOfMarketChoiseType)
						{
							printf(kEnterShopNameMessage);
							printf(kInputSymbolMessage);
							StringType shopName;
							gets_s(shopName);

							if(!data.findMarketByName(shopName))
							{
								printf(kSuchShopNotExist);
								break;
							}

							PrintMenu(kRandomOrManualMenuPrint);
							int currentChoise;

							cin >> currentChoise;
							if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
								continue;

							if (kRandomChoiseType > currentChoise || kManualChoiseType < currentChoise)
							{
								printf(kNoCorrespondingOptionErrorMessage);
								continue;
							}

							if (currentChoise == kRandomChoiseType)
							{
								data.addProductByMarketName(DefaultProduct(&ArrayForRandomProductTitle[0]), shopName);
							}
							else
							{
								data.addProductByMarketName(CreateNewProduct(),shopName);
							}
						}
					}
					else
					{
						isSubmenuExit = true;
					}
				}
				break;
			}
		case kRemoveProductChoiseType:
			{
				PrintMenu(kSubmenuManageMenu5Print);
				int currentChoise;

				cin >> currentChoise;
				if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
					break;

				if (kFromAllExistingMarketsChoiseType > currentChoise || kFromCertainMarketChoiseType < currentChoise)
				{
					printf(kNoCorrespondingOptionErrorMessage);
					break;
				}

				switch (currentChoise)
				{
				case kFromAllExistingMarketsChoiseType:
					{
						PrintMenu(kDoubleSubmenuFivePrint);
						int currentChoise;

						cin >> currentChoise;
						if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
							break;

						if (kRemoveByProductTitleChoiseType > currentChoise || kRemoveByProductAmountChoiseType < currentChoise)
						{
							printf(kNoCorrespondingOptionErrorMessage);
							break;
						}

						switch (currentChoise)
						{
						case kRemoveByProductTitleChoiseType:
							{
								printf(kEnterProductTitleMessage);
								printf(kInputSymbolMessage);
								StringType productTitle;
								gets_s(productTitle);

								data.removeProductByTitleFromAllMarkets(productTitle); //     ??
								break;
							}
						case kRemoveByProductPriceChoiseType:
							{
								printf(kEnterProductPriceMessage);
								printf(kInputSymbolMessage);
								int price;

								cin >> price;
								if(!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
									break;

								data.removeProductByPriceFromAllMarkets(price); //             ??
								break;
							}
						case kRemoveByProductAmountChoiseType:
							{
								printf(kEnterProductAmountMessage);
								printf(kInputSymbolMessage);
								int amount;

								cin >> amount;
								if(!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
									break;

								data.removeProductByAmountFromAllMarkets(amount); //			??
								break;
							}
						default:
							{
								printf(kNoCorrespondingOptionErrorMessage);
								break;
							}
						}
						break;
					}
				case kFromCertainMarketChoiseType:
					{
						PrintMenu(kNumberOrNameMarketMenuPrint);
						int currentChoise;

						cin >> currentChoise;
						if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
							break;

						if (kNumberOfMarketChoiseType > currentChoise || kNameOfMarketChoiseType < currentChoise)
						{
							printf(kNoCorrespondingOptionErrorMessage);
							break;
						}

						if (currentChoise == kNumberOfMarketChoiseType)
						{
							printf(kEnterNumberOfShopMessage);
							int currentNumber;

							cin >> currentNumber;
							if(!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
								break;

							if(1 > currentNumber || currentNumber > data.getShopsAmount())
							{
								printf(kEntarValueInRange, data.getShopsAmount());
								break;
							}

							PrintMenu(kDoubleSubmenuFivePrint);
							int currentChoise;

							cin >> currentChoise;
							if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
								break;

							if (kRemoveByProductTitleChoiseType > currentChoise || kRemoveByProductAmountChoiseType < currentChoise)
							{
								printf(kNoCorrespondingOptionErrorMessage);
								break;
							}

							switch (currentChoise)
							{
							case kRemoveByProductTitleChoiseType:
								{
									printf(kEnterProductTitleMessage);
									printf(kInputSymbolMessage);
									StringType productTitle;
									gets_s(productTitle);

									data.removeProductByTitleFromMarketNumber(productTitle, currentNumber);
									break;
								}
							case kRemoveByProductPriceChoiseType:
								{
									printf(kEnterProductPriceMessage);
									printf(kInputSymbolMessage);
									int price;

									cin >> price;
									if(!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
										break;

									data.removeProductByPriceFromMarketNumber(price, currentNumber);
									break;
								}
							case kRemoveByProductAmountChoiseType:
								{
									printf(kEnterProductAmountMessage);
									printf(kInputSymbolMessage);
									int amount;

									cin >> amount;
									if(!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
										break;

									data.removeProductByAmountFromMarketNumber(amount,currentNumber);
									break;
								}
							default:
								{
									printf(kNoCorrespondingOptionErrorMessage);
									break;
								}
							}
						}
						else if (currentChoise == kNameOfMarketChoiseType)
						{
							printf(kEnterShopNameMessage);
							printf(kInputSymbolMessage);
							StringType shopName;
							gets_s(shopName);

							if(!data.findMarketByName(shopName))
							{
								printf(kSuchShopNotExist);
								break;
							}

							PrintMenu(kDoubleSubmenuFivePrint);
							int currentChoise;

							cin >> currentChoise;
							if(!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
								break;

							if (kRemoveByProductTitleChoiseType > currentChoise || kRemoveByProductAmountChoiseType < currentChoise)
							{
								printf(kNoCorrespondingOptionErrorMessage);
								break;
							}

							switch (currentChoise)
							{
							case kRemoveByProductTitleChoiseType:
								{
									printf(kEnterProductTitleMessage);
									printf(kInputSymbolMessage);
									StringType productTitle;
									gets_s(productTitle);

									data.removeProductByTitleFromMarketName(productTitle, shopName);
									break;
								}
							case kRemoveByProductPriceChoiseType:
								{
									printf(kEnterProductPriceMessage);
									printf(kInputSymbolMessage);
									int price;

									cin >> price;
									if(!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
										break;

									data.removeProductByPriceFromMarketName(price, shopName);
									break;
								}
							case kRemoveByProductAmountChoiseType:
								{
									printf(kEnterProductAmountMessage);
									printf(kInputSymbolMessage);
									int amount;

									cin >> amount;
									if(!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
										break;

									data.removeProductByAmountFromMarketName(amount, shopName);
									break;
								}
							default:
								{
									printf(kNoCorrespondingOptionErrorMessage);
									break;
								}
							}
						}						
						break;
					}
				default:
					{
						printf(kNoCorrespondingOptionErrorMessage);
						break;
					}
				}				
				break;
			}
		case kClearSreanChoiseType:
			{
				system("cls");
				break;
			}
		case kExitProgramChoiseType:
			{
				printf(kExitConfirmationMessage);
				printf(kInputSymbolMessage);
				char answerString[20];
				gets_s(answerString);

				int lenght = strlen(answerString);
				for (int i = 0; i < lenght; i++)
					answerString[i] = tolower(answerString[i]);

				if (strcmp(answerString, "y") == 0 || strcmp(answerString, "yes") == 0)
					isExit = true;
				break;
			}
		default:
			{
				printf(kNoCorrespondingOptionErrorMessage);
				break;
			}
		}		
	}
	return 0;
}



void PrintMenu(PrintMenusChoiseType currentMenu)
{
	switch (currentMenu)
	{
	 case kMarketCreationMenuPrint:
		 {
			 printf(kCreationMenuMessage);
			 printf(kChaineStoresRandomlyCreationMessage);
			 printf(kChaineStoresManuallyCreationMessage);
			 printf(kInputSymbolMessage);
			 break;
		 }
	 case kManageMenuPrint:
		 {
			 printf(kManageMenu);
			 printf(kIformationShowMessage);
			 printf(kMarketAddMessage);
			 printf(kMarketRemoveMessage);
			 printf(kProductAddMessage);
			 printf(kProductRemoveMessage);
			 printf(kClearManageMenuMessage);
			 printf(kExitProgramMessage);
			 printf(kInputSymbolMessage);
			 break;
		 }
	 case kSubmenuManageMenu1Print:
		 {
			 printf(kMarketListMessage);
			 printf(kProductInformationForSpesificMarketMessage);
			 printf(kAllDataMessage);
			 printf(kClearSubmenuManageMenu1Message);
			 printf(kBackSubmenuManageMenu1Message);
			 printf(kInputSymbolMessage);
			 break;
		 }
	 case kSubmenuManageMenu4Print:
		 {
			 printf(kToAllExistingMarketsMessage);
			 printf(kToCertainMarketMessage);
			 printf(kBackSubmenuManageMenu4Message);
			 printf(kInputSymbolMessage);
			 break;
		 }
	 case kSubmenuManageMenu5Print:
		 {
			 printf(kFromAllExistingMarketsMessage);
			 printf(kFromCertainMarketMessage);
			 printf(kInputSymbolMessage);
			 break;
		 }
	 case kRandomOrManualMenuPrint:
		 {
			 printf(kRandomMessage);
			 printf(kManualMessage);
			 printf(kInputSymbolMessage);
			 break;
		 }
	 case kNumberOrNameMarketMenuPrint:
		 {
			 printf(kByNumderFromMarketListMessage);
			 printf(kByShopNameMessage);
			 printf(kInputSymbolMessage);
			 break;
		 }
	 case kDoubleSubmenuFivePrint:
		 {
			 printf(kRemoveByProductTitleMessage);
			 printf(kRemoveByProductPriceMessage);
			 printf(kRemoveByProductAmountMessage);
			 printf(kInputSymbolMessage);
			 break;
		 }
	 default:
		 break;
	}
}

bool MakeCheckForNumberInputFromCin(const char inErrorMessage[])
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
		printf(inErrorMessage);
	}
	return result;
}

Product DefaultProduct(StringType Array[matrixSize])
{
	Product result;
	result.setTitle(Array[RandomNumberReturn(0, 5)]);
	result.setPrice(RandomNumberReturn(1, 200));
	result.setAmount(RandomNumberReturn(100, 350));
	return result;
}

Market DefaultMarket(Data data, StringType Array[matrixSize])
{
	Market result;
	StringType currentShopName;
	strcpy(currentShopName, Array[RandomNumberReturn(0, 5)]);
	bool exit = false;
	for (int i = 0; i < matrixSize; i++)
	{
		if (data.findMarketByName(currentShopName))
		{
			StringType index;
			int id = i + 1;
			itoa (id, index, 10);
			strcat(currentShopName, index);
			//exit = true;
		}
		if (exit)
			break;
	}
	result.setShopName(currentShopName);

	int productAmount = RandomNumberReturn(3, 6);
	result.setProductAmount(0);

	for (int i = 0; i < productAmount; i++)
		result.addProduct(DefaultProduct(&ArrayForRandomProductTitle[0]));

	return result;
}

Data DefaultData()
{
	Data result;
	int shopAmount = RandomNumberReturn(3, 6);
	result.setShopsAmount(0);

	for (int i = 0; i < shopAmount; i++)
		result.addNewMarket(DefaultMarket(result, &ArrayForRandomMarketNames[0]));

	return result;
}

Data CreateNewData()
{
	Data result;
	bool exitAnswer = false;
	int count;

	while (!exitAnswer)
	{
		printf(kShopAmountEnterMessage, kMaxShopRange);
		printf(kInputSymbolMessage);
				
		cin >> count;
		if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
			continue;

		if (count < 1 && count > kMaxShopRange)
		{
			printf(kEntarValueInRange, kMaxShopRange);
			continue;
		}		
		exitAnswer = true;
	}

	for (int i = 0; i < count; i++)
	{
		printf(kCreateShopMessage, i+1);
		result.addNewMarket(CreateNewShop(result));
	}
	return result;
}

Market CreateNewShop(Data data)
{
	Market result;

	int shopAmount = data.getShopsAmount();
	bool exit = false;
	while (!exit)
	{
		printf(kShopNameEnterMessage);
		printf(kInputSymbolMessage);
		StringType shopName;
		gets_s(shopName);
		
		if (data.findMarketByName(shopName))
		{
			printf(kShopNameAlreadyExistMessage);
			continue;
		}
		result.setShopName(shopName);
		exit = true;
	}

	bool exitAnswer = false;
	int count;

	while(!exitAnswer)
	{
		printf(kProductAmountEnterMessage, kMaxProductRange);
		printf(kInputSymbolMessage);

		cin >> count;
		if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
			continue;

		if (count < 1 && count > kMaxProductRange)
		{
			printf(kEntarValueInRange, kMaxProductRange);
			continue;
		}
		exitAnswer = true;
	}

	for (int i = 0; i < count; i++)
	{
		printf(kCreateProductMessage, i+1);
		result.addProduct(CreateNewProduct());
	}
	return result;
}

Product CreateNewProduct()
{
	Product result;

	printf(kProductTitleEnterMessage);
	printf(kInputSymbolMessage);
	StringType productTitle;
	gets_s(productTitle);
	result.setTitle(productTitle);

	bool exit = false;
	while(!exit)
	{
		printf(kEnterPriceMessage);
		printf(kInputSymbolMessage);
		
		int value;
		cin >> value;
		if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
			continue;

		result.setPrice(value);
		exit = true;
	}

	exit = false;
	while(!exit)
	{
		printf(kEnterAmountMessage);
		printf(kInputSymbolMessage);

		int value;
		cin >> value;
		if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
			continue;

		result.setAmount(value);
		exit = true;
	}
	return result;
}

void PrintMarketInfoByIndex(Data data, int index)
{
	Market printMarket = data.getMarketByIndex(index);
	if (index < 0 || index > data.getShopsAmount())
		return;

	StringType shopName;
	printMarket.getShopName(shopName);

	printf(kMarketMessage, index, shopName);
	printf(kListOfProductMessage);
	printf(kHeadProductStringMessage);

	for (int i = 0; i < printMarket.getProductAmount(); i++)
	{
		Product printProduct =  printMarket.getProductByIndex(i);
		StringType productTitle;
		printProduct.getTitle(productTitle);
		printf("%s\t%d\t%d\n", productTitle, printProduct.getPrice(), printProduct.getAmount());
	}
}

void PrintMarketInfoByName(Data data, StringType shopName)
{
	int index = 0;
	StringType compareShopName;
	TolowerString(shopName, compareShopName);

	StringType currentShopName;
	do
	{
		Market printMarket = data.getMarketByIndex(index);		
		printMarket.getShopName(currentShopName);
		TolowerString(currentShopName, currentShopName);
		index++;

		if (index > data.getShopsAmount())
		{
			index = 0;
			break;
		}	
	} while (strcmp(currentShopName, compareShopName));

	PrintMarketInfoByIndex(data, --index);
}

void PrintMarketList(Data data)
{
	for (int i = 0; i < data.getShopsAmount(); i++)
	{
		Market printMarket = data.getMarketByIndex(i);
		StringType shopName;
		printMarket.getShopName(shopName);
		printf("%d\t%s", i, shopName);
	}
}