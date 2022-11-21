#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include "MuSoenMath.h"
#pragma comment(lib, "OpenGL32")

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;

vec3 star[5];
vec3 transformedStar[5];
vec3 circle[360];
vec3 transformedCircle[360];

vec4 starColor[5];
vec4 circleColor[360];
vec4 transformedStarColor[5];
vec4 transformedCircleColor[360];

mat3 translate;
mat3 scale;
mat3 rotation;

//////////////////////////////////////////////////////////////////////////////////////////

bool rrotation = true;//크기 체크

float f = 1.0f;//회전 사용할거
float s = 1.0f;//크기 사용할거
float xx = 0.0f;//이동할때 사용할거

const float PI = 3.1415926f;

float a = sin(30 * PI / 180);
float b = cos(30 * PI / 180);

//////////////////////////////////////////////////////////////////////////////////////////

void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void Init()
{
    glfwSetErrorCallback(error_callback);
    //error_callback되면 밖으로 나가짐
    if (!glfwInit())
        exit(EXIT_FAILURE);
    //윈도우창을 720x720으로 정함
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();

    //object생성부
    /// Star(오망성) 생성
    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {

        star[i].x[0][0] = -sin(theta * PI / 180) * 0.5f;
        star[i].x[1][0] = cos(theta * PI / 180) * 0.5f;
        star[i].x[2][0] = 1.0f;

        starColor[i].x[0][0] = 0.3f;
        starColor[i].x[1][0] = 0.0f;
        starColor[i].x[2][0] = theta / 360.0f;
        starColor[i].x[3][0] = 0.7f;

        transformedStar[i] = star[i];
        transformedStarColor[i] = starColor[i];

        i++;
    }

    // 원 생성
    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].x[0][0] = -sin((float)theta * PI / 180) * 0.5;
        circle[theta].x[1][0] = cos((float)theta * PI / 180) * 0.5;
        circle[theta].x[2][0] = 1.0f;

        circleColor[theta].x[0][0] = 0.3f;
        circleColor[theta].x[1][0] = 0.0f;
        circleColor[theta].x[2][0] = (float)theta / 360.0f;
        circleColor[theta].x[3][0] = 0.7f;

        transformedCircle[theta] = circle[theta];
        transformedCircleColor[theta] = circleColor[theta];
    }
}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        xx += 0.001f;
        f -= 1.0f;

        //이동
        translate = mat3
        (
            1, 0, xx,
            0, 1, 0,
            0, 0, 1
        );
        //회전
        rotation = mat3
        (
            cos(f * PI / 180), -sin(f * PI / 180), 0,
            sin(f * PI / 180), cos(f * PI / 180), 0,
            0, 0, 1
        );
        //크기
        scale = mat3
        (
            s, 0, 0,
            0, s, 0,
            0, 0, 1
        );

        if (rrotation) //크기를 -0.01일씩 -함
        {
            s -= 0.01;
            //크기가 0.7보다 같거나 작으면 rrotation false 변환
            if (s <= 0.7)
            {
                rrotation = false;
            }
                
        }
        else  //크기를 +0.01일씩 +함
        {
            s += 0.01;
            //크기가 0.7보다 같거나 작으면 rrotation true 변환
            if (s >= 1.3)
            {
                rrotation = true;
            }
                
        }
       

        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i] = translate * rotation * scale * circle[i];
        }

        for (int i = 0; i < 5; i++)
        {
            transformedStar[i] = translate * rotation * scale * star[i];
        }

        //색 초기화
        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //선두께
        glLineWidth(7.0f);
        //오망성 그리기
        glBegin(GL_LINE_STRIP);
        int a = 0;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0], transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);
        a = 3;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0], transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);
        a = 1;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0], transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);
        a = 4;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0], transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);
        a = 2;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0], transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);
        a = 0;
        glColor4f(transformedStarColor[a].x[0][0], transformedStarColor[a].x[1][0], transformedStarColor[a].x[2][0], transformedStarColor[a].x[3][0]);
        glVertex3f(transformedStar[a].x[0][0], transformedStar[a].x[1][0], 0.0f);
        glEnd();

        //원생성
        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircleColor[theta].x[0][0], transformedCircleColor[theta].x[1][0], 
                transformedCircleColor[theta].x[2][0], transformedCircleColor[theta].x[3][0]);
            glVertex3f(transformedCircle[theta].x[0][0], transformedCircle[theta].x[1][0], 0.0f);
        }
        glEnd();

        //화면 스왑
        glfwSwapBuffers(window);
        glfwPollEvents();

        //렌더시간 측정
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        string fps_s = "FPS : " + to_string(fps);
        cout << fps_s << endl;
    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init();
    Update();
    Release();
    exit(EXIT_SUCCESS);
}