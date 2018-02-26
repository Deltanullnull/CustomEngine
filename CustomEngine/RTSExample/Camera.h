#include "Leaf.h"
#include "Renderer.h"
#include "Transformation.h"

#pragma once
class Camera : 
	public Leaf
{
public:
	Camera();
	~Camera();

	void LookAt(glm::vec3 eye, glm::vec3 direction, glm::vec3 up);
	void CreateProjection(float fov, float ratio, float zNear, float zFar);

	void CreateProjection(float left, float right, float bottom, float top, float zNear, float zFar);

	void PushCameraMatrix(Renderer * renderer);
	
	void PopCameraMatrix(Renderer * renderer);

	virtual void Accept(Traverser* traverser) override;

	virtual void Init() {}

	virtual void Update() { cout << "Default camera update" << endl; }

	

private:

	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;

};

