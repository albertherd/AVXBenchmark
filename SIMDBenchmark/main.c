#include "main.h"

float x[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
float y[] = { 5, 10, 15, 20, 25, 30, 35, 40};

int main(int argc, int argv)
{
	DWORD startTicks, endTicks;

	do
	{
		startTicks = GetTickCount();
		DoNaiveAddition(ITERATIONS);
		endTicks = GetTickCount();
		printf("Naive addition: %d \t", endTicks - startTicks);

		startTicks = GetTickCount();
		DoAvxAddition(ITERATIONS);
		endTicks = GetTickCount();
		printf("AVX addition: %d \n", endTicks - startTicks);

		startTicks = GetTickCount();
		DoNaiveSubtraction(ITERATIONS);
		endTicks = GetTickCount();
		printf("Naive subtraction: %d \t", endTicks - startTicks);

		startTicks = GetTickCount();
		DoAvxSubtraction(ITERATIONS);
		endTicks = GetTickCount();
		printf("AVX subtraction: %d \n", endTicks - startTicks);
		
		startTicks = GetTickCount();
		DoNaiveMultiplication(ITERATIONS);
		endTicks = GetTickCount();
		printf("Naive multiplication: %d \t", endTicks - startTicks);

		startTicks = GetTickCount();
		DoAvxMultiplication(ITERATIONS);
		endTicks = GetTickCount();
		printf("AVX multiplication: %d \n", endTicks - startTicks);

		startTicks = GetTickCount();
		DoNaiveDivision(ITERATIONS);
		endTicks = GetTickCount();
		printf("Naive division: %d \t", endTicks - startTicks);

		startTicks = GetTickCount();
		DoAvxDivision(ITERATIONS);
		endTicks = GetTickCount();
		printf("AVX division: %d \n", endTicks - startTicks);

	} while (getchar());

	return 0;
}

void DoNaiveAddition(int iterations)
{
	float z[8];

	for (int i = 0; i < iterations; i++)
	{
		z[0] = x[0] + y[0];
		z[1] = x[1] + y[1];
		z[2] = x[2] + y[2];
		z[3] = x[3] + y[3];
		z[4] = x[4] + y[4];
		z[5] = x[5] + y[5];
		z[6] = x[6] + y[6];
		z[7] = x[7] + y[7];
	}
}

void DoNaiveSubtraction(int iterations)
{
	float z[8];

	for (int i = 0; i < iterations; i++)
	{
		z[0] = x[0] - y[0];
		z[1] = x[1] - y[1];
		z[2] = x[2] - y[2];
		z[3] = x[3] - y[3];
		z[4] = x[4] - y[4];
		z[5] = x[5] - y[5];
		z[6] = x[6] - y[6];
		z[7] = x[7] - y[7];
	}
}

void DoNaiveMultiplication(int iterations)
{
	float z[8];

	for (int i = 0; i < iterations; i++)
	{
		z[0] = x[0] * y[0];
		z[1] = x[1] * y[1];
		z[2] = x[2] * y[2];
		z[3] = x[3] * y[3];
		z[4] = x[4] * y[4];
		z[5] = x[5] * y[5];
		z[6] = x[6] * y[6];
		z[7] = x[7] * y[7];
	}
}

void DoNaiveDivision(int iterations)
{
	float z[8];

	for (int i = 0; i < iterations; i++)
	{
		z[0] = x[0] / y[0];
		z[1] = x[1] / y[1];
		z[2] = x[2] / y[2];
		z[3] = x[3] / y[3];
		z[4] = x[4] / y[4];
		z[5] = x[5] / y[5];
		z[6] = x[6] / y[6];
		z[7] = x[7] / y[7];
	}
}

void DoAvxAddition(int iterations)
{
	__m256 x256 = _mm256_loadu_ps((__m256*)x);
	__m256 y256 = _mm256_loadu_ps((__m256*)y);
	__m256 result;

	for (int i = 0; i < iterations; i++)
	{
		result = _mm256_add_ps(x256, y256);
	}
}

void DoAvxSubtraction(int iterations)
{
	__m256 x256 = _mm256_loadu_ps((__m256*)x);
	__m256 y256 = _mm256_loadu_ps((__m256*)y);
	__m256 result;

	for (int i = 0; i < iterations; i++)
	{
		result = _mm256_sub_ps(x256, y256);
	}
}

void DoAvxMultiplication(int iterations)
{
	__m256 x256 = _mm256_loadu_ps((__m256*)x);
	__m256 y256 = _mm256_loadu_ps((__m256*)y);
	__m256 result;

	for (int i = 0; i < iterations; i++)
	{
		result = _mm256_mul_ps(x256, y256);
	}
}


void DoAvxDivision(int iterations)
{
	__m256 x256 = _mm256_loadu_ps((__m256*)x);
	__m256 y256 = _mm256_loadu_ps((__m256*)y);
	__m256 result;

	for (int i = 0; i < iterations; i++)
	{
		result = _mm256_div_ps(x256, y256);
	}
}





