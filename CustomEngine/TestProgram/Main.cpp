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


	Skybox * skybox = new Skybox();


	ShaderCore * sCore = new ShaderCore();
	sCore->GenerateShader("./../glsl/phong.vert", "", "./../glsl/phong.frag");

	ShaderCore * sCoreSkybox = new ShaderCore();
	sCoreSkybox->GenerateShader("./../glsl/skybox.vert", "", "./../glsl/skybox.frag");

	GeometryCore * gCore = Geometry::CreatePlane(100.f, 100.f);
	GeometryCore * gCoreBox = Geometry::CreateBox(500.f, 500.f, 500.f);

	TextureCore * texCore = Texture::CreateTextureCoreFromFile("lena.jpg");

	const char * skyboxFiles[6] = {"skybox/left.jpg", "skybox/front.jpg", "skybox/top.jpg", "skybox/bottom.jpg","skybox/right.jpg", "skybox/back.jpg"};
	TextureCore * texCoreSpace = Texture::CreateCubemapCoreFromFile(skyboxFiles);
	//TextureCore * texCoreSpace = Texture::CreateCubemapCoreFromFile("skybox_texture_0.jpg");
	//TextureCore * texCoreEmpty = Texture::CreateEmpty();

	obj->AddCore(sCore);
	
	skybox->AddCore(sCoreSkybox);
	skybox->AddCore(gCoreBox);
	skybox->AddCore(texCoreSpace);

	obj0->AddRotation(glm::vec3(1, 0, 0), -glm::pi<float>() / 2);
	obj0->AddTranslation(glm::vec3(0, -2.5f, 0));
	
	obj0->AddCore(sCore);
	obj0->AddCore(gCore);
	obj0->AddCore(texCore);

	//obj->m_transform->AddChild(obj0->m_transform);

	viewer->AddObjectToScene(skybox->m_transform);

	viewer->AddObjectToScene(obj->m_transform);
	
	viewer->AddObjectToScene(obj0->m_transform);

	

	CustomCamera * mainCamera = new CustomCamera();
	//mainCamera->LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
	mainCamera->LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));
	mainCamera->CreateProjection(45.f, 800.f / 600.f, 0.1f, 1000.f);

	

	CameraSocket * elevation = new CameraSocket();

	GameObject * camSocket = new GameObject();

	//camSocket->m_transform->AddTranslation(glm::vec3(0, 0, 0));

	elevation->m_transform->AddChild(camSocket->m_transform);
	camSocket->m_transform->AddChild(mainCamera->m_transform);
	
	//camSocket->AddTranslation(glm::vec3(0, 0, -20));

	//obj->m_transform->AddChild(mainCamera->m_transform);

	obj->m_transform->AddChild(elevation->m_transform);

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

