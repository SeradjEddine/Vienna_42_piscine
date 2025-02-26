#include "ft_stock_str.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    t_stock_str *tab;
    
    // Test with command line arguments
    if (argc > 1)
    {
        tab = ft_strs_to_tab(argc - 1, argv + 1);
    }
    else // Hardcoded test case
    {
        char *test_strings[] = {"Hello", "42", "Test string", "Goodbye!", NULL};
        tab = ft_strs_to_tab(4, test_strings);
    }
    
    if (!tab)
        return (1);
        
    ft_show_tab(tab);
    
    // Free allocated memory
    int i = 0;
    while (tab[i].str)
    {
        free(tab[i].copy);
        i++;
    }
    free(tab);
    
    return (0);
}
