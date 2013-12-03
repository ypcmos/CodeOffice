//======================================================================
//
//        Copyright (C) 2013.7 Yao Peng   
//        All rights reserved
//
//        filename : ssh.h
//        description : automatically generates code for database tables using SSH framework
//
//        mail : yaopengdn@126.com
//        http://weibo.com/u/2151926144
//
//======================================================================

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "xml.h"
#include <time.h>

struct Column {
	string type;
	string name;
};

struct Table {
	string name;
	string objectName;
	string schema;
	vector<Column> columns;
};

class SSHTables {
	class Template {
	public:
		Template();
		string GetCode() const;
		SSHTables::Template* Update(string o, string s);

	protected:
		void Set(string o, string s);
	protected:
		string code;
	};

	class DomainTemplate: public Template {
	public:
		DomainTemplate(int size);
	};

	class DAOTemplate: public Template {
	public:
		DAOTemplate(int size);
	};

	class DAOImplTemplate: public Template {
	public:
		DAOImplTemplate(int size);
	};

	class ServiceTemplate: public Template {
	public:
		ServiceTemplate(int size);
	};

	class ServiceImplTemplate: public Template {
	public:
		ServiceImplTemplate(int size);
	};

public:
	SSHTables(string packagePath, const vector<Table>& tables);
	void Make();
private:
	void CreateDomain(string path, const Table& table) const;
	void CreateDAO(string path, const Table& table) const;
	void CreateService(string path, const Table& table) const;
	void CreateDAOImpl(string path, const Table& table) const;
	void CreateServiceImpl(string path, const Table& table) const;
	void Write(ofstream& fp, string text) const;
	string GetPackage() const;
private:
	const vector<Table> tables;
	const string packagePath;
	const string package;
};

class SSHTablesConfig {
public:
	bool Parse(string xmlFile);
	const vector<Table>& GetTables() const;
	string GetPackagePath() const;
private:
	vector<Table> tables;
	string packagePath;
};