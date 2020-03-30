#include <iostream>
#include "Bank.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <windows.h>
#include<stdio.h> 
#include<graphics.h> 
#include<dos.h> 
  
// function for printing 
// message as colored character 

void print_Welcome_Msg() 
{ 

    // auto detection 
    int gdriver = DETECT,gmode,i; 
  
//     initialize graphics mode 
    char msg[] = "C:\\Turboc3\\Aamir";
	initgraph(&gdriver,&gmode,msg); 
    
  // setcolor(GREEN);
	
    initwindow(2000, 2000, "BANK");

	 setfillstyle(SOLID_FILL,2);
    bar(20,600,55,20);
    setfillstyle(SOLID_FILL,3);
    bar(10,20,1200,1);
    setfillstyle(SOLID_FILL,2);
    bar(20,20,1200,50);
    setfillstyle(SOLID_FILL,3);
    bar(1,600,20,1);
    setfillstyle(SOLID_FILL,3);
    bar(1225,600,1200,1);
    setfillstyle(SOLID_FILL,2);
    bar(1200,600,1170,20);
    setfillstyle(SOLID_FILL,3);
    bar(1,620,1225,590);
    setfillstyle(SOLID_FILL,2);
    bar(20,600,1200,575);
	
	for (i=0; i<7; i++) 
    { 
        // setcolor of cursor 
        setcolor(i); 
          
        // set text style as 
        // settextstyle(font, orientation, size) 
        settextstyle(5,0,50); 
          
        // print text at coordinate x,y; 
    char  msg1[] = "Welcome To Bank";
		outtextxy(300,150,msg1); 
          
        delay(1000); 
    }
	 setbkcolor(128);

    char msg3[] = "Made By Aamir and Moain  ";
    outtextxy(140, 210, msg3);
    //    
    
    char msg4[] = "Press any key for Main Menu.";
    outtextxy(140, 280, msg4);

getch(); 
closegraph();
return;

} 
  
// driver program 

void gotoxy(int x_axis, int y_axis)
{	
	COORD axis;
	axis.X = x_axis;
	axis.Y = y_axis;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),axis);

}
void New_Account::No_Object()
{
	// I don't want to create any object of Parent (Account) Class
}

Account::Account()
{
	is_true = true;
	is_false = false;
	full_Name = "";
	NIC = "";
	file_name = "";
	amount = 0;
}
void Account::check_name()
{
	system("Color 3f");
	int ist = 0;
	bool is_true = true;
	int count = -1;	// dummy value
	while(count != 0){
		count = 0;
		if(ist == 0){
			std::cout << "Enter your Full Name  :  " ; // this code will execute for ist time . 
				//	std::cin >> full_Name;
				std::cin.get();
			getline(std::cin, full_Name);
		}
		else{
			std::cout << "Invalid name. Please enter valid name :  ";
		//	std::cin >> full_Name;
			std::cin.get();
			getline(std::cin, full_Name);
		}
		if(full_Name.length() <= 2){
			std::cout << "Name is too short " << std::endl; // name should be greater than 2 alphabets.
			count = -1;
		}
		else
		{
			for(int i = 0; i < full_Name.length(); i++){
				    // the below logic is for user input other than alphabets.
				    // 65(A)  to  90(Z) capital alphabets                                      large alphabets   97(a) to (122)z
				if((full_Name[i] >= 0 && full_Name[i] <= 31) || (full_Name[i] >= 33 && full_Name[i] <= 64 ) || (full_Name[i] >= 91 && full_Name[i] <= 96) ||  (full_Name[i] > 122))
				{
					count++;
					ist++;
				}
			}
		
		}
	}
			
			
			
}
int Account::amount_to_int()
{
	system("Color 3f");
	int temp;
	int count_amount_len = 0;
	int amount_int = 0;
	std::string line = "";
	std::ifstream fin;
	fin.open(file_name.c_str());
	if (fin)
	{
		for (int i = 0; i < 5; i++)
		{
			getline(fin, line);
		}
		fin.close();

	}
	else
	{
		std::cout << "Cannot update account " << std::endl;
	}
	unsigned int i = 0;
	for (i; i < line.length(); i++)
	{
		if (line[i] >= 48 && line[i] <= 57)
		{
			temp = int(line[i]) - 48;
			count_amount_len++;
			amount_int = (amount_int * 10) +  temp;
		}
			
	}
	return amount_int;
}

