#include <list>
#include <vector>
#include "Traverser.h"

#pragma once

using namespace std;

class Component
{
public:
	Component();
	~Component();

	virtual void AddChild(Component * child);

	virtual void RemoveChild(Component * child);

	virtual void Accept(Traverser * traverser);

private:

	list<Component*> m_listChildren;
	
	Component * m_pParent = nullptr;
};

