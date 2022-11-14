#pragma once
//vec3에 좌표 x,y,z
struct vec3
{
	//vec3
	float x[3][1];
	vec3()
	{
		x[0][0] = 0;
		x[1][0] = 0;
		x[2][0] = 0;
	}
	vec3(float x_, float y_, float z_)
	{
		x[0][0] = x_;
		x[1][0] = y_;
		x[2][0] = z_;
	}
	void printvec3();
};

//vec1x3
struct vec1x3
{
	float x[1][3];
	vec1x3()
	{
		x[0][0] = 0;
		x[0][1] = 0;
		x[0][2] = 0;
	}

	vec1x3(float x_, float y_, float z_)
	{
		x[0][0] = x_;
		x[0][1] = y_;
		x[0][2] = z_;
	}
	void vec3to1x3(float x1, float y1, float z1);
	void printvec1x3();
};
void vec1x3::vec3to1x3(float x1, float y1, float z1)
{
	vec1x3 r;
	vec3 p(x1, y1, z1);

	for (int i = 0; i < 3; i++)
		r.x[0][i] = p.x[i][0];
}

//vec3와 vec3 +- 연산
vec3 operator+(vec3 a, vec3 b)
{
	vec3 result(a.x[0][0] + b.x[0][0], a.x[1][0] + b.x[1][0], a.x[2][0] + b.x[2][0]);
	return result;
}
vec3 operator-(vec3 a, vec3 b)
{
	vec3 result(a.x[0][0] - b.x[0][0], a.x[1][0] - b.x[1][0], a.x[2][0] - b.x[2][0]);
	return result;
}

//vec3와 vec3 */ 연산
vec3 operator*(float b, vec3 a) {
	vec3 result(a.x[0][0] * b, a.x[1][0] * b, a.x[2][0] * b);
	return result;
}
vec3 operator/(vec3 a, float b) {
	vec3 result(a.x[0][0] / b, a.x[1][0] / b, a.x[2][0] / b);
	return result;
}

//vec1x3와 vec1x3 +- 연산
vec1x3 operator+(vec1x3 a, vec1x3 b)
{
	vec1x3 result(a.x[0][0] + b.x[0][0], a.x[0][1] + b.x[0][1], a.x[0][2] + b.x[0][2]);
	return result;
}
vec1x3 operator-(vec1x3 a, vec1x3 b)
{
	vec1x3 result(a.x[0][0] - b.x[0][0], a.x[0][1] - b.x[0][1], a.x[0][2] - b.x[0][2]);
	return result;
}

//vec1x3와 상수 */ 연산
vec1x3 operator*(float a, vec1x3 b) {
	vec1x3 result(b.x[0][0] * a, b.x[0][1] * a, b.x[0][2] * a);
	return result;
}
vec1x3 operator*(vec1x3 b, float a) {
	vec1x3 result(b.x[0][0] * a, b.x[0][1] * a, b.x[0][2] * a);
	return result;
}
vec1x3 operator/(vec1x3 b, float a) {
	vec1x3 result(b.x[0][0] / a, b.x[0][1] / a, b.x[0][2] / a);
	return result;
}

//vec4
struct vec4
{
	float x[4][1];

	vec4()
	{
		x[0][0] = 0;
		x[1][0] = 0;
		x[2][0] = 0;
		x[3][0] = 0;
	}
	vec4(float x_, float y_, float z_, float w_)
	{
		x[0][0] = x_;
		x[1][0] = y_;
		x[2][0] = z_;
		x[3][0] = w_;
	}
	void printvec4();
};

//vec1x4
struct vec1x4
{
	float x[1][4];
	vec1x4()
	{
		x[0][0] = 0;
		x[0][1] = 0;
		x[0][2] = 0;
		x[0][3] = 0;
	}
	vec1x4(float x_, float y_, float z_, float w_)
	{
		x[0][0] = x_;
		x[0][1] = y_;
		x[0][2] = z_;
		x[0][3] = w_;
	}
	void printvec1x4();
};

