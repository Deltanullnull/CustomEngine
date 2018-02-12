#include ".\..\RTSExample\Viewer.h"
#include <Windows.h>

void DoSth(Viewer * viewer)
{
	viewer->CreateSampleObject();
}

void Foo(Component * comp)
{
	GameObject * obj = (GameObject*)comp;

	obj->MoveForward();
}


void AddSampleGameObject(Viewer * viewer)
{
	cout << "Creating a new object" << endl;

	GameObject * obj = new GameObject();

	obj->AddAction('u', std::bind(&Foo, std::placeholders::_1));

	ShaderCore * sCore = new ShaderCore();
	sCore->GenerateShader("./../glsl/default.vert", "", "./../glsl/default.frag");
	GeometryCore * gCore = Geometry::CreatePlane(20.f, 10.f);

	obj->AddCore(sCore);
	obj->AddCore(gCore);

	viewer->AddObjectToScene(obj);

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

