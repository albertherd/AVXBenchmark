#pragma once
#include <Windows.h>
#include <immintrin.h>
#include <stdio.h>

#define ITERATIONS 200000000

void DoNaiveAddition(int iterations);
void DoAvxAddition(int iterations);