#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<Windows.h>
void menu();
void password();
void changepassword();
using namespace std;
class Address
{
	char* city;
	char* country;
public:

	void set_city()
	{
		char* City;
		City = new char[100];
		cout << "\t\t\t\t\t\nEnter city =";
		cin >> City;
		int size = strlen(City);
		city = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			city[i] = City[i];
		}
		city[size] = '\0';
	}
	char* get_city()
	{
		return city;
	}
	void set_country()
	{
		char* Country;
		Country = new char[100];
		cout << "\t\t\t\t\t\nEnter country =";
		cin >> Country;
		int size = strlen(Country);
		country = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			country[i] = Country[i];
		}
		country[size] = '\0';
	}
	char* get_country()
	{
		return country;
	}
};
class Person
{
	char* name;
	char* address;
	int age;
	char Gender;
	long long int phone_no;
public:
	Address* adrs;
	virtual void set_information() = 0;
	virtual void display() = 0;
	void set_name()
	{
		char* Name;
		Name = new char[100];
		cin.ignore();
		cout << "\t\t\t\t\t\nEnter Name =";
		cin.getline(Name, 100);
		int size = strlen(Name);
		name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			name[i] = Name[i];
		}
		name[size] = '\0';
	}
	char* get_name()
	{
		return name;
	}
	void set_address()
	{
		char* cIty = new char[20];
		char* COuntry = new char[20];
		adrs = new Address();
		adrs->set_city();
		cIty = adrs->get_city();
		adrs->set_country();
		COuntry = adrs->get_country();
		int citysize = 0, countrysize = 0;
		citysize = strlen(cIty);
		countrysize = strlen(COuntry);
		int address_size = 0;
		address_size = citysize + countrysize;
		address = new char[address_size + 1];
		for (int i = 0; i < citysize; i++)
		{
			address[i] = cIty[i];
		}
		int count = 0;
		for (int i = citysize; i < address_size; i++)
		{
			address[i] = COuntry[count];
			count++;
		}
		address[address_size] = '\0';
	}
	char* get_address()
	{
		return address;
	}
	void set_age()
	{
		int Age = 0;
		cout << "\t\t\t\t\t\nEnter age =";
		cin >> Age;
		if (Age >= 0)
		{
			age = Age;
		}
		else
		{
			cout << "\t\t\t\t\t\n Invalid Input!";
			cout << "\t\t\t\t\t\nEnter age =";
			cin >> Age;
			age = Age;
		}
	}
	int get_age()
	{
		return age;
	}
	void set_Gender()
	{
		char gender;
		cout << "\t\t\t\t\t\nEnter Gender(m or f)=";
		cin >> gender;
		if (('m' == gender || gender == 'M') || ('f' == gender || gender == 'F'))
		{
			Gender = gender;
		}
		else
		{
			cout << "\t\t\t\t\t\n Invalid Input!";
			cout << "\t\t\t\t\t\nEnter Gender=";
			cin >> gender;
			Gender = gender;
		}
	}
	char get_Gender()
	{
		return Gender;
	}
	void set_phone_no()
	{
		long long int p;
		cout << "\t\t\t\t\t\nEnter Phone no: ";
		cin >> p;
		if (p >= 03000000000 && p <= 99999999999)
		{
			phone_no = p;
		}
		else
		{
			cout << "\t\t\t\t\tEnter Valid Phone no It must be 11 digit: ";
			cout << "\t\t\t\t\tEnter Phone no: ";
			cin >> p;
		}
	}
	long long int get_phone_no()
	{
		return phone_no;
	}
};
class Patient : public Person
{
	char* time;
	int appointmentno;
public:

	void set_time()
	{
		char* Time = new char[50];
		cout << "\t\t\t\t\t\nEnter the Apointment time =";
		cin >> Time;
		int size = strlen(Time);
		time = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			time[i] = Time[i];
		}
		time[size] = '\0';
	}
	char* get_time()
	{
		return time;
	}
	void set_appointmentno()
	{
		int an = 0;
		cout << "\t\t\t\t\t\nEnter the Apointment no =";
		cin >> an;
		if (an >= 0)
		{
			appointmentno = an;
		}
		else
		{
			cout << "\t\t\t\t\t\n Invalid Input!";
			cout << "\t\t\t\t\t\nEnter the Apointment no =";
			cin >> an;
			appointmentno = an;
		}
	}
	int get_appointmentno()
	{
		return appointmentno;
	}
	//temp
	void set_information()
	{
		system("cls");
		set_name();
		set_age();
		set_Gender();
		set_phone_no();
		set_address();
		set_appointmentno();
		set_time();

	}////temp
	void display()
	{
		cout << "\t\t\t\t\t\nName =" << get_name();
		cout << "\t\t\t\t\t\nAge =" << get_age();
		cout << "\t\t\t\t\t\nGender =" << get_Gender();
		cout << "\t\t\t\t\t\nPhone No# =" << get_phone_no();
		cout << "\t\t\t\t\t\nAddress =" << get_address() << endl;
		cout << "\t\t\t\t\t\nApointment no =" << get_appointmentno();
		cout << "\t\t\t\t\t\nTime =" << get_time();

	}

};
class Dr :public Patient
{
	char all[999];

public:

