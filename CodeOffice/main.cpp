#include "ssh.h"

void main() {
	system("color 0A"); 
	string welcome = "CodeOffice v1.0.3 \nCopyright (c) 姚鹏. 2013.7\n用于SSH框架下数据库相关操作类的自动生成。\n \n", pwd;
	cout << welcome;
	SSHTablesConfig config;
	if (config.Parse("config.xml")) {
		SSHTables sshTables(config.GetPackagePath(), config.GetTables());
		sshTables.Make();
		cout << "finished" << endl;
	}
	system("pause");
}