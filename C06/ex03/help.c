#include <unistd.h>

// Function to compare two strings based on ASCII order
int compare_strings(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

// Function to sort an array of strings using bubble sort
void sort_strings(char **arr, int size) {
    int i = 0;
    while (i < size - 1) {
        int j = 0;
        while (j < size - i - 1) {
            if (compare_strings(arr[j], arr[j + 1]) > 0) {
                // Swap the strings
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 0; // No arguments to sort
    }

    // Sort the arguments (excluding argv[0])
    sort_strings(argv + 1, argc - 1);

    // Display the sorted arguments
    int i = 0;
    while (i < argc - 1) {
        char *arg = argv[i + 1];
        while (*arg) {
            write(1, arg, 1); // Write each character
            arg++;
        }
        write(1, "\n", 1); // Write a newline
        i++;
    }

    return 0;
}
