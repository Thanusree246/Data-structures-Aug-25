#include <stdio.h>
#include <math.h>

double calculateTriangleArea(double a, double b, double c) {

    double s = (a + b + c) / 2;

    
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}

int main() {
    double side1, side2, side3;

    printf("Enter the lengths of the three sides of the triangle: ");
    scanf("%lf %lf %lf", &side1, &side2, &side3);

    double area = calculateTriangleArea(side1, side2, side3);

    printf("Area of the triangle using Heron's formula: %lf\n", area);

    return 0;
}
