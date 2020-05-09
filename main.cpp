/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */

struct A {};

struct HeapA
{
    A* a;

    HeapA() :
    a(new A)
    {

    }

    ~HeapA()
    {
        delete a;
        a = nullptr;
    }
};

 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers  
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
        These functions should return the result of calling the function that takes the primitive.
     
 
 5) print out the results with some creative couts 
    i.e.
         FloatType ft(0.1f);
         IntType it(3);
         std::cout << "adding 3 and subtracting 'it' from 'ft' results in the following value: " << *ft.add(2.f).subtract( it ).value << std::endl;  //note the dereference of the `value` member of `ft`
 
 6) Don't let your heap-allocated owned type leak!
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>

struct DoubleType;
struct IntType;

struct FloatType
{
    float* value;

    FloatType(float i);
    ~FloatType();
    
    FloatType& add(float valueToAdd);
    FloatType& add(const FloatType& ft);
    FloatType& add(const DoubleType& dt);
    FloatType& add(const IntType& it);

    FloatType& subtract(float valueToSubtract);
    FloatType& subtract(const FloatType& ft);
    FloatType& subtract(const DoubleType& dt);
    FloatType& subtract(const IntType& it);

    FloatType& multiply(float valueToMultipyBy);
    FloatType& multiply(const FloatType& ft);
    FloatType& multiply(const DoubleType& dt);
    FloatType& multiply(const IntType& it);

    FloatType& divide(float valueToDivideBy);
    FloatType& divide(const FloatType& ft);
    FloatType& divide(const DoubleType& dt);
    FloatType& divide(const IntType& it);
};

FloatType::FloatType(float i) : 
value(new float(i))
{

}

FloatType::~FloatType()
{
    delete value;
    value = nullptr;
}


FloatType& FloatType::add(float valueToAdd)
{
    *value += valueToAdd;
    return *this;
}


FloatType& FloatType::subtract(float valueToSubtract)
{
    *value -= valueToSubtract;
    return *this;
}

FloatType& FloatType::multiply(float valueToMultiplyBy)
{
    *value *= valueToMultiplyBy;
    return *this;
}

FloatType& FloatType::divide(float valueToDivideBy)
{
    if (valueToDivideBy == 0.f)
    {
        std::cout << "Warning! Dividing float by zero!" << std::endl;
    }

    *value /= valueToDivideBy;
    return *this;
}


struct DoubleType
{
    double* value;

    DoubleType(double d);
    ~DoubleType();

    DoubleType& add(double valueToAdd);
    DoubleType& add(const FloatType& valueToAdd);
    DoubleType& add(const DoubleType& valueToAdd);
    DoubleType& add(const IntType& valueToAdd);

    DoubleType& subtract(double valueToSubtract);
    DoubleType& subtract(const FloatType& valueToSubtract);
    DoubleType& subtract(const DoubleType& valueToSubtract);
    DoubleType& subtract(const IntType& valueToSubtract);

    DoubleType& multiply(double valueToMultipyBy);
    DoubleType& multiply(const FloatType& valueToMultipyBy);
    DoubleType& multiply(const DoubleType& valueToMultipyBy);
    DoubleType& multiply(const IntType& valueToMultipyBy);

    DoubleType& divide(double valueToDivideBy);
    DoubleType& divide(const FloatType& valueToDivideBy);
    DoubleType& divide(const DoubleType& valueToDivideBy);
    DoubleType& divide(const IntType& valueToDivideBy);
};

DoubleType::DoubleType(double d) :
value(new double(d))
{
    
}

DoubleType::~DoubleType()
{
    delete value;
    value = nullptr;
}

DoubleType& DoubleType::add(double valueToAdd)
{
    *value += valueToAdd;
    return *this;
}


DoubleType& DoubleType::subtract(double valueToSubtract)
{
    *value -= valueToSubtract;
    return *this;
}

DoubleType& DoubleType::multiply(double valueToMultipyBy)
{
    *value *= valueToMultipyBy;
    return *this;
}

DoubleType& DoubleType::divide(double valueToDivideBy)
{
    if (valueToDivideBy == 0.0)
    {
        std::cout << "Warning! Dividing double by zero!" << std::endl;
    }

    *value /= valueToDivideBy;
    return *this;
}


struct IntType
{
    int* value;

    IntType(int i);
    ~IntType();

