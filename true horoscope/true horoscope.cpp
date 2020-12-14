
//  main.cpp
//  Lab_3_29
//
//  Created by Alyona Borushnova on 13.10.2020.
//

#include <iostream>
#include <cstring>
#include "charset.h"

int main(int argc, const char* argv[]) {

    

    char* n1 = new char[100];
    char* n2 = new char[100];
   

    std::cout << "Enter first name: ";
    std::cin >> n1;
    std::cout << "Enter second name: ";
    std::cin >> n2;

    ThirdLab3::CharSet Name1(n1);
    ThirdLab3::CharSet Name2(n2);

    int car;
    if ((Name1.getcar()) > (Name2.getcar()))
        car = Name1.getcar();
    else
        car = Name2.getcar();

    int sumcar = Name1.getcar() + Name2.getcar();

   ThirdLab3::CharSet inter = Name1.Intersection(Name2);

   

   double math = (double) (inter.getcar()) /(double) car;
    std::cout << "\n% of common: " << math*100 << "%\n";

  
    ThirdLab3::CharSet* sub = Name1.Subtraction(Name2);


    math = (double)((*sub).getcar()) / (double)sumcar;
    std::cout << "% of arguement: " << math * 100 << "%\n";


std::cout<<"Name1: "<<Name1<<"\nName2: "<<Name2<<"\nIntersection: "<< inter << "\nSubsription: " << *sub;

    system("pause");

    return 0;

}