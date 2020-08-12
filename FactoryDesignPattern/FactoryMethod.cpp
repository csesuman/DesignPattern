#include <bits/stdc++.h>
#include "Factory.h"

using namespace std;

int main(){

    CountryFactory* countryFactory = new Factory();
    Country *country;

    char name[50];

    while(scanf("%s",&name)!=EOF) {

        country = countryFactory->createCountry(name);

        if(country != nullptr){
            country->capitalCity();
            country->nationalAnimal();
        }
        else {
            cout<<" NO country Exists "<<endl;
        }

        cout<<"========================================================================="<<endl;
    }

    return 0;
}
