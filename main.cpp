#include "mainwindow.h"

#include <QApplication>
#include"qdlglogin.h"
#include"mcommon.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDlgLogin*dlgLogin=new QDlgLogin();
   if(! readQss("LoginQss.qss",dlgLogin))
       return 0;
    if(dlgLogin->exec()==QDialog::Accepted){
 //   MainWindow w;
   // w.show();
  //  return a.exec();
    }
    else return 0;
}
