#pragma once
#include <iostream>
#include <string>

class SteeringSystem {
public:
	enum SteeringType
	{
		BOSCH_S = 1,
		MOBIS
	};

	int type;
	std::string name;

	SteeringSystem(const std::string& name) : name(name) {
		type = typeNumbering(name);
	}
	int typeNumbering(const std::string& name) {

		if (name == "BOSCH_S") {
			return SteeringType::BOSCH_S;
		}
		
		if (name == "MOBIS") {
			return SteeringType::MOBIS;
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

class BOSCHSystem : public SteeringSystem {

public:
	BOSCHSystem() : SteeringSystem("BOSCH_S") {

	}

	//void work() override {
	//	std::cout << "BOSCH Steering System is working\n";
	//}
};

class MOBISSystem : public SteeringSystem {

public:
	MOBISSystem() :SteeringSystem("MOBIS") {

	}

	//void work() override {
	//	std::cout << "MOBIS Steering System  is working\n";
	//}
};
