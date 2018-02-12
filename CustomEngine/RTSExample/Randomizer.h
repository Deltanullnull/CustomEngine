#pragma once

#include <random>

class Randomizer
{
public:

	static void Init();

	static double GetRandomDouble();

	static int GetRandomInt();

private:

 	//static std::random_device seed_gen;
	static std::mt19937 engine;

	static std::uniform_int_distribution<> distInt;
};