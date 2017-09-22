#ifndef APPSTORE_H
#define APPSTORE_H

#include <QMainWindow>

namespace Ui {
class AppStore;
}

class AppStore : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppStore(QWidget *parent = 0);
    ~AppStore();

private slots:
    void on_btSearch_clicked();

    void on_btInstall_clicked();

private:
    Ui::AppStore *ui;
};

#endif // APPSTORE_H
