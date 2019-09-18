#include <iostream>
#include "hands_methods.h"

int main() {
    std::string pathToImage = "/Users/danorel/Workspace/World of C/C++/KMA/MMPI/Negative/image3.jpg";
    std::string NegativeLabel = "Negative image";
    std::string LogLabel = "Log image";

    Mat NegativeImage = MakeNegative(pathToImage);
    imshow(NegativeLabel, NegativeImage);

    Mat LogImage = MakeLog(pathToImage);
    imshow(LogLabel, LogImage);

    waitKey(0);
    return 0;
}