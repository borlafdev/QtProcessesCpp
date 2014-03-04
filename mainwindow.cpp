#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int child_status;
char * arg_list[] = {"ls",
                     "/",
                     NULL };

int spawn(char * program, char ** arg){
    pid_t child_pid=0;
    child_pid=fork();
     if (child_pid!=0){
          return child_pid;
     }
     else{
        execvp(program, arg);
     }

}
/***************/

struct web_info{
    QString url;
    int time;
};

void* factorial(){

}

/***/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    spawn("ls", arg_list);

    wait(&child_status);
    if(WIFEXITED(child_status)){
      ui->prResult->setText(QString::number(WEXITSTATUS(child_status)));

    }else{
    ui->prResult->setText("Execution failed");
    }

}
