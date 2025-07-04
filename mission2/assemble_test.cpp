#ifdef _DEBUG
#include "assemble.cpp"
#include "car.cpp"
#include "gmock/gmock.h"

class CarAssembleTestFixture : public testing::Test {
public:

	const std::string testPassMsg = "자동차 부품 조합 테스트 결과 : PASS\n";
	const std::string testFailMsg = "자동차 부품 조합 테스트 결과 : FAIL\n";
	const std::string SedanWithContinentalTestMsg = "Sedan에는 Continental제동장치 사용 불가\n";
	const std::string SuvWithToyotaTestMsg = "SUV에는 TOYOTA엔진 사용 불가\n";
	const std::string TruckWithWiaTestMsg = "Truck에는 WIA엔진 사용 불가\n";
	const std::string TruckWithMandoTestMsg = "Truck에는 Mando제동장치 사용 불가\n";
	const std::string BoschWithNotBoschTestMsg = "Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n";



	Assembler* assembler;
	void SetUp() override {
		assembler = new Assembler();
	}
};

TEST_F(CarAssembleTestFixture, setCarType)
{
	assembler->selectCarType(Car::CarType::SEDAN);
	int carType = assembler->car->getCarType();
	EXPECT_EQ(carType, Car::CarType::SEDAN);

}

TEST_F(CarAssembleTestFixture, setEngineTest1)
{
	assembler->selectEngine(Engine::GM);
	Engine* engine = assembler->car->getEngine();
	EXPECT_EQ(engine->getType(), Engine::GM);

}
TEST_F(CarAssembleTestFixture, setEngineTest2)
{
	assembler->selectEngine(-1);
	Engine* engine = assembler->car->getEngine();
	EXPECT_EQ(engine, nullptr);

}


TEST_F(CarAssembleTestFixture, setBreakTest)
{
	assembler->selectBreak(Break::CONTINENTAL);
	Break* breakSystem = assembler->car->getBrakeSystem();
	EXPECT_EQ(breakSystem->getType(), Break::CONTINENTAL);
}

TEST_F(CarAssembleTestFixture, setSteeringSystemTest)
{
	assembler->selectSteeringSystem(SteeringSystem::BOSCH_S);
	SteeringSystem* steeringSystem = assembler->car->getSteeringSystem();
	EXPECT_EQ(steeringSystem->getType(), SteeringSystem::BOSCH_S);
}

TEST_F(CarAssembleTestFixture, runProducedCarTest)
{
	assembler->selectCarType(Car::CarType::SEDAN);
	assembler->selectEngine(Engine::GM);
	assembler->selectBreak(Break::MANDO);
	assembler->selectSteeringSystem(SteeringSystem::BOSCH_S);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(assembler->car->getCarType(), Car::CarType::SEDAN);
	EXPECT_EQ(assembler->car->getEngine()->getType(), Engine::GM);
	EXPECT_EQ(assembler->car->getBrakeSystem()->getType(), Break::MANDO);
	EXPECT_EQ(assembler->car->getSteeringSystem()->getType(), SteeringSystem::BOSCH_S);
	EXPECT_EQ(result, Car::RunCode::WORKING);

}

TEST_F(CarAssembleTestFixture, runProducedCarTest2)
{
	assembler->selectCarType(Car::CarType::SEDAN);
	assembler->selectEngine(Engine::GM);
	assembler->selectBreak(Break::BOSCH_B);
	assembler->selectSteeringSystem(SteeringSystem::BOSCH_S);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(result, Car::RunCode::WORKING);

}

TEST_F(CarAssembleTestFixture, runProducedCarTest3)
{
	assembler->selectCarType(Car::CarType::TRUCK);
	assembler->selectEngine(Engine::GM);
	assembler->selectBreak(Break::BOSCH_B);
	assembler->selectSteeringSystem(SteeringSystem::BOSCH_S);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(result, Car::RunCode::WORKING);

}

TEST_F(CarAssembleTestFixture, runProducedCarTest4)
{
	assembler->selectCarType(Car::CarType::SUV);
	assembler->selectEngine(Engine::GM);
	assembler->selectBreak(Break::BOSCH_B);
	assembler->selectSteeringSystem(SteeringSystem::BOSCH_S);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(result, Car::RunCode::WORKING);

}

TEST_F(CarAssembleTestFixture, runProducedCarTestBrokenEngine)
{
	assembler->selectCarType(Car::CarType::SEDAN);
	assembler->selectEngine(Engine::BROKEN);
	assembler->selectBreak(Break::MANDO);
	assembler->selectSteeringSystem(SteeringSystem::BOSCH_S);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(assembler->car->getCarType(), Car::CarType::SEDAN);
	EXPECT_EQ(assembler->car->getEngine()->getType(), Engine::BROKEN);
	EXPECT_EQ(assembler->car->getBrakeSystem()->getType(), Break::MANDO);
	EXPECT_EQ(assembler->car->getSteeringSystem()->getType(), SteeringSystem::BOSCH_S);
	EXPECT_EQ(result, Car::RunCode::BROKEN_ENGINE);

}

TEST_F(CarAssembleTestFixture, runProducedCarInvalidTest)
{
	assembler->selectCarType(Car::CarType::SEDAN);
	assembler->selectEngine(Engine::GM);
	assembler->selectBreak(Break::CONTINENTAL);
	assembler->selectSteeringSystem(SteeringSystem::BOSCH_S);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(result, Car::RunCode::NOT_WORKING);

}

