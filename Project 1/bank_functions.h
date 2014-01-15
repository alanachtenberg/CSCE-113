//Project 1
// Alan Jason Chihyen
#include "bank.h"

class Bad_format{};
class Bad_input{};
class Not_int{};

int access_account(Bank& b); // return int to access customer in customers vector
void record_t(Customer& c,Transaction t);// record transaction

int generate(const Bank& b); // create account number
int four_generate(); // create random 4 digit pin

Transaction withdrawal(Customer& c);
Transaction deposit(Customer& c);

void open(Bank& b); // open new account
void close(Bank& b); // close account

Statistic display_stat(Bank& b);// display stats
vector<Transaction> display_history(Customer& c);// display customer history