#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <Windows.h>

using namespace std;

class worker {
public:
	string m_Name = "Œ¥∑÷≈‰";
	string m_DeptName = "Œ¥∑÷≈‰";
	int m_ID = 0;
	int m_Password = 0;
	string* m_MissionPtr = NULL;
	int m_MissionNum = 0;
	int* m_AttachClassIDPtr = NULL;
	int m_AttachClassNum = 0;
	virtual int GetClassType();
	void ReviseMission();
	void PrintMission();
	void AddAttachClass(int& AttachClassID);
	void RemoveAttachClass(int& AttachClassID);
	int m_AttachToClassID = 0;
};

class boss :public worker {
public:
	boss(int ID, int Password, string Name, int MissionNum,string* MissionPtr, int AttachClassNum, int* AttachClassPtr);
	int GetClassType();

};

class manager :public worker {
public:
	manager(int ID, int Password, string Name,string DeptName, int MissionNum,string* MissionPtr, int AttachClassNum, int* AttachClassPtr);
	int GetClassType();
};

class employee :public worker {
public:
	employee(int ID, int Password, string Name, string DeptName, int MissionNum,string* MissionPtr);
	int GetClassType();
};

class Control {
public:
	int m_WorkerNum = 0;
	int* m_ID_DatabasePtr = NULL;
	int Permission = 0;
	worker** WorkerClassPtr = NULL;
	int TableID = 0;
	void InnitialSystem();
	void InnitialClass();
	void LogIn();
	int ID_DistributeSytem();
	void GroupAddClass();
	void SoloAddClass();
	void FileIn();
	void FileOut();
	int Menu();
	void PrintStuff();
	void DeleteClass();
	void ReviseClass();
	void ReviseMission();
	void PrintMission();
	void AddAttachClass();
	int IDSearch_TableID(int& ID);
	string IDSearch_Name(int& ID);
	void PrintAttachClass();
};