TEST_F(CarAssembleTestFixture, runProducedCarInvalidTest2)
{
	assembler->selectCarType(Car::CarType::SUV);
	assembler->selectEngine(Engine::TOYOTA);
	assembler->selectBreak(Break::CONTINENTAL);
	assembler->selectSteeringSystem(SteeringSystem::BOSCH_S);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(result, Car::RunCode::NOT_WORKING);

}

TEST_F(CarAssembleTestFixture, runProducedCarInvalidTest3)
{
	assembler->selectCarType(Car::CarType::SUV);
	assembler->selectEngine(Engine::TOYOTA);
	assembler->selectBreak(Break::CONTINENTAL);
	assembler->selectSteeringSystem(SteeringSystem::BOSCH_S);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(result, Car::RunCode::NOT_WORKING);
}

TEST_F(CarAssembleTestFixture, runProducedCarInvalidTest4)
{
	assembler->selectCarType(Car::CarType::SUV);
	assembler->selectEngine(Engine::TOYOTA);
	assembler->selectBreak(Break::BOSCH_B);
	assembler->selectSteeringSystem(SteeringSystem::MOBIS);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(result, Car::RunCode::NOT_WORKING);
}

TEST_F(CarAssembleTestFixture, runProducedCarInvalidTest5)
{
	assembler->selectCarType(Car::CarType::TRUCK);
	assembler->selectEngine(Engine::WIA);
	assembler->selectBreak(Break::BOSCH_B);
	assembler->selectSteeringSystem(SteeringSystem::BOSCH_S);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(result, Car::RunCode::NOT_WORKING);
}



TEST_F(CarAssembleTestFixture, runProducedCarInvalidTest6)
{
	assembler->selectCarType(Car::CarType::TRUCK);
	assembler->selectEngine(Engine::TOYOTA);
	assembler->selectBreak(Break::MANDO);
	assembler->selectSteeringSystem(SteeringSystem::MOBIS);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(result, Car::RunCode::NOT_WORKING);
}

TEST_F(CarAssembleTestFixture, runProducedCarInvalidTest7)
{
	assembler->selectCarType(Car::CarType::TRUCK);
	assembler->selectEngine(Engine::TOYOTA);
	assembler->selectBreak(Break::BOSCH_B);
	assembler->selectSteeringSystem(SteeringSystem::MOBIS);
	int result = assembler->car->runProducedCar();
	EXPECT_EQ(result, Car::RunCode::NOT_WORKING);
}


TEST_F(CarAssembleTestFixture, testProducedCarTest0)
{
	assembler->selectCarType(Car::CarType::SUV);
	assembler->selectEngine(Engine::GM);
	assembler->selectBreak(Break::BOSCH_B);
	assembler->selectSteeringSystem(SteeringSystem::BOSCH_S);
	std::string result = assembler->car->testProducedCar();
	EXPECT_EQ(result, testPassMsg);
}

TEST_F(CarAssembleTestFixture, testProducedCarTest1)
{
	assembler->selectCarType(Car::CarType::SEDAN);
	assembler->selectEngine(Engine::TOYOTA);
	assembler->selectBreak(Break::CONTINENTAL);
	assembler->selectSteeringSystem(SteeringSystem::MOBIS);
	std::string result = assembler->car->testProducedCar();
	EXPECT_EQ(result,  testFailMsg + SedanWithContinentalTestMsg);
}

TEST_F(CarAssembleTestFixture, testProducedCarTest2)
{
	assembler->selectCarType(Car::CarType::SUV);
	assembler->selectEngine(Engine::TOYOTA);
	assembler->selectBreak(Break::CONTINENTAL);
	assembler->selectSteeringSystem(SteeringSystem::MOBIS);
	std::string result = assembler->car->testProducedCar();
	EXPECT_EQ(result, testFailMsg + SuvWithToyotaTestMsg);
}

TEST_F(CarAssembleTestFixture, testProducedCarTest3)
{
	assembler->selectCarType(Car::CarType::TRUCK);
	assembler->selectEngine(Engine::WIA);
	assembler->selectBreak(Break::CONTINENTAL);
	assembler->selectSteeringSystem(SteeringSystem::MOBIS);
	std::string result = assembler->car->testProducedCar();
	EXPECT_EQ(result, testFailMsg + TruckWithWiaTestMsg);
}

TEST_F(CarAssembleTestFixture, testProducedCarTest4)
{
	assembler->selectCarType(Car::CarType::TRUCK);
	assembler->selectEngine(Engine::TOYOTA);
	assembler->selectBreak(Break::MANDO);
	assembler->selectSteeringSystem(SteeringSystem::MOBIS);
	std::string result = assembler->car->testProducedCar();
	EXPECT_EQ(result, testFailMsg + TruckWithMandoTestMsg);
}

TEST_F(CarAssembleTestFixture, testProducedCarTest5)
{
	assembler->selectCarType(Car::CarType::TRUCK);
	assembler->selectEngine(Engine::TOYOTA);
	assembler->selectBreak(Break::BOSCH_B);
	assembler->selectSteeringSystem(SteeringSystem::MOBIS);
	std::string result = assembler->car->testProducedCar();
	EXPECT_EQ(result, testFailMsg + BoschWithNotBoschTestMsg);
}

#endif