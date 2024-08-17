#include "ClassBase.h"

//Worker
//4��
int worker::GetClassType()
{
	return 0;
}

void worker::ReviseMission()
{
	system("cls");
	PrintMission();
	cout << "����������ʲô����" << endl;
	cout << "1.��� 2.�޸� 3.ɾ��" << endl;
	int Option = 0;
	int MissionTable = 0;
	cin >> Option;
	if (Option == 1)
	{
		string Mission;
		cout << "��������Ҫ��ӵ���������(��Ҫ�пո񣬿ո������ݽ��ᱻĨ��)" << endl;
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
		cout << "�ɹ���Ӳ�������ļ���" << endl;
		return;
	}
	else if (Option == 2)
	{
		if (m_MissionNum == 0)
		{
			cout << "��ǰ��û���κ�����" << endl;
			return;
		}
		string Mission;
		bool Result = 0;
		cout << "��������Ҫ�޸ĵ��������" << endl;
		cin >> MissionTable;
		cout << "�������޸ĺ������(��Ҫ�пո񣬿ո������ݽ��ᱻĨ��)" << endl;
		cin >> m_MissionPtr[MissionTable - 1];
		cin.ignore(128, '\n');
		cout << "�ɹ��޸Ĳ�������ļ���" << endl;
		return;
	}
	else if (Option == 3)
	{
		if (m_MissionNum == 0)
		{
			cout << "��ǰ��û���κ�����" << endl;
			return;
		}
		bool Result = 0;
		cout << "��������Ҫɾ�����������" << endl;
		cin >> MissionTable;
		while (cin.good() != 1)
		{
			cin >> MissionTable;
			cout << "����Ĳ������벻���Ϲ淶������������:";
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
			cout << "�ɹ�ɾ����������ļ���" << endl;
			return;
		}
		else if (m_MissionNum != 1 && MissionTable > m_MissionNum)
		{
			cout << "��Ų�����Ҫ��������" << endl;
		}
		else
		{
			m_MissionNum = 0;
			delete[] m_MissionPtr;
			m_MissionPtr = NULL;
			cout << "�ɹ�ɾ����������ļ���" << endl;
			return;
		}
	}
}

