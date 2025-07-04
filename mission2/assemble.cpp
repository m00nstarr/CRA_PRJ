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
			printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
		if (answer == 2)
			printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
		if (answer == 3)
			printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");

		car->setCarType(answer);
	}

	void selectEngine(int answer) {
		switch (answer) {
		case Engine::GM:
			printf("GM ������ �����ϼ̽��ϴ�.\n");
			car->setEngine(new GMEngine());
			break;

		case Engine::TOYOTA:
			printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
			car->setEngine(new TOYOTAEngine());
			break;

		case Engine::WIA:
			printf("WIA ������ �����ϼ̽��ϴ�.\n");
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
				printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
				car->setBrakeSystem(new MandoBreak());
				break;
			case Break::CONTINENTAL:
				printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
				car->setBrakeSystem(new ContinentalBreak());
				break;
			case Break::BOSCH_B:
				printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
				car->setBrakeSystem(new BoschBreak());
				break;
		}
	}

	void selectSteeringSystem(int answer) {
		switch (answer) {
			case SteeringSystem::BOSCH_S:
				printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
				car->setSteeringSystem(new BOSCHSystem());
				break;
			case SteeringSystem::MOBIS:
				printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
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