    IntType& add(int valueToAdd);
    IntType& add(const FloatType& valueToAdd);
    IntType& add(const DoubleType& valueToAdd);
    IntType& add(const IntType& valueToAdd);

    IntType& subtract(int valueToSubtract);
    IntType& subtract(const FloatType& valueToSubtract);
    IntType& subtract(const DoubleType& valueToSubtract);
    IntType& subtract(const IntType& valueToSubtract);

    IntType& multiply(int valueToMultipyBy);
    IntType& multiply(const FloatType& valueToMultipyBy);
    IntType& multiply(const DoubleType& valueToMultipyBy);
    IntType& multiply(const IntType& valueToMultipyBy);

    IntType& divide(int valueToDivideBy);
    IntType& divide(const FloatType& valueToDivideBy);
    IntType& divide(const DoubleType& valueToDivideBy);
    IntType& divide(const IntType& valueToDivideBy);
};

IntType::IntType(int i) :
value(new int(i))
{

}

IntType::~IntType()
{
    delete value;
    value = nullptr;
}


IntType& IntType::add(int valueToAdd)
{
    *value += valueToAdd;
    return *this;
}


IntType& IntType::subtract(int valueToSubtract)
{
    *value -= valueToSubtract;
    return *this;
}


IntType& IntType::multiply(int valueToMultipyBy)
{
    *value *= valueToMultipyBy;
    return *this;
}


IntType& IntType::divide(int valueToDivideBy)
{
    if (valueToDivideBy == 0)
    {
        std::cout << "Error! Cannot divide integer by zero!" << std::endl;
        return *this;
    }

    *value /= valueToDivideBy;
    return *this;
}



FloatType& FloatType::add(const FloatType& valueToAdd)
{
    return add(*valueToAdd.value);
}

FloatType& FloatType::add(const DoubleType& valueToAdd)
{
    return add(static_cast<float>(*valueToAdd.value));
}

FloatType& FloatType::add(const IntType& valueToAdd)
{
    return add(static_cast<float>(*valueToAdd.value));
}


FloatType& FloatType::subtract(const FloatType& valueToSubtract)
{
    return subtract(*valueToSubtract.value);
}

FloatType& FloatType::subtract(const DoubleType& valueToSubtract)
{
    return subtract(static_cast<float>(*valueToSubtract.value));
}

FloatType& FloatType::subtract(const IntType& valueToSubtract)
{
    return subtract(static_cast<float>(*valueToSubtract.value));
}


FloatType& FloatType::multiply(const FloatType& valueToMultiplyBy)
{
    return multiply(*valueToMultiplyBy.value);
}

FloatType& FloatType::multiply(const DoubleType& valueToMultiplyBy)
{
    return multiply(static_cast<float>(*valueToMultiplyBy.value));
}

FloatType& FloatType::multiply(const IntType& valueToMultiplyBy)
{
    return multiply(static_cast<float>(*valueToMultiplyBy.value));
}


FloatType& FloatType::divide(const FloatType& valueToDivideBy)
{
    return divide(*valueToDivideBy.value);
}

FloatType& FloatType::divide(const DoubleType& valueToDivideBy)
{
    return divide(static_cast<float>(*valueToDivideBy.value));
}

FloatType& FloatType::divide(const IntType& valueToDivideBy)
{
    return divide(static_cast<float>(*valueToDivideBy.value));
}


DoubleType& DoubleType::add(const FloatType& valueToAdd)
{
    return add(static_cast<double>(*valueToAdd.value));
}

DoubleType& DoubleType::add(const DoubleType& valueToAdd)
{
    return add(*valueToAdd.value);
}

DoubleType& DoubleType::add(const IntType& valueToAdd)
{
    return add(static_cast<double>(*valueToAdd.value));
}


DoubleType& DoubleType::subtract(const FloatType& valueToSubtract)
{
    return subtract(static_cast<double>(*valueToSubtract.value));
}

DoubleType& DoubleType::subtract(const DoubleType& valueToSubtract)
{
    return subtract(*valueToSubtract.value);
}

DoubleType& DoubleType::subtract(const IntType& valueToSubtract)
{
    return subtract(static_cast<double>(*valueToSubtract.value));
}


DoubleType& DoubleType::multiply(const FloatType& valueToMultiplyBy)
{
    return multiply(static_cast<double>(*valueToMultiplyBy.value));
}

