#pragma once

#include "Traverser.h"

class LightTraverser : public Traverser
{
public:
	LightTraverser();
	~LightTraverser();

	// Inherited via Traverser
	virtual void Visit(Component * component) override;
	virtual void PostVisit(Component * component) override;
	virtual void Visit(Camera * camera) override;
	virtual void PostVisit(Camera * camera) override;
	virtual void Visit(Scene * scene) override;
	virtual void PostVisit(Scene * scene) override;
	virtual void Visit(GameObject * transformation) override;
	virtual void PostVisit(GameObject * transformation) override;
	virtual void Visit(Transformation * transformation) override;
	virtual void PostVisit(Transformation * transformation) override;
	virtual void Visit(Light * light) override;
	virtual void PostVisit(Light * light) override;
};

