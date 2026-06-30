#include <iostream>
#include <string>
#include <fstream>

class Interpreter {
private:
    char tape[30000];
    int data_pointer;

public:
    Interpreter() {
        for (int i = 0; i < 30000; i++)
            tape[i] = 0;

        data_pointer = 0;
    }

public:
    void interpret(const std::string& code) {
        for (size_t ip = 0; ip < code.length(); ip++)
            switch(code[ip]) {
                case '>':
                    data_pointer++;
                    break;
                
                case '<':
                    data_pointer--;
                    break;
                
                case '+':
                    tape[data_pointer]++;
                    break;
                
                case '-':
                    tape[data_pointer]--;
                    break;
                
                case '.':
                    std::cout << tape[data_pointer];
                    break;
                
                case ',':
                    std::cin >> tape[data_pointer];
                    break;
                    
                case '[':
                    if (tape[data_pointer] == 0) {
                        int loop_count = 1;

                        while (loop_count > 0) {
                            ip++;
                            if (code[ip] == '[') loop_count++;
                            else if (code[ip] == ']') loop_count--;
                        }
                    }
                    break;
                
                case ']':
                    if (tape[data_pointer] != 0) {
                        int loop_count = 1;

                        while (loop_count > 0) {
                            ip--;
                            if (code[ip] == ']') loop_count++;
                            else if (code[ip] == '[') loop_count--;
                        }
                    }
                    break;
        }
    }
};

int main(int argc, char* argv[]) {
    std::string line;
    std::string code;
    std::string filePath;

    if (argc < 2) {
        std::cout << "Enter file path: ";
        std::cin >> filePath;
    } else {
        filePath = argv[1];
    }

    std::ifstream brainFuckCodeFile(filePath);
   
    if (!brainFuckCodeFile.is_open())
        throw std::runtime_error("Error: Couldn't open BrainFuck file");
    
    while (std::getline(brainFuckCodeFile, line))
        code += line + "\n";
    
    brainFuckCodeFile.close();
    
    Interpreter brainFuckInterpreter;
    brainFuckInterpreter.interpret(code);

    return 0;
}