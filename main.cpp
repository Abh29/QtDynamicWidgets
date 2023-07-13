#include <QApplication>
#include <QPushButton>
#include <QFile>
#include "forms/dynamicui.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	QFile styleFile("style/Adaptic.qss");
	styleFile.open(QFile::ReadOnly);
	QString styleString = QLatin1String(styleFile.readAll());

	 dynamicUI dui;
	 dui.setStyleSheet(styleString);

	 dui.show();

	return QApplication::exec();
}
