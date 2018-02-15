#include ".\..\RTSExample\Viewer.h"
#include "CustomObject.h"
#include "CustomObject0.h"
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
	CustomObject0 * obj0 = new CustomObject0();

	ShaderCore * sCore = new ShaderCore();
	sCore->GenerateShader("./../glsl/phong.vert", "", "./../glsl/phong.frag");
	GeometryCore * gCore = Geometry::CreatePlane(100.f, 100.f);

	ShaderCore * sCorePhong = new ShaderCore();
	sCorePhong->GenerateShader("./../glsl/phong.vert", "", "./../glsl/phong.frag");

	GeometryCore * gCoreBox = Geometry::CreateBox(5.f, 5.f, 5.f);

	obj->AddCore(sCore);
	obj->AddCore(gCore);

	
	obj->AddRotation(glm::vec3(0, glm::pi<float>() / 2, 0));
	obj->MoveUp(-10.f);

	obj0->AddCore(sCorePhong);
	obj0->AddCore(gCoreBox);

	viewer->AddObjectToScene(obj);
	viewer->AddObjectToScene(obj0);

}

void AddLight(Viewer * viewer)
{
	Light * light0 = new Light();

	light0->UpdateOrientation(glm::vec3(-10, -10, -10), glm::vec3(1, 1, 1), glm::vec3(0, 1, 0));

	viewer->AddLightToScene(light0);
}

int main(int argc, char ** argv)
{
	Viewer * mainViewer = new Viewer();

	mainViewer->InitViewer(argc, argv);

	AddLight(mainViewer);

	std::function<void(Viewer*)> testFunc = std::bind(&DoSth, std::placeholders::_1);

	mainViewer->BindFunctionToKey(32, testFunc);

	AddSampleGameObject(mainViewer);

	mainViewer->Start();

}

