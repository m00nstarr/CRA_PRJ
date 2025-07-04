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
            printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
        if (answer == 2)
            printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
        if (answer == 3)
            printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
    }

    void selectEngine(int answer)
    {
        stack[Engine] = answer;
        if (answer == 1)
            printf("GM ������ �����ϼ̽��ϴ�.\n");
        if (answer == 2)
            printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
        if (answer == 3)
            printf("WIA ������ �����ϼ̽��ϴ�.\n");
    }

    void selectbrakeSystem(int answer)
    {
        stack[BrakeSystem] = answer;
        if (answer == 1)
            printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == 2)
            printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == 3)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    }

    void selectSteeringSystem(int answer)
    {
        stack[SteeringSystem] = answer;
        if (answer == 1)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        if (answer == 2)
            printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
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
            printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        }
        else
        {
            if (stack[Engine] == 4)
            {
                printf("������ ���峪�ֽ��ϴ�.\n");
                printf("�ڵ����� �������� �ʽ��ϴ�.\n");
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

                printf("�ڵ����� ���۵˴ϴ�.\n");
            }
        }
    }

    void testProducedCar()
    {
        if (stack[CarType] == SEDAN && stack[BrakeSystem] == CONTINENTAL)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Sedan���� Continental������ġ ��� �Ұ�\n");
        }
        else if (stack[CarType] == SUV && stack[Engine] == TOYOTA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("SUV���� TOYOTA���� ��� �Ұ�\n");
        }
        else if (stack[CarType] == TRUCK && stack[Engine] == WIA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� WIA���� ��� �Ұ�\n");
        }
        else if (stack[CarType] == TRUCK && stack[BrakeSystem] == MANDO)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� Mando������ġ ��� �Ұ�\n");
        }
        else if (stack[BrakeSystem] == BOSCH_B && stack[SteeringSystem] != BOSCH_S)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
        }
    }


};
