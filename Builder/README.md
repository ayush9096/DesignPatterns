## Builder Pattern

It is a Creational Design Pattern that lets one construct complex objects step by step. The pattern allows one to produce different types and representation of an object using the same construction code. Relationships can be changed at run-time and are more dynamic.

### Usage

* One can use Builder Pattern to get rid of a "telescopic constructor"
* One can use the Builder Pattern when one want the code to be able to create different representation of some product. Here the base Builder interface define all possible construction steps, and concrete builders implement these steps to construct particular representation of the product. The Director class guides the order of construction.
* One can use Builder to construct Composite Trees or other complex objects.



