#include<string> 
#include<fstream>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <sstream> 

using namespace std;

class classy
{
private:
	string className;
	string courseName;
	long courseID;
	long sTime;
	long eTime;
	long sMinute;
	long eMinute;
	long sDate;
	long eDate;
	long sDay;
	long eDay;
	long sYear;
	long eYear;

	long size;
public:
	long GetCourseID()
	{
		return courseID;
	}
	void SetCourseID(int CourseID)
	{
		courseID = CourseID;
	}
	std::string GetClassName()
    	{
		return className;
    	}
    	void SetClassName(std::string ClassName)
    	{
    		className = ClassName;
    	}
	std::string GetCourseName()
    	{
		return courseName;
    	}
    	void SetCourseName(std::string CourseName)
    	{
    		courseName = CourseName;
    	}
	long GetStartTime()
	{
		return sTime;
	}
	void SetStartTime(int startTime)
	{
		sTime = startTime;
	}
	long GetStartMinute()
	{
		return sMinute;
	}
	void SetStartMinute(int startMinute)
	{
		sMinute = startMinute;
	}
	long GetEndTime()
	{
		return eTime;
	}
	void SetEndTime(int endTime)
	{
		eTime = endTime;
	}
	long GetEndMinute()
	{
		return eMinute;
	}
	void SetEndMinute(int endMinute)
	{
		eMinute = endMinute;
	}

	long GetStartDate()
	{
		return sDate;
	}
	void SetStartDate(int startDate)
	{
		sDate = startDate;
	}
	long GetEndDate()
	{
		return eDate;
	}
	void SetEndDate(int endDate)
	{
		eDate = endDate;
	}
	long GetStartDay()
	{
		return sDay;
	}
	void SetStartDay(int startDay)
	{
		sDay = startDay;
	}
	long GetEndDay()
	{
		return eDay;
	}
	void SetEndDay(int endDay)
	{
		eDay = endDay;
	}
	long GetStartYear()
	{
		return sYear;
	}
	void SetStartYear(int startYear)
	{
		sYear = startYear;
	}
	long GetEndYear()
	{
		return eYear;
	}
	void SetEndYear(int endYear)
	{
		eYear = endYear;
	}

	long GetCompacity()
	{
		return size;
	}
	void SetCompacity(int compacity)
	{
		size = compacity;
	}

};