#ifdef _DEBUG
#include "gmock/gmock.h"

int main() {
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else
#define CLEAR_SCREEN "\033[H\033[2J"

#include "assemble.cpp"

enum QuestionType
{
    CarType_Q,
    Engine,
    BrakeSystem,
    SteeringSystem,
    RunOrTest,
};

int delay(int ms)
{
    int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }

    return sum;
}

void prompt(int step) {
    if (step == Car::QuestionType::CarType)
    {
        printf(CLEAR_SCREEN);

        std::cout << "        ______________\n";
        std::cout << "       /|            | \n";
        std::cout << "  ____/_|_____________|____\n";
        std::cout << " |                      O  |\n";
        std::cout << " '-(@)----------------(@)--'\n";
        std::cout << "===============================\n";
        std::cout << "� ���� Ÿ���� �����ұ��?\n";
        std::cout << "1. Sedan\n";
        std::cout << "2. SUV\n";
        std::cout << "3. Truck\n";
    }
    else if (step == Car::QuestionType::Engine) {
        printf(CLEAR_SCREEN);

        std::cout << "� ������ ž���ұ��?\n";
        std::cout << "0. �ڷΰ���\n";
        std::cout << "1. GM\n";
        std::cout << "2. TOYOTA\n";
        std::cout << "3. WIA\n";
        std::cout << "4. ���峭 ����\n";
    }
    else if (step == Car::QuestionType::BrakeSystem) {
        printf(CLEAR_SCREEN);

        std::cout << "� ������ġ�� �����ұ��?\n";
        std::cout << "0. �ڷΰ���\n";
        std::cout << "1. MANDO\n";
        std::cout << "2. CONTINENTAL\n";
        std::cout << "3. BOSCH\n";
    }
    else if (step == Car::QuestionType::SteeringSystem) {
        printf(CLEAR_SCREEN);

        std::cout << "� ������ġ�� �����ұ��?\n";
        std::cout << "0. �ڷΰ���\n";
        std::cout << "1. BOSCH\n";
        std::cout << "2. MOBIS\n";
    }
    else if (step == Car::QuestionType::RunOrTest) {
        printf(CLEAR_SCREEN);

        std::cout << "���� ������ �ϼ��Ǿ����ϴ�.\n";
        std::cout << "� ������ �ұ��?\n";
        std::cout << "0. ó�� ȭ������ ���ư���\n";
        std::cout << "1. RUN\n";
        std::cout << "2. Test\n";
    }

    std::cout << "===============================\n";
    std::cout << "INPUT > ";
}

bool validCheck(int step, int answer) {

    if (step == QuestionType::CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
        return false;
    }
    if (step == QuestionType::Engine && !(answer >= 0 && answer <= 4))
    {
        printf("ERROR :: ������ 0 ~ 4 ������ ���� ����\n");
        return false;
    }
    if (step == QuestionType::BrakeSystem && !(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: ������ġ�� 0 ~ 3 ������ ���� ����\n");
        return false;
    }
    if (step == QuestionType::SteeringSystem && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: ������ġ�� 0 ~ 2 ������ ���� ����\n");
        return false;
    }
    if (step == QuestionType::RunOrTest && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
        return false;
    }
    return true;
}

bool isExitCommand(const char* buf) {
    return strcmp(buf, "exit") == 0;
}

bool goStartPoint(int step, int answer) {
    return answer == 0 && step == QuestionType::RunOrTest;
}

int main()
{
    char buf[100];
    int step = QuestionType::CarType_Q;
    Car *car = new Car();

    while (1)
    {
        prompt(step);
        fgets(buf, sizeof(buf), stdin);

        char* context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (isExitCommand(buf))
        {
            printf("���̹���\n");
            break;
        }

        // ���ڷ� �� ������� Ȯ��
        char* checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ

        if (*checkNumber != '\0')
        {
            printf("ERROR :: ���ڸ� �Է� ����\n");
            delay(800);
            continue;
        }

        if (!validCheck(step, answer)) {
            delay(800);
            continue;
        }

        // ó������ ���ư���
        if (goStartPoint(step, answer))
        {
            step = QuestionType::CarType_Q;
            continue;
        }

        // �������� ���ư���
        if (answer == 0 && step >= 1)
        {
            step -= 1;
            continue;
        }

        if (step == QuestionType::RunOrTest && answer == 1)
        {
            car->runProducedCar();
            delay(2000);
            continue;
        }
        else if (step == QuestionType::RunOrTest && answer == 2)
        {
            printf("Test...\n");
            delay(1500);
            car->testProducedCar();
            delay(2000);
            continue;
        }


        switch (step) {

        case QuestionType::CarType_Q:
            car->selectCarType(answer);
			break;

        case QuestionType::Engine:
            car->selectEngine(answer);
            break;
        
        case QuestionType::BrakeSystem:
            car->selectbrakeSystem(answer);
			break;
        
        case QuestionType::SteeringSystem:
            car->selectSteeringSystem(answer);
            break;
        }

        delay(800);
        step += 1;
    }
}
#endif