
#include "fabonacci.h"

int main(int argc, char *argv[])
{
    std::cout << "TEST 1" << std::endl;
    printf("n=3, result= %d \n", fabonacci(3));
    printf("n=6, result= %d \n", fabonacci(6));

    std::cout << "Dynamic programming" << std::endl;
    std::cout << "n=3:" << dp_fabonacci(3) << std::endl;
    std::cout << "n=6:" << dp_fabonacci(6) << std::endl;

    printf("-------END---------\n");
    return 0;
}
