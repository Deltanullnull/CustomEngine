#pragma once

class Component;
class GameObject;
class Camera;
class Scene;
class Transformation;
class Light;
class Renderer;
class Skybox;

class Traverser
{
public:
	Traverser();
	~Traverser();

	virtual void Visit(Component * component) = 0;
	virtual void PostVisit(Component * component) = 0;

	virtual void Visit(Camera * camera) = 0;
	virtual void PostVisit(Camera * camera) = 0;

	virtual void Visit(Scene * scene) = 0;
	virtual void PostVisit(Scene * scene) = 0;

	virtual void Visit(GameObject * transformation) = 0;
	virtual void PostVisit(GameObject * transformation) = 0;

	virtual void Visit(Skybox * transformation) = 0;
	virtual void PostVisit(Skybox * transformation) = 0;

	virtual void Visit(Transformation * transformation) = 0;
	virtual void PostVisit(Transformation * transformation) = 0;

	virtual void Visit(Light * light) = 0;
	virtual void PostVisit(Light * light) = 0;

public:

	Renderer * m_pRenderer = nullptr;
};