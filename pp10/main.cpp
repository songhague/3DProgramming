#include <iostream>
#include <math.h>
#include "MuSoenMath.h"
using namespace std;
int main()
{  
    //30�� ����
    const float pi = 3.1415;
    double a = sin(30 * pi / 180);
    double b = cos(30 * pi / 180);

    //�ﰢ�Լ� ����
    //��ǥ��(1,1,1) 
    vec3 Vec = vec3(1, 1, 1);

    //(3,5)�̵����
    mat3 Translate = mat3(1.0, 0.0, 0.0,
                          0.0, 1.0, 0.0,
                          3.0, 5.0, 1.0);
    //30�� ȸ�����
    mat3 Rotate = mat3(b, -a, 0.0,
                       a, b, 0.0,
                       0.0, 0.0, 1.0);
    //2�� ũ�����
    mat3 Scale = mat3(2.0, 0.0, 0.0,
                      0.0, 2.0, 0.0,
                      0.0, 0.0, 1.0);
    //����� = ��ǥ�� * �̵���� * ȸ����� * ũ�����
    vec3 p = Vec * Translate * Rotate * Scale;
    //�����
    cout << "x:" << " " << p.x << " " << "y:" << " " << p.y << " " << "z:" << " " << p.z << endl;
}