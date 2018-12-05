/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QCheckBox>
#include <qcombobox.h>
#include <QComboBox>
#include <QComboBox>
#include <QtGlobal>
#include "tabdialog.h"
#include <QObject>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QString>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <sstream>
#include <QDataStream>
#include <QFileDialog>
#include <QVector>
#include <QtGlobal>

using namespace std;

static QVector<QString> Course;
static QVector<QString> Event;
static QVector<QString> Room;


TabDialog::TabDialog(const QString &fileName, QWidget *parent) : QDialog(parent)
{
   QFileInfo fileInfo(fileName);

   tabWidget = new QTabWidget;
   tabWidget->addTab(new Create_Database_Tab(fileInfo), tr("Create Database"));
   tabWidget->addTab(new Import_Database_Tab(fileInfo), tr("Import Database"));
   tabWidget->addTab(new Add_room_Tab(fileInfo), tr("Add Room"));
   tabWidget->addTab(new Add_course(fileInfo), tr("Add Course"));
   tabWidget->addTab(new Add_event(fileInfo), tr("Add Event"));
   tabWidget->addTab(new Revise(fileInfo), tr("Revise"));
   tabWidget->addTab(new Run(fileInfo), tr("Run"));
   QVBoxLayout *mainLayout = new QVBoxLayout;
   mainLayout->addWidget(tabWidget);
   setLayout(mainLayout);
   setWindowTitle(tr("UNT Schedule Manager"));
}

Create_Database_Tab::Create_Database_Tab(const QFileInfo &fileInfo, QWidget *parent) : QWidget(parent)
{

    //------------
    QString fname;
    QString Error_List;
    //------------

    QLabel *selDatabase = new QLabel(tr("Select Database Type: "));
    QComboBox *CreateDatabaseComboBox= new QComboBox;
    CreateDatabaseComboBox->addItem(tr("[Select]"));
    CreateDatabaseComboBox->addItem(tr("Room Database"));
    CreateDatabaseComboBox->addItem(tr("Course Database"));
    CreateDatabaseComboBox->addItem(tr("Event Database"));

    QLabel *DatabaseNameLabel = new QLabel(tr("Database Name:"));//changed to Database Name
    QLineEdit *DatabaseNameEdit = new QLineEdit(fileInfo.fileName());

    QPushButton *button_Create = new QPushButton("&Create", this);
    QPushButton *button_Cancel = new QPushButton("&Cancel", this);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(selDatabase);
    mainLayout->addWidget(CreateDatabaseComboBox);
    mainLayout->addWidget(DatabaseNameLabel);
    mainLayout->addWidget(DatabaseNameEdit);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
    //put in a condidtion statment when the create burron is clicked
    if(CreateDatabaseComboBox->currentText() == "[Select]" || DatabaseNameEdit->text().isEmpty())
    {
        if(CreateDatabaseComboBox->currentText() == "[Select]")
        {
            //pop up box error need to select database type
            Error_List + "\n" +"ERROR: Database type not selected";
        }
        else
        {
            //pop up box error need to fill in the filename
            Error_List + "\n" + "ERROR: Filename was not given";
        }
    }
    else
    {
        QString Name = DatabaseNameEdit->text();
        int Name_size = Name.size();
        if(CreateDatabaseComboBox->currentText() == "Room Database")
        {
            //add to drop down
            Room.push_back(DatabaseNameEdit->text());
        }
        else if (CreateDatabaseComboBox->currentText() == "Course Database")
        {
            //add to drop down
            Course.push_back(DatabaseNameEdit->text());
        }
        else if (CreateDatabaseComboBox->currentText() == "Event Database")
        {
            //add to drop down
            Event.push_back(DatabaseNameEdit->text());
        }
        if (CreateDatabaseComboBox->count() > 0 && CreateDatabaseComboBox->currentText() != "[Select]" && Name_size > 0)
        {
            fname = CreateDatabaseComboBox->currentText() + "-" + DatabaseNameEdit->text() + ".txt";
        }
        QString name = DatabaseNameEdit->text();
        QFile database(name);
        database.open(QIODevice::WriteOnly);
        database.close();

     }
    mainLayout->addWidget(button_Create);
    mainLayout->addWidget(button_Cancel);
}

