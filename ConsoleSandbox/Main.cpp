#include <iostream>
#include <Core//src/ioc/Container.h>

struct Base {
	virtual int Test() {
		return 100;
	}
	virtual ~Base() = default;
};

struct Derived : public Base {
	int Test() override {
		return 50;
	}
};

int main()
{
	using namespace ales;
	ioc::Get().Register<Base>([] {return std::make_shared<Derived>(); });

	std::cout << ioc::Get().Resolve<Base>()->Test() << std::endl;
}