#include "ClassBase.h"

//Worker
//4行
int worker::GetClassType()
{
	return 0;
}

void worker::ReviseMission()
{
	system("cls");
	PrintMission();
	cout << "请问您想做什么操作" << endl;
	cout << "1.添加 2.修改 3.删除" << endl;
	int Option = 0;
	int MissionTable = 0;
	cin >> Option;
	if (Option == 1)
	{
		string Mission;
		cout << "请输入需要添加的任务内容(不要有空格，空格后的数据将会被抹除)" << endl;
		cin >> Mission;
		cin.ignore(128, '\n');
		string* NewSpace = new string[m_MissionNum + 1];
		if (m_MissionPtr != NULL)
		{
			for (int i = 0; i < m_MissionNum; i++)
			{
				NewSpace[i] =m_MissionPtr[i];
			}
		}
		NewSpace[m_MissionNum] = Mission;
		delete[] m_MissionPtr;
		m_MissionPtr = NewSpace;
		NewSpace = NULL;
		m_MissionNum++;
		cout << "成功添加并保存进文件！" << endl;
		return;
	}
	else if (Option == 2)
	{
		if (m_MissionNum == 0)
		{
			cout << "当前您没有任何任务" << endl;
			return;
		}
		string Mission;
		bool Result = 0;
		cout << "请输入需要修改的任务序号" << endl;
		cin >> MissionTable;
		cout << "请输入修改后的任务(不要有空格，空格后的数据将会被抹除)" << endl;
		cin >> m_MissionPtr[MissionTable - 1];
		cin.ignore(128, '\n');
		cout << "成功修改并保存进文件！" << endl;
		return;
	}
	else if (Option == 3)
	{
		if (m_MissionNum == 0)
		{
			cout << "当前您没有任何任务" << endl;
			return;
		}
		bool Result = 0;
		cout << "请输入需要删除的任务序号" << endl;
		cin >> MissionTable;
		while (cin.good() != 1)
		{
			cin >> MissionTable;
			cout << "输入的操作代码不符合规范，请重新输入:";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		if (m_MissionNum != 1 && MissionTable <= m_MissionNum)
		{
			string* NewSpace = new string[m_MissionNum - 1];
			for (int i = 0; i < m_MissionNum; i++)
			{
				if (i != MissionTable - 1 && Result == 0)
				{
					NewSpace[i] = m_MissionPtr[i];
				}
				else if (i != MissionTable - 1 && Result == 1)
				{
					NewSpace[i - 1] = m_MissionPtr[i];
				}
				else
				{
					Result = 1;
				}
			}

			delete[] m_MissionPtr;
			m_MissionPtr = NewSpace;
			NewSpace = NULL;
			m_MissionNum--;
			cout << "成功删除并保存进文件！" << endl;
			return;
		}
		else if (m_MissionNum != 1 && MissionTable > m_MissionNum)
		{
			cout << "序号不符合要求，请重试" << endl;
		}
		else
		{
			m_MissionNum = 0;
			delete[] m_MissionPtr;
			m_MissionPtr = NULL;
			cout << "成功删除并保存进文件！" << endl;
			return;
		}
	}
}

void worker::PrintMission()
{
	cout << "当前您共有任务" << m_MissionNum << "项" << endl;
	for (int i = 0; i < m_MissionNum; i++)
	{
		cout << i + 1 << "     " << m_MissionPtr[i] << endl;
	}
}

void worker::AddAttachClass(int &AttachClassID)
{
	int* NewSpace = new int [m_AttachClassNum + 1];
	if (m_AttachClassIDPtr != NULL)
	{
		for (int i = 0; i < m_AttachClassNum; i++)
		{
			NewSpace[i] = m_AttachClassIDPtr[i];
		}
	}
	NewSpace[m_AttachClassNum] = AttachClassID;
	delete[] m_AttachClassIDPtr;
	m_AttachClassIDPtr = NewSpace;
	NewSpace = NULL;
	m_AttachClassNum++;
}

void worker::RemoveAttachClass(int& AttachClassID)
{
	int* NewSpace = new int[m_AttachClassNum - 1];
	bool Result = 0;
	if (m_AttachClassIDPtr != NULL)
	{
		for (int i = 0; i < m_AttachClassNum; i++)
		{
			if (m_AttachClassIDPtr[i] != AttachClassID && Result == 0)
			{
				NewSpace[i] = m_AttachClassIDPtr[i];
			}
			else if (m_AttachClassIDPtr[i] != AttachClassID && Result == 1)
			{
				NewSpace[i - 1] = m_AttachClassIDPtr[i];
			}
			else
			{
				Result = 1;
			}
		}
	}
	delete[] m_AttachClassIDPtr;
	m_AttachClassIDPtr = NewSpace;
	NewSpace = NULL;
	m_AttachClassNum--;
}
//Boss
//9行
boss::boss(int ID, int Password, string Name, int MissionNum,string* MissionPtr, int AttachClassNum, int* AttachClassPtr)
{
	this->m_ID = ID;
	this->m_Name = Name;
	this->m_Password = Password;
	this->m_DeptName = "董事会";
	this->m_MissionPtr = MissionPtr;
	this->m_MissionNum = MissionNum;
	this->m_AttachClassNum = AttachClassNum;
	this->m_AttachClassIDPtr = AttachClassPtr;
}
//4行
int boss::GetClassType()
{
	return 1;
}

//Manager
//9行
manager::manager(int ID, int Password, string Name,string DeptName, int MissionNum,string* MissionPtr, int AttachClassNum, int* AttachClassPtr)
{
	this->m_ID = ID;
	this->m_Name = Name;
	this->m_Password = Password;
	this->m_DeptName = DeptName;
	this->m_MissionPtr = MissionPtr;
	this->m_MissionNum = MissionNum;
	this->m_AttachClassNum = AttachClassNum;
	this->m_AttachClassIDPtr = AttachClassPtr;
}
//4行
int manager::GetClassType()
{
	return 2;
}

//Employee
//8行
employee::employee(int ID,int Password, string Name, string DeptName, int MissionNum,string* MissionPtr)
{
	this->m_ID = ID;
	this->m_Name = Name;
	this->m_DeptName = DeptName;
	this->m_Password = Password;
	this->m_MissionPtr = MissionPtr;
	this->m_MissionNum = MissionNum;
}
//6行
//4行
int employee::GetClassType()
{
	return 3;
}

//Control
//94行
void Control::InnitialSystem()
{
	ifstream ifs;
	cout << "欢迎使用本职工管理系统" << endl;
	cout << "正在从文件中载入数据" << endl;
	ifs.open("Database.txt", ios::in);

	if (ifs.is_open() == true)
	{
		cout << "成功打开文件，正在载入信息" << endl;
		if (ifs.good() == 0)
		{
			cout << "文件损坏，重新创建初始化账号" << endl;
			ifs.close();
			InnitialClass();
			FileOut();
		}
		else
		{
			ifs >> m_WorkerNum;
			if (m_WorkerNum == 0)
			{
				cout << "文件损坏，重新创建初始化账号" << endl;
				ifs.close();
				InnitialClass();
				FileOut();
			}
			else
			{
				cout << "开始载入数据" << endl;
				ifs.close();
				FileIn();
			}
		}

	}
	else
	{
		cout << "未找到相关文件，创建初始化账号" << endl;
		InnitialClass();
		FileOut();
	}
	cout << "初始化完成" << endl;
}

void Control::InnitialClass()
{
	ofstream ofs;
	ofs.open("Database.txt", ios::trunc);
	ofs.close();
	WorkerClassPtr = new worker * [1];
	worker* InnitialBoss = new boss(ID_DistributeSytem(), 666666, "admin", 0, NULL,0,NULL);
	WorkerClassPtr[0] = InnitialBoss;
	cout << "初始管理员账号创建完成" << endl;
	cout << "姓名:admin 密码:666666" << endl;
	m_WorkerNum = 1;
}
//52行
void Control::LogIn()
{
	Sleep(1000);
	system("cls");
	string Name;
	int Password;
	bool LogIn = 0;

	while (1)
	{
		cout << "请输入姓名以及密码以登录该系统" << endl;
		cin >> Name;
		cin >> Password;
		for (int i = LogIn = 0; i < m_WorkerNum; i++)
		{
			if (Name == WorkerClassPtr[i]->m_Name && Password == WorkerClassPtr[i]->m_Password&&WorkerClassPtr[i]->GetClassType() !=0)
			{
				Permission = WorkerClassPtr[i]->GetClassType();
				LogIn = 1;
				TableID = i;
				break;
			}
			else if (Name == WorkerClassPtr[i]->m_Name && Password == WorkerClassPtr[i]->m_Password && WorkerClassPtr[i]->GetClassType() == 0)
			{
				cout << "该姓名所属账号出现错误，请联系相关管理员" << endl;
				break;
			}
		}
		if (LogIn == 1)
		{
			cout << "成功以" << Name << "账号登录" << endl;
			switch (Permission)
			{
			case 1:
				cout << "权限组:董事" << endl;
				break;
			case 2:
				cout << "权限组:主管" << endl;
				break;
			case 3:
				cout << "权限组:职员" << endl;
				break;
			}
			break;
		}
		else
		{
			cout << "用户名或者密码错误，请重试" << endl;
		}
	}
}
//82行
void Control::GroupAddClass()
{
	system("cls");
	//设置新添加的员工人数
	int AddNum = 0;
	cout << "正在批量添加员工" << endl;
	cout << "请输入需要添加的人数" << endl;
	while (1)
	{
		cin >> AddNum;
		if (AddNum <= 0)
		{
			cout << "输入人数不符合要求，请重新输入" << endl;
		}
		else
		{
			break;
		}
	}
	//扩容指针
	worker** NewSpace = new worker * [AddNum + m_WorkerNum];
	for (int i = 0; i < m_WorkerNum; i++)
	{
		NewSpace[i] = WorkerClassPtr[i];
	}

	//设置新添加的员工信息
	string name;
	int StuffType = 0;
	for (int i = 0; i < AddNum; i++)
	{
		cout << "请输入第" << i + 1 << "名员工姓名" << endl;
		cin >> name;
		cout << "请输入员工职务代码" << endl;
		cout << "1.董事 2.主管 3.职员" << endl;
		while (1)
		{
			cin >> StuffType;
			while (cin.good() != 1)
			{
				cout << "输入的职务代码不符合规范，请重新输入" << endl;
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			if (StuffType != 1 && StuffType != 2 && StuffType != 3)
			{
				cout << "输入的职务不符合规范，请重新输入";
			}
			else if (StuffType < Permission)
			{
				cout << "您所添加的员工权限高于您，请重新设置职务" << endl;
			}
			else
			{
				break;
			}
		}
		switch (StuffType)
		{
		case 1:
			NewSpace[m_WorkerNum + i] = new boss(ID_DistributeSytem(), 666666, name,0,NULL, 0, NULL);
			break;
		case 2:
			NewSpace[m_WorkerNum + i] = new manager(ID_DistributeSytem(), 666666, name,"未分配",0,NULL, 0, NULL);
			break;
		case 3:
			NewSpace[m_WorkerNum + i] = new employee(ID_DistributeSytem(), 666666, name, "未分配",0,NULL);
			break;
		}
	}
	m_WorkerNum = m_WorkerNum + AddNum;

	delete[] WorkerClassPtr;
	WorkerClassPtr = NewSpace;
	NewSpace = NULL;
	cout << "完成批量添加操作(登录密码为666666)" << endl;
	cout << "返回主菜单" << endl;
	FileOut();
}
//80行
void Control::SoloAddClass()
{
	system("cls");
	cout << "正在单独添加员工" << endl;
	string Name;
	int Password;
	int StuffType;
	string DeptName;
	cout << "请输入员工姓名，登录密码以及职务(1.董事长 2.主管 3.职员) 中间用空格区分" << endl;
	cout << "注意，如果为主管或者职员，请在职务后输入所在部门" << endl;
	cin >> Name;
	cin >> Password;
	while (cin.good() != 1)
	{
		cout << "输入的密码不符合规范，请重新输入:";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}

	while (1)
	{
		cin >> StuffType;
		while (cin.good() != 1)
		{
			cout << "输入的职务代码不符合规范，请重新输入" << endl;
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		if (StuffType != 1 && StuffType != 2 && StuffType != 3)
		{
			cout << "输入的职务不符合规范，请重新输入" << endl;
			while (cin.get() != '\n')
				continue;
		}
		else if(StuffType < Permission)
		{
			cout << "您所设置的员工权限高于您，请重新设置职务" << endl;
			while (cin.get() != '\n')
				continue;
		}
		else
		{
			break;
		}
	}

	if (StuffType != 1)
	{
		cin >> DeptName;
	}
	//指针扩容
	worker** NewSpace = new worker * [m_WorkerNum + 1];
	//转移数据
	for (int i = 0; i < m_WorkerNum; i++)
	{
		NewSpace[i] = WorkerClassPtr[i];
	}
	//添加数据
	switch (StuffType)
	{
	case 1:
		NewSpace[m_WorkerNum] = new boss(ID_DistributeSytem(), Password, Name, 0, NULL, 0, NULL);
		break;
	case 2:
		NewSpace[m_WorkerNum] = new manager(ID_DistributeSytem(), Password, Name, DeptName,0,NULL, 0, NULL);
		break;
	case 3:
		NewSpace[m_WorkerNum] = new employee(ID_DistributeSytem(), Password, Name, DeptName,0,NULL);
		break;
	}
	//转移指针
	delete[] WorkerClassPtr;
	WorkerClassPtr = NewSpace;

	NewSpace = NULL;
	m_WorkerNum++;
	cout << "完成单人添加操作" << endl;

	FileOut();
}

void Control::FileIn()
{
	ifstream ifs;
	ifs.open("Database.txt", ios::in);
	ifs.ignore();
	WorkerClassPtr = new worker * [m_WorkerNum];
	int ClassType;
	int Password;
	int ID;
	string Name;
	int MissionNum;
	string DeptName;
	string* MissionPtr = NULL;
	int AttachClassNum;
	int* AttachClassIDPtr = NULL;
	for (int i = 0; i < m_WorkerNum; i++)
	{
		if (ifs.good() == 1)
		{
			ifs >> ClassType >> MissionNum >> AttachClassNum >> Name >> ID >> DeptName >> Password;
			MissionPtr = new string[MissionNum];
			for (int i = 0; i < MissionNum; i++)
			{
				ifs >> MissionPtr[i];
			}
			AttachClassIDPtr = new int[AttachClassNum];
			for (int i = 0; i < AttachClassNum; i++)
			{
				ifs >> AttachClassIDPtr[i];
			}
			switch (ClassType)
			{
			case 1:
				WorkerClassPtr[i] = new boss(ID, Password, Name, MissionNum, MissionPtr, AttachClassNum, AttachClassIDPtr);
				break;
			case 2:
				WorkerClassPtr[i] = new manager(ID, Password, Name, DeptName, MissionNum, MissionPtr, AttachClassNum, AttachClassIDPtr);
				break;
			case 3:
				WorkerClassPtr[i] = new employee(ID, Password, Name, DeptName, MissionNum, MissionPtr);
				break;
			}
			ifs.ignore(128, '\n');
		}
		else
		{
			m_WorkerNum--;
		}
	}
	ifs.close();
}
//24行
void Control::FileOut()
{
	ofstream ofs;
	ofs.open("Database.txt", ios::trunc | ios::out);
	ofs << m_WorkerNum << endl;
	for (int i = 0; i < m_WorkerNum; i++)
	{
		ofs << WorkerClassPtr[i]->GetClassType() << " ";
		ofs << WorkerClassPtr[i]->m_MissionNum << " ";
		ofs << WorkerClassPtr[i]->m_AttachClassNum << " ";
		ofs << WorkerClassPtr[i]->m_Name << " ";
		ofs << WorkerClassPtr[i]->m_ID << " ";
		ofs << WorkerClassPtr[i]->m_DeptName << " ";
		ofs << WorkerClassPtr[i]->m_Password << " ";
		for (int j = 0; j < WorkerClassPtr[i]->m_MissionNum; j++)
		{
			ofs << WorkerClassPtr[i]->m_MissionPtr[j] << " ";
		}
		for (int j = 0; j < WorkerClassPtr[i]->m_AttachClassNum; j++)
		{
			ofs << WorkerClassPtr[i]->m_AttachClassIDPtr[j] << " ";
		}
		ofs << endl;
	}
	cout << "完成文件保存" << endl;
	ofs.close();
}
//40行
int Control::ID_DistributeSytem()
{
	int ID = 0;
	bool Result = 0;
	srand(time(0));
	while (1)
	{
		Result = 0;
		ID = rand();
		if (m_ID_DatabasePtr != NULL)
		{
			for (int i = 0; i < m_WorkerNum; i++)
			{
				if (ID == m_ID_DatabasePtr[i])
				{
					Result = 1;
					break;
				}
			}
			if (Result != 1)
			{
				int* NewSpace = new int[m_WorkerNum];

				for (int i = 0; i < m_WorkerNum - 1; i++)
				{
					NewSpace[i] = m_ID_DatabasePtr[i];
				}
				NewSpace[m_WorkerNum - 1] = ID;
				m_ID_DatabasePtr = NewSpace;
				delete[] NewSpace;
				return ID;
			}
		}
		else
		{
			m_ID_DatabasePtr = new int[1];
			return ID;
		}
	}
}
//45行
int Control::Menu()
{
	int Option = 0;
	while (1)
	{
		Sleep(600);
		system("cls");
		cout << "操作系统主菜单" << endl;
		switch (Permission)
		{
		case 0:
			cout << "检测到您以错误的方式登录该系统，正在注销系统" << endl;
			break;
		case 1:
			cout << "1.全体职工信息" << endl;
			cout << "2.批量添加职工" << endl;
			cout << "3.单独添加职工" << endl;
			cout << "4.删除职工" << endl;
			cout << "5.您所管理的职工信息" << endl;
			cout << "6.向所管理部门添加员工" << endl;
			cout << "7.修改职工信息" << endl;
			cout << "8.修改您的信息" << endl;
			cout << "9.修改您的任务" << endl;
			cout << "10.返回登录菜单" << endl;
			cout << "11.退出系统" << endl;
			cin >> Option;
			while (cin.good() != 1)
			{
				cin >> Option;
				cout << "输入的操作代码不符合规范，请重新输入:";
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			switch (Option)
			{
			case 1:
				PrintStuff();
				break;
			case 2:
				GroupAddClass();
				break;
			case 3:
				SoloAddClass();
				break;
			case 4:
				DeleteClass();
				break;
			case 5:
				PrintAttachClass();
				break;
			case 6:
				AddAttachClass();
				break;
			case 7:
				ReviseClass();
				break;
			case 8:
				break;
			case 9:
				ReviseMission();
				break;
			case 10:
				FileOut();
				return 1;
			case 11:
				FileOut();
				return 0;
			}
			break;
		case 2:
			cout << "1.全体职工信息" << endl;
			cout << "2.批量添加职工" << endl;
			cout << "3.单独添加职工" << endl;
			cout << "4.删除职工" << endl;
			cout << "5.您所管理的职工信息" << endl;
			cout << "6.向所管理部门添加员工" << endl;
			cout << "7.修改职工信息" << endl;
			cout << "8.修改您的信息" << endl;
			cout << "9.修改您的任务" << endl;
			cout << "10.返回登录菜单" << endl;
			cout << "11.退出系统" << endl;
			cin >> Option;
			while (cin.good() != 1)
			{
				cin >> Option;
				cout << "输入的操作代码不符合规范，请重新输入:";
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			switch (Option)
			{
			case 1:
				PrintStuff();
				break;
			case 2:
				GroupAddClass();
				break;
			case 3:
				SoloAddClass();
				break;
			case 4:
				break;
			case 5:
				PrintAttachClass();
				break;
			case 6:
				AddAttachClass();
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				ReviseMission();
				break;
			case 10:
				return 1;
			case 11:
				return 0;
			}
			break;
		case 3:
			cout << "1.全体职工信息" << endl;
			cout << "2.修改您的账号信息" << endl;
			cout << "3.删除您的账号" << endl;
			cout << "4.修改您的任务" << endl;
			cout << "5.返回登录菜单" << endl;
			cout << "6.退出系统" << endl;
			cin >> Option;
			while (cin.good() != 1)
			{
				cin >> Option;
				cout << "输入的操作代码不符合规范，请重新输入" << endl;
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			switch (Option)
			{
			case 1:
				PrintStuff();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				ReviseMission();
				break;
			case 5:
				return 1;
			case 6:
				return 0;
			}
			break;
		}
	}
}
//49行
void Control::PrintStuff()
{
	system("cls");
	bool Existence = 0;
	cout << "董事权限组" << endl;
	cout << "序号" << " " << "姓名" << " " << "ID" << " " << "所属部门" << endl;
	//int SearchGood = 0;
	for (int i = 0,SearchGood = 0; i < m_WorkerNum; i++)
	{
		if (WorkerClassPtr[i]->GetClassType() == 1)
		{
			SearchGood++;
			cout << SearchGood << " " << WorkerClassPtr[i]->m_Name << " " << WorkerClassPtr[i]->m_ID << " " << WorkerClassPtr[i]->m_DeptName << endl;
			Existence = 1;
		}
	}
	if (Existence == 0)
	{
		cout << "无" << endl;
	}
	Existence = 0;
	cout << "主管权限组" << endl;
	cout << "序号" << " " << "姓名" << " " << "ID" << " " << "所属部门" << endl;
	for (int i = 0,SearchGood = 0; i < m_WorkerNum; i++)
	{
		if (WorkerClassPtr[i]->GetClassType() == 2)
		{
			SearchGood++;
			cout << SearchGood << " " << WorkerClassPtr[i]->m_Name << " " << WorkerClassPtr[i]->m_ID << " " << WorkerClassPtr[i]->m_DeptName << endl;
			Existence = 1;
		}
	}
	if (Existence == 0)
	{
		cout << "无" << endl;
	}
	Existence = 0;
	cout << "职员权限组" << endl;
	cout << "序号" << " " << "姓名" << " " << "ID" << " " << "所属部门" << endl;
	for (int i =0,SearchGood = 0; i < m_WorkerNum; i++)
	{
		if (WorkerClassPtr[i]->GetClassType() == 3)
		{
			SearchGood++;
			cout << SearchGood << " " << WorkerClassPtr[i]->m_Name << " " << WorkerClassPtr[i]->m_ID << " " << WorkerClassPtr[i]->m_DeptName << endl;
			Existence = 1;
		}
	}
	if (Existence == 0)
	{
		cout << "无" << endl;
	}
	system("pause");
}

void Control::PrintAttachClass()
{
	int ID;
	system("cls");
	cout << "当前您一共管理" << WorkerClassPtr[TableID]->m_AttachClassNum << "名员工" << endl;
	for (int i = 0; i < WorkerClassPtr[TableID]->m_AttachClassNum; i++)
	{
		ID = WorkerClassPtr[TableID]->m_AttachClassIDPtr[i];
		cout << i + 1<< " " << IDSearch_Name(ID) << endl;
	}
	system("pause");
}
//72行
void Control::DeleteClass()
{
	system("cls");
	PrintStuff();
	if (m_WorkerNum == 0)
	{
		cout << "当前不存在任何员工" << endl;
		return;
	}
	string Name;
	int Result = 0;
	cout << "开始删除员工" << endl;
	while (1)
	{
		cout << "请输入需要删除的员工姓名(输入退出以返回菜单)" << endl;

		cin >> Name;
		if (Name == "退出")
		{
			break;
		}
		for (int i = Result = 0; i < m_WorkerNum; i++)
		{
			if (WorkerClassPtr[i]->m_Name == Name&&WorkerClassPtr[i]->GetClassType() >= Permission)
			{

				worker** NewSpace = new worker * [m_WorkerNum - 1];
				//int* IDNewSpace = new int [m_WorkerNum];
				bool ProgressResult = 0;
				for (int j =0; j < m_WorkerNum; j++)
				{
					if (j != i&&ProgressResult == 0)
					{
						NewSpace[j] = WorkerClassPtr[j];
					}
					else if (j != i&&ProgressResult == 1)
					{
						NewSpace[j - 1] = WorkerClassPtr[j];
					}
					else
					{
						ProgressResult = 1;
					}
					//IDNewSpace[j] = m_ID_DatabasePtr[j + 1];
				}
				delete[] WorkerClassPtr;
				//delete[] m_ID_DatabasePtr;
				WorkerClassPtr = NewSpace;
				//m_ID_DatabasePtr = IDNewSpace;
				NewSpace = NULL;
				//IDNewSpace = NULL;
				Result = 1;
				break;
			}
			else if (WorkerClassPtr[i]->m_Name == Name && WorkerClassPtr[i]->GetClassType() < Permission)
			{
				Result = 2;
				break;
			}
		}
		if (Result == 1)
		{
			m_WorkerNum--;
			cout << "已经成功删除员工:" << Name << endl;
		}
		else if(Result == 2)
		{
			cout << "该员工权限高于您，无法删除" << endl;
		}
		else
		{
			cout << "未能查询到该员工" << endl;
		}
	}
	FileOut();
}

void Control::ReviseClass()
{
	if (m_WorkerNum == 0)
	{
		cout << "当前不存在任何员工" << endl;
		return;
	}
}
//66行
void Control::ReviseMission()
{
	WorkerClassPtr[TableID]->ReviseMission();
	FileOut();
}

void Control::PrintMission()
{
	WorkerClassPtr[TableID]->PrintMission();
}

void Control::AddAttachClass()
{
	system("cls");
	if (m_WorkerNum <= 1)
	{
		cout << "当前不存在可添加的员工，操作已取消" << endl;
		return;
	}
	PrintStuff();
	string Name;
	bool Result = 0;
	cout << "请输入需要添加至您所在部门的员工姓名" << endl;
	cin >> Name;
	for (int i = 0; i < m_WorkerNum; i++)
	{
		if (Name == WorkerClassPtr[i]->m_Name && WorkerClassPtr[i]->GetClassType() > Permission && WorkerClassPtr[i]->m_AttachToClassID == 0)
		{
			WorkerClassPtr[i]->m_DeptName = WorkerClassPtr[TableID]->m_DeptName;
			WorkerClassPtr[i]->m_AttachToClassID = WorkerClassPtr[TableID]->m_ID;
			WorkerClassPtr[TableID]->AddAttachClass(WorkerClassPtr[i]->m_ID);
			Result = 1;
			break;
		}
		else if (Name == WorkerClassPtr[i]->m_Name && WorkerClassPtr[i]->GetClassType() > Permission && WorkerClassPtr[i]->m_AttachToClassID != 0)
		{
			string Option;
			while (1)
			{
				cout << "该员工已经在一个组内，您仍然要这样做吗(是 或 否)" << endl;
				cin >> Option;
				if (Option == "是")
				{
					cout << "成功添加" << endl;
					WorkerClassPtr[i]->m_DeptName = WorkerClassPtr[TableID]->m_DeptName;
					WorkerClassPtr[IDSearch_TableID(WorkerClassPtr[i]->m_AttachToClassID)]->RemoveAttachClass(WorkerClassPtr[i]->m_ID);
					WorkerClassPtr[i]->m_AttachToClassID = WorkerClassPtr[TableID]->m_ID;
					WorkerClassPtr[TableID]->AddAttachClass(WorkerClassPtr[i]->m_ID);
					break;
				}
				else if (Option == "否")
				{
					cout << "取消添加" << endl;
					break;
				}
				else
				{
					cout << "输入错误，请重试" << endl;
					continue;
				}
			}
			Result = 1;
			break;
		}
		else if(Name == WorkerClassPtr[i]->m_Name && WorkerClassPtr[i]->GetClassType() <= Permission)
		{
			cout << "该员工权限组高于您或者与您相同，无法添加" << endl;
			Result = 1;
			break;
		}
	}
	if (Result == 0)
	{
		cout << "未查询到该员工" << endl;
	}

	FileOut();
}

int Control::IDSearch_TableID(int &ID)
{
	for (int i = 0; i < m_WorkerNum; i++)
	{
		if (WorkerClassPtr[i]->m_ID == ID)
		{
			return i;
		}
	}
	cout << "未查询到该ID，该函数将返回0" << endl;
	system("pause");
	return 0;
}

string Control::IDSearch_Name(int& ID)
{for (int i = 0; i < m_WorkerNum; i++)
	{
		if (WorkerClassPtr[i]->m_ID == ID)
		{
			return WorkerClassPtr[i]->m_Name;
		}
	}
	cout << "未查询到该ID，该函数将返回NULL" << endl;
	system("pause");
	return "NULL";
}
