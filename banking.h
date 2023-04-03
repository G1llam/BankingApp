#include <iostream>

int _withdraw {};
int _deposit {};
int bal {1534};
int *_bal {&bal};

class banking{
    public:
        void Withdraw(){
            std::cout << "how much would you like to withdraw? ";
            std::cin >> _withdraw;
            *_bal -= _withdraw;
            std::cout << _withdraw << " has been withdrawn" << std::endl;
        }

        void Deposit(){
            std::cout << "how much would you like to deposit? ";
            std::cin >> _deposit;
            *_bal += _deposit;
            std::cout << _deposit << " has been deposited" << std::endl;
        }

        void Balance(){
            std::cout << "Balance: " << *_bal << std::endl;
        }
};