Import_Database_Tab::Import_Database_Tab(const QFileInfo &fileInfo, QWidget *parent) : QWidget(parent)
{
   QString Error_List;
    //have warning at the top
    QLabel *warning = new QLabel(tr("WARNING: To import a file into this application it must be at .csv file."));
   //database type
    QLabel *SelectDatabaseLabel = new QLabel(tr("Select Database Type: "));
    QComboBox *ImportDatabaseComboBox = new QComboBox;
    ImportDatabaseComboBox->addItem(tr("[Select]"));
    ImportDatabaseComboBox->addItem(tr("Room Database"));
    ImportDatabaseComboBox->addItem(tr("Course Database"));
    ImportDatabaseComboBox->addItem(tr("Event Database"));
   //File Location - figure out own to open file explorer window
    QLabel *fileNameLabel = new QLabel(tr("File Name:"));//changed to Database Name
    QLineEdit *fileNameEdit = new QLineEdit(fileInfo.fileName());
/*
    QLabel *pathLabel = new QLabel(tr("Path:"));
    QLabel *pathValueLabel = new QLabel(fileInfo.absoluteFilePath());
    pathValueLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
*/
    QPushButton *button_Import = new QPushButton("&Import", this);
    QPushButton *button_Cancel = new QPushButton("&Cancel", this);

    //------------------------------------popup/*

    if(ImportDatabaseComboBox->currentText() == "[Select]")
    {
        //error for database not selected
        Error_List + "\n" +"ERROR: Database type not selected";
    }
    else
    {
	/*if()
	{
		switch( QMessageBox::question(
                this,

                tr("Are You Sure?"),

                QMessageBox::Yes |
                QMessageBox::No |
                QMessageBox::Cancel,

                QMessageBox::Cancel ) )
    {
      case QMessageBox::Yes:
        qDebug( "yes" );
        break;
      case QMessageBox::No:
        qDebug( "no" );
        break;
      case QMessageBox::Cancel:
        qDebug( "cancel" );
        break;
      default:
        qDebug( "close" );
        break;
    }
   */
    //=-----------------------------------------
       if(ImportDatabaseComboBox->currentText() == "Room Database")
        {
            //add to drop down
            Room.push_back(fileNameEdit->text());
        }
        else if (ImportDatabaseComboBox->currentText() == "Course Database")
        {
            //add to drop down
            Course.push_back(fileNameEdit->text());
        }
        else if (ImportDatabaseComboBox->currentText() == "Event Database")
        {
            //add to drop down
            Event.push_back(fileNameEdit->text());
        }
    }
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(warning);
    mainLayout->addWidget(SelectDatabaseLabel);
    mainLayout->addWidget(ImportDatabaseComboBox);
    mainLayout->addWidget(fileNameLabel);
    mainLayout->addWidget(fileNameEdit);
    mainLayout->addWidget(button_Import);
    mainLayout->addWidget(button_Cancel);
    mainLayout->addStretch(1);
    setLayout(mainLayout);


//need to put inside if statement when button is pressed
/*
	char * word;
	FILE *fin = fopen("Room.txt", "r");
	if (fin == NULL)
	{
		//throw error for file not found
	}

	FILE *fout = fopen("Room.csv", "w");
	if (fout == NULL)
	{
		//throw error for file not found
	}

	char line[1000];
	while (fgets(line, sizeof line, fin) != NULL)
	{
		bool first_word = true;
		word = strtok(line, " \t\n");
		while (word)
		{
			fprintf(fout, "%s%s", first_word ? "" : ",", word);
			first_word = false;
			word = strtok(NULL, " \t\n");
		}
		fprintf(fout, "\n");
	}
    fclose(fout);
    fclose(fin);
*/
}

