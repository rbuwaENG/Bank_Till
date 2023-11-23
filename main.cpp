/*
20/ENG/016
Steps followed:
  1.get customer details
  2.get loan details
  3.select laon type
  4.calculate intrests and loans
  5.display loan details
  6.print loan details to text file

*/


#include<iostream>
#include<fstream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

struct Account{
  string name;
  string loanName;
  int age;
  double monthlyincome;
  double loan;
  int repay;
  int Maxrepay;
  double rate;
  double totalpayment;

};


//Enter customer details
void  accountHolderDetails(Account& customer){
  cout<<"\nEnter customer name:";
  getline (cin,customer.name);
  cout<<"\nEnter customer age:";
  cin>>customer.age;
  cout<<"\nEnter monthly income:";
  cin>>customer.monthlyincome;
  cout<<"\n";
}

//loan details 
void loandetails(int age , double mi){
  int state =0;
  cout<<"Loan Name" << "\tLoan Amount" << "\tRepay Period" << "\tAnnual Interest Rate\n";

  if(((age>=18)&&(age<=55))&&(mi >= 45000)){
  cout<<"1.Vehicle" << "\t1000000.00" << "\t60" << "\t\t14\n";
  state = 1;
  }
   if(((age>=25)&&(age<=55))&&(mi >= 100000)){
  cout<<"2.Housing" << "\t2500000.00" << "\t60" << "\t\t8\n";  
  state = 1;
  }
   if(((age>=25)&&(age<=35))&&(mi >= 45000)){
  cout<<"3.Education" << "\t1500000.00" << "\t284" << "\t\t6\n";  
  }
   if((age>=60)&&(mi >= 35000)){
  cout<<"4.Senior" << "\t500000.00" << "\t60" << "\t\t4.5\n"; 
  cout<<"Citizen\n";
  state = 1; 
  }
   if(((age>=30)&&(age<=55))&&(mi >= 100000)){
  cout<<"5.Personal" << "\t2000000.00" << "\t60" << "\t\t14.5\n"; 
  cout<<"--------" << "\t3000000.00" << "\t84" << "\t\t16.2\n"; 
  state = 1; 
  }
  if(state == 0){
    cout<<"\nSorry,You are not eligible for the loan\n";
    exit(0);
  }
}

//select loan
void selectloan(Account& customer){
menue:
  int selection;
  cout<<"\nEnter the loan type number:";
  cin>>selection;
  switch(selection){
    case 1:
case1:
      customer.Maxrepay = 60;
      cout<<"Enter loan amount:";
      cin>>customer.loan;
      cout<<"Enter repay period:";
      cin>>customer.repay;
      if((customer.loan >=1000000) || (customer.Maxrepay<customer.repay)){
        cout<<"\nAmount or period is higher than provided , Please retry!!\n";
        goto case1;
      }
      customer.loanName = "Vehicle";
      customer.rate = 0.14;
      break;
    case 2:
case2:
      customer.Maxrepay = 60;
      cout<<"Enter loan amount:";
      cin>>customer.loan;
      cout<<"Enter repay period:";
      cin>>customer.repay;
       if((customer.loan >=2500000) || (customer.Maxrepay<customer.repay)){
        cout<<"\nAmount or period is higher than provided , Please retry!!\n";
        goto case2;
      }
      customer.loanName = "Housing";
      customer.rate = 0.08;
      break;
    case 3:
case3:
      customer.Maxrepay = 284;
      cout<<"Enter loan amount:";
      cin>>customer.loan;
      cout<<"Enter repay period:";
      cin>>customer.repay;
       if((customer.loan >=1500000) || (customer.Maxrepay<customer.repay)){
        cout<<"\nAmount or period is higher than provided ,  Please retry!!\n";
        goto case3;
      }
      customer.loanName = "Education";
      customer.rate = 0.06;
      break;
    case 4:
case4:
      customer.Maxrepay = 60;
      cout<<"Enter loan amount:";
      cin>>customer.loan;
      cout<<"Enter repay period:";
      cin>>customer.repay;
       if((customer.loan >=500000) || (customer.Maxrepay<customer.repay)){
        cout<<"\nAmount or period is higher than provided ,  Please retry!!\n";
        goto case4;
      }
      customer.loanName = "Senior Citizen";
      customer.rate = 0.045;
      break;
    case 5:
case5:
      cout<<"Enter loan amount:";
      cin>>customer.loan;
        if(customer.loan <=3000000 && customer.loan >=2000000){
          customer.Maxrepay =84;
      }
      else if (customer.loan <=2000000){
         customer.Maxrepay =60;

      }
      cout<<"Enter repay period:";
      cin>>customer.repay;
        if((customer.loan >=300000) || (customer.Maxrepay<customer.repay)){
        cout<<"\nAmount or period is higher than provided ,  Please retry!!\n";
        goto case5;
      }
     
      customer.loanName = "Personal";
      customer.rate = 0.145;
      
      break;
    default:
      cout<<"Please select the correct loan type\n";
      goto menue;
      }
}