bool New_Account::check_NIC(std::string input)
{
	system("Color 3f");
	int count = 0;
	// NIC length must be 13
	if (input.length() != 13)
		return false;
	else if (true)
	{
		unsigned int i = 0;
		for (i; i < input.length(); i++)
		{
			if (input[i] >= 48 && input[i] <= 57)	// check every char for integer. 
				count++;
			else
			{
				return false;
			}
		}
		if (count == input.length())
			return true;
	}

}

void Account::set_account_number()
{
	system("Color 3f");
	is_true = true;

	while (is_true)
	{

		int count_account_no = 0;
		std::cout << "Enter your account number  : " ;
		std::cin >> account_no;
			unsigned int i = 0;
			for (i ; i < account_no.length(); i++)
			{
				if (int(account_no[i]) >= 48 && int(account_no[i]) <= 57)
				{
					count_account_no++;
				}

			}
			if (count_account_no != account_no.length())
			{
				std::cout << "Invalid account number. Please enter valid account number " << std::endl;
			}
			else
			{
				is_true = false;
			}

	}

	std::string extension = ".txt";
	file_name = account_no;
	file_name += extension;
}
void New_Account::Make_Account()
{
	system("cls");
	system("Color 3f");
	
	/*
	std::cout << "    __             __   ___  ___   __            _____ " << std::endl;
   std::cout <<"|\  |__ \  /\  /   |__| |    |     |  | |  | |\ |   |" << std::endl;
	std::cout<< | \||__  \/  \/    |  | |___ |___  |__| |__| | \|  |   " << std::endl;
	*/
	std::ofstream fout;
	std::ifstream fin;

	set_account_number();
	
		std::cout << "Enter your NIC number without dashes : ";
		std::cin >> NIC;
		is_true = check_NIC(NIC);

		while (!(is_true))
		{
			std::cout << "You entered invalid NIC number. Please enter valid NIC : ";
			std::cin >> NIC;

			is_true = check_NIC(NIC);
		}
	  check_name();
		
		fout.open(file_name.c_str());
		fout << "Account Number :          " << account_no << "\n";
		fout << "Account Holder Name : \"  " << full_Name << "\" " << "\n";
								 						

		fout << "National Identity Card :  "<< NIC << "\n";

		std::cout << "Enter type of your account 'Current, or Saving'	c/s : ";
		std::cin >> type_of_account;
		is_true = true;
		if (type_of_account == 'c' || type_of_account == 's')
		{
			is_true = false;

		}
		else
		{
			is_true = true;
			while (is_true)
			{
				std::cout << "Choose valid account type  " ;
				std::cin >> type_of_account;
				if (type_of_account == 'c' || type_of_account == 's')
					is_true = false;

			}
			
		}

		if (type_of_account == 's')
		{
			std::cout << "Please enter your amount. You can enter minimum amount of 1000 : ";
			std::cin >> amount;
			if (amount >= 1000)
			{
				fout << "Type of  account  " << type_of_account << "\n";

				fout << "Total amount is " << amount << "\n";
				std::cout << "Thank you your amount has been saved \n";
				std::cin.get();
				system("pause");
			}
			else if (amount < 1000)
			{
				is_true = false;
				while (!(is_true))
				{
					std::cout << "You have entered low amount. Please enter valid amount or enter 1 to Main Menue  if you don't have enough amount ': ";
					std::cin >> amount;
					if (amount == 1)
					{
						fout.close();
						remove(file_name.c_str());
						//exit(EXIT_FAILURE);
						std::cin.get();
						return;
					}

					else if (amount >= 1000)
					{
						fout << "Type of  account  " << type_of_account << "\n";

						fout << "Total amount is " << amount  << "\n";
						std::cout << "Thank you your amount has been saved \n";
						std::cin.get();
						system("pause");
						is_true = true;
					}
					else {

						is_true = false;
					}
				}
			}
		}
		else if (type_of_account == 'c') {
			is_true = true;
			std::cout << "Please enter your amount. You can enter minimum amount of 500 : ";
			std::cin >> amount;
			if (amount >= 500)
			{
				fout << "Type of  account  " << type_of_account << "\n";

				fout << "Total amount is " << amount;
				std::cout << "Thank you your amount has been saved " << std::endl;
				std::cin.get();
				system("pause");
			}
			else if (amount < 500)
			{

				is_true = true;
				while (is_true)
				{
					std::cout << "You have entered low amount. Please enter valid amount or enter 1 to terminate : " ;
					std::cin >> amount;
					if (amount == 1)
					{
						fout.close();
						remove(file_name.c_str());
					//	exit(EXIT_FAILURE);
					
					return;
					}
					else if (amount < 500)
					{
						is_true = true;
					}
					else if (amount >= 500)
					{
						fout << "Type of  account  " << type_of_account << "\n";
						fout << "Total amount is " << amount << "\n";
						std::cout << "Thank you your amount has been saved " << std::endl;
						
						system("pause");
						is_true = false;
					}
				}
			}
			else
			{
				fout.close();
			//	exit(EXIT_FAILURE);
			std::cin.get();
			return;
			}
		}
		fout.close();

}

