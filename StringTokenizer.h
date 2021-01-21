#ifndef STRING_TOKENIZER
#define STRING_TOKENIZER
#include <iostream>
#include "LinkedList.h"
using namespace std;

class StringTokenizer
{
    string subject, delimiters;
    LinkedList<string> list;

    void tokenize()
    {
        int start = 0;
        for (int i = 0; i < subject.length(); i++)
        {
            int index = delimiters.find(subject[i]);
            if (index != string::npos)
            {
                string token = subject.substr(start, i - start);
                list.addToLast(token);
                while (delimiters.find(subject[++i]) != string::npos)
                {
                }
                start = i;
            }
        }
        string token = subject.substr(start, subject.length() - start);
        list.addToLast(token);
    }

public:
    StringTokenizer(string subject, string delimiters)
    {
        this->subject = subject;
        this->delimiters = delimiters;
        list = LinkedList<string>();
        tokenize();
    }

    bool hasMoreTokens()
    {
        return !list.isEmpty();
    }

    string nextToken()
    {
        return list.deleteFromFront();
    }
};

#endif