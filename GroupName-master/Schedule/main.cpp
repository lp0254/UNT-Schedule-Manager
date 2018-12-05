#include<iostream>
#include<stdlib.h>
#ifndef CLASSY_H
#define CLASSY_H
	#include"classy.h"
#endif
#ifndef CLASSES_H
#define CLASSES_H
	#include"classes.h"
#endif
#ifndef EVENT_H
#define EVENT_H
	#include"event.h"
#endif
#ifndef EVENTS_H
#define EVENTS_H
	#include"events.h"
#endif
#ifndef ROOM_H
#define ROOM_H
	#include"room.h"
#endif
#ifndef ROOMS_H
#define ROOMS_H
	#include"rooms.h"
#endif

using namespace std;

void CreateDatabaseUI();
void ImportDatabaseUI();
void AddRoomUI();
void AddCourseUI();
void AddEventUI();
void ReviseUI();
void RunUI();

int main()
{
	
	int choice;
	
	cout<<"UNT LIBRARY MANAGEMENT"<<endl;
	cout<<"Select your choice"<<endl;
	cout<<"1. Create Database"<<endl;
	cout<<"2. Import Database"<<endl;
	cout<<"3. Add Room"<<endl;
	cout<<"4. Add Course"<<endl;
	cout<<"5. Add Event"<<endl;
	cout<<"6. Revise"<<endl;
	cout<<"7. Run"<<endl;

	cin>>choice;
	
	switch(choice)
	{
		case 1:
			CreateDatabaseUI();
			break;
		case 2:

			break;
		case 3:
			AddRoomUI();
			break;
		case 4:
			AddCourseUI();
			break;
		case 5:
			AddEventUI();
			break;
		case 6:

			break;
		case 7:
			RunUI();
			break;
		default:
			cout<<"Select the correct command."<<endl;
			break;
	}
	
}
void CreateDatabaseUI()
{
	cout<<"Create Database"<<endl;
	
}
void ImportDatabaseUI()
{
	cout<<"Import Database"<<endl;
}
void AddRoomUI()
{
	room myRoom;
	rooms myRooms;

	string building;
	long roomNumber;
	long compacity;
	char y;

	cout<<"Create Room"<<endl;
	
	cout<<"Enter Building"<<endl;
	cin>>building;
	myRoom.SetBuildingName(building);

	cout<<"Enter Room Number"<<endl;
	cin>>roomNumber;
	myRoom.SetRoomNumber(roomNumber);

	cout<<"Enter the Compacity "<<endl;
	cin>>compacity;
	myRoom.SetCompacity(compacity);
	
	cout<<"Are you sure everything is right?"<<endl;
	cin>>y;
	if(y == 'Y'||'y')
	{
		cout<<"Room added"<<myRooms.addRoom(myRoom)<<endl;
	}
	
}
void AddCourseUI()
{
	classy myClass;
	classes myClasses;

	string ClassName, CourseName;
	long CourseID;
	long startTime = 0, endTime = 0;
	long startMinute = 0, endMinute = 0;
	long startDate = 0, endDate = 0;
	long startDay = 0, endDay = 0;
	long startYear = 0, endYear = 0;
	long compacity;
	char y;

	cout<<"Create Class"<<endl;
	cout<<"Enter Class Name"<<endl;
	cin >>ClassName;
	myClass.SetClassName(ClassName);
	cout<<"Enter your course name"<<endl;
	cin>>CourseName;
	myClass.SetCourseName(CourseName);
	//cout<<"Display "<<myPatron.GetAdress()<<endl;
	//myPatron.name;
	cout<<"Enter Course ID "<<endl;
	cin>>CourseID;
	myClass.SetCourseID(CourseID);
	cout<<"Enter start Hour "<<endl;
	cin>>startTime;
	while(startTime == 0 || startTime > 12)
	{
		cout<<"Inside"<<endl;
		if(startTime > 12)
		{
			cout<<"Value goes above 12 hours. Please type less than 12 Hours."<<endl;
			cin>>startTime;
		}
		else if(startTime != 0)
		{
			break;
		}
	}

	myClass.SetStartTime(startTime);
	cout<<"Enter start Minute "<<endl;
	cin>>startMinute;
	while(startMinute == 0 || startMinute > 60)
	{
		if(startMinute > 60)
		{
			cout<<"Value goes above 60 minutes. Please type less than 60 minutes."<<endl;
			cin>>startMinute;
		}
		else if(startMinute != 0)
		{
			break;
		}
	}
	myClass.SetStartMinute(startMinute);
	cout<<"Enter end Hour "<<endl;
	cin>>endTime;
	while(endTime== 0 || endTime> 12)
	{
		if(endTime> 12)
		{
			cout<<"Value goes above 12 hours. Please type less than 12 Hours."<<endl;
			cin>>endTime;
		}
		else if(endTime != 0)
		{
			break;
		}
	}
	myClass.SetEndTime(endTime);
	cout<<"Enter end Minute "<<endl;
	cin>>endMinute;
	while(endMinute == 0 || endMinute > 60)
	{
		if(endMinute > 60)
		{
			cout<<"Value goes above 60 minutes. Please type less than 60 minutes."<<endl;
			cin>>endMinute;
		}
		else if(endMinute != 0)
		{
			break;
		}
	}

	myClass.SetEndMinute(endMinute);
	cout<<"Enter start Month "<<endl;
	cin>>startDate;
	myClass.SetStartDate(startDate);
	cout<<"Enter start Day "<<endl;
	cin>>startDay;
	myClass.SetStartDay(startDay);
	cout<<"Enter start Year "<<endl;
	cin>>startYear;
	myClass.SetStartYear(startYear);
	cout<<"Enter end Month "<<endl;
	cin>>endDate;
	myClass.SetEndDate(endDate);
	cout<<"Enter end Day "<<endl;
	cin>>endDay;
	myClass.SetEndDay(endDay);
	cout<<"Enter end Year "<<endl;
	cin>>endYear;
	myClass.SetEndYear(endYear);
	cout<<"Enter the Compacity "<<endl;
	cin>>compacity;
	myClass.SetCompacity(compacity);
	cout<<"Are you sure everything is right?"<<endl;
	cin>>y;
	if(y == 'Y'||'y')
	{
		cout<<"Course"<<myClasses.addClass(myClass)<<endl;
	}


}
void AddEventUI()
{
	event myEvent;
	events myEvents;

	string EventName;
	long startTime = 0, endTime = 0;
	long startMinute = 0, endMinute = 0;
	long startDate = 0, endDate = 0;
	long startDay = 0, endDay = 0;
	long startYear = 0, endYear = 0;
	long compacity = 0;
	char y;

	cout<<"Create Event"<<endl;
	cout<<"Enter Event Name"<<endl;
	cin >>EventName;
	myEvent.SetEventName(EventName);
	cout<<"Enter start Hour "<<endl;
	cin>>startTime;
	while(startTime == 0 || startTime > 12)
	{
		cout<<"Inside"<<endl;
		if(startTime > 12)
		{
			cout<<"Value goes above 12 hours. Please type less than 12 Hours."<<endl;
			cin>>startTime;
		}
		else if(startTime != 0)
		{
			break;
		}
	}
	myEvent.SetStartTime(startTime);
	cout<<"Enter start Minute "<<endl;
	cin>>startMinute;
	while(startMinute == 0 || startMinute > 60)
	{
		if(startMinute > 60)
		{
			cout<<"Value goes above 60 minutes. Please type less than 60 minutes."<<endl;
			cin>>startMinute;
		}
		else if(startMinute != 0)
		{
			break;
		}
	}
	myEvent.SetStartMinute(startMinute);
	cout<<"Enter end Hour "<<endl;
	cin>>endTime;
	while(endTime== 0 || endTime> 12)
	{
		cout<<"Inside"<<endl;
		if(endTime> 12)
		{
			cout<<"Value goes above 12 hours. Please type less than 12 Hours."<<endl;
			cin>>endTime;
		}
		else if(endTime!= 0)
		{
			break;
		}
	}
	myEvent.SetEndTime(endTime);
	cout<<"Enter end Minute "<<endl;
	cin>>endMinute;
	while(endMinute == 0 || endMinute > 60)
	{
		if(endMinute > 60)
		{
			cout<<"Value goes above 60 minutes. Please type less than 60 minutes."<<endl;
			cin>>endMinute;
		}
		else if(endMinute != 0)
		{
			break;
		}
	}

	myEvent.SetEndMinute(endMinute);
	cout<<"Enter start Month "<<endl;
	cin>>startDate;
	myEvent.SetStartDate(startDate);
	cout<<"Enter start day "<<endl;
	cin>>startDay;
	myEvent.SetStartDay(startDay);
	cout<<"Enter start year "<<endl;
	cin>>startYear;
	myEvent.SetStartYear(startYear);
	cout<<"Enter end Month "<<endl;
	cin>>endDate;
	myEvent.SetEndDate(endDate);
	cout<<"Enter End day "<<endl;
	cin>>endDay;
	myEvent.SetEndDay(endDay);
	cout<<"Enter End year "<<endl;
	cin>>endYear;
	myEvent.SetEndYear(endYear);
	cout<<"Enter the Compacity "<<endl;
	cin>>compacity;
	myEvent.SetCompacity(compacity);
	cout<<"Are you sure everything is right?"<<endl;
	cin>>y;
	if(y == 'Y'||'y')
	{
		cout<<"Event added "<<myEvents.addEvent(myEvent)<<endl;
	}


}
void ReviseUI()
{
	cout<<"Revise"<<endl;
}
void RunUI()
{
	event myEvent;
	events myEvents;
	classy myClass;
	classes myClasses;
	room myRoom;
	rooms myRooms;
	int choice;
	

	cout<<"Run"<<endl;
	cout<<"Enter the databases to use"<<endl;
	cout<<"1. Course"<<endl;
	cout<<"2. Room"<<endl;
	cout<<"3. Event"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			myClasses.runClass();
			break;
		case 2:
			myRooms.runRoom();
			break;
		case 3:
			myEvents.runEvent();
			break;
		default:
			cout<<"Select the correct command."<<endl;
			break;
	}

}
