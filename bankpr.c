#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bank account
typedef struct {
    int accountNumber;
    char accountHolder[50];
    double balance;
} BankAccount;

// Function to create a new bank account
BankAccount* createAccount(int accountNumber, const char* accountHolder, double initialBalance) {
    BankAccount* account = (BankAccount*)malloc(sizeof(BankAccount));
    if (account == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    account->accountNumber = accountNumber;
    snprintf(account->accountHolder, sizeof(account->accountHolder), "%s", accountHolder);
    account->balance = initialBalance;

    return account;
}

// Function to credit funds to an account
void credit(BankAccount* account, double amount) {
    account->balance += amount;
    printf("Credited %.2lf to account %d. New balance: %.2lf\n", amount, account->accountNumber, account->balance);
}

// Function to debit funds from an account
void debit(BankAccount* account, double amount) {
    if (amount > account->balance) {
        printf("Insufficient funds for account %d\n", account->accountNumber);
    } else {
        account->balance -= amount;
        printf("Debited %.2lf from account %d. New balance: %.2lf\n", amount, account->accountNumber, account->balance);
    }
}

// Function to probe balance
void probeBalance(const BankAccount* account) {
    printf("Account %d - Holder: %s, Balance: %.2lf\n", account->accountNumber, account->accountHolder, account->balance);
}

// Function to close an account and free memory
void closeAccount(BankAccount* account) {
    free(account);
    printf("Account %d closed\n", account->accountNumber);
}

int main() {
    // Example usage
    BankAccount* account1 = createAccount(1001, "Shaniyah Hall ", 1000.0);
    probeBalance(account1);

    credit(account1, 500.0);
    debit(account1, 200.0);

    probeBalance(account1);

    closeAccount(account1);

    return 0;
}

