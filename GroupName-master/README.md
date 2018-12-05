# GroupName
UNT Schedule manager


This project is creating a schedule for UNT Discovery Park.



To Install the application you need to

1. Go to https://www.qt.io/download-qt-installer?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5

2. Scroll down and click on download.

3. On the kits, click on the 5.11.2. Make sure tool is selected.
Warning: Instalation may take up to 2 hours at most.

4. Open the application
5. Open the project and run the application.

The Back end

The back end of this project creates the databases and allows the user to enter what they need into the database.
You can use any C++ editing program(Visual Studio ect.) but we recommend using the CSE machines.

The files required are main.cpp, room.h, rooms.h, classy.h, classes.h, event.h and events.h.

When you first start the aplication you need to compile the program by using g++ -std=c++11 main.cpp events.h event.h classes.h classy.h rooms.h room.h
It takes a few seconds.

1. Once you start the program you are taken to the menu.

2. The add room, courses and events automatically create databases when you first start the function. Start there first.
Warning: Do not use spaces when specifying the course, room or event as it will cause the program to auto add everything to the database.
3. The add database and import database allow to import database that are .csv to be used inside the program.

4. Once you have everything in use the run function in the menu to convert the database into an excel file.