//vec4와 vec4 +- 연산
vec4 operator+(vec4 a, vec4 b)
{
	vec4 result(a.x[0][0] + b.x[0][0], a.x[1][0] + b.x[1][0], a.x[2][0] + b.x[2][0], a.x[3][0] + b.x[3][0]);
	return result;
}
vec4 operator-(vec4 a, vec4 b)
{
	vec4 result(a.x[0][0] - b.x[0][0], a.x[1][0] - b.x[1][0], a.x[2][0] - b.x[2][0], a.x[3][0] - b.x[3][0]);
	return result;
}

//상수와 vec4 */연산
vec4 operator*(float b, vec4 a) {
	vec4 result(a.x[0][0] * b, a.x[1][0] * b, a.x[2][0] * b, a.x[3][0] * b);
	return result;
}
vec4 operator*(vec4 a, float b) {
	vec4 result(a.x[0][0] * b, a.x[1][0] * b, a.x[2][0] * b, a.x[3][0] * b);
	return result;
}
vec4 operator/(vec4 a, float b) {
	vec4 result(a.x[0][0] / b, a.x[1][0] / b, a.x[2][0] / b, a.x[3][0] / b);
	return result;
}

//vec1x4와vec1x4 +- 연산
vec1x4 operator+(vec1x4 a, vec1x4 b)
{
	vec1x4 result(a.x[0][0] + b.x[0][0], a.x[0][1] + b.x[0][1], a.x[0][2] + b.x[0][2], a.x[0][3] + b.x[0][3]);
	return result;
}
vec1x4 operator-(vec1x4 a, vec1x4 b)
{
	vec1x4 result(a.x[0][0] - b.x[0][0], a.x[0][1] - b.x[0][1], a.x[0][2] - b.x[0][2], a.x[0][3] - b.x[0][3]);
	return result;
}

//vec1x4와상수 */ 연산
vec1x4 operator*(float a, vec1x4 b) {
	vec1x4 result(b.x[0][0] * a, b.x[0][1] * a, b.x[0][2] * a, b.x[0][3] * a);
	return result;
}
vec1x4 operator/(vec1x4 b, float a) {
	vec1x4 result(b.x[0][0] / a, b.x[0][1] / a, b.x[0][2] / a, b.x[0][3] / a);
	return result;
}

//3*3행렬
struct mat3
{//mat3
	float a[3][3];

	mat3()
	{
		a[0][0] = 0; a[0][1] = 0; a[0][2] = 0;
		a[1][0] = 0; a[1][1] = 0; a[1][2] = 0;
		a[2][0] = 0; a[2][1] = 0; a[2][2] = 0;
	}
	mat3(float a_, float b_, float c_, float d_, float e_, float f_, float g_, float h_, float i_)
	{
		a[0][0] = a_; a[0][1] = b_; a[0][2] = c_;
		a[1][0] = d_; a[1][1] = e_; a[1][2] = f_;
		a[2][0] = g_; a[2][1] = h_; a[2][2] = i_;
	}
	void operator=(const mat3& a);
	void printmat3();
	void Mat3identity();
	void Mat3Transpose();
	void multiplytransposematrix(mat3 x, mat3 y);
};

