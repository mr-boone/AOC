#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    // Ensure a filename is passed in
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream infile(filename);

 
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file " << filename << "\n";
        return 1;
    }

    std::string line;
    int dialPos = 50; 
    int oldDial = 50; 
    int zeroCount = 0; 
    while (std::getline(infile, line)) {
        int turnDial = std::stoi(line.substr(1,line.length()-1)); 
        zeroCount += turnDial/100; 
        turnDial -= (turnDial/100) * 100; 
        oldDial = dialPos;
        if(line[0] == 'R')
        {
           dialPos = ((dialPos + turnDial) % 100); 
        }
        if(line[0]== 'L')
        {
          dialPos = ((dialPos - turnDial + 100) % 100);
        }
        if((dialPos == 0 && oldDial != 0)
          || (dialPos < oldDial && line[0] == 'R')
          || (dialPos > oldDial && oldDial > 0 && line[0] == 'L')) zeroCount++; 
    }
    std::cout << zeroCount << std::endl;
    infile.close();
    return 0;
}
