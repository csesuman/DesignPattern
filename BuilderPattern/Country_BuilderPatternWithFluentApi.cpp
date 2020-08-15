#include<iostream>
#include<sstream>
#include<string>

using namespace std;

class CountryBuilder;

class Country  {

private:
    Country() = default;

    string name;
    string capital;
    string currency;

public:
    friend class CountryBuilder ; // the builder can access Country's Privates
    static CountryBuilder build() ;

    string to_string() const {

        stringstream stream ;
        stream << " Name : " << name
               << "\n Capital : " << capital
               << "\n Currency : " << currency
               <<endl;

        return stream.str();
    }
};

class CountryBuilder  {
private:
    Country country;
public:
    CountryBuilder& name(const string& name) {
        country.name = name;
        return *this;
    }

    CountryBuilder& capital(const string& capital) {
        country.capital = capital;
        return *this;
    }

    CountryBuilder& currency(const string& currency) {
        country.currency = currency;
        return *this;
    }

    operator Country&&() {
        return std::move(country);
    }
};

CountryBuilder Country::build() {

    return CountryBuilder();
}

ostream& operator << ( ostream& stream, const Country& country ) {
    stream << country.to_string();
    return stream;
}

int main() {

    Country country = Country::build()
                        .name("Bangladesh")
                        .currency("Taka")
                        .capital("Dhaka");


    cout << country << endl;

    return 0;
}