//calculation
void calculation(Account& customer){
  int n = customer.repay ;
  double ir = customer.rate/12;
  double d;
  d =(pow((1.00+ir),n)-1)/(ir*pow((1.00+ir),n));
  customer.totalpayment = customer.loan/d;

}


//display loan details
void displaydetails(Account& customer){
cout<<"\n===============================\n";
cout<<"========Details of loan=========\n";
cout<<"Monthly repay Amount:" << "\t"<<customer.totalpayment<<"\n";
cout<<"Total Amount:" << "\t\t"<<customer.totalpayment*customer.repay<<"\n";
cout<<"Interest earned " << "\t"<<(customer.totalpayment*customer.repay)-customer.loan<<"\n";
cout<<"by the bank:\n";
cout<<"\n===============================\n";

}


//print loan details
void printDetails(Account& customer){
  string namewithU = customer.name;
   for (int i = 0; i < namewithU.length(); ++i) {
      // replacing character to '-' with a 'space'.
      if (namewithU[i] == ' ') {
         namewithU[i] = '_';
      }}
   double amount = customer.loan;
   int period = customer.repay;
   double intrest = 0.0;
   double repaidla = 0.0;
  ofstream accountFile;
        accountFile.open(namewithU + ".txt", ios::trunc);
            accountFile<<"\n========================================\n";
            accountFile << "Name of customer:\t"<<customer.name<<"\n";
            accountFile << "Selected loan:\t"<<customer.loanName<<"\n";
            accountFile << "Maximum repay period:\t"<<customer.Maxrepay<<"\n";
            accountFile << "Anual interest rate:\t"<<customer.rate*100<<"%\n";
            accountFile << "Requested loan amount:\t"<<customer.loan<<"\n";
            accountFile <<"Requested repay period:\t"<<customer.repay<<"\n";
            accountFile<<"Monthly repay calculation\n";
            accountFile<<"--------------------------------\n";
            accountFile<<"Month" << "\t\tRemaining Loan Amount" << "\t\tInterest" << "\t\tRepaid Loan Amount\n";
            for(int i =1; i<=period;i++){
              intrest = amount*(customer.rate/12);
              repaidla = customer.totalpayment-intrest;
            accountFile<<"\t"<<i<< "\t\t\t\t\t"<<amount << "\t\t\t\t\t"<<intrest << "\t\t\t"<< repaidla<<"\n";
              amount = amount-repaidla;
            }
            accountFile <<"\nTotal amount to be paid:\t"<<customer.totalpayment*customer.repay<<"\n";
            accountFile<<"\n========================================\n";
        
        accountFile.close();


}




int main(){
  Account customer;
  accountHolderDetails(customer);
  loandetails(customer.age,customer.monthlyincome);
  selectloan(customer);
  calculation(customer);
  displaydetails(customer);
  printDetails(customer);

}


