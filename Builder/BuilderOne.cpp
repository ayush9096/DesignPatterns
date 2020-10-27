/*
 * Design Pattern : Builder
 * Creational Design Pattern
 * Author : Ayush Agarwal [https://github.com/ayush9096]
 * 
 */

#include <iostream>
#include <string>

using namespace std;


// Final Product
class Product{
    public:

        void addMaterialA(const string &material){
            materialA = material;
        }

        void addMaterialB(const string &material){
            materialB = material;
        }

        void addMaterialC(const string &material){
            materialC = material;
        }

        void productMaterial(){
            cout << "Material Used : " << materialA << ", " << materialB << ", " << materialC << " \n";
        }

    private:
        string materialA;
        string materialB;
        string materialC;
};


// Builder Abstract Interface
class Builder{
    public: 
        virtual ~Builder(){};

        virtual void buildPartA() = 0;
        virtual void buildPartB() = 0;
        virtual void buildPartC() = 0;

        Product getProduct(){
            return product;
        }
    
    protected:

        Product product;

};


class ConcreteBuilderOne : public Builder{

    public:

        void buildPartA(){
            product.addMaterialA(" One-A ");
        }

        void buildPartB(){
            product.addMaterialB(" One-B ");
        }

        void buildPartC(){
            product.addMaterialC(" One-C ");
        }
};


class ConcreteBuilderTwo : public Builder{

    public:

        void buildPartA(){
            product.addMaterialA(" Two-A ");
        }

        void buildPartB(){
            product.addMaterialB(" Two-B ");

        }

        void buildPartC(){
            product.addMaterialC(" Two-C ");
        }
};


// Director class

class Director{

    public:
        Director() : builder() {}

        ~Director(){
            if (builder)
                delete builder;
        }

        void assignBuilder(Builder *b){
            
            if(builder)
                delete builder;
            
            builder = b;
        }

        void build(){
            builder->buildPartA();
            builder->buildPartB();
            builder->buildPartC();
        }

        Product getProduct(){
            return builder->getProduct();
        }

    private:
        Builder *builder;
};


// Client Code

int main(){

    Director d;
    d.assignBuilder(new ConcreteBuilderOne());
    d.build();
    

    Product product = d.getProduct();
    product.productMaterial();
    
    return 0;
}