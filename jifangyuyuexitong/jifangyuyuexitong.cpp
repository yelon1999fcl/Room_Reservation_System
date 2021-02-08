#include <iostream>
#include <fstream>
#include <string>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

//����ѧ���Ӳ˵�ҳ��
void studentMenu(Identity*& student) {
	while (true) {

		//����ѧ���Ӳ˵�
		student->openMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;	//�����û�ѡ��

		if (select == 1) {	//����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2) {	//�鿴����ԤԼ
			stu->showMyOrder();
		}
		else if (select == 3) {	//�鿴����ԤԼ
			stu->showAllOrder();
		}
		else if (select == 4) {	//ȡ��ԤԼ
			stu->cancelOrder();
		}
		else {
			//ע����½
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ�Ӳ˵�ҳ��
void teacherMenu(Identity*& teacher) {
	while (true) {

		//������ʦ�Ӳ˵�
		teacher->openMenu();

		Teacher* Tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;	//�����û�ѡ��

		if (select == 1) {	//�鿴����ԤԼ
			Tea->showAllOrder();
		}
		else if (select == 2) {	//���ԤԼ
			Tea->validOrder();
		}
		else {
			//ע����½
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�ҳ��
void managerMenu(Identity* &manager) {
	while (true) {
		//���ù���Ա�Ӳ˵�
		manager->openMenu();

		//������ָ��תΪ����ָ�룬���������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1) {	//�����˺�
			//cout << "�����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) {	//�鿴�˺�
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {	//�鿴����
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) {	//���ԤԼ
			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			//ע��
			delete manager;	//���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��½���� ����1 �����ļ��� ����2������������
void LoginIn(string fileName, int type) {
	//����ָ�� ����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ	
	int id = 0;
	string name;
	string pwd;

	//�ж�����
	if (type == 1) {	//ѧ������
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1) {
		//ѧ��������֤
		int fId;	//���ļ��л�ȡ��id��
		string fName;	//���ļ��л�ȡ������
		string fPwd;	//���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//���û�����Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ����֤��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//���뵽ѧ�����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//��ʦ������֤
		int fId;	//���ļ��л�ȡ��id��
		string fName;	//���ļ��л�ȡ������
		string fPwd;	//���ļ��л�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//���û�����Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��֤��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//���뵽��ʦ���ݵ��Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա������֤
		string fName;	//���ļ��л�ȡ������
		string fPwd;	//���ļ��л�ȡ������
		while (ifs >> fName && ifs >> fPwd) {
			//���û�����Ϣ���Ա�
			if (fName == name && fPwd == pwd) {
				cout << "����Ա��֤��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//���뵽����Ա���ݵ��Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��½ʧ�ܣ�" << endl;
	system("pause");
	system("cls");

	return;
}

int main() {
	int select = 0;

	while (true) {
		cout << "==================��ӭ��������ԤԼϵͳ====================" << endl;
		cout << endl << "��������������" << endl;
		cout << "\t\t----------------------------\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|        1.ѧ������        |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|        2.��    ʦ        |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|        3.�� �� Ա        |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t|        0.��    ��        |\n";
		cout << "\t\t|                          |\n";
		cout << "\t\t----------------------------\n";

		cout << "��������ѡ��";
		cin >> select;	//�����û�ѡ��

		switch (select) {
		case 1:	//ѧ������
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:	//��ʦ����
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:	//����Ա����
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: {	//�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break; 
		}
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
