#include ".\..\RTSExample\Viewer.h"
#include "CustomObject.h"
#include "CustomObject0.h"
#include "CustomCamera.h"
#include "CameraSocket.h"
#include <Windows.h>

void DoSth(Viewer * viewer)
{
	//viewer->CreateSampleObject();
}

void Foo(Component * comp)
{
	GameObject * obj = (GameObject*)comp;

	obj->MoveForward(0.1f);
}


void AddSampleGameObject(Viewer * viewer)
{
	cout << "Creating a new object" << endl;


	CustomObject * obj = new CustomObject();
	GameObject * obj0 = new GameObject();


	ShaderCore * sCore = new ShaderCore();
	sCore->GenerateShader("./../glsl/phong.vert", "", "./../glsl/phong.frag");

	GeometryCore * gCore = Geometry::CreatePlane(100.f, 100.f);
	GeometryCore * gCoreBox = Geometry::CreateBox(5.f, 5.f, 5.f);
	TextureCore * texCore = Texture::LoadTexture("BobaFett.png");

	obj->AddCore(sCore);
	obj->AddCore(gCoreBox);

	obj0->AddRotation(glm::vec3(1, 0, 0), -glm::pi<float>() / 2);
	obj0->AddTranslation(glm::vec3(0, -2.5f, 0));
	//obj->MoveUp(-1.f);

	obj0->AddCore(sCore);
	obj0->AddCore(gCore);

	//obj->m_transform->AddChild(obj0->m_transform);

	viewer->AddObjectToScene(obj->m_transform);
	
	viewer->AddObjectToScene(obj0->m_transform);

	CustomCamera * mainCamera = new CustomCamera();
	mainCamera->LookAt(glm::vec3(0, 0, -20), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
	mainCamera->CreateProjection(45.f, 800.f / 600.f, 0.1f, 1000.f);


	CameraSocket * camSocket = new CameraSocket();

	//camSocket->m_transform->AddTranslation(glm::vec3(0, 0, 0));

	camSocket->m_transform->AddChild(mainCamera->m_transform);

	//obj->m_transform->AddChild(mainCamera->m_transform);

	obj->m_transform->AddChild(camSocket->m_transform);

	//viewer->AddObjectToScene(camSocket->m_transform);

	viewer->SetMainCamera(mainCamera);

}

void AddLight(Viewer * viewer)
{
	Light * light0 = new Light();

	light0->UpdateOrientation(glm::vec3(-10, 10, -10), glm::vec3(1, -1, 1), glm::vec3(0, 1, 0));
	light0->UpdateProjection(-10, 10, -10, 10, 0.1, 100);

	viewer->AddLightToScene(light0);
}

int main(int argc, char ** argv)
{
	Viewer * mainViewer = new Viewer();

	mainViewer->InitViewer(argc, argv);

	AddLight(mainViewer);

	AddSampleGameObject(mainViewer);

	

	mainViewer->Start();

}