DoubleType& DoubleType::multiply(const DoubleType& valueToMultiplyBy)
{
    return multiply(*valueToMultiplyBy.value);
}

DoubleType& DoubleType::multiply(const IntType& valueToMultiplyBy)
{
    return multiply(static_cast<double>(*valueToMultiplyBy.value));
}


DoubleType& DoubleType::divide(const FloatType& valueToDivideBy)
{
    return divide(static_cast<double>(*valueToDivideBy.value));
}

DoubleType& DoubleType::divide(const DoubleType& valueToDivideBy)
{
    return divide(*valueToDivideBy.value);
}

DoubleType& DoubleType::divide(const IntType& valueToDivideBy)
{
    return divide(static_cast<double>(*valueToDivideBy.value));
}



IntType& IntType::add(const FloatType& valueToAdd)
{
    return add(static_cast<int>(*valueToAdd.value));
}

IntType& IntType::add(const DoubleType& valueToAdd)
{
    return add(static_cast<int>(*valueToAdd.value));
}

IntType& IntType::add(const IntType& valueToAdd)
{
    return add(*valueToAdd.value);
}


IntType& IntType::subtract(const FloatType& valueToSubtract)
{
    return subtract(static_cast<int>(*valueToSubtract.value));
}

IntType& IntType::subtract(const DoubleType& valueToSubtract)
{
    return subtract(static_cast<int>(*valueToSubtract.value));
}

IntType& IntType::subtract(const IntType& valueToSubtract)
{
    return subtract(*valueToSubtract.value);
}


IntType& IntType::multiply(const FloatType& valueToMultipyBy)
{
    return multiply(static_cast<int>(*valueToMultipyBy.value));
}

IntType& IntType::multiply(const DoubleType& valueToMultipyBy)
{
    return multiply(static_cast<int>(*valueToMultipyBy.value));
}

IntType& IntType::multiply(const IntType& valueToMultipyBy)
{
    return multiply(*valueToMultipyBy.value);
}


IntType& IntType::divide(const FloatType& valueToDivideBy)
{
    return divide(static_cast<int>(*valueToDivideBy.value));
}

IntType& IntType::divide(const DoubleType& valueToDivideBy)
{
    return divide(static_cast<int>(*valueToDivideBy.value));
}

IntType& IntType::divide(const IntType& valueToDivideBy)
{
    return divide(*valueToDivideBy.value);
}

int main()
{
    FloatType ft(4.5f);
    DoubleType dt(101.101);
    IntType it(9);
    
    /*  PART 1 
    auto resultFt = ft.add(1.20f, 6.78f);
    std::cout << "Result of ft.add(): " << resultFt << std::endl;

    resultFt = ft.subtract(89.456f, 43.635467f);
    std::cout << "Result of ft.subtract(): " << resultFt << std::endl;

    resultFt = ft.multiply(120.60f, 30.563f);
    std::cout << "Result of ft.multiply(): " << resultFt << std::endl;

    resultFt = ft.divide(200.56f, 0.45f);
    std::cout << "Result of ft.divide(): " << resultFt << std::endl;


    auto resultDt = dt.add(2.476, 8.3451);
    std::cout << "Result of dt.add(): " << resultDt << std::endl;

    resultDt = dt.subtract(12.56346, 3.3276);
    std::cout << "Result of dt.subtract(): " << resultDt << std::endl;

    resultDt = dt.multiply(4.75, 9.5623);
    std::cout << "Result of dt.multiply(): " << resultDt << std::endl;

    resultDt = dt.divide(790.3564, 23.46578);
    std::cout << "Result of dt.divide(): " << resultDt << std::endl;


    auto resultIt = it.add(40, 78);
    std::cout << "Result of it.add(): " << resultIt << std::endl;

    resultIt = it.subtract(850, 32);
    std::cout << "Result of it.subtract(): " << resultIt << std::endl;

    resultIt = it.multiply(6, 3);
    std::cout << "Result of it.multiply(): " << resultIt << std::endl;

    resultIt = it.divide(48, 8);
    std::cout << "Result of it.divide(): " << resultIt << std::endl;
    */

    std::cout << "Testing IntType: " << *it.add(1).multiply(2).value << std::endl;

    std::cout << "good to go!" << std::endl;
}
