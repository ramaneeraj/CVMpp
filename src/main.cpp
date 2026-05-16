#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"
#include "parser.h"
#include "compiler.h"
#include "vm.h"

void runSource(const std::string& source, bool debugMode) {
    // Stage 1: Lex
    auto tokens = tokenize(source);

    // Stage 2: Parse
    Parser parser(tokens);
    auto ast = parser.parse();

    if (debugMode) {
        std::cout << "[DEBUG] Parsed " << ast->statements.size()
                  << " top-level statements.\n";
    }

    // Stage 3: Compile
    Compiler compiler;
    auto bytecode = compiler.compile(ast.get());

    if (debugMode) {
        std::cout << "[DEBUG] Compiled to "
                  << bytecode.instructions.size() << " instructions.\n";
        std::cout << "[DEBUG] Variables: ";
        for (auto& v : bytecode.varTable) std::cout << v << " ";
        std::cout << "\n";
    }

    // Stage 4: Execute
    VM vm;
    vm.execute(bytecode);
}

int main(int argc, char* argv[]) {
    bool debugMode = false;

    // Check for --debug flag in any argument position
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--debug")
            debugMode = true;
    }

    if (argc == 1 || (argc == 2 && debugMode)) {
        // No file given → launch REPL
        std::cout << "==============================\n";
        std::cout << "  CVM++ Interactive REPL\n";
        std::cout << "  Type 'exit' to quit\n";
        std::cout << "==============================\n";

        std::string accumulated;

        while (true) {
            std::cout << ">> ";
            std::string line;
            std::getline(std::cin, line);

            if (line == "exit") break;
            if (line.empty()) continue;

            accumulated += line + "\n";

            // Run when we see a statement-ending } or ;
            char last = line.back();
            if (last == ';' || last == '}') {
                try {
                    runSource(accumulated, debugMode);
                } catch (std::exception& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                accumulated.clear();
            }
        }

        } else {
        // File mode — run each .cvm file passed as argument
        for (int i = 1; i < argc; i++) {
            if (std::string(argv[i]) == "--debug") continue;

            std::ifstream file(argv[i]);
            if (!file.is_open()) {
                std::cerr << "Error: Cannot open file '" << argv[i] << "'\n";
                continue;
            }

            std::stringstream ss;
            ss << file.rdbuf();   // read entire file into string

            try {
                runSource(ss.str(), debugMode);
            } catch (std::exception& e) {
                std::cerr << "Error in '" << argv[i] << "': " << e.what() << "\n";
            }
        }
    }

    return 0;
}