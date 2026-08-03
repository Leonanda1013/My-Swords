#include <iostream>

using namespace std;
class Employee{
public:    
    string Name;
    string Company;
    int Age;

    void IntroduceYourself(){
        cout << "Name - " << Name << " From - " << Company << " Age - " << Age << endl;
    }

    Employee(string name, string company, int age){ //this is a constructor, it is a special method that is called when an object of the class is created
        Name = name;
        Company = company;
        Age = age;
    }
};

class Encapsulation{
    private:
        string Name;
    
    public: 
        void setName(string name){ //this is a setter method, it is used to set the value of the private attribute Name
            Name = name;
        }

        string getName(){ //this is a getter method, it is used to get the value of the private attribute Name
            return Name;
        }
};

int main(){
    int number; //this is a variable of type int
    number = 10; //assigning a value to the variable

    Employee employee1("John", "Youtube", 22); //this is an object of the class Employee 
    // employee1.Name = "John"; //assigning a value to the Name attribute of employee1 
    // employee1.Company = "Youtube";
    // employee1.Age = 22;  // this is without using constructor, we can also assign values to the attributes of the object using constructor as shown below
    employee1.IntroduceYourself(); //calling the method IntroduceYourself of employee1 object

    Encapsulation obj;
    obj.setName("tio");
    cout << "Name is: " << obj.getName() << endl; //calling the getter method getName of obj object
}

