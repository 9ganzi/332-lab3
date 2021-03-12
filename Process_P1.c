#include <fcntl.h>

int main(){

    creat("destination1.txt", 0777); // creat expects octal value, 0 preceding 777 converts decimal to octal
    creat("destination2.txt", 0777);

    return 0;
}