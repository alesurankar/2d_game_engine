// Core.cpp : Defines the functions for the static library.
//

#include <memory>

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

std::unique_ptr<Base> MakeDerived() {
	return std::make_unique<Derived>();
}

int Test() {
	return MakeDerived()->Test();
}