Add_room_Tab::Add_room_Tab(const QFileInfo &fileInfo, QWidget *parent) : QWidget(parent)
{   
    QString fname;
    QString Error_list;
    QLabel *selDatabase = new QLabel(tr("Select Database: "));
    QComboBox *comboBox_add_room = new QComboBox;
    comboBox_add_room->addItem(tr("[Select]"));
    QLabel *RoomNumberLabel = new QLabel(tr("Room Number: "));
    QLineEdit *RoomNumberEdit = new QLineEdit(fileInfo.fileName());
    QLabel *RoomCapacityLabel = new QLabel(tr("Room Capacity: "));
    QLineEdit *RoomCapacityEdit = new QLineEdit(fileInfo.fileName());
    QCheckBox *computers = new QCheckBox("Computers", this);
    QCheckBox *projectorsCBLabel = new QCheckBox("Projectors", this);
    QCheckBox *wbCB = new QCheckBox("WhiteBoard", this);
    QPushButton *button_Add = new QPushButton("&Add", this);
    QPushButton *button_Cancel = new QPushButton("&Cancel", this);
    QVBoxLayout *mainLayout = new QVBoxLayout;

    if(Room.size() > 0)
    {
        for(int i = 0; i < Room.size(); i++)
        {
             comboBox_add_room->addItem(Room[i]);
        }
    }
    Room.clear();

    mainLayout->addWidget(selDatabase);
    mainLayout->addWidget(comboBox_add_room);
    mainLayout->addWidget(RoomNumberLabel);
    mainLayout->addWidget(RoomNumberEdit);
    mainLayout->addWidget(RoomCapacityLabel);
    mainLayout->addWidget(RoomCapacityEdit);
    mainLayout->addWidget(computers);
    mainLayout->addWidget(projectorsCBLabel);

    mainLayout->addWidget(wbCB);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
    if(comboBox_add_room->currentText() == "[Select]" || RoomNumberEdit->text().isEmpty() || RoomCapacityEdit->text().isEmpty())
    {
        if(comboBox_add_room->currentText() == "[Select]")
        {
            //database tyoe was not selected
            Error_list + "\n" + "ERROR: Database type was not selected";
        }
        if(RoomNumberEdit->text().isEmpty())
        {
            //no filename was entered
            Error_list + "\n" + "ERROR: filename was not entered";
        }
        else
        {
            //room capacity was not entered
            Error_list + "\n" + "ERROR: room capacity was not entered";
        }
    }
    else
    {
        QString cap =  RoomCapacityEdit->text();
        int cap_size = cap.size();

        QString Num = RoomNumberEdit->text();
        int num_size = Num.size();

        if(comboBox_add_room->currentText() == "Room Database")
        {
            //add to drop down
        }
        else if (comboBox_add_room->currentText() == "Course Database")
        {
            //add to drop down
        }
        else if (comboBox_add_room->currentText() == "Event Database")
        {
            //add to drop down
        }
        if (comboBox_add_room->count() > 0 && comboBox_add_room->currentText() != "[Select]" && cap_size > 0 && num_size > 0)
        {
            QString filename = comboBox_add_room->currentText() + ".txt";
            
//just organizing things this gose somewhere in here and put in if statement for the trigger or it will freak out
            ofstream fout;
            fout.open(filename, ios::app);
            fname = comboBox_add_room->currentText() + "\t" + fileNameEdit->text() + "\t" + RoomCapacityLabel->text();
            if(computers->isTristate() == true)
            {
                fname + "\t" + "computers";
            }
		else{
			fname;
		}
            if(projectorsCBLabel->isTristate() == true)
            {
                fname + "\t" + "Projectors";
            }
		else{
			fname;
		}
		
            if(wbCB->isTristate() == true)
            {
                fname + "\t" + "WhiteBoard";
            }
		else{
			fname;
		}
            fout << fname;
            fout.close();
           
        }
    }
    mainLayout->addWidget(button_Add);
    mainLayout->addWidget(button_Cancel);
}

