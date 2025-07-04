#pragma once
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>


class Car {

public:
    int stack[10];

    enum QuestionType
    {
        CarType,
        Engine,
        BrakeSystem,
        SteeringSystem,
        RunOrTest,
    };

    enum CarType
    {
        SEDAN = 1,
        SUV,
        TRUCK
    };

    enum Engine
    {
        GM = 1,
        TOYOTA,
        WIA
    };

    enum brakeSystem
    {
        MANDO = 1,
        CONTINENTAL,
        BOSCH_B
    };

    enum SteeringSystem
    {
        BOSCH_S = 1,
        MOBIS
    };

    void selectCarType(int answer)
    {
        stack[CarType] = answer;
        if (answer == 1)
            printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
        if (answer == 2)
            printf("차량 타입으로 SUV을 선택하셨습니다.\n");
        if (answer == 3)
            printf("차량 타입으로 Truck을 선택하셨습니다.\n");
    }

    void selectEngine(int answer)
    {
        stack[Engine] = answer;
        if (answer == 1)
            printf("GM 엔진을 선택하셨습니다.\n");
        if (answer == 2)
            printf("TOYOTA 엔진을 선택하셨습니다.\n");
        if (answer == 3)
            printf("WIA 엔진을 선택하셨습니다.\n");
    }

    void selectbrakeSystem(int answer)
    {
        stack[BrakeSystem] = answer;
        if (answer == 1)
            printf("MANDO 제동장치를 선택하셨습니다.\n");
        if (answer == 2)
            printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
        if (answer == 3)
            printf("BOSCH 제동장치를 선택하셨습니다.\n");
    }

    void selectSteeringSystem(int answer)
    {
        stack[SteeringSystem] = answer;
        if (answer == 1)
            printf("BOSCH 조향장치를 선택하셨습니다.\n");
        if (answer == 2)
            printf("MOBIS 조향장치를 선택하셨습니다.\n");
    }

    int isValidCheck()
    {
        if (stack[CarType] == SEDAN && stack[BrakeSystem] == CONTINENTAL)
        {
            return false;
        }
        else if (stack[CarType] == SUV && stack[Engine] == TOYOTA)
        {
            return false;
        }
        else if (stack[CarType] == TRUCK && stack[Engine] == WIA)
        {
            return false;
        }
        else if (stack[CarType] == TRUCK && stack[BrakeSystem] == MANDO)
        {
            return false;
        }
        else if (stack[BrakeSystem] == BOSCH_B && stack[SteeringSystem] != BOSCH_S)
        {
            return false;
        }
        else
        {
            return true;
        }
        return true;
    }

    void runProducedCar()
    {
        if (isValidCheck() == false)
        {
            printf("자동차가 동작되지 않습니다\n");
        }
        else
        {
            if (stack[Engine] == 4)
            {
                printf("엔진이 고장나있습니다.\n");
                printf("자동차가 움직이지 않습니다.\n");
            }
            else
            {
                if (stack[CarType] == 1)
                    printf("Car Type : Sedan\n");
                if (stack[CarType] == 2)
                    printf("Car Type : SUV\n");
                if (stack[CarType] == 3)
                    printf("Car Type : Truck\n");
                if (stack[Engine] == 1)
                    printf("Engine : GM\n");
                if (stack[Engine] == 2)
                    printf("Engine : TOYOTA\n");
                if (stack[Engine] == 3)
                    printf("Engine : WIA\n");
                if (stack[BrakeSystem] == 1)
                    printf("Brake System : Mando");
                if (stack[BrakeSystem] == 2)
                    printf("Brake System : Continental\n");
                if (stack[BrakeSystem] == 3)
                    printf("Brake System : Bosch\n");
                if (stack[SteeringSystem] == 1)
                    printf("SteeringSystem : Bosch\n");
                if (stack[SteeringSystem] == 2)
                    printf("SteeringSystem : Mobis\n");

                printf("자동차가 동작됩니다.\n");
            }
        }
    }

    void testProducedCar()
    {
        if (stack[CarType] == SEDAN && stack[BrakeSystem] == CONTINENTAL)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Sedan에는 Continental제동장치 사용 불가\n");
        }
        else if (stack[CarType] == SUV && stack[Engine] == TOYOTA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("SUV에는 TOYOTA엔진 사용 불가\n");
        }
        else if (stack[CarType] == TRUCK && stack[Engine] == WIA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 WIA엔진 사용 불가\n");
        }
        else if (stack[CarType] == TRUCK && stack[BrakeSystem] == MANDO)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 Mando제동장치 사용 불가\n");
        }
        else if (stack[BrakeSystem] == BOSCH_B && stack[SteeringSystem] != BOSCH_S)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");
        }
    }


};
