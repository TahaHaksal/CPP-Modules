#include <iostream>

int     main(int ac, char **av)
{
    if (ac < 2)
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        for (int i = 1; i < ac; i++)
            std::cout<<av[i];
        std::cout<<'\n';
    }
    return (0);
}