Add_course::Add_course(const QFileInfo &fileInfo, QWidget *parent) : QWidget(parent)
{
    QString fname;
    QString Error_list;
    QLabel *AddCourseSelectDatabase = new QLabel(tr("Select Database: "));
    QComboBox *comboBox_add_course = new QComboBox;
    comboBox_add_course->addItem(tr("[Select]"));

    QLabel *StartDateLabel = new QLabel(tr("Start Date: "));//changed to Database Nam
    QLineEdit *StartDateEdit = new QLineEdit(fileInfo.fileName());

    QLabel *EndDateLabel = new QLabel(tr("End Date: "));
    QLineEdit *EndDateEdit = new QLineEdit(fileInfo.fileName());

    QLabel *StartTimeLabel = new QLabel(tr("Start Time: "));//changed to Database Nam
    QLineEdit *StartTimeEdit = new QLineEdit(fileInfo.fileName());

    QLabel *endTimeLabel = new QLabel(tr("End Time: "));
    QLineEdit *endTimeEdit = new QLineEdit(fileInfo.fileName());

    QLabel *numAttendiesLabel= new QLabel(tr("Number of Students"));
    QLineEdit *numAttendiesEdit=new QLineEdit(fileInfo.fileName());

    QCheckBox *computers;
    computers = new QCheckBox("Computers", this);

    QCheckBox *projectorsCBLabel;
    projectorsCBLabel = new QCheckBox("Projectors", this);

    QCheckBox *wbCB;
    wbCB = new QCheckBox("WhiteBoard", this);

    QPushButton *button_Add = new QPushButton("&Add", this);
    QPushButton *button_Cancel = new QPushButton("&Cancel", this);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    if(Course.size() > 0)
    {
        for(int i = 0; i < Course.size(); i++)
        {
             comboBox_add_course->addItem(Room[i]);
        }
    }
    Course.clear();

    mainLayout->addWidget(AddCourseSelectDatabase);
    mainLayout->addWidget(comboBox_add_course);
    mainLayout->addWidget(StartDateLabel);
    mainLayout->addWidget(StartDateEdit);
    mainLayout->addWidget(EndDateLabel);
    mainLayout->addWidget(EndDateEdit);
    mainLayout->addWidget(StartTimeLabel);
    mainLayout->addWidget(StartTimeEdit);
    mainLayout->addWidget(endTimeLabel);
    mainLayout->addWidget(endTimeEdit);
    mainLayout->addWidget(numAttendiesLabel);
    mainLayout->addWidget(numAttendiesEdit);
    mainLayout->addWidget(computers);
    mainLayout->addWidget(projectorsCBLabel);
    mainLayout->addWidget(wbCB);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
    if(comboBox_add_course->currentText() == "[Select]" || StartDateEdit->text().isEmpty() || EndDateEdit->text().isEmpty() || StartTimeEdit->text().isEmpty() || endTimeEdit->text().isEmpty() || numAttendiesEdit->text().isEmpty())
    {
        if(comboBox_add_course->currentText() == "[Select]")
        {
            //database type not selected
            Error_list + "\n" + "ERROR: Database type was not selected";
        }
        if(StartDateEdit->text().isEmpty())
        {
            //file name not entered
            Error_list + "\n" + "ERROR: start date was not entered";
        }
        if(EndDateEdit->text().isEmpty())
        {
            //room capacity not entered
            Error_list + "\n" + "ERROR: end date was not entered";
        }
        if(StartTimeEdit->text().isEmpty())
        {
            //start time not entered
            Error_list + "\n" + "ERROR: start time was not entered";
        }
        if(endTimeEdit->text().isEmpty())
        {
            //end time not entered
            Error_list + "\n" + "ERROR: end time was not entered";
        }
        else
        {
            //number of attendies not entered
            Error_list + "\n" + "ERROR: number of attendies was not entered";
        }
    }
    else
    {
        QString SD = StartDateEdit->text();
        int SD_size = SD.size();
        QString ED = EndDateEdit->text();
        int ED_size = ED.size();
        QString NOS = numAttendiesEdit->text();
        int NOS_size = NOS.size();
        if(comboBox_add_course->currentText() == "Room Database")
		{
			//add to drop down
		}
        else if (comboBox_add_course->currentText() == "Course Database")
		{
			//add to drop down
		}
        else if (comboBox_add_course->currentText() == "Event Database")
		{
			//add to drop down
		}
        if (comboBox_add_course->count() > 0 && comboBox_add_course->currentText() != "[Select]" && SD_size > 0 && ED_size > 0 && NOS_size > 0)
		{
			
			QString filename = comboBox_add_event->currentText() + ".txt";
			ofstream fout;
			fout.open(filename, ios::app);
			fname = comboBox_add_event->currentText() + "\t" + fileNameEdit->text() + "\t" + RoomCapacityEdit->text() + "\t" + numAttendiesEdit->text();
			if(computers->isTristate() == true)
			{
				fname + "\t" + "computers";
			}
			else
			{
				fname;
			}
			if(projectorsCBLabel->isTristate() == true)
			{
				fname + "\t" + "Projectors";
			}
			else
			{
				fname;
			}
			if(wbCB->isTristate() == true)
			{
				fname + "\t" + "WhiteBoard";
			}
			else
			{
				fname;
			}
		

			fout << fname;
			fout.close();
			
		}
    }
    mainLayout->addWidget(button_Add);
    mainLayout->addWidget(button_Cancel);
}

