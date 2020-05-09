/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
 do not remove anything from main().  you'll be revising your main() to work with these new code changes.
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function
 
 6) clean up any forward declaration that you might have.
 
 7) make sure it compiles & runs without errors.
 
 8) use your knowledge of casting to remove any conversion warnings. 
 
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

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    FloatType ft(4.5f);
    DoubleType dt(101.101);
    IntType it(9);

    std::cout << "ft's initial value is: " << *ft.value << std::endl;
    std::cout << "dt's initial value is: " << *dt.value << std::endl;
    std::cout << "it's initial value is: " << *it.value << std::endl;

    std::cout << "Adding 1 to it, then multiplying that by dt results in: " << *it.add(1).multiply(dt).value << std::endl;

    std::cout << "Subtracting dt from ft, then dividing that by it results in: " << *ft.subtract(dt).divide(it).value << std::endl;

    std::cout << "Dividing dt by ft, then adding it results in: " << *dt.divide(ft).add(it).value << std::endl;
    
    /*  PART 1 STUFF
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

    std::cout << "good to go!" << std::endl;
}