//mat3와 mat3 연산
mat3 operator*(mat3 a, mat3 b)
{
	mat3 r;

	r.a[0][0] = (a.a[0][0] * b.a[0][0]) + (a.a[0][1] * b.a[1][0]) + (a.a[0][2] * b.a[2][0]);
	r.a[0][1] = (a.a[0][0] * b.a[0][1]) + (a.a[0][1] * b.a[1][1]) + (a.a[0][2] * b.a[2][1]);
	r.a[0][2] = (a.a[0][0] * b.a[0][2]) + (a.a[0][1] * b.a[1][2]) + (a.a[0][2] * b.a[2][2]);

	r.a[1][0] = (a.a[1][0] * b.a[0][0]) + (a.a[1][1] * b.a[1][0]) + (a.a[1][2] * b.a[2][0]);
	r.a[1][1] = (a.a[1][0] * b.a[0][1]) + (a.a[1][1] * b.a[1][1]) + (a.a[1][2] * b.a[2][1]);
	r.a[1][2] = (a.a[1][0] * b.a[0][2]) + (a.a[1][1] * b.a[1][2]) + (a.a[1][2] * b.a[2][2]);

	r.a[2][0] = (a.a[2][0] * b.a[0][0]) + (a.a[2][1] * b.a[1][0]) + (a.a[2][2] * b.a[2][0]);
	r.a[2][1] = (a.a[2][0] * b.a[0][1]) + (a.a[2][1] * b.a[1][1]) + (a.a[2][2] * b.a[2][1]);
	r.a[2][2] = (a.a[2][0] * b.a[0][2]) + (a.a[2][1] * b.a[1][2]) + (a.a[2][2] * b.a[2][2]);
	//연산 결과값 반환
	return r;
}
//mat3 와 상수 */ 연산
mat3 operator*(float a, mat3 b) {

	mat3 r;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.a[i][j] = a * b.a[i][j];
	return r;
}
mat3 operator*(mat3 b, float a) {

	mat3 r;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.a[i][j] = b.a[i][j] * a;
	return r;
}
mat3 operator/(mat3 b, float a) {

	mat3 r;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.a[i][j] = b.a[i][j] / a;
	return r;
}

//mat3 와 mat3 +- 연산
mat3 operator+(mat3 a, mat3 b) {
	mat3 r;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.a[i][j] = a.a[i][j] + b.a[i][j];

	return r;
}
mat3 operator-(mat3 a, mat3 b) {
	mat3 r;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.a[i][j] = a.a[i][j] - b.a[i][j];
	return r;
}

//mat3와 vec3 연산
vec3 operator*(mat3 b, vec3 a)
{

	vec3 r;
	r.x[0][0] = (a.x[0][0] * b.a[0][0]) + (a.x[1][0] * b.a[0][1]) + (a.x[2][0] * b.a[0][2]);
	r.x[1][0] = (a.x[0][0] * b.a[1][0]) + (a.x[1][0] * b.a[1][1]) + (a.x[2][0] * b.a[1][2]);
	r.x[2][0] = (a.x[0][0] * b.a[2][0]) + (a.x[1][0] * b.a[2][1]) + (a.x[2][0] * b.a[2][2]);
	return r;
}
vec3 operator*(vec3 a, mat3 b)
{
	b.Mat3Transpose();
	vec3 r;
	vec1x3 a1;
	for (int i = 0; i < 3; i++)
		a1.x[0][i] = a.x[i][0];
	r.x[0][0] = (a1.x[0][0] * b.a[0][0]) + (a1.x[0][1] * b.a[1][0]) + (a1.x[0][2] * b.a[2][0]);
	r.x[0][1] = (a1.x[0][0] * b.a[0][1]) + (a1.x[0][1] * b.a[1][1]) + (a1.x[0][2] * b.a[2][1]);
	r.x[0][2] = (a1.x[0][0] * b.a[0][2]) + (a1.x[0][1] * b.a[1][2]) + (a1.x[0][2] * b.a[2][2]);
	return r;
}