void worker::PrintMission()
{
	cout << "��ǰ����������" << m_MissionNum << "��" << endl;
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
//9��
boss::boss(int ID, int Password, string Name, int MissionNum,string* MissionPtr, int AttachClassNum, int* AttachClassPtr)
{
	this->m_ID = ID;
	this->m_Name = Name;
	this->m_Password = Password;
	this->m_DeptName = "���»�";
	this->m_MissionPtr = MissionPtr;
	this->m_MissionNum = MissionNum;
	this->m_AttachClassNum = AttachClassNum;
	this->m_AttachClassIDPtr = AttachClassPtr;
}
//4��
int boss::GetClassType()
{
	return 1;
}

//Manager
//9��
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
//4��
int manager::GetClassType()
{
	return 2;
}

//Employee
//8��
employee::employee(int ID,int Password, string Name, string DeptName, int MissionNum,string* MissionPtr)
{
	this->m_ID = ID;
	this->m_Name = Name;
	this->m_DeptName = DeptName;
	this->m_Password = Password;
	this->m_MissionPtr = MissionPtr;
	this->m_MissionNum = MissionNum;
}
//6��
//4��
int employee::GetClassType()
{
	return 3;
}

//Control
//94��
void Control::InnitialSystem()
{
	ifstream ifs;
	cout << "��ӭʹ�ñ�ְ������ϵͳ" << endl;
	cout << "���ڴ��ļ�����������" << endl;
	ifs.open("Database.txt", ios::in);

	if (ifs.is_open() == true)
	{
		cout << "�ɹ����ļ�������������Ϣ" << endl;
		if (ifs.good() == 0)
		{
			cout << "�ļ��𻵣����´�����ʼ���˺�" << endl;
			ifs.close();
			InnitialClass();
			FileOut();
		}
		else
		{
			ifs >> m_WorkerNum;
			if (m_WorkerNum == 0)
			{
				cout << "�ļ��𻵣����´�����ʼ���˺�" << endl;
				ifs.close();
				InnitialClass();
				FileOut();
			}
			else
			{
				cout << "��ʼ��������" << endl;
				ifs.close();
				FileIn();
			}
		}

	}
	else
	{
		cout << "δ�ҵ�����ļ���������ʼ���˺�" << endl;
		InnitialClass();
		FileOut();
	}
	cout << "��ʼ�����" << endl;
}

void Control::InnitialClass()
{
	ofstream ofs;
	ofs.open("Database.txt", ios::trunc);
	ofs.close();
	WorkerClassPtr = new worker * [1];
	worker* InnitialBoss = new boss(ID_DistributeSytem(), 666666, "admin", 0, NULL,0,NULL);
	WorkerClassPtr[0] = InnitialBoss;
	cout << "��ʼ����Ա�˺Ŵ������" << endl;
	cout << "����:admin ����:666666" << endl;
	m_WorkerNum = 1;
}
//52��
void Control::LogIn()
{
	Sleep(1000);
	system("cls");
	string Name;
	int Password;
	bool LogIn = 0;

	while (1)
	{
		cout << "�����������Լ������Ե�¼��ϵͳ" << endl;
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
				cout << "�����������˺ų��ִ�������ϵ��ع���Ա" << endl;
				break;
			}
		}
		if (LogIn == 1)
		{
			cout << "�ɹ���" << Name << "�˺ŵ�¼" << endl;
			switch (Permission)
			{
			case 1:
				cout << "Ȩ����:����" << endl;
				break;
			case 2:
				cout << "Ȩ����:����" << endl;
				break;
			case 3:
				cout << "Ȩ����:ְԱ" << endl;
				break;
			}
			break;
		}
		else
		{
			cout << "�û��������������������" << endl;
		}
	}
}
//82��
void Control::GroupAddClass()
{
	system("cls");
	//��������ӵ�Ա������
	int AddNum = 0;
	cout << "�����������Ա��" << endl;
	cout << "��������Ҫ��ӵ�����" << endl;
	while (1)
	{
		cin >> AddNum;
		if (AddNum <= 0)
		{
			cout << "��������������Ҫ������������" << endl;
		}
		else
		{
			break;
		}
	}
	//����ָ��
	worker** NewSpace = new worker * [AddNum + m_WorkerNum];
	for (int i = 0; i < m_WorkerNum; i++)
	{
		NewSpace[i] = WorkerClassPtr[i];
	}

	//��������ӵ�Ա����Ϣ
	string name;
	int StuffType = 0;
	for (int i = 0; i < AddNum; i++)
	{
		cout << "�������" << i + 1 << "��Ա������" << endl;
		cin >> name;
		cout << "������Ա��ְ�����" << endl;
		cout << "1.���� 2.���� 3.ְԱ" << endl;
		while (1)
		{
			cin >> StuffType;
			while (cin.good() != 1)
			{
				cout << "�����ְ����벻���Ϲ淶������������" << endl;
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			if (StuffType != 1 && StuffType != 2 && StuffType != 3)
			{
				cout << "�����ְ�񲻷��Ϲ淶������������";
			}
			else if (StuffType < Permission)
			{
				cout << "������ӵ�Ա��Ȩ�޸�����������������ְ��" << endl;
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
			NewSpace[m_WorkerNum + i] = new manager(ID_DistributeSytem(), 666666, name,"δ����",0,NULL, 0, NULL);
			break;
		case 3:
			NewSpace[m_WorkerNum + i] = new employee(ID_DistributeSytem(), 666666, name, "δ����",0,NULL);
			break;
		}
	}
	m_WorkerNum = m_WorkerNum + AddNum;

	delete[] WorkerClassPtr;
	WorkerClassPtr = NewSpace;
	NewSpace = NULL;
	cout << "���������Ӳ���(��¼����Ϊ666666)" << endl;
	cout << "�������˵�" << endl;
	FileOut();
}
//80��
void Control::SoloAddClass()
{
	system("cls");
	cout << "���ڵ������Ա��" << endl;
	string Name;
	int Password;
	int StuffType;
	string DeptName;
	cout << "������Ա����������¼�����Լ�ְ��(1.���³� 2.���� 3.ְԱ) �м��ÿո�����" << endl;
	cout << "ע�⣬���Ϊ���ܻ���ְԱ������ְ����������ڲ���" << endl;
	cin >> Name;
	cin >> Password;
	while (cin.good() != 1)
	{
		cout << "��������벻���Ϲ淶������������:";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}

	while (1)
	{
		cin >> StuffType;
		while (cin.good() != 1)
		{
			cout << "�����ְ����벻���Ϲ淶������������" << endl;
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		if (StuffType != 1 && StuffType != 2 && StuffType != 3)
		{
			cout << "�����ְ�񲻷��Ϲ淶������������" << endl;
			while (cin.get() != '\n')
				continue;
		}
		else if(StuffType < Permission)
		{
			cout << "�������õ�Ա��Ȩ�޸�����������������ְ��" << endl;
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
	//ָ������
	worker** NewSpace = new worker * [m_WorkerNum + 1];
	//ת������
	for (int i = 0; i < m_WorkerNum; i++)
	{
		NewSpace[i] = WorkerClassPtr[i];
	}
	//�������
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
	//ת��ָ��
	delete[] WorkerClassPtr;
	WorkerClassPtr = NewSpace;

	NewSpace = NULL;
	m_WorkerNum++;
	cout << "��ɵ�����Ӳ���" << endl;

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
//24��
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
	cout << "����ļ�����" << endl;
	ofs.close();
}
//40��
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
//45��
int Control::Menu()
{
	int Option = 0;
	while (1)
	{
		Sleep(600);
		system("cls");
		cout << "����ϵͳ���˵�" << endl;
		switch (Permission)
		{
		case 0:
			cout << "��⵽���Դ���ķ�ʽ��¼��ϵͳ������ע��ϵͳ" << endl;
			break;
		case 1:
			cout << "1.ȫ��ְ����Ϣ" << endl;
			cout << "2.�������ְ��" << endl;
			cout << "3.�������ְ��" << endl;
			cout << "4.ɾ��ְ��" << endl;
			cout << "5.���������ְ����Ϣ" << endl;
			cout << "6.�������������Ա��" << endl;
			cout << "7.�޸�ְ����Ϣ" << endl;
			cout << "8.�޸�������Ϣ" << endl;
			cout << "9.�޸���������" << endl;
			cout << "10.���ص�¼�˵�" << endl;
			cout << "11.�˳�ϵͳ" << endl;
			cin >> Option;
			while (cin.good() != 1)
			{
				cin >> Option;
				cout << "����Ĳ������벻���Ϲ淶������������:";
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
			cout << "1.ȫ��ְ����Ϣ" << endl;
			cout << "2.�������ְ��" << endl;
			cout << "3.�������ְ��" << endl;
			cout << "4.ɾ��ְ��" << endl;
			cout << "5.���������ְ����Ϣ" << endl;
			cout << "6.�������������Ա��" << endl;
			cout << "7.�޸�ְ����Ϣ" << endl;
			cout << "8.�޸�������Ϣ" << endl;
			cout << "9.�޸���������" << endl;
			cout << "10.���ص�¼�˵�" << endl;
			cout << "11.�˳�ϵͳ" << endl;
			cin >> Option;
			while (cin.good() != 1)
			{
				cin >> Option;
				cout << "����Ĳ������벻���Ϲ淶������������:";
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
			cout << "1.ȫ��ְ����Ϣ" << endl;
			cout << "2.�޸������˺���Ϣ" << endl;
			cout << "3.ɾ�������˺�" << endl;
			cout << "4.�޸���������" << endl;
			cout << "5.���ص�¼�˵�" << endl;
			cout << "6.�˳�ϵͳ" << endl;
			cin >> Option;
			while (cin.good() != 1)
			{
				cin >> Option;
				cout << "����Ĳ������벻���Ϲ淶������������" << endl;
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
//49��
void Control::PrintStuff()
{
	system("cls");
	bool Existence = 0;
	cout << "����Ȩ����" << endl;
	cout << "���" << " " << "����" << " " << "ID" << " " << "��������" << endl;
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
		cout << "��" << endl;
	}
	Existence = 0;
	cout << "����Ȩ����" << endl;
	cout << "���" << " " << "����" << " " << "ID" << " " << "��������" << endl;
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
		cout << "��" << endl;
	}
	Existence = 0;
	cout << "ְԱȨ����" << endl;
	cout << "���" << " " << "����" << " " << "ID" << " " << "��������" << endl;
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
		cout << "��" << endl;
	}
	system("pause");
}

void Control::PrintAttachClass()
{
	int ID;
	system("cls");
	cout << "��ǰ��һ������" << WorkerClassPtr[TableID]->m_AttachClassNum << "��Ա��" << endl;
	for (int i = 0; i < WorkerClassPtr[TableID]->m_AttachClassNum; i++)
	{
		ID = WorkerClassPtr[TableID]->m_AttachClassIDPtr[i];
		cout << i + 1<< " " << IDSearch_Name(ID) << endl;
	}
	system("pause");
}
//72��
void Control::DeleteClass()
{
	system("cls");
	PrintStuff();
	if (m_WorkerNum == 0)
	{
		cout << "��ǰ�������κ�Ա��" << endl;
		return;
	}
	string Name;
	int Result = 0;
	cout << "��ʼɾ��Ա��" << endl;
	while (1)
	{
		cout << "��������Ҫɾ����Ա������(�����˳��Է��ز˵�)" << endl;

		cin >> Name;
		if (Name == "�˳�")
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
			cout << "�Ѿ��ɹ�ɾ��Ա��:" << Name << endl;
		}
		else if(Result == 2)
		{
			cout << "��Ա��Ȩ�޸��������޷�ɾ��" << endl;
		}
		else
		{
			cout << "δ�ܲ�ѯ����Ա��" << endl;
		}
	}
	FileOut();
}

void Control::ReviseClass()
{
	if (m_WorkerNum == 0)
	{
		cout << "��ǰ�������κ�Ա��" << endl;
		return;
	}
}
//66��
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
		cout << "��ǰ�����ڿ���ӵ�Ա����������ȡ��" << endl;
		return;
	}
	PrintStuff();
	string Name;
	bool Result = 0;
	cout << "��������Ҫ����������ڲ��ŵ�Ա������" << endl;
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
				cout << "��Ա���Ѿ���һ�����ڣ�����ȻҪ��������(�� �� ��)" << endl;
				cin >> Option;
				if (Option == "��")
				{
					cout << "�ɹ����" << endl;
					WorkerClassPtr[i]->m_DeptName = WorkerClassPtr[TableID]->m_DeptName;
					WorkerClassPtr[IDSearch_TableID(WorkerClassPtr[i]->m_AttachToClassID)]->RemoveAttachClass(WorkerClassPtr[i]->m_ID);
					WorkerClassPtr[i]->m_AttachToClassID = WorkerClassPtr[TableID]->m_ID;
					WorkerClassPtr[TableID]->AddAttachClass(WorkerClassPtr[i]->m_ID);
					break;
				}
				else if (Option == "��")
				{
					cout << "ȡ�����" << endl;
					break;
				}
				else
				{
					cout << "�������������" << endl;
					continue;
				}
			}
			Result = 1;
			break;
		}
		else if(Name == WorkerClassPtr[i]->m_Name && WorkerClassPtr[i]->GetClassType() <= Permission)
		{
			cout << "��Ա��Ȩ�������������������ͬ���޷����" << endl;
			Result = 1;
			break;
		}
	}
	if (Result == 0)
	{
		cout << "δ��ѯ����Ա��" << endl;
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
	cout << "δ��ѯ����ID���ú���������0" << endl;
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
	cout << "δ��ѯ����ID���ú���������NULL" << endl;
	system("pause");
	return "NULL";
}