void New_Account::Deposite_Amount()
{
	system("cls");
	system("Color 3f");
	std::string update_file[4];		// for storing record into string and rewriting to a file to update amount
	int amount_len = 0;
	std::cout << "_____________________Account Status _____________________________" << std::endl;
	std::string line;
	std::ifstream fin;
	std::ofstream fout;
	set_account_number();
		fin.open(file_name.c_str());
		if (!(fin))
		{
			std::cout << "There is no such type of Account. Please make one ist " << std::endl;
			std::cin.get();
			system("pause");
			//exit(EXIT_FAILURE);
			
			return;
		}
			
		else
		{
			system("cls");
			int inc = 0;
			while (fin)
			{
				inc++;
				getline(fin, line);
				std::cout << line << std::endl;
				if (inc == 5)
					break;
			}
			fin.close();
			std::cout << "Enter the amount to Add. You can Deposite minimum Amount of 500 " ;
			std::cin >> amount;
			is_true = true;
		while(is_true)
		{
			if(amount < 500 )
				{
					std::cout << "Invalid amount. Please enter valid amount : ";
					std::cin >> amount;
				}
			else{
				is_true = false;
			}
		}
			amount = amount + amount_to_int();
			int i = 0;
			fin.open(file_name.c_str());
			while (fin)
			{
				getline(fin, line);
				update_file[i] = line;
				i++;
				if (i == 4)
					break;
			}
			fin.close();
			fout.open(file_name.c_str());
			if (fout.is_open())
			{
				i = 0;
				while (true)
				{
					fout << update_file[i] << "\n";
					i++;
					if (i == 4)
						break;
				}
				fout << "Total Amount : " << amount << "\n";
				std::cout << "Update Successfull. Your Amount has been added " << std::endl;
				std::cin.get();
				system("pause");
			}
			else
			{

				std::cout << "Can't update Sorry " << std::endl;
			}


			std::cin.get();
			fin.close();
		}

}