//vec1x3와 mat3 *연산
vec1x3 operator*(vec1x3 b, mat3 a)
{
	a.Mat3Transpose();
	vec1x3 r;
	r.x[0][0] = (b.x[0][0] * a.a[0][0]) + (b.x[0][1] * a.a[1][0]) + (b.x[0][2] * a.a[2][0]);
	r.x[0][1] = (b.x[0][0] * a.a[0][1]) + (b.x[0][1] * a.a[1][1]) + (b.x[0][2] * a.a[2][1]);
	r.x[0][2] = (b.x[0][0] * a.a[0][2]) + (b.x[0][1] * a.a[1][2]) + (b.x[0][2] * a.a[2][2]);
	return r;
}
vec1x3 operator*(mat3 b, vec1x3 a)
{
	vec1x3 r;
	vec3 a1;
	for (int i = 0; i < 3; i++)
		a1.x[i][0] = a.x[0][i];

	r.x[0][0] = (a1.x[0][0] * b.a[0][0]) + (a1.x[1][0] * b.a[0][1]) + (a1.x[2][0] * b.a[0][2]);
	r.x[0][1] = (a1.x[0][0] * b.a[1][0]) + (a1.x[1][0] * b.a[1][1]) + (a1.x[2][0] * b.a[1][2]);
	r.x[0][2] = (a1.x[0][0] * b.a[2][0]) + (a1.x[1][0] * b.a[2][1]) + (a1.x[2][0] * b.a[2][2]);
	return r;
}

//4*4행렬
struct mat4
{
	float b[4][4];

	mat4() {
		b[0][0] = 0; b[0][1] = 0; b[0][2] = 0; b[0][3] = 0;
		b[1][0] = 0; b[1][1] = 0; b[1][2] = 0; b[1][3] = 0;
		b[2][0] = 0; b[2][1] = 0; b[2][2] = 0; b[2][3] = 0;
		b[3][0] = 0; b[3][1] = 0; b[3][2] = 0; b[3][3] = 0;
	}

	mat4(float m4_1, float m4_2, float m4_3, float m4_4, float m4_5, float m4_6, float m4_7, float m4_8, float m4_9, float m4_10, float m4_11, float m4_12, float m4_13, float m4_14, float m4_15, float m4_16) {
		b[0][0] = m4_1; b[0][1] = m4_2; b[0][2] = m4_3; b[0][3] = m4_4;
		b[1][0] = m4_5; b[1][1] = m4_6; b[1][2] = m4_7; b[1][3] = m4_8;
		b[2][0] = m4_9; b[2][1] = m4_10; b[2][2] = m4_11; b[2][3] = m4_12;
		b[3][0] = m4_13; b[3][1] = m4_14; b[3][2] = m4_15; b[3][3] = m4_16;
	}
	void Mat4Transpose();
	void printmat4();
	void Mat4Identity();
	void operator=(const mat4& a);
	void multiplytransposematrix(mat4 a, mat4 b);
};

