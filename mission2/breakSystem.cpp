#pragma once
#include <iostream>
#include <string>

class Break {
public:
	enum BrakeType
	{
		MANDO = 1,
		CONTINENTAL,
		BOSCH_B,
	};

	int type;
	std::string name;

	Break(const std::string& name) : name(name) {
		type = typeNumbering(name);
	}
	int typeNumbering(const std::string& name) {

		if (name == "MANDO") {
			return BrakeType::MANDO;
		}
		
		if (name == "CONTINENTAL") {
			return BrakeType::CONTINENTAL;
		}
		
		if (name == "BOSCH_B") {
			return BrakeType::BOSCH_B;
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

class MandoBreak : public Break {

public:
	MandoBreak() : Break("MANDO") {

	}

	//void work() override {
	//	std::cout << "MANDO Break is working\n";
	//}
};

class ContinentalBreak : public Break {

public:
	ContinentalBreak() :Break("CONTINENTAL") {

	}

	//void work() override {
	//	std::cout << "Continental Break is working\n";
	//}
};

class BoschBreak : public Break {

public:
	BoschBreak() : Break("BOSCH_B") {

	}

	//void work() override {
	//	std::cout << "Bosch Break is working\n";
	//}
};