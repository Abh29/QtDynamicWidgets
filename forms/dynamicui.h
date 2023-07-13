//
// Created by abh29 on 7/13/23.
//

#ifndef DYNAMICWIDGETS_DYNAMICUI_H
#define DYNAMICWIDGETS_DYNAMICUI_H

#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class dynamicUI; }
QT_END_NAMESPACE

class dynamicUI : public QWidget {
Q_OBJECT

public:

	explicit dynamicUI(QWidget *parent = nullptr);

	~dynamicUI() override;

public slots:
	void onAddClicked();
	void onRemoveClicked();

private:
	QHash<QPushButton *, QHBoxLayout *> dItems;
	QVBoxLayout *verticalLayout;
	QPushButton *add;
	QScrollArea *sArea;
	QWidget 	*scrollAreaWidgetContents;
	QVBoxLayout *verticalLayout_2;
	QSpacerItem *verticalSpacer;

};


#endif //DYNAMICWIDGETS_DYNAMICUI_H
