/*
 * Copyright (C) 2026 Mohammed Tamer Mohammed Ahmed El-Azab Nour (V3LK)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Project: Brainfuck Interpreter
*/

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