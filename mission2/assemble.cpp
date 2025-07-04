#pragma once
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "car.cpp"
#include "engine.cpp"

class Assembler {

public :

	Car* car;
	Assembler() {
		car = new Car();
	}

	void selectCarType(int answer) {
		if (answer == 1)
			printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
		if (answer == 2)
			printf("차량 타입으로 SUV을 선택하셨습니다.\n");
		if (answer == 3)
			printf("차량 타입으로 Truck을 선택하셨습니다.\n");

		car->setCarType(answer);
	}

	void selectEngine(int answer) {
		switch (answer) {
		case Engine::GM:
			printf("GM 엔진을 선택하셨습니다.\n");
			car->setEngine(new GMEngine());
			break;

		case Engine::TOYOTA:
			printf("TOYOTA 엔진을 선택하셨습니다.\n");
			car->setEngine(new TOYOTAEngine());
			break;

		case Engine::WIA:
			printf("WIA 엔진을 선택하셨습니다.\n");
			car->setEngine(new WIAEngine());
			break;
		case Engine::BROKEN:
			car->setEngine(new BrokenEngine());
			break;
		}
	}

	void selectBreak(int answer) {
		switch (answer) {
			case Break::MANDO:
				printf("MANDO 제동장치를 선택하셨습니다.\n");
				car->setBrakeSystem(new MandoBreak());
				break;
			case Break::CONTINENTAL:
				printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
				car->setBrakeSystem(new ContinentalBreak());
				break;
			case Break::BOSCH_B:
				printf("BOSCH 제동장치를 선택하셨습니다.\n");
				car->setBrakeSystem(new BoschBreak());
				break;
		}
	}

	void selectSteeringSystem(int answer) {
		switch (answer) {
			case SteeringSystem::BOSCH_S:
				printf("BOSCH 조향장치를 선택하셨습니다.\n");
				car->setSteeringSystem(new BOSCHSystem());
				break;
			case SteeringSystem::MOBIS:
				printf("MOBIS 조향장치를 선택하셨습니다.\n");
				car->setSteeringSystem(new MOBISSystem());
				break;	
		}
	}

	void runProducedCar() {
		car->runProducedCar();
	}

	void testProducedCar() {
		std::string result = car->testProducedCar();
		std::cout << result;
	}

};

