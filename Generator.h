#pragma once
#include <QWidget>
#include <QString>
#include <QTextEdit>
#include <QPushButton>
#include <QDialog>
#include <QBoxLayout>
#include <QClipboard>

class Generator : public QDialog
{
    Q_OBJECT
public:
    Generator(const QString &data, QWidget *parent = nullptr);

private:
    QTextEdit *_textEdit;
    QPushButton *_quitBtn;
    QString _data;

    QVBoxLayout *_windowVBox;
    QHBoxLayout *_buttonHBox;
};
