#include "ssh.h"

void main() {
	system("color 0A"); 
	string welcome = "CodeOffice v1.0.3 \nCopyright (c) Ҧ��. 2013.7\n����SSH��������ݿ���ز�������Զ����ɡ�\n \n", pwd;
	cout << welcome;
	SSHTablesConfig config;
	if (config.Parse("config.xml")) {
		SSHTables sshTables(config.GetPackagePath(), config.GetTables());
		sshTables.Make();
		cout << "finished" << endl;
	}
	system("pause");
}