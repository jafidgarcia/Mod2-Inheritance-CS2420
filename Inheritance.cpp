#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

class Creature {
    public:
    void print();
    unsigned int getValue();
    static std::random_device rd; //used to obtain a seed for the random numnber engine 
    static std::mt19937 gen; //standard mersenne_twister_engine seeded with rd()

    // protected instead of private so inherited classes below can access
    protected:
    unsigned int value{};
    private:
};

// implentation for Creature class
std::random_device Creature::rd;
std::mt19937 Creature::gen(Creature::rd());
// std::uniform_int_distribution<> Creature::distrib(1,5);
void Creature::print(){
    cout << "The damage is: " << value << endl;
}
unsigned int Creature::getValue(){
    return value;
}
//////////////////////////////////////////////////////////////////


//  creating class Applods that inherits everything from Creature class also
class Applods : public Creature {
    public:
    Applods(); //constructor
    private:
};

// implentation for Applods class
Applods::Applods(){
   std::uniform_int_distribution<> distrib(1,5); 
   this->value = distrib(Creature::gen);
}
//////////////////////////////////////////////////////////////////


// creating class Barbles that inherits everything from Creature class also
class Barbles : public Creature {
    public:
    Barbles(); //contructor
    void print();
    unsigned int getValue();
    private:
    // Barbles will differ by having a second value plus the value inherited from Creature class
    unsigned int secondValue{};
};

// implentation for Barbles
Barbles::Barbles(){
    std::uniform_int_distribution<> distrib(1,2); 
    this->value = distrib(Creature::gen);
    std::uniform_int_distribution<> distrib2(1,3);
    this->secondValue = distrib2(Creature::gen); 
}
void Barbles::print(){
    cout << "The damage is: " << this->value << " + " << this->secondValue << endl;
}
unsigned int Barbles::getValue(){
     return this->value + this->secondValue; //25:25
}
//////////////////////////////////////////////////////////////////

class Cruds : public Creature {
    public:
    Cruds(); // constructor
    private:

};
// implementation
Cruds::Cruds(){
    std::uniform_int_distribution<> distrib(1,2); 
    this->value = distrib(Creature::gen);
    // changing the 2 to 5
    if(this->value == 2){this->value = 5;}
}

//////////////////////////////////////////////////////



int main (){
    Applods myApllods[10]; //creating 10 Applods
    Barbles myBarbles[10]; //
    Cruds myCruds[10];

    cout << "10 Applods have spawned!" << endl;
    for (int i =0; i < 10; i++){
        myApllods[i].print();
    }
    cout << "-----------------" << endl;

    cout << "10 Barbles have spawned!" << endl;
    for (int i =0; i < 10; i++){
        myBarbles[i].print();
    }
    cout << "-----------------" << endl;

    cout << "10 Cruds have spawned!" << endl;
    for (int i =0; i < 10; i++){
        myCruds[i].print();
    }

    cout << "-----------------" << endl;
    cout << "-----------------" << endl;
    cout << "Lets Battle!" << endl;

    for (int i=0; i < 10; i++){
        unsigned int a = myApllods[i].getValue();
        unsigned int b = myBarbles[i].getValue();
        unsigned int c = myCruds[i].getValue();

        if(a > b){
            if(a > c ){cout << "The Applod Won" << endl;}
            else{ cout << "The Crud Won" << endl;}
        }
        else{
            if (b > c){cout << "The Barbel Won" << endl;}
            else{cout << "The Crud Won" << endl;}
        }
    }


}