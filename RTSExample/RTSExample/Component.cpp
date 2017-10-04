#include "Component.h"


Component::Component()
{
}


Component::~Component()
{
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
