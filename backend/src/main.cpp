#include <string>
#include "Ability.h"
#include <iostream>

using namespace std;

int main(){
    Ability abilities = Ability::Builder()
        .name("Aidan")
        .text("this is text")
        .build();
    cout << abilities.getText() << endl;


    return 0;
}