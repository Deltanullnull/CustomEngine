#include ".\..\RTSExample\Viewer.h"
#include "MovementScript.h"
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
	const string assetPath = "./../assets/";

	cout << "Creating a new object" << endl;

	GameObject * obj = new GameObject();
	obj->AddBehavior(new MovementScript());
	GameObject * obj0 = new GameObject();

	GameObject * obj2;
	vector<GeometryCore*> geomList;
	vector<TextureCore*> texList;
	
	if (ObjectFactory::LoadFile(assetPath + "mesh/stormtrooper/source/EP7 ST.obj", &obj2, &geomList, &texList))
	{
		// TODO make list of textures (must have same size like texList

		string texturePath = assetPath + "mesh/stormtrooper/textures/";

		cout << "Number of materials: " << texList.size() << endl;
		
		string texListPath[11] = {
			texturePath + "chest.png", // OK
			texturePath + "Rubber_joints.png",
			texturePath + "Belt.png",
			texturePath + "ArmNLeg.png", // OK
			texturePath + "Back_crotch.png", // OK
			texturePath + "Helmet.png", // OK
			texturePath + "Helmet.png", // Forehead
			texturePath + "Rubber_joints.png", // Arms joints
			texturePath + "HandsNFeet.png", // Hands and feet
			texturePath + "Rubber_joints.png",
			assetPath + "textures/lena.jpg", 
		};

		for (int i = 0; i < 11; i++)
		{
			BYTE * buffer;
			int width, height;
			//if (Texture::LoadTexture(texListPath[i].c_str(), &buffer, &width, &height))
			//if (Texture::LoadTexture((assetPath + "textures/lena.jpg").c_str(), &buffer, &width, &height))
			
			if (Texture::LoadTexture(texListPath[i].c_str(), &buffer, &width, &height))
			{
				texList.at(i)->AddTexture(buffer, width, height);
			}
			
			
		}
	}

	//GameObject * obj2 = ObjectFactory::LoadFile("./../assets/mesh/stormtrooper/source/EP7 ST.obj");

	Skybox * skybox = new Skybox();

	//GeometryCore * gCoreModel = Geometry::LoadFile("./../assets/mesh/stormtrooper/source/EP7 ST.obj");
	GeometryCore * gCore = Geometry::CreatePlane(100.f, 100.f);
	GeometryCore * gCoreBox = Geometry::CreateBox(500.f, 500.f, 500.f);

	ShaderCore * sCore = new ShaderCore();
	sCore->GenerateShader("./../glsl/phong.vert", "", "./../glsl/phong.frag");

	ShaderCore * sCoreSkybox = new ShaderCore();
	sCoreSkybox->GenerateShader("./../glsl/skybox.vert", "", "./../glsl/skybox.frag");

	
	//GeometryCore * gCoreModel = Geometry::LoadFile("./../assets/mesh/stormtrooper/source/EP7 ST.obj");

	TextureCore * texCore = Texture::CreateTextureCoreFromFile((assetPath + "mesh/stormtrooper/textures/Back_crotch.png").c_str());
	//TextureCore * texCore = Texture::CreateTextureCoreFromFile("./../assets/textures/kai.png");

	const char * skyboxFiles[6] = {
		"./../assets/textures/skybox/left.jpg", 
		"./../assets/textures/skybox/front.jpg", 
		"./../assets/textures/skybox/top.jpg", 
		"./../assets/textures/skybox/bottom.jpg",
		"./../assets/textures/skybox/right.jpg", 
		"./../assets/textures/skybox/back.jpg"
	};
	TextureCore * texCoreSpace = Texture::CreateCubemapCoreFromFile(skyboxFiles);

	TextureCore * texCoreEmpty = Texture::CreateEmpty();

	obj->AddCore(sCore);
	
	skybox->AddCore(sCoreSkybox);
	skybox->AddCore(gCoreBox);
	skybox->AddCore(texCoreSpace);

	obj0->AddRotation(glm::vec3(1, 0, 0), -glm::pi<float>() / 2);
	obj0->AddTranslation(glm::vec3(0, -2.5f, 0));
	
	obj2->Scale(glm::vec3(1.0f) * 0.001f);
	
	obj0->AddCore(sCore);
	obj0->AddCore(gCore);
	//obj0->AddCore(gCoreModel);
	obj0->AddCore(texCore);
	//obj0->AddCore(texCoreEmpty);

	//obj2->AddCore(sCore);

	//obj->m_transform->AddChild(obj0->m_transform);

	viewer->AddObjectToScene(skybox->m_transform);

	cout << "Adding object to scene" << endl;
	viewer->AddObjectToScene(obj->m_transform);
	
	viewer->AddObjectToScene(obj0->m_transform);
	viewer->AddObjectToScene(obj2->m_transform);
	

	Camera * mainCamera = new Camera();
	//mainCamera->LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
	mainCamera->LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));
	mainCamera->CreateProjection(45.f, 800.f / 600.f, 0.1f, 1000.f);

	
	GameObject * elevation = new GameObject();
	elevation->AddBehavior(new CameraSocket());
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

