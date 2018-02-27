#include "Leaf.h"
#include "Transformation.h"


Leaf::Leaf()
{
}


Leaf::~Leaf()
{
}

void Leaf::GetMouseInput(int& x, int& y)
{
	m_transform->GetMouseInput(x, y);
	
}