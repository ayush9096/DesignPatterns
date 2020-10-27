/*
 * Design Pattern : Builder
 * Creational Design Pattern
 * Author : Ayush Agarwal [https://github.com/ayush9096]
 * 
 */


/*
 * Problems Solved :
 * Object of Order Class are Immutuable
 * Builder Pattern to solve problem of Telescopic Constructor
 *
 */


#include <iostream>

using namespace std;



class Order{

    public:

        class Material{

            public:

                Material(){}
                ~Material(){}
                
                Material* addMaterialA(){
                    materialA = "A";
                    return this;
                }

                Material* addMaterialB(){
                    materialB = "B";
                    return this;
                }

                Material* addMaterialC(){
                    materialC = "C";
                    return this;
                }

                Material* addMaterialD(){
                    materialD = "D";
                    return this;
                }

                string getMaterialA(){
                    return materialA;
                }

                string getMaterialB(){
                    return materialB;
                }

                string getMaterialC(){
                    return materialC;
                }

                string getMaterialD(){
                    return materialD;
                }

                Order* build(){
                    return new Order(this);
                }

            private:

                string materialA;
                string materialB;
                string materialC;
                string materialD;
        };

        // Added static Method for creating Inner Class Object, since class can't be static
        // and wanted to access Material class before creating object of Order class
        static Material* setAllMaterial(){
            return new Material();
        }

        void getProduct(){
            cout << " MaterialA : " << materialA << "\n MaterialB : " << materialB << "\n MaterialC : " << materialC << "\n MaterialD : " << materialD << "\n";
        }

        ~Order(){}

        
    private:

        Order(Material* m){
            this->materialA = m->getMaterialA();
            this->materialB = m->getMaterialB();
            this->materialC = m->getMaterialC();
            this->materialD = m->getMaterialD();
        }



        string materialA;
        string materialB;
        string materialC;
        string materialD;
};



// Client Code

int main(){

    Order *checkOrder = Order::setAllMaterial()->addMaterialA()->addMaterialB()->addMaterialC()->addMaterialD()->build();
    checkOrder->getProduct();

    delete checkOrder;
    return 0;
}