Add_event::Add_event(const QFileInfo &fileInfo, QWidget *parent) : QWidget(parent)
{
    QString fname;
    QString Error_list;
    QLabel *Add_event = new QLabel(tr("Select Database: "));
    QComboBox *comboBox_add_event = new QComboBox;
    comboBox_add_event->addItem(tr("[Select]"));

    QLabel *StartDateLabel = new QLabel(tr("Start Date: "));//changed to Database Nam
    QLineEdit *StartDateEdit = new QLineEdit(fileInfo.fileName());

    QLabel *EndDateLabel = new QLabel(tr("End Date: "));
    QLineEdit *EndDateEdit = new QLineEdit(fileInfo.fileName());

    QLabel *StartTimeLabel = new QLabel(tr("Start Time: "));//changed to Database Nam
    QLineEdit *StartTimeEdit = new QLineEdit(fileInfo.fileName());

    QLabel *endTimeLabel = new QLabel(tr("End Time: "));
    QLineEdit *endTimeEdit = new QLineEdit(fileInfo.fileName());

    QLabel *numAttendiesLabel= new QLabel(tr("Number of Attendies"));
    QLineEdit *numAttendiesEdit=new QLineEdit(fileInfo.fileName());

    QCheckBox *computers;
    computers = new QCheckBox("Computers", this);

    QCheckBox *projectorsCBLabel;
    projectorsCBLabel = new QCheckBox("Projectors", this);

    QCheckBox *wbCB;
    wbCB = new QCheckBox("WhiteBoard", this);

    QPushButton *button_Add = new QPushButton("&Add", this);
    QPushButton *button_Cancel = new QPushButton("&Cancel", this);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    if(Course.size() > 0)
    {
        for(int i = 0; i < Event.size(); i++)
        {
             comboBox_add_event->addItem(Room[i]);
        }
    }
    Event.clear();

    mainLayout->addWidget(Add_event);
    mainLayout->addWidget(comboBox_add_event);
    mainLayout->addWidget(StartDateLabel);
    mainLayout->addWidget(StartDateEdit);
    mainLayout->addWidget(EndDateLabel);
    mainLayout->addWidget(EndDateEdit);
    mainLayout->addWidget(StartTimeLabel);
    mainLayout->addWidget(StartTimeEdit);
    mainLayout->addWidget(endTimeLabel);
    mainLayout->addWidget(endTimeEdit);
    mainLayout->addWidget(numAttendiesLabel);
    mainLayout->addWidget(numAttendiesEdit);
    mainLayout->addWidget(computers);
    mainLayout->addWidget(projectorsCBLabel);
    mainLayout->addWidget(wbCB);
    mainLayout->addStretch(1);
    setLayout(mainLayout);

    if(comboBox_add_event->currentText() == "[Select]" || StartDateEdit->text().isEmpty() || EndDateEdit->text().isEmpty() || StartTimeEdit->text().isEmpty() || endTimeEdit->text().isEmpty() || numAttendiesEdit->text().isEmpty())
    {
        if(comboBox_add_event->currentText() == "[Select]")
        {
            //database type not selected
            Error_list + "\n" + "ERROR: Database type not selected";
        }
        if(StartDateEdit->text().isEmpty())
        {
            //file name not entered
            Error_list + "\n" + "ERROR: start date was not entered";
        }
        if(EndDateEdit->text().isEmpty())
        {
            //room capacity not entered
            Error_list + "\n" + "ERROR: end date was not entered";
        }
        if(StartTimeEdit->text().isEmpty())
        {
            //start time not entered
            Error_list + "\n" + "ERROR: start time was not entered";
        }
        if(endTimeEdit->text().isEmpty())
        {
            //end time not entered
            Error_list + "\n" + "ERROR: end time was not entered";
        }
        else
        {
            //number of attendies not entered
            Error_list + "\n" + "ERROR: number of attendies was not entered";
        }
    }
    else
    {
        QString SD = StartDateEdit->text();
        int SD_size = SD.size();
        QString ED = EndDateEdit->text();
        int ED_size = ED.size();
        QString NOS = numAttendiesEdit->text();
        int NOS_size = NOS.size();
        if(comboBox_add_event->currentText() == "Room Database")
		{
			//add to drop down
		}
        else if (comboBox_add_event->currentText() == "Course Database")
		{
			//add to drop down
		}
        else if (comboBox_add_event->currentText() == "Event Database")
		{
			//add to drop down
		}
        if (comboBox_add_event->count() > 0 && comboBox_add_event->currentText() != "[Select]" && SD_size > 0 && ED_size > 0 && NOS_size > 0)
		{
			
			QString filename = comboBox_add_event->currentText() + "txt;";
			ofstream fout;
			fout.open(filename, ios::app);
			fname = comboBox_add_event->currentText() + "\t" + fileNameEdit->text() + "\t" + RoomCapacityEdit->text() + "\t" + numAttendiesEdit->text();
			if(computers->isTristate() == true)
			{
				fname + "\t" + "computers";
			}
			else
			{
				fname;
			}
			if(projectorsCBLabel->isTristate() == true)
			{
				fname + "\t" + "Projectors";
			}
			else
			{
				fname;
			}
			if(wbCB->isTristate() == true)
			{
				fname + "\t" + "WhiteBoard";
			}
			else
			{
				fname;
			}

			fout << filename;
			fout.close();
			
		}
    }
    mainLayout->addWidget(button_Add);
    mainLayout->addWidget(button_Cancel);
}

