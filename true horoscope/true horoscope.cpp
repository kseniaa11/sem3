//
//  main.cpp
//  Lab_3_29
//
//  Created by Alyona Borushnova on 13.10.2020.
//

#include <iostream>
#include "charset.h"

int main(int argc, const char* argv[]) {

    ThirdLab3::CharSet c1(4);
    ThirdLab3::CharSet c2(3);
    char* line = new char [2];
    for (int i = 0; i < 2; i++)
        line[i] = 'a';
    line[2] = '\0';
    ThirdLab3::CharSet c3(line);
    ThirdLab3::CharSet c4('h');
    c2 += 'a';
    //    ThirdLab3::CharSet c3 = c3.Subtraction(c1, c2);
    //    ThirdLab3::CharSet c3(10);
    //    ThirdLab3::CharSet c4;
    //    std::cin >> c4;
    //char* symbol = "n";
    //    bool b = c4.Existence(symbol, c4);
    //    ThirdLab3::CharSet * f = c1.Subtraction(c2);
    //    ThirdLab3::CharSet * a = c1.intersection(c2);
        //char c = "s";
    //    ThirdLab3::CharSet * f = c1.Addition(c2);
    ThirdLab3::CharSet nw = c1 - c2;
      //  nw.Injection(symbol);
    std::cout << c1;
    std::cout << c2;
        std::cout << nw;

    return 0;

}