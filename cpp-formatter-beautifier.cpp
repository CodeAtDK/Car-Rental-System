#include<iostream>

#include<fstream>
#include<vector>
#include <string>
#include<string.h>
#include <cstring>
#include<ctime>

using namespace std;

// login class is created for singup for user and admin all data is stored in Userlogin.txt for user and Adminlogin.txt for admin login

class login {

    public: int logintype;
    string USERID;
    string Password;
    int moible;

    // Function

    void loginold();
    void new_user();
    void Admin_login();
    int useridknown(string USERID);

    // constructer
    login() {
        cout << "login\nNew User\nAdmin" << endl;
        cin >> logintype;

        if (logintype == 1) {
            loginold();
        }
        if (logintype == 2) {
            new_user();
        }
        if (logintype == 3) {
            Admin_login();
        }

    }

};

// for already users

void login::loginold() {

    string id, password;
    cout << "Enter the User id" << endl;
    cin >> USERID;

    cout << "Enter the Password" << endl;
    cin >> Password;

    // opening file
    ifstream mylogin("Userlogin.txt");

    // get user id and password from file and matching it. on all odd lines ther is userid and on even lines Password.
    while (!mylogin.eof()) {

        getline(mylogin, id);
        getline(mylogin, password);
        //compare    
        if (USERID == id) {
            if (password == Password) {
                break;
            } else {
                cout << "enter Password is wrong" << endl;
                break;
            }
        }

    }
    if (id != USERID) {
        cout << "Enter USER ID is wrong" << endl;
        // if not match the recalling the constructer
        login();
    }
}

// new users

void login::new_user() {

    // opening file to put the data of users
    fstream mylogin("Userlogin.txt");

    cout << "welcome to car rentals" << endl;
    cout << "Enter the moblie Number" << endl;
    cin >> moible;

    cout << "Enter the User id" << endl;
    cin >> USERID;

    // cheaking if the user id is all ready present or not
    while (1) {
        int same = useridknown(USERID);

        if (same == 1) {

            cout << "Enter User id already present choose diffrent user id" << endl;
            cin >> USERID;

        } else {
            break;
        }

    }

    cout << "Enter the Password" << endl;
    cin >> Password;

    mylogin << USERID << endl;
    mylogin << Password << endl;
    // creating sperate file for the user
    fstream user(USERID.c_str());
    user << "break" << endl;
    user.close();

}

// for admin

void login::Admin_login() {

    string id, password;
    cout << "Enter the User id" << endl;
    cin >> USERID;

    cout << "Enter the Password" << endl;
    cin >> Password;
    // oping file
    ifstream mylogin("Adminlogin.txt");
    // cheaking if the user id and password is correct or not
    while (!mylogin.eof()) {

        getline(mylogin, id);
        getline(mylogin, password);

        if (USERID == id) {
            if (password == Password) {

                break;
            } else {
                cout << "enter Password is wrong" << endl;
                break;
            }
        }

    }
    // if wrong recalling the constructer
    if (id != USERID) {
        cout << "Enter USER ID is wrong" << endl;
        login();
    }
}
// function for cheaking that the useri id already present or not
int login::useridknown(string USERID) {

    string id;
    string password;
    // opening file
    fstream mylogin("Userlogin.txt");

    while (!mylogin.eof()) {

        getline(mylogin, id);
        getline(mylogin, password);

        if (USERID == id) {

            mylogin.close();
            return 1;

        }

    }

    mylogin.close();
    return 0;
}

// class for user
class user: public login {

    int option;

    public:
        user() {

            cout << "Rented cars" << endl;
            cout << "Rent car" << endl;
            cout << "Return car" << endl;
            cin >> option;

            if (option == 1) {
                fstream user(USERID.c_str());
                string a;

                if (user.eof() == 1) {
                    cout << "you have not renter any car yet" << endl;
                } else {
                    for (int i = 0; !user.eof(); i++) {

                        getline(user, a);
                        cout << a << endl;

                    }
                }
                user.close();

            } else if (option == 2) {

            } else if (option == 3) {

            } else {
                cout << "Enter option is not found" << endl;
                //user();
            }

        }

};

class car: public user {
    public:

        int cartype;
    void SUV();
    car() {
        cout << "SUV\nMini SUV\nHackBack\nSedan" << endl;
        cin >> cartype;
        if (cartype == 1) {

            SUV();

        }
        if (cartype == 2) {

        }
        if (cartype == 3) {

        }
        if (cartype == 4) {

        }
    }
};

void car::SUV() {
    fstream suv("SUV.doc");

    int line_number;
    vector < string > lines;
    string line;

    while (getline(suv, line)) {

        cout << line << endl;
        lines.push_back(line);
    }
    suv.close();

    cin >> line_number;
    //  line_number--;
    //line_number;

    if (line_number > lines.size()) {
        cout << "You Enter input is not valid" << endl;

        cout << "File has " << lines.size() / 7;
        cout << " lines." << endl;

    }

    ofstream suv1;
    suv1.open("SUV.doc");

    fstream car_rented(USERID.c_str());

    line_number--;
    cout << line_number;

    for (int i = 0; i < lines.size(); i++) {

        if (i < line_number || i > line_number + 8) {

            suv1 << lines[i] << endl;
        } else {

            car_rented << lines[i] << endl;
        }
    }

    suv1.close();

}

class rent: public car {
    public: int price;

