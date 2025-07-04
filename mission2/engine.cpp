#pragma once
#include <iostream>
#include <string>

class Engine {
public:
	enum EngineType
	{
		GM = 1,
		TOYOTA,
		WIA,
		BROKEN // 고장난 엔진
	};

	int type;
	std::string name;

	Engine(const std::string &name): name(name) {
		type = typeNumbering(name);
	}	
	int typeNumbering(const std::string& name) {

		if (name == "GM") {
			return EngineType::GM;
		}
		
		if (name == "TOYOTA") {
			return EngineType::TOYOTA;
		}
		
		if (name == "WIA") {
			return EngineType::WIA;
		}
		
		if (name == "BROKEN") {
			return EngineType::BROKEN;
		}
	}

	int getType() {
		return type;
	}

	std::string getName() {
		return name;
	}

	//virtual void work() = 0;
};

class GMEngine : public Engine {

public:
	GMEngine() : Engine("GM") {

	}

	//void work() override {
	//	std::cout << "GM Engine is working\n";
	//}
};

class TOYOTAEngine : public Engine {

public:
	TOYOTAEngine() :Engine("TOYOTA") {

	}
	
	//void work() override {
	//	std::cout << "TOYOTA Engine is working\n";
	//}
};


class WIAEngine : public Engine {

public:
	WIAEngine() : Engine("WIA") {

	}

	//void work() override {
	//	std::cout << "WIA Engine is working\n";
	//}
};

class BrokenEngine : public Engine {

public:
	BrokenEngine() : Engine("BROKEN") {

	}

	//void work() override {
	//	std::cout << "Engine이 고장나있씁니다\n";
	//}
};