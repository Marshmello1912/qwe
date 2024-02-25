

#include <iostream>

int main()
{
    int line_count = 0;
    std::cout << "Введите количество строк \n";
    std::cin >> line_count;
    std::cout << "Введите значения x/y \n";
    float* X_points = new float[line_count];
    float* Y_points = new float[line_count];
    for (int i = 0; i < line_count; i++) {
        std::cin >> X_points[i];
        std::cin >> Y_points[i];
    }
    std::cout << "1. a0 * x\n";
    std::cout << "2. a0 + a1 * x\n";
    int var;
    std::cin >> var;

    if (var == 1) {
        float b22 = 0;
        float c2 = 0;
        for (int i = 0; i < line_count; i++) {
            b22 += X_points[i];
            c2 += Y_points[i];
        }
        float a0 = c2 / b22;
        for (int i = 0; i < line_count; i++) {
            Y_points[i] = X_points[i] * a0;
        }
        std::cout << "b22 " << b22 << " c2 " << c2 << std::endl;
    }
    else {
        float b11 = line_count;
        float b12 = 0;
        float b22 = 0;
        float c1 = 0;
        float c2 = 0;
        for (int i = 0; i < line_count; i++) {
            b12 += X_points[i];
            b22 += X_points[i] * X_points[i];
            c1 += Y_points[i];
            c2 += Y_points[i] * X_points[i];
        }
        float b21 = b12;
        float a0 = (c1 * b22 - c2 * b12) / (b11 * b22 - b12 * b21);
        float a1 = (b11 * c2 - b21 * c1) / (b11 * b22 - b12 * b21);

        for (int i = 0; i < line_count; i++) {
            Y_points[i] = a0 + X_points[i] * a1;
        }
        std::cout << "b11 " << b11 << " b12 " << b12 << " c1 " << c1 << "\nb21 " << b21 << " b22 " << b22 << " c2 " << c2 << std::endl;

    }
    for (int i = 0; i < line_count; i++) {
        std::cout << "x\t" << X_points[i] << ' y\t' << Y_points[i] << std::endl;
    }
}

