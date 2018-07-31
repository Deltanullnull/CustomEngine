#pragma once

#include <QOpenGLFunctions_4_3_Core>

class Core
{
public:
	Core() {} 
	~Core() {}

public:
	QOpenGLFunctions_4_3_Core * m_func;
};