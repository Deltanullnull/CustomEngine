#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CustomEngine.h"

class CustomEngine : public QMainWindow
{
	Q_OBJECT

public:
	CustomEngine(QWidget *parent = Q_NULLPTR);

private:
	Ui::CustomEngineClass ui;
};
