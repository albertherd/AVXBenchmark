#include "main.h"

float x[] = { 5, 10, 15, 20, 25, 30, 35, 40};
float y[] = { 10, 20, 30, 40, 50, 60, 70, 80 };

int main(int argc, int argv)
{
	DWORD startTicks, endTicks;

	do
	{
		startTicks = GetTickCount();
		DoNaiveAddition(ITERATIONS);
		endTicks = GetTickCount();

		printf("Naive implementation: %d \t", endTicks - startTicks);

		startTicks = GetTickCount();
		DoAvxAddition(ITERATIONS);
		endTicks = GetTickCount();

		printf("AVX implementation: %d \n", endTicks - startTicks);
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

void DoAvxAddition(int iterations)
{
	__m256 x256 = _mm256_loadu_ps((__m256*)x);
	__m256 y256 = _mm256_loadu_ps((__m256*)y);

	for (int i = 0; i < iterations; i++)
	{
		__m256 result = _mm256_add_ps(x256, y256);
	}
}



