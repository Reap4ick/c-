#pragma once

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QInputDialog>

class Table : public QWidget {
    Q_OBJECT

public:
    Table(QWidget* parent = nullptr);

private slots:
    void createTable();

private:
    QPushButton* createTableButton;
    QTableWidget* table;
};
