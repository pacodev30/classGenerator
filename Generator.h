#pragma once

#include <QWidget>
#include <QDialog>
#include <QTextEdit>
#include <QBoxLayout>
#include <QString>
#include <QPushButton>

class Generator : public QDialog
{
    Q_OBJECT
public:
    Generator(const QString &data, QWidget *parent = nullptr);

private:
    QTextEdit *_textEdit;
    QPushButton *_quitBtn;
    QString _data;

    QVBoxLayout *_vBoxWindow;
    QHBoxLayout *_hBoxValid;
};
