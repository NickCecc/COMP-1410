




#include <stdio.h>
#include <string.h>
#include <ctype.h>

    void CreateAcronym(char userPhrase[], char userAcronym[]){

        char a;


        for(int i = 0; i < strlen(userPhrase); i++){
            if (isupper(userPhrase[i]) != 0)  {
                a = userPhrase[i];
                strncat(userAcronym, &a, 1);
                strncat(userAcronym, ".", 1);

                continue;
            }
            else if(isspace(userPhrase[i])!=0){
                continue;
            }

        }

        for(int i = 0; i < strlen(userAcronym); i++){

            printf("%c", userAcronym[i]);

        }
    }


    int main() {

        char str[40];
        char str2[40];
        scanf("%[^\n]", str);

        CreateAcronym(str, str2);

        return 0;
    }

    typedef struct Calculator_struct{
    double val;
}Calculator;

Calculator InitCalculator();
Calculator Add(double val, Calculator c);
Calculator Subtract(double val, Calculator c);
Calculator Multiply(double val, Calculator c);
Calculator Divide(double val, Calculator c);
Calculator Clear(Calculator c);
Calculator GetValue(Calculator c);

Calculator InitCalculator(){
    Calculator newC;
    newC.val = 0;
    return newC;
}

Calculator Add(double val, Calculator c){
    c.val += val;
    return c;
}
Calculator Subtract(double val, Calculator c){
    c.val -= val;
    return c;
}
Calculator Multiply(double val, Calculator c){
    c.val *= val;
    return c;
}
Calculator Divide(double val, Calculator c){
    c.val /= val;
    return c;
}
Calculator Clear(Calculator c){
    c.val = 0;
    return c;
}
Calculator GetValue(Calculator c){
    return c;
}
////////////////////////////////////////////////

typedef struct BankAccount_struct{
    char name[20];
    double checkings;
    double savings;
}BankAccount;
BankAccount InitBankAccount(char* newName, double amt1, double amt2);
BankAccount SetName(char* newName, BankAccount account);
BankAccount SetChecking(double amt, BankAccount account);
double GetChecking(BankAccount account);
BankAccount SetSavings(double amt, BankAccount account);
double GetSavings(BankAccount account);
BankAccount DepositChecking(double amt, BankAccount account);
BankAccount DepositSavings(double amt, BankAccount account);
BankAccount WithdrawChecking(double amt, BankAccount account);
BankAccount WithdrawSavings(double amt, BankAccount account);
BankAccount TransferToSavings(double amt, BankAccount account);

#include <stdio.h>
//#include "BankAccount.h"
#include <string.h>
BankAccount InitBankAccount(char* newName, double amt1, double amt2){
    BankAccount acc;
    strcpy(acc.name, newName);
    acc.checkings = amt1;
    acc.savings = amt2;
    return acc;

}
BankAccount SetName(char* newName, BankAccount account){
    strcpy(account.name, newName);
    return account;

}
void GetName(char* customerName, BankAccount account){
    strcpy(customerName, account.name);
}
BankAccount SetChecking(double amt, BankAccount account){
    account.checkings=amt;
    return account;
}
double GetChecking(BankAccount account){
    return account.checkings;
}
BankAccount SetSavings(double amt, BankAccount account){
    account.savings = amt;
    return account;
}
double GetSavings(BankAccount account){
    return account.savings;
}
BankAccount DepositChecking(double amt, BankAccount account){
    if (amt > 0){
        account.checkings += amt;

    }
    return account;
}
BankAccount DepositSavings(double amt, BankAccount account){
    if (amt > 0){
        account.savings += amt;

    }
    return account;
}
BankAccount WithdrawChecking(double amt, BankAccount account){
    if (amt > 0){
        account.checkings -= amt;

    }
    return account;
}
BankAccount WithdrawSavings(double amt, BankAccount account){
    if (amt > 0){
        account.savings -= amt;

    }
    return account;

}
BankAccount TransferToSavings(double amt, BankAccount account) {
    if (amt > 0) {
        account.checkings -= amt;
        account.savings += amt;


    }
    return account;
}
    ///////////////////////////////////
    typedef struct Product_struct{
        char code[20];
        double price;
        int count;
    }Product;
#include <string.h>
    Product InitProduct(char *code, double price, int count);
    Product SetCode(char *code, Product product);
    void GetCode(char *productCode, Product product);
    Product SetPrice(double price, Product productdouble);
    double GetPrice(Product product);
    Product SetCount(int count, Product product);
    int GetCount(Product product);
    Product AddInventory(int amt, Product product);
    Product SellInventory(int amt, Product product);

    Product InitProduct(char *code, double price, int count){
        Product newP;
        strcpy(newP.code, code);
        newP.price = price;
        newP.count = count;
        return newP;
    }
    Product SetCode(char *code, Product product){
        strcpy(product.code, code);
        return product;
    }
    void GetCode(char *productCode, Product product){
        strcpy(productCode, product.code);
    }
    Product SetPrice(double price, Product productdouble){
        productdouble.price = price;
        return productdouble;
    }
    double GetPrice(Product product){
        return product.price;
    }
    Product SetCount(int count, Product product){
        product.count = count;
        return product;
    }
    int GetCount(Product product){
        return product.count;
    }
    Product AddInventory(int amt, Product product){
        product.count += amt;
        return product;
    }
    Product SellInventory(int amt, Product product){
        product.count -= amt;
        return product;
    }
/////////////////////////////////

typedef struct Student_struct{
        char name[20];
        double gpa;
    }Student;


Student InitStudent();
Student SetName(char *name, Student s);
Student SetGPA(double gpa, Student s);
void GetName(char* studentName, Student s);
double GetGPA(Student s);

Student InitStudent(){
    Student st;
    strcpy(st.name, "Louie");
    st.gpa = 1.0;
    return st;
}
Student SetGPA(double gpa, Student s){
    s.gpa = gpa;
    return s;
}
void GetName(char* studentName, Student s){
    strcpy(studentName, s.name);
}
double GetGPA(Student s){
    return s.gpa;
}
char per[1] = ".";
























