#include "Model.h"



Model::Model()
{
}


Model::~Model()
{
}

void Model::render(Renderer * renderer)
{
	shader_core->accept(renderer);

	geometry_core->accept(renderer);
}
