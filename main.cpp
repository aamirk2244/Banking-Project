#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <windows.h>
#include "Bank.h"

int main()
{
	
	bool flag = true;
	print_Welcome_Msg();
		 HANDLE hout= GetStdHandle(STD_OUTPUT_HANDLE);
        HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
        INPUT_RECORD InputRecord;
        DWORD Events;
        COORD coord;
        CONSOLE_CURSOR_INFO cci;
        cci.dwSize = 25;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(hout, &cci);
        SetConsoleMode(hin,  ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
        bool EXITGAME = false;
        int buttonX=1, buttonY=1;

char mouse;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()
		

	
	    int len = 0,x, y=245; // 240 = white background, black foreground 
		std::string text;
		text = "Do You want to Allow Mouse ? Y/N: (I think You should not allow it to enjoy better performance) ";
			
			len = text.length();
	    	std::cout << std::endl << std::endl << "\t\t"; // start 3 down, 2 tabs, right
		    for ( x=0;x<len;x++)
			{
			       SetConsoleTextAttribute(console, y); // set color for the next print
			        std::cout << text[x];
			 //       
			   	Sleep(20);
			}
				
		    SetConsoleTextAttribute(console, 15); // set color to black background, white chars
		  
//std::cout << "Do You want to Allow Mouse ? Y/N:  " ;
std::cin >> mouse;
 if(mouse == 'n' || mouse == 'N')
 {				// below code will work  without mouse. 
	//I did this because when mouse is active we cannot  use system(Color 3f) which I  love the most
 	system("cls");
	 while(flag)
	{	
		 
			system("Color 3f");
	//	system("Color 0b");
				New_Account a;
			int choice;
			///////////////////////////
			HANDLE console1 = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()
		
		
		
			int len1 = 0,x1, y1=240; // 240 = white background, black foreground
			
			std::cout << "\n\n"; 
			std::string text1 = "------------------------Welcome To The Account Section -----------------------------";
			len1 = text1.length();
		    	std::cout << std::endl << std::endl << "\t\t"; // start 3 down, 2 tabs, right
			  
			  
			    for ( x1=0;x1<len1;x1++)
				{
				       SetConsoleTextAttribute(console1, y1); // set color for the next print
				        std::cout << text1[x1];
				 //       y++; // add 1 to y, for a new color
				        
						if ( y1 >254) // There are 255 colors. 255 being white on white. Nothing to see. Bypass it
			            y1=240; // if y > 254, start colors back at white background, black chars
				  //      Sleep(250); // Pause between letters
				   	Sleep(20);
				}
					
			    SetConsoleTextAttribute(console1, 15); // set color to black background, white chars
			    
			
			gotoxy(12, 10);
			std::cout << "	################## MAIN MENUE ###############\n";
			
			
			
			HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()
		

	
	    int len = 0,x, y=245; // 240 = white background, black foreground 
		std::string text;
		for(int i= 0; i < 8; i++){
			if(i == 0)
				text = "01: New Account         ";
			else if(i ==1)
				text =  "02: Deposite Amount     ";
			else if(i ==2)
				text =  "03:  Withdraw Amount    ";
			else if(i ==3)
				text =  "04:  Balance Enquiry    ";
			else if(i ==4)
				text =  "05:  Delete Account     ";
			else if(i ==5)
				text =  "06: Modify Account      "; 
			else if(i ==6)
				text =  "07: Exit                ";
			else if(i ==7)
				text =  "Select Options (1-7)    ";
			      
		
			
			len = text.length();
	    	std::cout << std::endl << std::endl << "\t\t"; // start 3 down, 2 tabs, right
		    for ( x=0;x<len;x++)
			{
			       SetConsoleTextAttribute(console, y); // set color for the next print
			        std::cout << text[x];
			 //       y++; // add 1 to y, for a new color
			        
					if ( y >254) // There are 255 colors. 255 being white on white. Nothing to see. Bypass it
		            y=240; // if y > 254, start colors back at white background, black chars
			  //      Sleep(250); // Pause between letters
			   	Sleep(20);
			}
				
		    SetConsoleTextAttribute(console, 15); // set color to black background, white chars
		    
		}
	
		while(!	(std::cin >> choice))
		{
			std::cout << "Enter valid choice ";
			std::cin >> choice;
			std::cin.clear();
			std::cin.ignore('9', '\n');
			
		}
		bool is_true = true;
		while(is_true)
		{
			if(choice < 1 || choice > 7)
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
		 ///////////////////
 		if(choice == 1)
		{
			a.Make_Account();
			std::cin.get();
			system("cls");
		}
		else if(choice == 2)
		{
			a.Deposite_Amount();
			std::cin.get();
			system("cls");
			
		}
		else if(choice == 3)
		{
			a.WithDraw_amount();
			std::cin.get();
			system("cls");
			
		}
		else if(choice == 4)
		{
			
			a.Account_Status();
			std::cin.get();
			system("cls");
			
		}
		else if(choice == 5)
		{
			a.Delete_Account();
			std::cin.get();
			system("cls");
			
		}
		else if(choice == 6)
		{
			a.Modify_Account();
			std::cin.get();
			system("cls");
		}
		else if(choice == 7)
		{
			flag = false;
			system("cls");
		}
	
	}


	char path[260];
	 
	GetModuleFileName(NULL,path,260);
	 
	HWND console = FindWindow("ConsoleWindowClass",path);
	 
	if(IsWindow(console))
	ShowWindow(console,SW_HIDE); // hides the window
 }
 	

/////////////////	
 
 else if(mouse == 'Y' || mouse == 'y')
 {
 	New_Account a;
		int choice;
		///////////////////////////
		HANDLE console1 = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()
		
		
		
		int len1 = 0,x1, y1=240; // 240 = white background, black foreground
			
		std::cout << "\n\n"; 
		std::string text1 = "------------------------Welcome To The Account Section -----------------------------";
		len1 = text1.length();		    	std::cout << std::endl << std::endl << "\t\t"; // start 3 down, 2 tabs, right
			  
			  
		for ( x1=0;x1<len1;x1++)
		{
	       SetConsoleTextAttribute(console1, y1); // set color for the next print	
		    std::cout << text1[x1];
		 //       y++; // add 1 to y, for a new color
				        
			
				  //      Sleep(250); // Pause between letters
				   	Sleep(20);
		}
					
			    SetConsoleTextAttribute(console1, 15); // set color to black background, white chars
			    
			//	std::cout << "\n\n------------------------Welcome To The Account Section -----------------------------\n" << std::endl;
			//	std::cout << "\tCreated by Muhammad Aamir Khan And Moain Khan.  #FAST-NU Peshawar# \n\n" << std::endl;
			//	std::cout << "                                                            \n" << std::endl;
				
			
			gotoxy(12, 10);
			std::cout << "	################## MAIN MENUE ###############\n";
			
			
			
			HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()
		

	
		    int len = 0,x, y=245; // 240 = white background, black foreground 
			std::string text;
		for(int i= 0; i < 8; i++){
			if(i == 0)
				text = " New Account         ";
			else if(i ==1)
				text =  " Deposite Amount     ";
			else if(i ==2)
				text =  "  Withdraw Amount    ";
			else if(i ==3)
				text =  "  Balance Enquiry    ";
			else if(i ==4)
				text =  "  Delete Account     ";
			else if(i ==5)
				text =  " Modify Account      "; 
			else if(i ==6)
				text =  " Exit                ";
			else if(i ==7)
				text =  "Click   on    Options ";
				      
			
				
			len = text.length();
	    	std::cout << std::endl << std::endl << "\t\t"; // start 3 down, 2 tabs, right
		    for ( x=0;x<len;x++)
			{
			       SetConsoleTextAttribute(console, y); // set color for the next print
			        std::cout << text[x];
			 //       y++; // add 1 to y, for a new color
			        
					if ( y >254) // There are 255 colors. 255 being white on white. Nothing to see. Bypass it
		            y=240; // if y > 254, start colors back at white background, black chars
			  //      Sleep(250); // Pause between letters
			   	Sleep(20);
			}
				
		    SetConsoleTextAttribute(console, 15); // set color to black background, white chars
		    
		}
		while(!EXITGAME)
		{
				ReadConsoleInput(hin, &InputRecord, 1, &Events);
	
	
	        switch ( InputRecord.EventType ){
	                case MOUSE_EVENT: // mouse input 

                    if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
                        coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
                        coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                        SetConsoleCursorPosition(hout,coord);
                        SetConsoleTextAttribute(hout,rand() %7+9);

                     
                        
						if(InputRecord.Event.MouseEvent.dwMousePosition.Y == 13){
							a.Make_Account();
							std::cin.get();
							system("cls");
							break;
						}
						
						else if(InputRecord.Event.MouseEvent.dwMousePosition.Y == 15){
							a.Deposite_Amount();
							EXITGAME = TRUE;
							//std::cin.get();
						//	system("cls");
							break;
						}
						
						else if(InputRecord.Event.MouseEvent.dwMousePosition.Y == 17){
							a.WithDraw_amount();
							EXITGAME = TRUE;
							//std::cin.get();
						//	system("cls");
							break;
						}
						
						else if(InputRecord.Event.MouseEvent.dwMousePosition.Y == 19){
							a.Account_Status();
							std::cin.get();
							
							EXITGAME = TRUE;
							//std::cin.get();
						//	system("cls");
							break;
						}
						
						else if(InputRecord.Event.MouseEvent.dwMousePosition.Y == 21){
							a.Delete_Account();
							EXITGAME = TRUE;
							//std::cin.get();
						//	system("cls");
							break;
						}
						else if(InputRecord.Event.MouseEvent.dwMousePosition.Y == 23){
							a.Modify_Account();
							EXITGAME = TRUE;
							//std::cin.get();
						//	system("cls");
							break;
						}
						else if(InputRecord.Event.MouseEvent.dwMousePosition.Y == 25){
							
							EXITGAME = TRUE;
							flag = false;
							//std::cin.get();
						//	system("cls");
							break;
						}
                    
					}// mouse 

        }



        FlushConsoleInputBuffer(hin);

	 }
	

   }
 
	
  } 

