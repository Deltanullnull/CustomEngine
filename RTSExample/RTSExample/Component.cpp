#include "Component.h"


Component::Component()
{
}


Component::~Component()
{
}

void Component::UpdateInput()
{
	/*for (std::map<unsigned char, bool>::iterator it = m_keyMap.begin(); it != m_keyMap.end(); it++)
	{
		unsigned char key = (*it).first;

		if (m_keyMap[key])
		{
			if (m_keyFuncMap.find(key) != m_keyFuncMap.end())
				(this->*m_keyFuncMap[key])();
		}
	}

	for (Component * child : m_listChildren)
	{
		if (child == nullptr)
			continue;

		child->UpdateInput();
	}*/
}

void Component::AddChild(Component * child)
{
	m_listChildren.push_back(child);

	child->m_pParent = this;
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

	for (list<Component *>::iterator it = m_listChildren.begin(); it != m_listChildren.end(); it++)
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

	for (list<Component *>::iterator it = m_listChildren.begin(); it != m_listChildren.end(); it++)
	{
		Component * child = (*it);

		if (child == nullptr)
			continue;

		child->Accept(traverser);
	}

	traverser->PostVisit(this);
}

void Component::AddInput(unsigned char key, void(Component::*func) (), Component& obj)
{
	//m_keyMap[key] = false;

	//m_keyFuncMap[key] = func;
}
