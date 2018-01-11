#pragma once
#include <Windows.h>
#include <immintrin.h>
#include <stdio.h>

#define ITERATIONS 200000000

void DoNaiveAddition(int iterations);
void DoAvxAddition(int iterations);

void DoNaiveSubtraction(int iterations);
void DoAvxSubtraction(int iterations);

void DoNaiveMultiplication(int iterations);
void DoAvxMultiplication(int iterations);

void DoNaiveDivision(int iterations);
void DoAvxDivision(int iterations);
