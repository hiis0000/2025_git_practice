#include <iostream>
#include <vector>

using namespace std;

class Item {
private:
	// �̸�, ���, �Һ�, �ּҷ�
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
	int number_of_purchases_per_once;	// 1ȸ���ŷ�?
	float weight;
	float value;
}Catalog;

void printCatalog(Catalog catalog[3]) {
	for (int i = 0;i < 3;i++) {
		cout << "��ǰ�� : " << catalog[i].name << "\n"
			<< "1ȸ���ŷ� : " << catalog[i].number_of_purchases_per_once << "\n"
			<< "���� : " << catalog[i].weight << "\n"
			<< "��ġ : " << catalog[i].value << "\n\n";
	}
}

int main() {
	Catalog catalog[3] = { {"����", 24, 3.6,10.0},{"���", 6, 1.0,5.0},{"�޹�",6,1.3,3.0} };
	printCatalog(catalog);
}