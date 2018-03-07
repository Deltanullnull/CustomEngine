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

void Leaf::GetMouseDelta(int& x, int& y)
{
	m_transform->GetMouseDelta(x, y);
}

