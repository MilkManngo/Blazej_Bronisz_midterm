#include <iostream>
#include <cmath>
#include <time.h>
#include <cstring>

int task1(int integer);
int task2();
int task3(char name[], int length);
void fill_with_randoms(double values[]);
double weighted_harmonic_mean(int weights[], double values[]);

int main()

{
    int task=0, end=0, integer;
    char name[20];



    while (end==0){
    std::cout << "Select a task 1-3 or exit with 20" << std::endl;
    std::cin >> task;

        switch (task){

        case 1: {
            std::cout << "Input one integer: " << std::endl;
            std::cin >> integer;
            std::cout << std::endl;
            std::cout << task1(integer) << std::endl;
            break;
        }

        case 2: {
            double values[3];
            fill_with_randoms(values);
            int weights[3] = {1,2,3};
                std::cout <<  weighted_harmonic_mean(weights, values) << std::endl;
            break;
        }

        case 3: {
            std::cout << "Input your name or any other word: " << std::endl;
            std::cin >> name;
            std::cout << std::endl;
            task3(name, std::strlen(name));
            break;
        }

        case 20: {
            std::cout << "Goodbye" << std::endl;
            end = 1;
            break;
        }

        default: {
            std::cout << "There is no such task" << std::endl;
            break;
        }
        }
        }
     return 0;
    }




int task1(int integer){
    return 3*pow(integer, 2) + 1;
}


int task3(char name[], int length){
    int capital = 0, letters = 0, ter = 0;

    while(ter<length){
        std::cout << name[ter] << std::endl;
        ter++;
    }
        std::cout << std::endl;

    for (int i = 0; i<length; i++){
        if (isupper(name[i]) || islower(name[i])){
            letters += 1;
        }
    }
        std::cout << "There are " << letters << " letters" << std::endl;

    for (int i=0; i<length; i++){
        if (isupper(name[i])){
            capital += 1;
        }
    }
        std::cout << capital << " of them are capital letters" << std::endl;
}


void fill_with_randoms(double values[]){
    srand (time(NULL));
    for (int i=0; i<3; i++){
        values[i] = rand() % 15 + 10;
    }

}



double weighted_harmonic_mean(int weights[], double values[]) {
    double up = 0, down = 0;
    for (int i=0; i<3; i++){
        down += weights[i]/values[i];
        up += weights[i];
    }

    double mean = up/down;

    return mean;
}
