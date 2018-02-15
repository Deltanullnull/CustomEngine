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
	sCore->GenerateShader("./../glsl/default.vert", "", "./../glsl/default.frag");
	GeometryCore * gCore = Geometry::CreatePlane(20.f, 10.f);

	GeometryCore * gCore0 = Geometry::CreateBox(5.f, 5.f, 5.f);

	obj->AddCore(sCore);
	obj->AddCore(gCore);

	obj0->AddCore(sCore);
	obj0->AddCore(gCore0);

	viewer->AddObjectToScene(obj);
	viewer->AddObjectToScene(obj0);

}

int main(int argc, char ** argv)
{
	Viewer * mainViewer = new Viewer();

	mainViewer->InitViewer(argc, argv);

	std::function<void(Viewer*)> testFunc = std::bind(&DoSth, std::placeholders::_1);

	mainViewer->BindFunctionToKey(32, testFunc);

	AddSampleGameObject(mainViewer);

	mainViewer->Start();

}

