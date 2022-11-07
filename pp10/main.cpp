#include <iostream>
#include <math.h>
#include "MuSoenMath.h"
using namespace std;
int main()
{  
    //30도 계산식
    const float pi = 3.1415;
    double a = sin(30 * pi / 180);
    double b = cos(30 * pi / 180);

    //삼각함수 선언
    //좌표값(1,1,1) 
    vec3 Vec = vec3(1, 1, 1);

    //(3,5)이동행렬
    mat3 Translate = mat3(1.0, 0.0, 0.0,
                          0.0, 1.0, 0.0,
                          3.0, 5.0, 1.0);
    //30도 회전행렬
    mat3 Rotate = mat3(b, -a, 0.0,
                       a, b, 0.0,
                       0.0, 0.0, 1.0);
    //2배 크기행렬
    mat3 Scale = mat3(2.0, 0.0, 0.0,
                      0.0, 2.0, 0.0,
                      0.0, 0.0, 1.0);
    //결과값 = 좌표값 * 이동행렬 * 회전행렬 * 크기행렬
    vec3 p = Vec * Translate * Rotate * Scale;
    //결과값
    cout << "x:" << " " << p.x << " " << "y:" << " " << p.y << " " << "z:" << " " << p.z << endl;
}