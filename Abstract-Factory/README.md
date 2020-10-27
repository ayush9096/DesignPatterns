## Abstract Factory Pattern

It is a Creational Design Pattern that lets one produce families of related objects without specifying there concrete classes.

### Example : Business Requirement

* Creating a Distributor Simulator having family of related products ProductA, ProductB, ProductC (like Aata, Besan and Maida )
* Several variants are available for this family : Manufactured from CompanyA, CompanyB, CompanyC
* Create individual product objects so that they match other objects of same family


### Usage

* Use Abstract Factory when ones code needs to work with various families of related product, but one don't want it to depend on the concrete classes of those products.
* A system should be independent of how its products are created, composed and represented
* A system should be configured with one of multiple families of product
* A family of related product objects is designed to be used together
* One wants to provide a class library of products, and want to reveal their interfaces and not their implementations.


