#include "Component.h"


Component::Component()
{
}


Component::~Component()
{
}

void Component::GenerateID()
{
	id = Randomizer::GetRandomInt();

	cout << "ID " << to_string(id) << " created" << endl;
}

void Component::UpdateInput()
{
	for (std::map<unsigned char, bool>::iterator it = m_keyMap.begin(); it != m_keyMap.end(); it++)
	{
		unsigned char key = (*it).first;

		if (m_keyMap[key])
		{
			//cout << "Update input " << to_string((int)key) << " at " << to_string(id) << endl;
			if (functions.find(key) != functions.end())
			{
				for (std::function<void(Component*)> func : functions[key])
				{
					cout << "Updating" << endl;
					func(this);
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

void Component::AddAction(unsigned char key, std::function<void(Component*)> func)
{
	int keyC = (int)key;

	cout << "Adding action for " << to_string(keyC) << " at " << to_string(id) << endl;

	functions[key].push_back(func);
}
