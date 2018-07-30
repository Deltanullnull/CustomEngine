#include "CustomEngine.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CustomEngine w;
	w.show();
	return a.exec();
}
