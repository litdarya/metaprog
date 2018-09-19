#include <iostream>
#include <vector>

class Items {
public:
	virtual int Sum() = 0;
	virtual ~Items() {}
};

class Box: public Items {
public:
	void Add(Items* item) {
		in_box.push_back(item);
	}

	virtual int Sum() {
		int sum = 0;
		for (auto it = in_box.begin(); it != in_box.end(); ++it) {
			sum += (*it)->Sum();
		}
		return sum;
	}

	~Box() {
		for (int i = 0; i < in_box.size(); ++i) {
			delete in_box[i];
		}
	}
private:
	std::vector<Items*> in_box;
};

class Clothes: public Items {
public:
	Clothes(int price_):price(price_) {}

	virtual int Sum() {
		return price;
	}
private:
	int price;
};

int main() {
	Clothes* shirt = new Clothes(10);
	Clothes* skirt = new Clothes(20);
	Box* t_shirts = new Box();
	t_shirts->Add(new Clothes(2));
	t_shirts->Add(new Clothes(3));
	Box order;
	order.Add(t_shirts);
	order.Add(shirt);
	order.Add(skirt);
	std::cout << order.Sum() << std::endl;
	return 0;
}