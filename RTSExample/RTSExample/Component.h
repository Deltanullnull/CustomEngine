#include <list>
#include <vector>
#include <iostream>
#include "Renderer.h"

#pragma once

using namespace std;

class Core;

class Component
{
public:
	Component();
	~Component();

	virtual void AddChild(Component * child);


	virtual void RemoveChild(Component * child);

	virtual void Accept(Renderer * renderer);


protected:

	list<Component*> m_listChildren;

	list<Core*> m_listCores;
	
	Component * m_pParent = nullptr;
};