    rent() {

        time_t now = time(0);
        tm * ltm = localtime( & now);
        char * dt = ctime( & now);
        dt = asctime(ltm);

        cout << dt << endl;

        int dayofrent;
        cout << "Enter the number of days you want to rent a car. \nIt should be less than 30 days" << endl;
        cin >> dayofrent;
        int return_time;

        int arrofmonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        if (31 == arrofmonth[ltm -> tm_mon]) {

            return_time = ltm -> tm_mday + dayofrent;

            if (return_time > 30) {

                ltm -> tm_mon += return_time / 30;

                ltm -> tm_mday += return_time - 31;

            }

        }
        if (30 == arrofmonth[ltm -> tm_mon]) {

            return_time = ltm -> tm_mday + dayofrent;

            if (return_time > 30) {

                ltm -> tm_mon += return_time / 30;
                ltm -> tm_mday += return_time - 30;
            }
        }
        if (28 == arrofmonth[ltm -> tm_mon]) {

            return_time = ltm -> tm_mday + dayofrent;

            if (return_time > 30) {

                ltm -> tm_mon += return_time / 30;
                ltm -> tm_mday += return_time - 28;
            }

        }
        cout << "car to be return by" << endl;
        cout << 1900 + ltm -> tm_year;
        cout << "/" << ltm -> tm_mon;
        cout << "/" << ltm -> tm_mday;
        cout << " " << ltm -> tm_hour << ":";
        cout << ltm -> tm_min << ":";
        cout << ltm -> tm_sec << endl;

        string rentedcars;

        rentedcars = USERID;
        //strcat(rentedcars,"rented");
        rentedcars.append("rented");

        ofstream rent(rentedcars.c_str());

        rent << dt;
        rent << 1900 + ltm -> tm_year;
        rent << "/" << ltm -> tm_mon;
        rent << "/" << ltm -> tm_mday << endl;

        cout << rentedcars << endl;
        fstream rented(USERID.c_str());

        for (int i = 0; i < 7; i++) {

            string a;
            getline(rented, a);
            rent << a << endl;
        }

        rented >> price;
        cout << price << endl;

    }

    friend class amount;
};

class amount: public rent {

    public: 
    int total_amount;

    void pay();

    amount() {
        
        total_amount = price + (500 + (price * 1 * 30) / 100) + (price * 18) / 100;
        cout << total_amount << endl;
        
        pay();
    }
};

void amount::pay() {

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

    cout << "Select the Payment method from following\n";
    cout << "1. Netbanking\n2. UPI\n3. Debit/Credit Card\n";

    cin >> pay_method;

    // switch case is use to select the payment method

    switch (pay_method) {

        // NET BANKING PAYMENT METHOD
    case 1:

        cout << "Select from Following Banks\n";
        cout << "1. State Bank Of India\n2. HDFC\n3. ICICI\n4. Cannar Bank\n5. Yes Bank\n6. Other\n";
        cin >> NameOfBank;

        // if Your bank name is not in list
        if (NameOfBank == 6) {

            cout << "Enter your Bank Name\n";
            cin >> BankName;

            cout << "Enter Your Login Id\n";
            cin >> NetBankingLoginId;

            cout << "Enter Your Passward\n";
            cin >> NetBankingPassword;

            cout << "Your OTP is 1234\n";

            // this while will cheak that opt is correct or in incorrect if incorrect it will tell to renter the OTP
            while (1) {

                cin >> BankOTP;
                if (BankOTP == 1234) {

                    cout << "Your Payment is in Process\n";
                    cout << "Your Payment is Succesful\n";
                    break;
                } 
                else {

                    cout << "you have Enter wrong OTP\n";
                    cout << "Renter the OTP\n";
                }
            }

            break;
        }

        // for bank in the list
        else {

            cout << "Enter Your Login Id\n";
            cin >> NetBankingLoginId;

            cout << "Enter Your Passward\n";
            cin >> NetBankingPassword;

            cout << "Your OTP is 1234\n";

            // this while will cheak that opt is correct or in incorrect if incorrect it will tell to renter the OTP
            while (1) {

                cin >> BankOTP;

                if (BankOTP == 1234) {

                    cout << "Your Payment is in Process\n";
                    cout << "Your Payment is Succesful\n";
                    break;
                } 
                else {

                    cout << "you have Enter wrong OTP\n";
                    cout << "Renter the OTP\n";
                }
            }
            break;
        }

        // UPI ID PAYMENT METHOD
    case 2:

        cout << "Enter your UPI Id\n";
        cin >> UPI_ID;

        cout << "Your Payment is in Process\n";
        cout << "Your Payment is Succesful\n";

        break;

        // CARD PAYMENT METHOD
    case 3:

        cout << "Enter your card number\n";
        cin >> Card_Number;

        while (Card_Number.length() != 16) {
            cout << "Enter card number is wrong renter it" << endl;
            cin >> Card_Number;

        }

        cout << "Enter your name\n";
        cin >> Card_Holder_Name;

        cout << "Enter your Card exp month\n";
        cin >> ExpMonth;
        while (ExpMonth > 12 || ExpMonth < 1) {
            cout << "Enter Exp Month is Wrong renter it" << endl;
            cin >> ExpMonth;
        }

        cout << "Enter your CVV Number\n";
        cin >> Card_CVV;

        while (Card_CVV.length() != 3) {
            cout << "Enter CVV is wrong renter it" << endl;
            cin >> Card_CVV;
        }

        cout << "Your OTP is 1234\n";

        // this while will cheak that opt is correct or in incorrect if incorrect it will tell to renter the OTP
        while (1) {

            cin >> BankOTP;
            if (BankOTP == 1234) {

                cout << "Your Payment is in Process\n";
                cout << "Your Payment is Succesful\n";
                break;
            } else {

                cout << "you have Enter wrong OTP\n";
                cout << "Renter the OTP\n";
            }

        }

    default:

        cout << "You have selected wrong option\n";
    }
}

int main() {

    amount a;

    return 0;
}