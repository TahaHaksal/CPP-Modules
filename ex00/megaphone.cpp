#include <iostream>
#include <string>

int     main(int ac, char **av)
{
    if (ac < 2)
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        for (int i = 1; i < ac; i++)
        {
            for (int j = 0; j < strlen(av[i]); j++)
            {
                std::cout<<(char)toupper(av[i][j]);
            }
        }
        std::cout<<'\n';
    }
    return (0);
}