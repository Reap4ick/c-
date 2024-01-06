#include "table.h"

Table::Table(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* vbox = new QVBoxLayout(this);

    createTableButton = new QPushButton("Create Table", this);
    connect(createTableButton, &QPushButton::clicked, this, &Table::createTable);

    table = new QTableWidget(this);

    vbox->addWidget(createTableButton);
    vbox->addWidget(table);
}

void Table::createTable() {
    bool ok;
    int rowCount = QInputDialog::getInt(this, tr("Enter Row Count"), tr("Rows:"), 25, 1, 1000, 1, &ok);
    if (ok) {
        int columnCount = QInputDialog::getInt(this, tr("Enter Column Count"), tr("Columns:"), 25, 1, 1000, 1, &ok);
        if (ok) {
            table->clear();
            table->setRowCount(rowCount);
            table->setColumnCount(columnCount);
        }
    }
}
