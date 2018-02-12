#include <list>
#include <vector>
#include <iostream>
#include <map>
#include <chrono>
#include "Renderer.h"
#include "Traverser.h"
#include <functional>
#include "Randomizer.h"

#pragma once

using namespace std;

class Core;

class Component
{
public:
	Component();
	~Component();

	virtual void GenerateID();

	virtual void UpdateInput();

	virtual void KeyUp(unsigned char key);

	virtual void KeyDown(unsigned char key);

	virtual void AddChild(Component * child);

	virtual void RemoveChild(Component * child);

	virtual void Accept(Traverser * traverser);

	virtual void Accept(Renderer * renderer);

	virtual void AddAction(unsigned char key, std::function<void(Component*)>);


protected:

	list<Component*> m_listChildren;

	list<Core*> m_listCores;

	std::map<unsigned char, bool> m_keyMap;
	std::map<unsigned char, void(Component::*) ()> m_keyFuncMap;

	std::map<unsigned char, std::vector<std::function<void(Component*)>>> functions;
	
	Component * m_pParent = nullptr;

	string cType = "Component";

	int id;
};

