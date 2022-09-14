#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class   contacts
{
public:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phon_num;
    std::string dark_secret;
};

class   phonebook
{
public:
    contacts    contact_list[8];
    int         current_index;
    int         total_entries;
    phonebook()
    {
        current_index = 0;
        total_entries = 0;
    }
    void    add(std::string name, std::string last_name, std::string nick, std::string phone_num, std::string secret)
    {
        this->contact_list[current_index % 8].first_name = name;
        this->contact_list[current_index % 8].last_name = last_name;
        this->contact_list[current_index % 8].nick_name = nick;
        this->contact_list[current_index % 8].phon_num = phone_num;
        this->contact_list[current_index % 8].dark_secret = secret;
        current_index++;
        total_entries++;
    }
};
