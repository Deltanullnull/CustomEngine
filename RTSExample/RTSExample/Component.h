#include <list>
#include <vector>
#include <iostream>
#include <map>
#include <chrono>
#include "Renderer.h"

#pragma once

using namespace std;

class Core;

class Component
{
public:
	Component();
	~Component();

	virtual void UpdateInput();

	virtual void AddChild(Component * child);

	virtual void RemoveChild(Component * child);

	virtual void Accept(Renderer * renderer);

	virtual void AddInput(unsigned char key, void(Component::*func) (), Component& obj);


protected:

	list<Component*> m_listChildren;

	list<Core*> m_listCores;

	std::map<unsigned char, bool> m_keyMap;
	std::map<unsigned char, void(Component::*) ()> m_keyFuncMap;
	
	Component * m_pParent = nullptr;
};

