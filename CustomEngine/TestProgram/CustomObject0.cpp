#include "CustomObject0.h"




CustomObject0::CustomObject0() : GameObject()
{
	Init();
}

CustomObject0::~CustomObject0()
{
}

void CustomObject0::Update()
{
	cout << "Custom update" << endl;
}

void CustomObject0::Init()
{
	cout << "Init " << endl;
}

