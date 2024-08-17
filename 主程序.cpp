#define DATABASE_STROAGE_VOLUME 100

#include "ClassBase.h"



int main()
{
	//初始化系统
	Control ct;
	ct.InnitialSystem();

	//登录系统
	while (1)
	{
		ct.LogIn();

		//显示菜单与进行操作

		if (ct.Menu() == 0)
		{
			break;
		}
	}












	return 0;
}