Revise::Revise(const QFileInfo &fileInfo, QWidget *parent) : QWidget(parent)
{
    QLabel *SelectDatabaseType = new QLabel(tr("Database Type: "));
    QComboBox *comboBox_SelectDatabaseType = new QComboBox;
    comboBox_SelectDatabaseType->addItem(tr("[Select]"));
    comboBox_SelectDatabaseType->addItem(tr("Room Database"));
    comboBox_SelectDatabaseType->addItem(tr("Course Database"));
    comboBox_SelectDatabaseType->addItem(tr("Event Database"));

    QLabel *TrackDatabaseName = new QLabel(tr("Database Name: "));
    QComboBox *comboBox_TrackDatabaseName = new QComboBox;
    comboBox_TrackDatabaseName->addItem(tr("[Select]"));

    QLabel *TrackId = new QLabel(tr("Select Name: "));
    QComboBox *comboBox_TrackId = new QComboBox;
    comboBox_TrackId->addItem(tr("[Select]"));


    QLabel *ReviseField = new QLabel(tr("Field to be revised: "));
    QComboBox *comboBox_ReviseField = new QComboBox;
    comboBox_ReviseField->addItem(tr("[Select]"));


    QLabel *ReviseFieldLabel = new QLabel(tr("Enter Replacement text:"));//changed to Database Nam
    QLineEdit *ReviseFieldEdit=new QLineEdit(fileInfo.fileName());

    QPushButton *button_Commit = new QPushButton("&Commit", this);
    QPushButton *button_Cancel = new QPushButton("&Cancel", this);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(SelectDatabaseType);
    mainLayout->addWidget(comboBox_SelectDatabaseType);
    mainLayout->addWidget(TrackDatabaseName);
    mainLayout->addWidget(comboBox_TrackDatabaseName);
    mainLayout->addWidget(TrackId);
    mainLayout->addWidget(comboBox_TrackId);
    mainLayout->addWidget(ReviseField);
    mainLayout->addWidget(comboBox_ReviseField);
    mainLayout->addWidget(ReviseFieldLabel);
    mainLayout->addWidget(ReviseFieldEdit);
    setLayout(mainLayout);

    mainLayout->addWidget(button_Commit);
    mainLayout->addWidget(button_Cancel);
}