//mat4와 mat4 연산
mat4 operator*(mat4 a, mat4 b)
{
	mat4 r;

	r.b[0][0] = (a.b[0][0] * b.b[0][0]) + (a.b[0][1] * b.b[1][0]) + (a.b[0][2] * b.b[2][0]) + (a.b[0][3] * b.b[3][0]);
	r.b[0][1] = (a.b[0][0] * b.b[0][1]) + (a.b[0][1] * b.b[1][1]) + (a.b[0][2] * b.b[2][1]) + (a.b[0][3] * b.b[3][1]);
	r.b[0][2] = (a.b[0][0] * b.b[0][2]) + (a.b[0][1] * b.b[1][2]) + (a.b[0][2] * b.b[2][2]) + (a.b[0][3] * b.b[3][2]);
	r.b[0][3] = (a.b[0][0] * b.b[0][3]) + (a.b[0][1] * b.b[1][3]) + (a.b[0][2] * b.b[2][3]) + (a.b[0][3] * b.b[3][3]);

	r.b[1][0] = (a.b[1][0] * b.b[0][0]) + (a.b[1][1] * b.b[1][0]) + (a.b[1][2] * b.b[2][0]) + (a.b[1][3] * b.b[3][0]);
	r.b[1][1] = (a.b[1][0] * b.b[0][1]) + (a.b[1][1] * b.b[1][1]) + (a.b[1][2] * b.b[2][1]) + (a.b[1][3] * b.b[3][1]);
	r.b[1][2] = (a.b[1][0] * b.b[0][2]) + (a.b[1][1] * b.b[1][2]) + (a.b[1][2] * b.b[2][2]) + (a.b[1][3] * b.b[3][2]);
	r.b[1][3] = (a.b[1][0] * b.b[0][3]) + (a.b[1][1] * b.b[1][3]) + (a.b[1][2] * b.b[2][3]) + (a.b[1][3] * b.b[3][3]);

	r.b[2][0] = (a.b[2][0] * b.b[0][0]) + (a.b[2][1] * b.b[1][0]) + (a.b[2][2] * b.b[2][0]) + (a.b[2][3] * b.b[3][0]);
	r.b[2][1] = (a.b[2][0] * b.b[0][1]) + (a.b[2][1] * b.b[1][1]) + (a.b[2][2] * b.b[2][1]) + (a.b[2][3] * b.b[3][1]);
	r.b[2][2] = (a.b[2][0] * b.b[0][2]) + (a.b[2][1] * b.b[1][2]) + (a.b[2][2] * b.b[2][2]) + (a.b[2][3] * b.b[3][2]);
	r.b[2][3] = (a.b[2][0] * b.b[0][3]) + (a.b[2][1] * b.b[1][3]) + (a.b[2][2] * b.b[2][3]) + (a.b[2][3] * b.b[3][3]);

	r.b[3][0] = (a.b[3][0] * b.b[0][0]) + (a.b[3][1] * b.b[1][0]) + (a.b[3][2] * b.b[2][0]) + (a.b[3][3] * b.b[3][0]);
	r.b[3][1] = (a.b[3][0] * b.b[0][1]) + (a.b[3][1] * b.b[1][1]) + (a.b[3][2] * b.b[2][1]) + (a.b[3][3] * b.b[3][1]);
	r.b[3][2] = (a.b[3][0] * b.b[0][2]) + (a.b[3][1] * b.b[1][2]) + (a.b[3][2] * b.b[2][2]) + (a.b[3][3] * b.b[3][2]);
	r.b[3][3] = (a.b[3][0] * b.b[0][3]) + (a.b[3][1] * b.b[1][3]) + (a.b[3][2] * b.b[2][3]) + (a.b[3][3] * b.b[3][3]);

	return r;
}

//mat4와 vec4 연산
vec4 operator*(mat4 b, vec4 a)
{
	vec4 r;
	r.x[0][0] = (a.x[0][0] * b.b[0][0]) + (a.x[1][0] * b.b[0][1]) + (a.x[2][0] * b.b[0][2]) + (a.x[3][0] * b.b[0][3]);
	r.x[1][0] = (a.x[0][0] * b.b[1][0]) + (a.x[1][0] * b.b[1][1]) + (a.x[2][0] * b.b[1][2]) + (a.x[3][0] * b.b[1][3]);
	r.x[2][0] = (a.x[0][0] * b.b[2][0]) + (a.x[1][0] * b.b[2][1]) + (a.x[2][0] * b.b[2][2]) + (a.x[3][0] * b.b[2][3]);
	r.x[3][0] = (a.x[0][0] * b.b[3][0]) + (a.x[1][0] * b.b[3][1]) + (a.x[2][0] * b.b[3][2]) + (a.x[3][0] * b.b[3][3]);
	return r;
}
//vec4와 mat4 연산
vec4 operator*(vec4 b, mat4 a)
{
	a.Mat4Transpose();
	vec1x4 b1;
	vec4 r;
	for (int i = 0; i < 4; i++)
		b1.x[0][i] = b.x[i][0];

	r.x[0][0] = (b1.x[0][0] * a.b[0][0]) + (b1.x[0][1] * a.b[1][0]) + (b1.x[0][2] * a.b[2][0]) + (b1.x[0][3] * a.b[3][0]);
	r.x[1][0] = (b1.x[0][0] * a.b[0][1]) + (b1.x[0][1] * a.b[1][1]) + (b1.x[0][2] * a.b[2][1]) + (b1.x[0][3] * a.b[3][1]);
	r.x[2][0] = (b1.x[0][0] * a.b[0][2]) + (b1.x[0][1] * a.b[1][2]) + (b1.x[0][2] * a.b[2][2]) + (b1.x[0][3] * a.b[3][2]);
	r.x[3][0] = (b1.x[0][0] * a.b[0][3]) + (b1.x[0][1] * a.b[1][3]) + (b1.x[0][2] * a.b[2][3]) + (b1.x[0][3] * a.b[3][3]);
	return r;
}

