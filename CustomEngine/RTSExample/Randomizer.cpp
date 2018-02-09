#include "Randomizer.h"

std::mt19937 Randomizer::engine;
std::uniform_int_distribution<> Randomizer::distInt;

void Randomizer::Init()
{
	std::random_device seed_gen;

	engine = std::mt19937(seed_gen());

	distInt = std::uniform_int_distribution<>();
}

double Randomizer::GetRandomDouble()
{
	
}


int Randomizer::GetRandomInt()
{
	return distInt(engine);
}