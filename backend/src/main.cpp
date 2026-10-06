#include "../include/player/features/Feature.h"
#include <iostream>
int main(){
	Feature f = Feature::Builder().name("Featurename!").build();
	std::cout << "Feature with name: " << f.getName() << std::endl;
}
