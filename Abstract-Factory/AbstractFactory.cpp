/*
 * Design Pattern : Abstract-Factory
 * Creational Design Pattern
 * Author : Ayush Agarwal [https://github.com/ayush9096]
 * 
 */


#include <iostream>
using namespace std;


// Abstract Product A
class AbstractProductA{
    
    public:
        virtual ~AbstractProductA(){}
        virtual string getProductName() = 0;
};


class ConcreteProductA1 : public AbstractProductA {

    public:
        ~ConcreteProductA1() {}

        string getProductName(){
            return "CompanyA - ProductA";
        }
};

class ConcreteProductA2 : public AbstractProductA {
    
    public:
        ~ConcreteProductA2() {}

        string getProductName(){
            return "CompanyB - ProductA";
        }
};


class ConcreteProductA3 : public AbstractProductA {

    public:
        ~ConcreteProductA3() {}

        string getProductName(){
            return "CompanyC - ProductA";
        }
};


// Abstract Product B
class AbstractProductB{
    public:
        virtual ~AbstractProductB(){};
        virtual string getProductName() = 0;
};

class ConcreteProductB1 : public AbstractProductB {
    
    public:
        ~ConcreteProductB1() {}
        string getProductName(){
            return "CompanyA - ProductB";
        }
};

class ConcreteProductB2 : public AbstractProductB {
    
    public:
        ~ConcreteProductB2() {}
        string getProductName(){
            return "CompanyB - ProductB";
        }
};

class ConcreteProductB3 : public AbstractProductB {
    public:
        ~ConcreteProductB3() {}
        string getProductName(){
            return "CompanyC - ProductC";
        }
};



// Abstract Factory provides an interface for creating a family of products
class AbstractFactory{
    
    public:
        virtual ~AbstractFactory() {}
        virtual AbstractProductA* createProductA() = 0;
        virtual AbstractProductB* createProductB() = 0;
};


/*
 * Concrete Factory creates a family of products.
 * Concrete Factory methods return a abstract product, inside method a concrete product is instantiated.
 */

class ConcreteFactory1: public AbstractFactory{

    public:
        ~ConcreteFactory1(){}

        AbstractProductA* createProductA(){
            return new ConcreteProductA1();
        }

        AbstractProductB* createProductB(){
            return new ConcreteProductB1();
        }
};

class ConcreteFactory2: public AbstractFactory{
    
    public:
        ~ConcreteFactory2(){}

        AbstractProductA* createProductA(){
            return new ConcreteProductA2();
        }

        AbstractProductB* createProductB(){
            return new ConcreteProductB2();
        }
};

class ConcreteFactory3: public AbstractFactory{
    public:
        ~ConcreteFactory3(){}

        AbstractProductA* createProductA(){
            return new ConcreteProductA3();
        }

        AbstractProductB* createProductB(){
            return new ConcreteProductB3();
        }
};




// Client Code

int main(){

    ConcreteFactory1 *companyA = new ConcreteFactory1();
    ConcreteFactory2 *companyB = new ConcreteFactory2();
    ConcreteFactory3 *companyC = new ConcreteFactory3();

    AbstractProductA* productA = companyA->createProductA();
    cout << "Product Name : " << productA->getProductName() << " \n";

    AbstractProductB* productB = companyB->createProductB();
    cout << "Product Name : " << productB->getProductName() << " \n";

    delete productA;
    delete productB;

    delete companyA;
    delete companyB;
    delete companyC;

    return 0;
}





