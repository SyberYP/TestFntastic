#include <iostream>
#include <string>
#include <map>

int main()
{
    while (true)
    {
        std::cout << "Hello! Please input the string." << std::endl;
        std::map<char, int> InputMap;

        std::string InputString = "";
        std::string OutputString = "";
        getline(std::cin, InputString);

        for (char InputChar : InputString)
        {
            InputMap[tolower(InputChar)]++;
        }

        for (char InputChar : InputString)
        {
            if (InputMap[tolower(InputChar)] > 1)
            {
                OutputString.append(")");
            }
            else
            {
                OutputString.append("(");
            }
        }
        std::cout << OutputString << std::endl;
    }
}
