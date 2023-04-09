#include <iostream>
#include <string>
#include <cstdlib>

int _withdraw {};
int _deposit {};
int bal {1534};
int *_bal {&bal};
std::string TransferClient;
int TransferAmount {};

enum TransferList{
    Dave, Lisa, Alfie
};

class banking{
    private:
        TransferList ChosenClient;

    public:
        //banking() : ChosenClient(Dave) {}  // using a constructor to set the default value to dave, not really needed for this

        void Withdraw(){
            while(true){
                std::cout << "how much would you like to withdraw? ";
                std::cin >> _withdraw;
                if(_withdraw > *_bal){
                    std::cout << "You're trying to withdraw a value grater than your balance! \n";
                    std::cout << "Your balance is: " << *_bal << "\n";
                }else {
                    *_bal -= _withdraw;
                    std::cout << _withdraw << " has been withdrawn" << std::endl;

                    Balance();
                    return;
                }
            }
        }

        void Deposit(){
            std::cout << "how much would you like to deposit? ";
            while (true) {
                std::cin >> _deposit;
                if (_deposit >= 0) {
                    *_bal += _deposit;
                    std::cout << _deposit << " has been deposited" << std::endl;
                    Balance();
                    break;
                }
                else {
                    std::cout << "You entered an invalid amount, Please enter a positive number: ";
                }
            }
        }

        void Transfer(){  
            std::cout << "Who would you like to transfer money to? ";
            std::cin >> TransferClient;
            std::cout << "How much would you like to transfer to " << TransferClient << "? ";

            while(true){
                std::cin >> TransferAmount;

                if (TransferAmount > *_bal) {
                    std::cout << "Insufficient balance. ";
                    std::cout << "You have " << *_bal << " available." << std::endl;
                    std::cout << "Please enter a valid amount: ";
                } else {
                    if (TransferClient == "Dave" || TransferClient == "dave") {
                        ChosenClient = Dave;
                    } else if (TransferClient == "Lisa" || TransferClient == "lisa") {
                        ChosenClient = Lisa;
                    } else if (TransferClient == "Alfie" || TransferClient == "alfie") {
                        ChosenClient = Alfie;
                    } else {
                        std::cout << "No such client exists, Please try again!";
                        return;
                    }

                    switch(ChosenClient){
                        case Dave: std::cout << "Sending "<< TransferAmount << " to Dave.. \n"; break;
                        case Lisa: std::cout << "Sending "<< TransferAmount << " to Lisa.. \n"; break;
                        case Alfie: std::cout << "Sending "<< TransferAmount << " to Alfie.. \n"; break;
                    }

                    *_bal -= TransferAmount;
                    Balance(); 
                    return;
                }       
            }
        }

        void Balance(){
            std::cout << "Balance: " << *_bal << std::endl;
        }
};
