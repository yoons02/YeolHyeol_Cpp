#include <iostream>

namespace yoons{
    void Introduce(){
        std::cout << "나야나윤스" << std::endl;
    }
}

namespace chans{
    void Introduce(){
        std::cout << "나야나찬스" << std::endl;
    }
}

int main(){
    yoons::Introduce();
    chans::Introduce();

    return 0;
}