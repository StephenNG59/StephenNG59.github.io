#include <stdlib.h>
#include <string>


int main()
{
    std::string s = "abc";
    printf("%d", s.size() == 3);
    printf("%s", s.substr(0, 1));

    printf("%d", INT_MAX);
}

