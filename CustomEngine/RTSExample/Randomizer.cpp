#include "Randomizer.h"

std::mt19937 Randomizer::engine;
std::uniform_int_distribution<> Randomizer::distInt;
std::uniform_real_distribution<> Randomizer::distReal;

void Randomizer::Init()
{
	std::random_device seed_gen;

	engine = std::mt19937(seed_gen());

	distInt = std::uniform_int_distribution<>();

	distReal = std::uniform_real_distribution<>();
}

double Randomizer::GetRandomDouble()
{
	return distReal(engine);
}


int Randomizer::GetRandomInt()
{
	return distInt(engine);
}