#include "phonebook.hpp"

int     main(void)
{
    std::string tmp;
    phonebook   phn;
    int         yo;

    while (1)
    {
        std::cout<<"Enter your query (ADD, SEARCH or EXIT)";
        std::cin>>tmp;
        if (!tmp.compare("ADD"))
        {
            contacts    tmp2;
            std::cout<<"enter first name";
            std::cin>>tmp;
            tmp2.first_name = tmp;
            std::cout<<"enter last name";
            std::cin>>tmp;
            tmp2.last_name = tmp;
            std::cout<<"enter nickname";
            std::cin>>tmp;
            tmp2.nick_name = tmp;
            std::cout<<"enter phone number";
            std::cin>>tmp;
            tmp2.phon_num = tmp;
            std::cout<<"enter dark_secret";
            std::cin>>tmp;
            tmp2.dark_secret = tmp;
            phn.add(tmp2);
        }
        std::cout<<
    }
}