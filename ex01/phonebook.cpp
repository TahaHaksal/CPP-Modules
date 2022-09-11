#include "phonebook.hpp"

int     main(void)
{
    std::string tmp;
    phonebook   *phn = new phonebook();
    int         yo;

    while (1)
    {
        std::cout<<"Enter your query (ADD, SEARCH or EXIT)"<<std::endl;
        std::cin>>tmp;
        if (!tmp.compare("ADD"))
        {
            contacts    *tmp2 = new contacts;
            std::cout<<"enter first name"<<std::endl<<std::endl;
            std::cin>>tmp;
            tmp2->first_name = tmp;
            std::cout<<"enter last name"<<std::endl;
            std::cin>>tmp;
            tmp2->last_name = tmp;
            std::cout<<"enter nickname"<<std::endl;
            std::cin>>tmp;
            tmp2->nick_name = tmp;
            std::cout<<"enter phone number"<<std::endl;
            std::cin>>tmp;
            tmp2->phon_num = tmp;
            std::cout<<"enter dark_secret"<<std::endl;
            std::cin>>tmp;
            tmp2->dark_secret = tmp;
            phn->add(tmp2);
            std::cout<<phn->contact_list[phn->current_index - 1].first_name<<" has been added to the list"<<std::endl;
        }
        else if (!tmp.compare("EXIT"))
        {
            std::cout<<"Goodbye!";
            exit(0);
        }
        else if (!tmp.compare("SEARCH"))
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
                phn->contact_list[i].first_name << "|" <<
                std::setfill(' ') <<
                std::setw(10) <<
                phn->contact_list[i].last_name <<"|" <<
                std::setfill(' ') <<
                std::setw(10) <<
                phn->contact_list[i].nick_name <<"|" <<
                std::setfill(' ') <<
                std::setw(10) <<
                phn->contact_list[i].phon_num <<"|" <<
                std::setfill(' ') <<
                std::setw(10) <<
                phn->contact_list[i].dark_secret <<"|"<<std::endl;
                std::string_view("");
            }
        }
    }
}
