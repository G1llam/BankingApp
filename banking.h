#include <iostream>
#include <string>

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
            std::cout << "how much would you like to withdraw? ";
            std::cin >> _withdraw;
            *_bal -= _withdraw;
            std::cout << _withdraw << " has been withdrawn" << std::endl;

            Balance();
        }

        void Deposit(){
            std::cout << "how much would you like to deposit? ";
            std::cin >> _deposit;
            *_bal += _deposit;
            std::cout << _deposit << " has been deposited" << std::endl;

            Balance();
        }

        void Transfer(){  
            std::cout << "Who would you like to transfer money to? ";
            std::cin >> TransferClient;
            std::cout << "How much would you like to transfer to " << TransferClient << "? ";
            std::cin >> TransferAmount;

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
        }

        void Balance(){
            std::cout << "Balance: " << *_bal << std::endl;
        }
};
