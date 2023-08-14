#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Entity
{
public:
    Entity()
    {
        cout << "Created Entity!" << endl;
    }

    ~Entity()
    {
        cout << "Destroyed Enitity" << endl;
    }

    void Print(){
        cout << "Hello unique pointer" << endl;
    }
};

int main()
{
    {
        shared_ptr<Entity> e0;
        {
            // That will create a unique point. UNique pointer represent exclusive ownership
            // when we use it new on unique ptr we prevent to raise a exception, but it's not mandatory
            //unique_ptr<Entity> entity(new Entity());


            // That will create a shared pointer
            // The difference between this implementation and the new that I used before it's 
            // when we use new, the compiler create a block of memory called control block where store that reference count 
            shared_ptr<Entity> sharedEntity = make_shared<Entity>();
            e0 = sharedEntity;


            // this is also some sort of copy, like shared ptr, but we don't have the ownership of the pointer
            // So, it's only be avaible if the sharedEntity still is avaiable.
            weak_ptr<Entity> weakEntity = sharedEntity;
        }

        // when all the reference die, the pointer die too
        e0->Print();
    }
    

    cin.get();
}