	void set_information(string Docname)
	{

		ofstream out(Docname += ".txt", ios::app);
		{
			system("cls");
			set_name();
			set_age();
			set_Gender();
			set_phone_no();
			set_address();
			set_appointmentno();
			set_time();

		}
		out << "\nName =" << get_name() << "\nAge =" << get_age() << "\nGender =" << get_Gender() << "\nPhone No# =" << get_phone_no() << "\nAddress =" << get_address();;
		out << "\nApointment no =" << get_appointmentno() << "\nTime =" << get_time() << endl << endl;
		out.close();
		cout << "Your Entry has been saved";
		menu();
	}
	void display(string Docname)
	{
		ifstream in(Docname += ".txt");
		if (!in)
		{
			cout << " \n\nNo Data In the File ";
			cout << " \n\n\t\tPress Any key To Continue : ";
			menu();
		}
		else {
			while (!in.eof())
			{
				in.getline(all, 999);
				cout << all << endl;
			}
			in.close();
			system("Pause");
			menu();
		}
	}

};//
class Receptionist :public Person
{

	double salary;
	char all[999];
	int positionno;
public:
	void set_salary()
	{
		float s;
		cout << "\t\t\t\t\t\nEnter the Staff salary =";
		cin >> s;
		if (s > 0)
		{
			salary = s;
		}
		else
		{
			cout << "\t\t\t\t\t\n Invalid Input!";
			cout << "\t\t\t\t\t\nEnter the Staff salary =";
			cin >> s;
			salary = s;
		}

	}
	double get_salary()
	{
		return salary;
	}

	void set_positonno()
	{
		int pn = 0;
		cout << "\t\t\t\t\tEnter the positon no =";
		cin >> pn;
		if (pn > 0)
		{
			positionno = pn;
		}
		else
		{
			cout << "\t\t\t\t\t\n Invalid Input!";
			cout << "\t\t\t\t\tEnter the positon no =";
			cin >> pn;
			positionno = pn;
		}
	}
	int get_positonno()
	{
		return positionno;
	}
	void set_information()
	{
		ofstream out("staff.txt", ios::app);
		{
			system("cls");
			set_name();
			set_age();
			set_Gender();
			set_phone_no();
			set_address();
			set_salary();
			set_positonno();

		}
		out << "\nName = " << get_name() << "\nAge = " << get_age() << "\nGender = " << get_Gender() << "\nPhone No# = " << get_phone_no() << "\nAddress = " << get_address();
		out << "\nSalary = " << get_salary() << "\nRank = " << get_positonno() << endl << endl;
		out.close();
		cout << "\n\nYour Information has been saved :\n\t\t\tPress any key to continue ";
		menu();

	}
	void display()
	{
		ifstream in("staff.txt");
		if (!in)
		{
			cout << "\t\t\t\t\tFile open Error!     File not found!!";
			menu();
		}
		else
		{
			while (!in.eof())
			{
				in.getline(all, 999);
				cout << all << endl;
			}
			in.close();
			cout << "\n\t\t\tPress any key to continue \n";
			system("Pause");
			menu();
		}
	}
};//
class Doctors :public Person
{

