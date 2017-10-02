#include "Model.h"



Model::Model()
{
}


Model::~Model()
{
}

void Model::render(Renderer * renderer)
{
	shader_core->BindShader();

	geometry_core->accept(renderer);
}
