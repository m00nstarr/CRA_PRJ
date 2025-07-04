#pragma once
#include <iostream>
#include "engine.cpp"
#include "steering.cpp"
#include "breakSystem.cpp"

class Car {
public:
    //BreakSystem* breakSystem;
    //SteeringSystem* steeringSystem;

    enum RunCode {
        WORKING = 0,
		NOT_WORKING,
        BROKEN_ENGINE,

    };

    enum CarType
    {
        SEDAN = 1,
        SUV,
        TRUCK
    };

    int isValidCheck()
    {
        int carType = this->type;
		int engineType = engine->getType();
		int brakeType = breakSystem->getType();
		int steeringType = steeringSystem->getType();

        //���� �� ���� ����
        if (carType == Car::SEDAN)
        {
            if (brakeType == Break::CONTINENTAL) {
                return false;
            }
        }

        if (carType == Car::SUV) {
            if (engineType == Engine::TOYOTA) {
                return false;
            }
		}

        if( carType == Car::TRUCK) {
            if (engineType == Engine::WIA) {
                return false;
            }
            if (brakeType == Break::MANDO) {
                return false;
            }
		}

        if (brakeType == Break::BOSCH_B && steeringType != SteeringSystem::BOSCH_S)
        {
            return false;
        }

        return true;
    }

    int runProducedCar()
    {
        if (isValidCheck() == false)
        {
            printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
            return RunCode::NOT_WORKING;
        }

        if( getEngine()->getType() == Engine::BROKEN )
        {
            printf("������ ���峪�ֽ��ϴ�.\n");
            printf("�ڵ����� �������� �ʽ��ϴ�.\n");
            return BROKEN_ENGINE;
		}

        printCarType();
        printEngineType();
        printBreakSystem();
        printSteeringSystem();
        printf("�ڵ����� ���۵˴ϴ�.\n");
		return RunCode::WORKING;
    }

    std::string testProducedCar()
    {
        std::string testResult;
        int carType = this->type;
        int engineType = engine->getType();
        int brakeType = breakSystem->getType();
        int steeringType = steeringSystem->getType();

        
        if (carType == Car::SEDAN)
        {
            if (brakeType == Break::CONTINENTAL) {
                testResult = "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n";
                testResult += "Sedan���� Continental������ġ ��� �Ұ�\n";

                return testResult;
            }
        }
        
        if (carType == Car::SUV) {
            if (engineType == Engine::TOYOTA) {
                testResult = "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n";
                testResult += "SUV���� TOYOTA���� ��� �Ұ�\n";

                return testResult;
            }
        }

        if (carType == Car::TRUCK) {
            if (engineType == Engine::WIA) {
                testResult = "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n";
				testResult += "Truck���� WIA���� ��� �Ұ�\n";
                return testResult;
            }
            if (brakeType == Break::MANDO) {
                testResult = "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n";
				testResult += "Truck���� Mando������ġ ��� �Ұ�\n";
                return testResult;
            }
        }

        if (brakeType == Break::BOSCH_B && steeringType != SteeringSystem::BOSCH_S)
        {
			testResult = "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n";
			testResult += "Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n";
            return testResult;
        }

        return "�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n";
    }

    void printCarType() {
        switch (type) {
            case SEDAN:
                std::cout << "Car Type : Sedan\n";
                break;
            case SUV:
                std::cout << "Car Type : SUV\n";
                break;
            case TRUCK:
                std::cout << "Car Type : Truck\n";
                break;
        }
	}

    void printEngineType() {
        std::cout << "Engine Type : " << engine->getName() << "\n";
    }

    void printBreakSystem() {
        std::cout << "Brake System : " << breakSystem->getName() << "\n";
	}

    void printSteeringSystem() {
        std::cout << "Steering System : " << steeringSystem->getName() << "\n";
    }

    int getCarType() {
        return type;
	}

    void setCarType(int selectedType){
        type = selectedType;
    }

    Engine * getEngine() {
        return engine;
	}

    void setEngine(Engine* engine) {
        this->engine = engine;
	}

    Break * getBrakeSystem() {
        return breakSystem;
	}

    void setBrakeSystem(Break* breakSystem) {
        this->breakSystem = breakSystem;
    }

    SteeringSystem* getSteeringSystem() {
        return steeringSystem;
    }

    void setSteeringSystem(SteeringSystem* steeringSystem) {
        this->steeringSystem = steeringSystem;
	}

private :
    int type;
    Engine* engine;
	Break* breakSystem;
    SteeringSystem* steeringSystem;
};