Run::Run(const QFileInfo &fileInfo, QWidget *parent) : QWidget(parent)
{

    QLabel *SelectDatabaseType = new QLabel(tr("Select a Room Database"));
    QComboBox *comboBox_SelectDatabaseType = new QComboBox;
    comboBox_SelectDatabaseType->addItem(tr("[Select]"));


    QLabel *TrackDatabaseName = new QLabel(tr("Select a Course Database"));
    QComboBox *comboBox_TrackDatabaseName = new QComboBox;
    comboBox_TrackDatabaseName->addItem(tr("[Select]"));

/*
    QLabel *TrackId = new QLabel(tr("Select Name: "));
    QComboBox *comboBox_TrackId = new QComboBox;
    comboBox_TrackId->addItem(tr("[Select]"));
    comboBox_TrackId->addItem(tr("item 1"));
    comboBox_TrackId->addItem(tr("item 2"));
    comboBox_TrackId->addItem(tr("item 3"));
*/
    QLabel *ReviseField = new QLabel(tr("Sekect a Event Database"));
    QComboBox *comboBox_ReviseField = new QComboBox;
    comboBox_ReviseField->addItem(tr("[Select]"));

    QLabel *ReviseFieldLabel = new QLabel(tr("Schedule Name"));//changed to Database Nam
    QLineEdit *ReviseFieldEdit = new QLineEdit(fileInfo.fileName());

   // QLabel *ReviseFieldEdit = new QLabel(tr("File Name:"));//changed to Database Name
   // QLineEdit *RevisedFieldEdit = new QLineEdit(fileInfo.fileName());
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QPushButton *button_Run = new QPushButton("&Run", this);
    QPushButton *button_Cancel = new QPushButton("&Cancel", this);

    mainLayout->addWidget(SelectDatabaseType);
    mainLayout->addWidget(comboBox_SelectDatabaseType);
    mainLayout->addWidget(TrackDatabaseName);
    mainLayout->addWidget(comboBox_TrackDatabaseName);
    //mainLayout->addWidget(TrackId);
   // mainLayout->addWidget(comboBox_TrackId);
    mainLayout->addWidget(ReviseField);
    mainLayout->addWidget(comboBox_ReviseField);
    mainLayout->addWidget(ReviseFieldLabel);
    mainLayout->addWidget(ReviseFieldEdit);
    mainLayout->addWidget(button_Run);
    mainLayout->addWidget(button_Cancel);
    setLayout(mainLayout);


}