	double salary;
	char all[999];
	char* special;
	int positionno;

public:
	void set_special()
	{
		char* Name;
		Name = new char[100];
		cin.ignore();
		cout << "\t\t\t\t\t\nEnter Specialization =";
		cin.getline(Name, 50);
		int size = strlen(Name);
		special = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			special[i] = Name[i];
		}
		special[size] = '\0';
	}
	char* get_special()
	{
		return special;
	}
	void set_salary()
	{
		float s;
		cout << "\t\t\t\t\t\nEnter the Doctor's salary =";
		cin >> s;
		if (s > 0)
		{
			salary = s;
		}
		else
		{
			cout << "\t\t\t\t\t\n Invalid Input!";
			cout << "\t\t\t\t\t\nEnter the Doctor's salary =";
			cin >> s;
			salary = s;
		}

	}
	double get_salary()
	{
		return salary;
	}

	void set_positonno()
	{
		int pn = 0;
		cout << "\nEnter the Rank =";
		cin >> pn;
		if (pn > 0)
		{
			positionno = pn;
		}
		else
		{
			cout << "\t\t\t\t\t\n Invalid Input!";
			cout << "\t\t\t\t\tEnter the Rank no =";
			cin >> pn;
			positionno = pn;
		}
	}
	int get_positonno()
	{
		return positionno;
	}
	void set_information()
	{
		ofstream out("Doctors.txt", ios::app);
		{
			system("cls");
			set_name();
			set_age();
			set_Gender();
			set_special();
			set_salary();
			set_positonno();
			set_phone_no();
			set_address();
		}
		out << "\n-------------------------------------------------------------------------------------------------------------\n";
		out << "\t\tDr." << get_name() << " (" << special << ")\n\n";
		out << "\t\t\t [[Timing]]:\n\n";
		out << "\tMonday to Friday\t8AM TO 5PM\n";
		out << "\tSaturday \t\t10AM TO 1PM\n";
		out << "\tSunday      \t\t off\n";
		out << "\n-------------------------------------------------------------------------------------------------------------\n";
		out.close();
		ofstream out1("DRPERSONAL.txt", ios::app);

		out1 << "\nName = " << get_name() << "\nAge = " << get_age() << "\nGender = " << get_Gender() << "\nSalary = " << get_salary();
		out1 << "\nPosition = " << get_positonno() << "\nPhone No# = " << get_phone_no() << "\nAddress = " << get_address() << endl;
		out1.close();
		cout << "\n\nYour Information has been saved :\n\t\t\tPress any key to continue ";
		menu();

	}
	void display()
	{

		ifstream in("Doctors.txt");
		if (!in)
		{
			cout << "\t\t\t\t\tFile open Error!   File not found!!";
			menu();
		}
		else
		{
			while (!in.eof())
			{
				in.getline(all, 999);

				system("color f6");
				cout << all << endl;
			}
			in.close();
			cout << "\n\t\t\tPress any key to continue \n";
			system("Pause");
			menu();
		}
	}
};
class Apointment
{

public:
	int choices;

	void call_dr() {
		system("cls");
		cout << "\n\n\t\t Dr Arslan \n\n\t\t Dr Talha \n\n\t\t Dr Haris \n\n\t\t For Other\n";
		Dr Doc_obj;
		string s;
		cout << "\nEnter Dr Name You Want to take Appointment: ";
		cin >> s;
		Doc_obj.set_information(s);

	}
	void displayDoctorsPatientindfo() {
		system("cls");
		cout << "\n\n\t\t Dr Arslan \n\n\t\t Dr Talha \n\n\t\t Dr Haris \n\n\t\t For Other\n";
		Dr Doc_obj;
		string s;
		cout << "\nEnter Dr Name You Want to See Appointment : ";
		cin >> s;
		Doc_obj.display(s);

	}
};
class Vaccine : public Patient
{
	char* Cnic;
	int doze;
	char all[999];
public:

