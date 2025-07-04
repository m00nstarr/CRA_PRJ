#ifdef _DEBUG
#include "assemble.cpp"
#include "gmock/gmock.h"

class CarAssembleTestFixture : public testing::Test {
public:
	Car* car;

	void SetUp() override {
		car = new Car();
	}
};

TEST_F(CarAssembleTestFixture, ValidTest1)
{
	car->selectCarType(Car::CarType::SEDAN);
	car->selectbrakeSystem(Car::brakeSystem::MANDO);
	car->selectEngine(Car::Engine::GM);
	car->selectSteeringSystem(Car::SteeringSystem::BOSCH_S);
	

	EXPECT_EQ(car->isValidCheck(), true);
}

TEST_F(CarAssembleTestFixture, ValidTest2)
{
	car->selectCarType(Car::CarType::SEDAN);
	car->selectbrakeSystem(Car::brakeSystem::MANDO);
	car->selectEngine(Car::Engine::GM);
	car->selectSteeringSystem(Car::SteeringSystem::BOSCH_S);


	EXPECT_EQ(car->isValidCheck(), true);
}

#endif