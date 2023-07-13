//
// Created by abh29 on 7/13/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_dynamicUI.h" resolved

#include <QRadioButton>
#include "dynamicui.h"


dynamicUI::dynamicUI(QWidget *parent) : QWidget(parent) {

	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("dynamicUI"));
	this->resize(400, 300);
	verticalLayout = new QVBoxLayout(this);
	verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
	add = new QPushButton(this);
	add->setObjectName(QString::fromUtf8("add"));

	verticalLayout->addWidget(add);


	sArea = new QScrollArea(this);
	sArea->setObjectName(QString::fromUtf8("scrollArea"));
	sArea->setWidgetResizable(true);
	scrollAreaWidgetContents = new QWidget();
	scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
	scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 247));
	verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
	verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
	verticalSpacer = new QSpacerItem(20, 226, QSizePolicy::Minimum, QSizePolicy::Expanding);

	verticalLayout_2->addItem(verticalSpacer);

	sArea->setWidget(scrollAreaWidgetContents);

	verticalLayout->addWidget(sArea);


	this->setWindowTitle(QCoreApplication::translate("dynamicUI", "dynamicUI", nullptr));
	add->setText(QCoreApplication::translate("dynamicUI", "Add a Widget", nullptr));


	QObject::connect(add, &QPushButton::clicked, this, &dynamicUI::onAddClicked);


	QMetaObject::connectSlotsByName(this);

}

dynamicUI::~dynamicUI() {}

void dynamicUI::onAddClicked() {
	QHBoxLayout *hb = new QHBoxLayout();

	QString buttonText = tr("Remove me %1").arg(verticalLayout_2->count());
	QPushButton *nb = new QPushButton(buttonText, this);
	QRadioButton *nrb = new QRadioButton(this);
	QSpacerItem *hs = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

	hb->addWidget(nb);
	hb->addItem(hs);
	hb->addWidget(nrb);

	verticalLayout_2->insertLayout(0,  hb);

	dItems.insert(nb, hb);
	QObject::connect(nb, &QPushButton::clicked, this, &dynamicUI::onRemoveClicked);
}

void dynamicUI::onRemoveClicked() {
	QPushButton* button = qobject_cast<QPushButton *>(sender());
	QHBoxLayout* hbox = dItems.take(button);

	while(hbox->count() > 0) {
		auto i = hbox->takeAt(0);
		delete i->widget();
		delete i;
	}

	delete hbox;
}