	void set_cnic()
	{
		char* cnic = new char[50];
		cout << "\t\t\t\t\t\nEnter Your Cnic =";
		cin >> cnic;
		int size = strlen(cnic);
		Cnic = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			Cnic[i] = cnic[i];
		}
		Cnic[size] = '\0';
	}
	char* get_cnic()
	{
		return Cnic;
	}

	void set_information(string Vacinetype)
	{

		ofstream out(Vacinetype += ".txt", ios::app);
		{
			system("cls");
			set_name();
			set_age();
			set_Gender();
			set_phone_no();
			set_cnic();
		}
		out << "\nName =" << get_name() << "\nAge =" << get_age() << "\nGender =" << get_Gender();
		out << "\nPhone No# =" << get_phone_no();
		out << "\nCNIC =" << get_cnic();
		out.close();
		cout << "Your Entry has been saved";
		menu();
	}
	void display(string Vacinetype)
	{
		ifstream in(Vacinetype += ".txt");
		if (!in)
		{
			cout << " \n\nNo Data In the File ";
			cout << " \n\n\t\tPress Any key To Continue : ";
			menu();
		}
		else {
			while (!in.eof())
			{
				in.getline(all, 999);
				cout << all << endl;
			}
			in.close();
			system("Pause");
			menu();
		}
	}
	void vaccinedisplay()
	{

		ifstream in("Vaccine.txt");
		if (!in)
		{
			cout << "\t\t\t\t\tFile open Error!    File not found!!!";
			menu();
		}
		else
		{
			while (!in.eof())
			{
				in.getline(all, 999);

				system("color f6");
				cout << all << endl;
			}
			in.close();
			cout << "\n\t\t\tPress any key to continue \n";
			system("Pause");
			menu();
		}
	}


};
void menu()
{

	system("cls");
	system("color FC");
	cout << "\n";
	cout << "\n";
	cout << "\t\t\t | +++++++++. MAIN MENU.      |\n";
	cout << "\t\t\t | Hospital Management System |\n";
	cout << "\t\t\t |============================|\n";
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "\t\tPlese Select Any Option\n";
	cout << "\n\t1-\t\tPrees 1 For Availabel Doctor Information:\n\n";
	cout << "\t2-\t\tPrees 2 for New Doctor  :\n\n";
	cout << "\t3-\t\tPress 3 for Doctor Appointment: \n\n";
	cout << "\t4-\t\tPrees 4 for Checking Patient Appointment Menu:\n\n";
	cout << "\t5-\t\tPrees 5 for Saving Staff information:\n\n";
	cout << "\t6-\t\tPrees 6 for Checking Staff Information Menu:\n\n";
	cout << "\t7-\t\tPrees 7 for Checking Availabel Vaccine Information:\n\n";
	cout << "\t8-\t\tPrees 8 for Register for Vaccine:\n\n";
	cout << "\t9-\t\tPrees 9 for Checking Vaccinated Patient Information Menu:\n\n";
	cout << "\t10-\t\tPrees 10 for Change Pasword or Create pasword :\n\n";
	cout << "\t11-\t\t\t[ Prees 11 for Logout ]\n";
	cout << "==================================================================================================\n";
	cout << "\n\n\t\tPlease Enter Your Choice : ";
	Person* ptr;
	Apointment appointment_obj;
	Receptionist receptionist_obj;
	Doctors doctorsdata_obj;
	Vaccine vaccine_obj;
	int a;
	cin >> a;
	if (a == 1)
	{
		ptr = &doctorsdata_obj;
		ptr->display();
	}
	else if (a == 2)
	{
		ptr = &doctorsdata_obj;
		ptr->set_information();

	}
	else if (a == 3)
	{
		appointment_obj.call_dr();

	}
	else if (a == 4)
	{
		appointment_obj.displayDoctorsPatientindfo();

	}
	else if (a == 5)
	{
		ptr = &receptionist_obj;
		ptr->set_information();

	}

	else if (a == 6)
	{
		ptr = &receptionist_obj;
		ptr->display();

	}
	else if (a == 7)
	{

		vaccine_obj.vaccinedisplay();

	}
	else if (a == 8)
	{

		string s;
		cout << "\nEnter  Vaccine Name which you want to Register : ";
		cin >> s;
		vaccine_obj.set_information(s);

	}
	else if (a == 9)
	{

		string s;
		cout << "\nEnter  Vaccine Name which you want to see Record : ";
		cin >> s;
		vaccine_obj.display(s);

	}
	else if (a == 10)
	{
		changepassword();

	}
	else if (a == 11)
	{
		password();
	}
	else
	{
		cout << "Invalid Choice !";
		cout << "\nPress Any Key For Continue:  ";
		system("Pause");
		menu();
	}
}
void password()
{
	system("cls");
	char p1[50], p2[50], p3[50];
	system("color Fc");
	ifstream in("password.txt");
	{

		cout << "\n\n\n\n\t\t\tEnter The  pasword ";
		cin >> p1;
		in.getline(p2, 50);
		if (strcmp(p2, p1) == 0)
		{
			menu();
		}
		else
		{
			cout << "\n\n\t\t\tIncorrect Password Please Try Again\n";
			Sleep(999);
			password();
		}
	}
	in.close();
}
void changepassword()
{
	char n[50];
	system("cls");
	ofstream out("password.txt");
	{
		cout << "\n\n\n\n\t\t\tEnter The New pasword ";
		cin >> n;
		out << n;
	}
	out.close();
	cout << "\n\nYour Pasword has been saved : ";
	menu();
}
int main()
{
	password();



	system("Pause");
	return 0;
}