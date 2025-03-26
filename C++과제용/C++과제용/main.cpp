#include <iostream>
#include <vector>

using namespace std;

class Item {
private:
	// 이름, 재고량, 소비량, 최소량
	string name;
	int	stock;
	int consume_rate;
	int min_stock;

public:
	Item(const string& n, int s, int c, int m)
		: name(n), stock(s), consume_rate(c), min_stock(m) {}

	string getName() const {
		return name;
	}

	int getStock() const {
		return stock;
	}

	int getConsumeRate() const {
		return consume_rate;
	}

	int getMinStock() const {
		return min_stock;
	}

	void changeStock(int amount) {
		stock += amount;
		if (stock < 0)stock = 0;
	}

	void setConsumeRate(int amount) {
		consume_rate = amount;
	}

	void setMinStock(int amount) {
		min_stock = amount;
	}
};

class Inventory {
private:
	vector<Item> items;

public:
	void newItems(const string& name, int stock, int consume_rate, int min_stock) {
		items.emplace_back(name, stock, consume_rate, min_stock);
	}

	void deleteItems(const string& name) {
		for (auto it = items.begin();it != items.end(); it++) {
			if (it->getName() == name) {
				items.erase(it);
				break;
			}
		}
	}
};

typedef struct Catalog {
	string name;
	int number_of_purchases_per_once;	// 1회구매량?
	float weight;
	float value;
}Catalog;

void printCatalog(Catalog catalog[3]) {
	for (int i = 0;i < 3;i++) {
		cout << "상품명 : " << catalog[i].name << "\n"
			<< "1회구매량 : " << catalog[i].number_of_purchases_per_once << "\n"
			<< "무게 : " << catalog[i].weight << "\n"
			<< "가치 : " << catalog[i].value << "\n\n";
	}
}

int main() {
	Catalog catalog[3] = { {"휴지", 24, 3.6,10.0},{"라면", 6, 1.0,5.0},{"햇반",6,1.3,3.0} };
	printCatalog(catalog);
}