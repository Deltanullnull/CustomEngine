#include "Component.h"



Component::Component()
{
}


Component::~Component()
{
}

void Component::GenerateID()
{
	//id = Randomizer::GetRandomInt();
}

Component * Component::GetChild(int idx)
{
	if (m_listChildren.size() > idx)
	{
		std::list<Component*>::iterator it = std::next(m_listChildren.begin(), idx);

		return *it;
	}

	return nullptr;

}

void Component::UpdateInput()
{
	for (std::map<unsigned char, bool>::iterator it = m_keyMap.begin(); it != m_keyMap.end(); it++)
	{
		unsigned char key = (*it).first;

		if (m_keyMap[key])
		{
			if (m_keyFunctionMap.find(key) != m_keyFunctionMap.end())
			{
				for (std::function<void()> func : m_keyFunctionMap[key])
				{
					func();
				}
			}
		}
	}

	for (Component * child : m_listChildren)
	{
		if (child == nullptr)
			continue;

		child->UpdateInput();
	}
}

void Component::KeyUp(unsigned char key)
{
	m_keyMap[key] = false;

	for (Component * child : m_listChildren)
	{
		child->KeyUp(key);
	}
}

void Component::KeyDown(unsigned char key)
{
	m_keyMap[key] = true;

	for (Component * child : m_listChildren)
	{
		child->KeyDown(key);
	}
}

void Component::GetMouseInput(int& x, int& y)
{
	x = mouseX;
	y = mouseY;
}

void Component::GetMouseDelta(int& x, int& y)
{
	x = mouseDeltaX;
	y = mouseDeltaY;
}

void Component::SetMousePosition(int x, int y)
{
	mouseX = x;
	mouseY = y;

	for (Component * child : m_listChildren)
	{
		child->SetMousePosition(x, y);
	}
}

void Component::SetMouseDelta(int x, int y)
{
	mouseDeltaX = x;
	mouseDeltaY = y;

	for (Component * child : m_listChildren)
	{
		child->SetMouseDelta(x, y);
	}
}

void Component::MouseDown(int key)
{

}

void Component::AddChild(Component * child)
{
	m_listChildren.push_back(child);

	child->m_pParent = this;

	child->Init();

	// TODO traverse through subtree and collect all lights
}

void Component::RemoveChild(Component * child)
{
	m_listChildren.remove(child);
}

void Component::Accept(Renderer * renderer)
{
	if (renderer == nullptr)
		return;

	//traverser->Visit(this);

	for (std::list<Component *>::iterator it = m_listChildren.begin(); it != m_listChildren.end(); it++)
	{
		Component * child = (*it);

		if (child == nullptr)
			continue;

		child->Accept(renderer);
	}

	//traverser->PostVisit(this);
}

void Component::Accept(Traverser * traverser)
{
	if (traverser == nullptr)
		return;

	traverser->Visit(this);

	for (std::list<Component *>::iterator it = m_listChildren.begin(); it != m_listChildren.end(); it++)
	{
		Component * child = (*it);

		if (child == nullptr)
			continue;

		child->Accept(traverser);
	}

	traverser->PostVisit(this);
}

//void Component::AddAction(unsigned char key, std::function<void(Component*)> func)
void Component::AddAction(unsigned char key, std::function<void()> func)
{
	int keyC = (int)key;

	m_keyFunctionMap[key].push_back(func);
}

void Component::AddAction(int mouseButton, MouseInput inputType, std::function<void()> func)
{
	m_mouseFunctionMap[mouseButton].push_back(func);
}
