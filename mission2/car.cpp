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

        //차량 별 제약 사항
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
            printf("자동차가 동작되지 않습니다\n");
            return RunCode::NOT_WORKING;
        }

        if( getEngine()->getType() == Engine::BROKEN )
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
            return BROKEN_ENGINE;
		}

        printCarType();
        printEngineType();
        printBreakSystem();
        printSteeringSystem();
        printf("자동차가 동작됩니다.\n");
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
                testResult = "자동차 부품 조합 테스트 결과 : FAIL\n";
                testResult += "Sedan에는 Continental제동장치 사용 불가\n";

                return testResult;
            }
        }
        
        if (carType == Car::SUV) {
            if (engineType == Engine::TOYOTA) {
                testResult = "자동차 부품 조합 테스트 결과 : FAIL\n";
                testResult += "SUV에는 TOYOTA엔진 사용 불가\n";

                return testResult;
            }
        }

        if (carType == Car::TRUCK) {
            if (engineType == Engine::WIA) {
                testResult = "자동차 부품 조합 테스트 결과 : FAIL\n";
				testResult += "Truck에는 WIA엔진 사용 불가\n";
                return testResult;
            }
            if (brakeType == Break::MANDO) {
                testResult = "자동차 부품 조합 테스트 결과 : FAIL\n";
				testResult += "Truck에는 Mando제동장치 사용 불가\n";
                return testResult;
            }
        }

        if (brakeType == Break::BOSCH_B && steeringType != SteeringSystem::BOSCH_S)
        {
			testResult = "자동차 부품 조합 테스트 결과 : FAIL\n";
			testResult += "Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n";
            return testResult;
        }

        return "자동차 부품 조합 테스트 결과 : PASS\n";
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