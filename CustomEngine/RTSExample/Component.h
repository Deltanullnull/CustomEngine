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

enum struct MouseInput
{
	Pressed,
	Clicked
};

class Component
{
public:
	Component();
	~Component();

	virtual void GenerateID();

	virtual void UpdateInput();

	virtual void KeyUp(unsigned char key);

	virtual void KeyDown(unsigned char key);

	virtual void GetMouseInput(int & x, int & y);

	void SetMousePosition(int deltaX, int deltaY);

	virtual void MouseDown(int key);

	virtual void AddChild(Component * child);

	virtual void RemoveChild(Component * child);

	virtual void Accept(Traverser * traverser);

	virtual void Accept(Renderer * renderer);

	virtual void AddAction(unsigned char key, std::function<void()> func);

	virtual void AddAction(int mouseButton, MouseInput inputType, std::function<void()> func);

protected:

	list<Component*> m_listChildren;

	list<Core*> m_listCores;

	std::map<unsigned char, bool> m_keyMap;
	
	std::map<unsigned char, std::vector<std::function<void()>>> m_keyFunctionMap;
	
	std::map<int, bool> m_mouseBtnMap;
	std::map<int, bool> m_mouseClickMap; // Will be set to false after update complete

	std::map<int, std::vector<std::function<void()>>> m_mouseFunctionMap;

	std::map<int, std::vector<std::function<void(int, int)>>> m_mouseMovementFunctionMap;
	
	Component * m_pParent = nullptr;

	string cType = "Component";

	int id;

	int mouseX = 0;
	int mouseY = 0;
};

