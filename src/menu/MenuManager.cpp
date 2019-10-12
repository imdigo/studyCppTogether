#include "MenuManager.h"

MenuManager* MenuManager::ins = 0; // or NULL, or nullptr in c++11

// class MenuManager {
// public:
// 	std::vector<Menu> getMenuList();
// 	void setMenuList(std::vector<Menu> menuList);
// 	void addMenu();
// 	void deleteMenu();

// private:
// 	std::vector<Menu> menuList;
// };


std::vector<Menu> MenuManager::getMenuList() {
	return menuList;
}

void MenuManager::setMenuList(std::vector<Menu> menuList) {
	this->menuList = menuList;
}

void MenuManager::addMenu() {
	std::string name;
	std::vector<Ingredient> ingredientList;
	unsigned int price = 0;
	unsigned int discount = 0;
	std::cout << "Input Menu Name : ";
	std::cin >> name;
	// get ingredients' list
	// need iterator
	IngredientManager *instance = IngredientManager::getInstance();
	std::vector<Ingredient> list = instance->getIngredientList();
	// std::vector<Ingredient> list;
	std::vector<Ingredient>::iterator iter;
	while (true) {
		std::cout << "=== Ingredient Selection ===" << std::endl;
		std::cout << std::endl;
		std::cout << "Current ingredients are .." << std::endl;
		int i = 1;
		for (iter = ingredientList.begin(); iter != ingredientList.end(); ++iter) {
			std::cout << i << ". " << iter->getName() << std::endl;
		}
		std::cout << std::endl;
		
		i = 1;
		int selection = 0;
		std::cout << "Select ingredient to add .." << std::endl;
		for (iter = list.begin(); iter != list.end(); ++iter) {
			std::cout << i << ". " << iter->getName() << std::endl;
		}
		std::cout << "Input(Input 0 to end ingredient selection) : ";
		std::cin >> selection;
		if (selection == 0)
			break;
		else {
			Ingredient temp(list[selection - 1]);
			ingredientList.push_back(temp);
		}
	}
	
	
	
	// calculate price
	iter = ingredientList.begin();
	for (; iter != ingredientList.end(); ++iter) {
		price += iter->getPrice();
	}
	
	// Set discount
	
	
	
	// Make object
	Menu newMenu(name, ingredientList, price, discount);
	menuList.push_back(newMenu);
	
}

void MenuManager::deleteMenu() {
	return ;
}