//vec1x4와 mat4 연산
vec1x4 operator*(vec1x4 b, mat4 a)
{
	a.Mat4Transpose();
	vec1x4 r;
	r.x[0][0] = (b.x[0][0] * a.b[0][0]) + (b.x[0][1] * a.b[1][0]) + (b.x[0][2] * a.b[2][0]) + (b.x[0][3] * a.b[3][0]);
	r.x[0][1] = (b.x[0][0] * a.b[0][1]) + (b.x[0][1] * a.b[1][1]) + (b.x[0][2] * a.b[2][1]) + (b.x[0][3] * a.b[3][1]);
	r.x[0][2] = (b.x[0][0] * a.b[0][2]) + (b.x[0][1] * a.b[1][2]) + (b.x[0][2] * a.b[2][2]) + (b.x[0][3] * a.b[3][2]);
	r.x[0][3] = (b.x[0][0] * a.b[0][3]) + (b.x[0][1] * a.b[1][3]) + (b.x[0][2] * a.b[2][3]) + (b.x[0][3] * a.b[3][3]);
	return r;
}

//mat4와 vec1x4 연산
vec1x4 operator*(mat4 b, vec1x4 a)
{
	vec4 a1;
	vec1x4 r;
	for (int i = 0; i < 4; i++)
		a1.x[i][0] = a.x[0][i];

	r.x[0][0] = (a1.x[0][0] * b.b[0][0]) + (a1.x[1][0] * b.b[0][1]) + (a1.x[2][0] * b.b[0][2]) + (a1.x[3][0] * b.b[0][3]);
	r.x[0][1] = (a1.x[0][0] * b.b[1][0]) + (a1.x[1][0] * b.b[1][1]) + (a1.x[2][0] * b.b[1][2]) + (a1.x[3][0] * b.b[1][3]);
	r.x[0][2] = (a1.x[0][0] * b.b[2][0]) + (a1.x[1][0] * b.b[2][1]) + (a1.x[2][0] * b.b[2][2]) + (a1.x[3][0] * b.b[2][3]);
	r.x[0][3] = (a1.x[0][0] * b.b[3][0]) + (a1.x[1][0] * b.b[3][1]) + (a1.x[2][0] * b.b[3][2]) + (a1.x[3][0] * b.b[3][3]);
	return r;
}
//mat4와 상수 */연산
mat4 operator*(float a, mat4 b) {

	mat4 r;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			r.b[i][j] = a * b.b[i][j];

	return r;
}
mat4 operator*(mat4 b, float a) {

	mat4 r;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			r.b[i][j] = b.b[i][j] * a;

	return r;
}
mat4 operator/(mat4 b, float a) {

	mat4 r;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			r.b[i][j] = b.b[i][j] / a;

	return r;
}

//mat4와 상수 +-연산
mat4 operator+(mat4 a, mat4 b) {
	mat4 r;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			r.b[i][j] = a.b[i][j] + b.b[i][j];
	return r;
}
mat4 operator-(mat4 a, mat4 b) {
	mat4 r;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			r.b[i][j] = a.b[i][j] - b.b[i][j];
	return r;
}