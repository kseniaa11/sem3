//
//  Charset.hpp
//  Lab_3_29
//
//  Created by Alyona Borushnova on 15.10.2020.
//

#ifndef Charset_h
#define Charset_h

#include <stdio.h>
#include <iostream>

namespace ThirdLab3 {

    //   #define MAX_SIZE 1000

    class CharSet {
    private:
        char* value = nullptr;
        int cardinality;
    public:
        CharSet(int cardinal = 0); // ����������� �� ���������
//        char* DeleteIdenticalChar (char* line, int &);
        CharSet(char line);
        CharSet(char* line);
        CharSet(CharSet const& ch);
        CharSet(CharSet&& ch);
        friend std::istream& operator >> (std::istream& c, CharSet&);
        friend std::ostream& operator << (std::ostream& s, const CharSet& charset);
        bool Equality(const CharSet& charset);
        CharSet* Subtraction(CharSet& charset);//��������� ��������
        CharSet Intersection(CharSet& charset);//�����������
        CharSet& Injection(char symbol[1]);//������� ������ ��������
        CharSet Addition(CharSet& charset);//����������� ��������
        ~CharSet();

        bool Existence(char symbol[1]) const;

        //���������� ����������
        const CharSet& operator= (const CharSet& charset);
        const CharSet& operator= (CharSet&& charset);
        CharSet operator+= (const char& ch);                                                   //ok
        friend CharSet operator- (const CharSet& charset1, const CharSet& charset2);    //ok
        friend CharSet operator* (const CharSet& charset1, const CharSet& charset2);    //ok
        friend CharSet operator+ (const CharSet& charset1, const CharSet& charset2);    //ok

    };

    char* DeleteIdenticalChar(const char* line);
}
#endif /* Charset_hpp */
