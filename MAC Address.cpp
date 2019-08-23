#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>
#include <string>
#include <windows.h>

using namespace std;

class Table{
private:
	string m_Nama, m_Model, m_MAC[6];
public:
	Table(string nama = "", string model = ""){
		m_Nama = nama;
		m_Model = model;
	}
	friend istream& operator >> (istream &in, Table &org) { 
		string temp;
		cout << "Nama : ";
		getline(in, temp);
		getline(in,org.m_Nama, '\n');
		cout << "Model : ";
		getline(in,org.m_Model, '\n');
		cout << "Mac Address : ";
		for(int i=0;i<6;i++){
			cout << "MAC[" << i << "] --> ";
			getline(in,org.m_MAC[i], '\n');
		}
	}
	friend fstream& operator >> (fstream &in, Table &org) { 
		getline(in, org.m_Nama, '\t'); 
		getline(in, org.m_Model, '\t'); 
		for(int i=0;i<6;i++){
			getline(in,org.m_MAC[i],':');
		}
		
	}
	friend ostream& operator << (ostream &out, Table &org) { 
		out << "Nama \t: " << org.m_Nama << endl;
		out << "Model \t: " << org.m_Model << endl;
		out << "Mac \t: ";
		for(int i=0;i<6;i++){
			out << org.m_MAC[i];
			if(i < 5){
				out << ":";
			}
		}
		return out;
	}
	friend fstream& operator << (fstream &out, Table &org) {
		out << org.m_Nama << '\t';
		out << org.m_Model << '\t';
		for(int i=0;i<6;i++){
			out << org.m_MAC[i];
			if(i < 5){
				out << ":";
			}
		}
		return out;
	}
};

int main(){
	
	int menu = 0;
	Table MAC_Table;
	string inputMAC[6];
	fstream data;
	
	do{
		system("cls");
		cout << "  >> CREATE MAC ADDRESS PLAIN-TEXT <<  " << endl
			 << "1. Write File" << endl
			 << "2. Read File" << endl
			 << "0. Exit File" << endl << endl;
		cout << "Pilihan : ";cin >> menu;
		
		if(menu == 1){
			data.open("DATA_MAC.txt", ios_base::app);
			cin >> MAC_Table;
			data << MAC_Table;
			data.close();
		}
		else if(menu == 2){
			system("cls");
			data.open("DATA_MAC.txt", ios_base::in);
			while(true){
				data >> MAC_Table;
				cout << MAC_Table;
				if(data.eof()){
					cout << endl << "END OF FILE" << endl;
					system("pause");
					break;
				}
			}
			data.close();
		}
		else{
			cout << "Error Input Menu" << endl;
			system("pause");
		}
			 
	}while(menu != 0);{
		cout << "GOOD LUCK :) :] :}" << endl;
		system("pause");
	}
	
	return 0;
}
