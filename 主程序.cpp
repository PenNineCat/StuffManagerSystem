#define DATABASE_STROAGE_VOLUME 100

#include "ClassBase.h"



int main()
{
	//��ʼ��ϵͳ
	Control ct;
	ct.InnitialSystem();

	//��¼ϵͳ
	while (1)
	{
		ct.LogIn();

		//��ʾ�˵�����в���

		if (ct.Menu() == 0)
		{
			break;
		}
	}












	return 0;
}