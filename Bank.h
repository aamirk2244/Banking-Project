

void print_Welcome_Msg();
void gotoxy(int x_axis, int y_axis);

class Account {
protected:
	virtual void No_Object() = 0;	// using concept of Ploymorphism to create Abstract class 
	std::string full_Name;
	std::string NIC;
	std::string file_name;
	long long amount;
	std::string account_no;
	char type_of_account;
	bool is_true;
	bool is_false;
	// file_name;

public:
	Account();
	int amount_to_int();
	void set_account_number();
	void check_name();
	
};
class New_Account : public Account {

public:
	void No_Object();
	void Deposite_Amount();
	bool check_NIC(std::string input);
	void Make_Account();
	void WithDraw_amount();
	int Account_Status();
	void Delete_Account();
	void Modify_Account();

};