void New_Account::WithDraw_amount()
{
	system("cls");
	system("Color 3f");
	
	std::string line;
	std::ifstream fin;
	std::ofstream fout;
	std::cout << "________________________________________Welcome to the withdraw field___________________________________ " << std::endl;
	set_account_number();
	fin.open(file_name.c_str());
	if (!fin)
	{
		std::cout << "Sorry you have not make any account. Please make one " << std::endl;
		std::cin.get();
		system("pause");
	//	exit(EXIT_FAILURE);
	std::cin.get();
		return;
	}
	std::cout << " _____________Your Account Information______________" << std::endl;
	int brk = 0;
	while (fin)
	{
		brk++;
		getline(fin, line);
		std::cout << line << std::endl;
		if(brk == 5){
			break;
		}
	}
	std::cout << " ____________________________________________________" << std::endl;
	std::cout << "\n\n ";
	std::cout << "You can Withdraw Minimum amount of 500 " << std::endl;

	std::cout << "Please enter ammount to withdraw -> ";

	std::cin >> amount;
	fin.close();
	int present_amount = amount_to_int();
	
	
	is_true = true;
	while(is_true)
	{
		if(amount < 500 || amount > present_amount)
		{
			std::cout << "Invalid amount. Please enter valid amount : ";
			std::cin >> amount;
		}
		else{
			is_true = false;
		}
	}
	int show_amount = amount;
	std::cout << std::endl;
	amount = present_amount - amount;
	std::ofstream temp_out;
	std::string temp_file_name = "temp.txt"; 
	fin.open(file_name.c_str());
	temp_out.open(temp_file_name.c_str());
	int inc = 0;
	while(fin)
	{
		inc++;
		std::getline(fin, line);
		temp_out << line << "\n";
		if(inc == 4)
		{
			break;
		}
	}
	fin.close();
	temp_out << "Total Amount : " << amount << "\n";
	remove(file_name.c_str());
	temp_out.close();
	std::rename(temp_file_name.c_str(), file_name.c_str());
	std::cout << "Update Successfull. Your Amount has been Withdraw Please Take your  " <<  show_amount <<  "  Rupees " <<  std::endl;
	std::cin.get();
	system("pause");
		
}
int New_Account::Account_Status()
{
	system("cls");
	system("Color 3f");
	set_account_number();
	std::ifstream fin;
	fin.open(file_name.c_str());
	if(!fin)
	{
		std::cout << "Sorry you have not make any account. Please make one " << std::endl;
		std::cin.get();
	//	exit(EXIT_FAILURE);
	std::cin.get();
	system("cls");
		return 0;
	}
	std::cout << " _____________Your Account Status___________________" << std::endl;
	
	std::string line;
	while(fin)
	{
		getline(fin, line);
		std::cout << line << "\n";
	}
	std::cout << " ____________________________________________________" << std::endl;
	std::cin.get();
	fin.close();
	return 1;

}
void New_Account::Delete_Account()
{
	system("cls");
	system("Color 3f");
	
	set_account_number();
	std::ifstream fin;
	fin.open(file_name.c_str());
	if(!fin)
	{
		std::cout << "You don't have any account. Please make one ist " << std::endl;
		
		//exit(EXIT_FAILURE);
		return;
	}
	char ch;
	std::cout << "Are you Sure you want to remove your Account. All your Record will be Lost ? Y/N : ";
	std::cin >> ch;
	if(ch == 'y' || ch == 'Y')
	{
		fin.close();
		remove(file_name.c_str());
		std::cout << "Your Account has been removed Successfully " << std::endl;
		return;
	}
	fin.close();
	std::cout << "Your Account is secure " << std::endl;
	
//	exit(EXIT_FAILURE);
	return;
	
}
void New_Account::Modify_Account()
{
	system("cls");
	system("Color 3f");
//	set_account_number();
//	std::ofstream fout;
//	fout.open(file_name.c_str());
int ret = Account_Status();
	if(ret == 0)
	{
		return;
	}
		
	std::ofstream fout,  tmpout;
	std::ifstream fin;
	std::cout << "\n/%~~~~~~~ Modify Account ~~~~~~~~%/\n";
	std::cout << "01: Change Account Number     -> " << std::endl;
	std::cout << "02: Change Name -> " << std::endl;
	std::cout << "03: Change NIC  -> " << std::endl;
	std::cout << "04: Change Account Type 'c,s'   " << std::endl;
	std::cout << "05: Main Menu			   " << std::endl;
	std::cout << "\nSelect Options (1-5) " << std::endl;
	int choice;
	while(!	(std::cin >> choice))
	{
		std::cout << "Enter valid choice ";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore('9', '\n');
		
	}
	is_true = true;
	while(is_true)
	{
		if(choice < 1 || choice > 5)
		{
			std::cout << "Please select the right choice ";
			while(!	(std::cin >> choice))
			{
				std::cout << "Enter valid choice ";
				std::cin >> choice;
				std::cin.clear();
				std::cin.ignore('9', '\n');
				
			}
		}
		else
			is_true = false;
	}
	
	std::string line;
	int k = 0;
	
	if(choice == 1)
	{
		
		fin.open(file_name.c_str());
		std::string file = file_name;
	//	fout.open(fil.c_str());
		set_account_number();
		fout.open(file_name.c_str());
	 	fout << "Account Number 	" << account_no << "\n";
		while(fin)
		{
			if (k == 0)
			{
				getline(fin,line);	// we don't need ist line
				k = 1;
			}
			else
			{
				getline(fin, line);
				fout << line << "\n";
			}		
		}
		fin.close();
		fout.close();
		remove(file.c_str());
		std::cout << "Account Number is Sucessfully updated " << std::endl;
		system("cls");
		return;
	
	}
	if(choice == 2)
	{
		
		check_name();
		fin.open(file_name.c_str());
		fout.open("tmp.txt");

		 while(fin)
		{
			if (k == 1)
			{
				getline(fin, line);
				fout << "Account Holder Name : 		" << full_Name << "\n";	// we don't need 2nd line
				k = 2;	// dummy value
			}
			else
			{
				getline(fin, line);
				fout << line << "\n";
				k++;
				if(k == 5){	// upto 5 lines in file;
					break;		// it is printing last line 2 times therefore for the stopping purpose breaked the loop.
				}
			}		
		}
		
		fin.close();
		fout.close();
		remove(file_name.c_str());
	
		rename("tmp.txt", file_name.c_str());
		std::cout << "Account Name is Sucessfully updated " << std::endl;
		system("cls");
		return;
	}
	if(choice == 3)
	{
		system("cls");
		std::cout << "Enter your new NIC number ";
		std::cin >> NIC;
		while(!(check_NIC(NIC)))
		{
			std::cout << "Enter Valid NIC number ";
			std::cin >> NIC;	
		}
			
		fin.open(file_name.c_str());
		fout.open("tmp.txt");

		 while(fin)
		{
			if (k == 2)
			{
				getline(fin, line);
				fout << "National Identity Card : 		" << NIC << "\n";	// we don't need 3rd line
				k = 3;	// dummy value
			}
			else
			{
				getline(fin, line);
				fout << line << "\n";
				k++;
				if(k == 5){	// upto 5 lines in file;
					break;		// it is printing last line 2 times therefore for the stopping purpose breaked the loop.
				}
			}		
		}
		
		fin.close();
		fout.close();
		remove(file_name.c_str());
	
		rename("tmp.txt", file_name.c_str());
		std::cout << "National Identity Card is Sucessfully updated " << std::endl;
		system("pause");
		system("cls");
		return;
			
	}
	if(choice == 4)
	{
		system("cls");
		std::cout << "Enter type of your account 'Current, or Saving'	c/s : ";
		std::cin >> type_of_account;
		is_true = true;
		if (type_of_account == 'c' || type_of_account == 's')
		{
			is_true = false;

		}
		else
		{
			is_true = true;
			while (is_true)
			{
				std::cout << "Choose valid account type " << std::endl;
				std::cin >> type_of_account;
				if (type_of_account == 'c' || type_of_account == 's')
					is_true = false;

			}
			
		}	
		fin.open(file_name.c_str());
		fout.open("tmp.txt");

		 while(fin)
		{
			if (k == 3)
			{
				getline(fin, line);
				fout << "Type of Account : 		" << type_of_account << "\n";	// we don't need 4th line
				k = 4;	// dummy value
			}
			else
			{
				getline(fin, line);
				fout << line << "\n";
				k++;
				if(k == 5){	// upto 5 lines in file;
					break;		// it is printing last line 2 times therefore for the stopping purpose breaked the loop.
				}
			}		
		}
		
		fin.close();
		fout.close();
		remove(file_name.c_str());
	
		rename("tmp.txt", file_name.c_str());
		std::cout << "Type of Account is Sucessfully updated " << std::endl;
		system("pause");
		system("cls");
		return;
			
	}
	if(choice == 4){
		system("cls");
		return;
	}
		

}
//////// 13 y 
