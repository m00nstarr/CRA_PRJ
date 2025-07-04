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
        std::cout << "어떤 차량 타입을 선택할까요?\n";
        std::cout << "1. Sedan\n";
        std::cout << "2. SUV\n";
        std::cout << "3. Truck\n";
    }
    else if (step == Car::QuestionType::Engine) {
        printf(CLEAR_SCREEN);

        std::cout << "어떤 엔진을 탑재할까요?\n";
        std::cout << "0. 뒤로가기\n";
        std::cout << "1. GM\n";
        std::cout << "2. TOYOTA\n";
        std::cout << "3. WIA\n";
        std::cout << "4. 고장난 엔진\n";
    }
    else if (step == Car::QuestionType::BrakeSystem) {
        printf(CLEAR_SCREEN);

        std::cout << "어떤 제동장치를 선택할까요?\n";
        std::cout << "0. 뒤로가기\n";
        std::cout << "1. MANDO\n";
        std::cout << "2. CONTINENTAL\n";
        std::cout << "3. BOSCH\n";
    }
    else if (step == Car::QuestionType::SteeringSystem) {
        printf(CLEAR_SCREEN);

        std::cout << "어떤 조향장치를 선택할까요?\n";
        std::cout << "0. 뒤로가기\n";
        std::cout << "1. BOSCH\n";
        std::cout << "2. MOBIS\n";
    }
    else if (step == Car::QuestionType::RunOrTest) {
        printf(CLEAR_SCREEN);

        std::cout << "멋진 차량이 완성되었습니다.\n";
        std::cout << "어떤 동작을 할까요?\n";
        std::cout << "0. 처음 화면으로 돌아가기\n";
        std::cout << "1. RUN\n";
        std::cout << "2. Test\n";
    }

    std::cout << "===============================\n";
    std::cout << "INPUT > ";
}

bool validCheck(int step, int answer) {

    if (step == QuestionType::CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        return false;
    }
    if (step == QuestionType::Engine && !(answer >= 0 && answer <= 4))
    {
        printf("ERROR :: 엔진은 0 ~ 4 범위만 선택 가능\n");
        return false;
    }
    if (step == QuestionType::BrakeSystem && !(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: 제동장치는 0 ~ 3 범위만 선택 가능\n");
        return false;
    }
    if (step == QuestionType::SteeringSystem && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: 조향장치는 0 ~ 2 범위만 선택 가능\n");
        return false;
    }
    if (step == QuestionType::RunOrTest && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
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
            printf("바이바이\n");
            break;
        }

        // 숫자로 된 대답인지 확인
        char* checkNumber;
        int answer = strtol(buf, &checkNumber, 10); // 문자열을 10진수로 변환

        if (*checkNumber != '\0')
        {
            printf("ERROR :: 숫자만 입력 가능\n");
            delay(800);
            continue;
        }

        if (!validCheck(step, answer)) {
            delay(800);
            continue;
        }

        // 처음으로 돌아가기
        if (goStartPoint(step, answer))
        {
            step = QuestionType::CarType_Q;
            continue;
        }

        // 이전으로 돌아가기
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