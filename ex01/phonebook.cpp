#include "phonebook.hpp"

std::string    format_names(std::string &str)
{
    std::string tmp;

    if (str.length() <= 10)
        return (str);
    else
    {
        tmp = str;
        tmp[9] = '.';
        std::fill_n(tmp.begin()+10, tmp.length() - 10, '\0');
        return tmp;
    }
}

int     main(void)
{
    std::string query;
    phonebook   *phn = new phonebook();
    int         yo;

    while (1)
    {
        std::cout<<"Enter your query (ADD, SEARCH or EXIT)"<<std::endl;
        std::cin>>query;
        if (!query.compare("ADD"))
        {
            std::string tmp_name, tmp_last, tmp_nick, tmp_phon, tmp_secret;
            std::cout<<"Enter first name"<<std::endl;
            std::cin>>tmp_name;
            std::cout<<"Enter last name"<<std::endl;
            std::cin>>tmp_last;
            std::cout<<"enter nickname"<<std::endl;
            std::cin>>tmp_nick;
            std::cout<<"enter phone number"<<std::endl;
            std::cin>>tmp_phon;
            std::cout<<"enter dark secret"<<std::endl;
            std::cin>>tmp_secret;
            phn->add(tmp_name, tmp_last, tmp_nick, tmp_phon, tmp_secret);
            std::cout<<format_names(phn->contact_list[(phn->current_index - 1) % 8].first_name)<<" has been added to the list"<<std::endl;
        }
        else if (!query.compare("EXIT"))
        {
            std::cout<<"Goodbye!";
            while (1);
            exit(0);
        }
        else if (!query.compare("SEARCH"))
        {
            int temp;

            if (phn->current_index >= 7)
                temp = 8;
            else
                temp = phn->current_index;
            for (int i = 0; i < temp; i++)
            {
                std::cout <<
                std::setfill(' ') <<
                std::setw(10) <<
                i + 1<< "|" <<
                std::setfill(' ') <<
                std::setw(10) <<
                format_names(phn->contact_list[i].first_name) <<"|" <<
                std::setfill(' ') <<
                std::setw(10) <<
                format_names(phn->contact_list[i].last_name) <<"|" <<
                std::setfill(' ') <<
                std::setw(10) <<
                format_names(phn->contact_list[i].nick_name) <<"|"<<std::endl;
            }
            std::cout<<"Enter the index"<<std::endl;
            std::cin>>temp;
            if (temp <= phn->total_entries && temp >= 1)
            {
                std::cout
                << "First name: " << phn->contact_list[temp - 1].first_name<<std::endl
                << "Last name: " << phn->contact_list[temp - 1].last_name<<std::endl
                << "Nickname: " << phn->contact_list[temp - 1].nick_name<<std::endl
                << "Phone number: " << phn->contact_list[temp - 1].phon_num<<std::endl
                << "Darkest secret: " << phn->contact_list[temp - 1].dark_secret<<std::endl;
            }
        }
    }
}
