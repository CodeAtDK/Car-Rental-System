#include<iostream>
#include<fstream>
#include<vector>
#include <string>
#include<string.h>
#include <cstring>
#include<ctime>
using namespace std;

void pay(){
    // payment method option
    int pay_method;

    // otp verfication
    int BankOTP;

    // NetBanking
    int NameOfBank;
    string BankName;
    string NetBankingLoginId;
    string NetBankingPassword;

    // UPI
    string UPI_ID;

    // Card Payment
    string Card_Number;
    string Card_Holder_Name;
    int ExpMonth;
    int ExpMonth_Verfiy;
    int ExpYear;
    int ExpYear_Verfiy;
    string Card_CVV;
    int Card_CVV_Verfiy;

    cout<<"Select the Payment method from following\n";
    cout<<"1. Netbanking\n2. UPI\n3. Debit/Credit Card\n";
    
    cin>>pay_method;

    // switch case is use to select the payment method

    switch (pay_method){
        
        // NET BANKING PAYMENT METHOD
        case 1:
    
              cout<<"Select from Following Banks\n";
              cout<<"1. State Bank Of India\n2. HDFC\n3. ICICI\n4. Cannar Bank\n5. Yes Bank\n6. Other\n";
            cin>>NameOfBank;
    
            // if Your bank name is not in list
            if (NameOfBank == 6){
    
                  cout<<"Enter your Bank Name\n";
                cin>>BankName;
    
                  cout<<"Enter Your Login Id\n";
                cin>>NetBankingLoginId;
    
                cout<<"Enter Your Passward\n";
                cin>>NetBankingPassword;
    
                  cout<<"Your OTP is 1234\n";
                
                // this while will cheak that opt is correct or in incorrect if incorrect it will tell to renter the OTP
                while (1){

                    cin>>BankOTP;
                    if (BankOTP == 1234){

                          cout<<"Your Payment is in Process\n";
                          cout<<"Your Payment is Succesful\n";
                        break;
                    }
                    
                    else{

                          cout<<"you have Enter wrong OTP\n";
                          cout<<"Renter the OTP\n";
                    }
                }

                break;
            }
    
            // for bank in the list
            else{
    
                  cout<<"Enter Your Login Id\n";
                cin>>NetBankingLoginId;
    
                  cout<<"Enter Your Passward\n";
                cin>>NetBankingPassword;
    
                  cout<<"Your OTP is 1234\n";
                
                // this while will cheak that opt is correct or in incorrect if incorrect it will tell to renter the OTP
                while (1){

                    cin>>BankOTP;
                    
                    if (BankOTP == 1234){

                          cout<<"Your Payment is in Process\n";
                          cout<<"Your Payment is Succesful\n";
                        break;
                    }

                    else{

                          cout<<"you have Enter wrong OTP\n";
                          cout<<"Renter the OTP\n";
                    }
                }
                break;
            }
        
        // UPI ID PAYMENT METHOD
        case 2:
            
              cout<<"Enter your UPI Id\n";
              cin>>UPI_ID;
    
              cout<<"Your Payment is in Process\n";
              cout<<"Your Payment is Succesful\n";
    
            break;
        
        // CARD PAYMENT METHOD
        case 3:
    
              cout<<"Enter your card number\n";
              cin>>Card_Number;

			  while(Card_Number.length() != 16){
				  cout<<"Enter card number is wrong renter it"<<endl;
              cin>>Card_Number;
				  
			  }
    
              cout<<"Enter your name\n";
            cin>>Card_Holder_Name;
    
              cout<<"Enter your Card exp month\n";
            cin>>ExpMonth;
			while(ExpMonth > 12 || ExpMonth < 1){
				cout<<"Enter Exp Month is Wrong renter it"<<endl;
				cin>>ExpMonth;
			}
    
              cout<<"Enter your CVV Number\n";
            cin>>Card_CVV;

			while(Card_CVV.length() != 3){
				cout<<"Enter CVV is wrong renter it"<<endl;
				cin>>Card_CVV;
			}

   
              cout<<"Your OTP is 1234\n";

            // this while will cheak that opt is correct or in incorrect if incorrect it will tell to renter the OTP
            while (1){

                cin>>BankOTP;
                if (BankOTP == 1234){

                      cout<<"Your Payment is in Process\n";
                      cout<<"Your Payment is Succesful\n";
                    break;
                }
    
                else{

                    cout<<"you have Enter wrong OTP\n";
                    cout<<"Renter the OTP\n";
                }
            
    
			}
    
            default:
    
              cout<<"You have selected wrong option\n";
            }
}

int main(){
pay();
	return 0;
}