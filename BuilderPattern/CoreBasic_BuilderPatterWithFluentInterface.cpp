// Sources :: https://stackoverflow.com/questions/50429631/c-builder-pattern-with-fluent-interface

#include <utility>

template <typename T>
class Builder {
public:
    static T builder() { return {}; }
    T & build() {return static_cast<T&>(*this); }
};

template <typename T>
class BaseClass : public Builder<T> {
    int base_class_variable;
public:
    T&& setBaseClassVariable(int variable) && {
        base_class_variable = variable;
        return std::move(static_cast<T&>(*this));
    }
};

class DerivedClass : public BaseClass<DerivedClass> {
    int derived_class_variable;
public:
    DerivedClass&& setDerivedClassVariable(int variable) && {
        derived_class_variable = variable;
        return std::move(*this);
    }
};

int main()
{
    // Creating an instance of DerivedClass
    DerivedClass dInstance = DerivedClass::builder()
        .setBaseClassVariable(5)
        .setDerivedClassVariable(10)
        .build();

//    dInstance.setBaseClassVariable(34); // will not compile
}
