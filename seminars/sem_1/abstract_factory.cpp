#include <iostream>

class AbstractElvishArmy {
public:
	virtual void Hello() = 0;
	virtual ~AbstractElvishArmy(){};
};

class EasyElvishArmy: public AbstractElvishArmy {
public:
	virtual void Hello() {
		std::cout << "Easy elf, hello" << std::endl;
	}
};

class ComplecatedElvishArmy: public AbstractElvishArmy {
public:
	virtual void Hello() {
		std::cout << "Complecated elf, hello" << std::endl;
	}
};

class AbstractOrksArmy {
public:
	virtual void WhoAmI() = 0;
	virtual ~AbstractOrksArmy(){};
};

class EasyOrksArmy: public AbstractOrksArmy {
public:
	virtual void WhoAmI() {
		std::cout << "Easy ork" << std::endl; 
	}
};

class ComplecatedOrksArmy: public AbstractOrksArmy {
public:
	virtual void WhoAmI() {
		std::cout << "Complecated ork" << std::endl; 
	}
};

class AbstractFactory {
public:
	virtual AbstractElvishArmy* CreateElvishArmy() = 0;
	virtual AbstractOrksArmy* CreateOrksArmy() = 0;
	virtual ~AbstractFactory(){};
};

class EasyLevelFactory: public AbstractFactory {
public:
	virtual AbstractElvishArmy* CreateElvishArmy() {
		return new EasyElvishArmy();
	}

	virtual AbstractOrksArmy* CreateOrksArmy() {
		return new EasyOrksArmy();
	}
};

class ComplecatedLevelFactory: public AbstractFactory {
	public:
	virtual AbstractElvishArmy* CreateElvishArmy() {
		return new ComplecatedElvishArmy();
	}

	virtual AbstractOrksArmy* CreateOrksArmy() {
		return new ComplecatedOrksArmy();
	}
};

void CreateArmy(AbstractFactory* factory) {
	AbstractElvishArmy* elves = factory->CreateElvishArmy();
	elves->Hello();
	AbstractOrksArmy* orks = factory->CreateOrksArmy();
	orks->WhoAmI();
	delete orks;
	delete elves;
	delete factory;
}

int main () {
	std::cout << "EASY MODE" << std::endl;
	// easy-mode
	CreateArmy(new EasyLevelFactory());
	std::cout << "COMPLECATED MODE" << std::endl;
	// complecated mode
	CreateArmy(new ComplecatedLevelFactory());
	return 0;
}