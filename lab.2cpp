#incldue <iostream>
using namespace std;

class dog()
{

    public: 
        string name;
        int weight;
        string type;

    
   void setBreed(string breed)
    {
        type = breed;
    }
    void setWeight(int w)
    {
        if(w < 0) 
        {
            cout << "You cant do that!!" << endl;
            weight = 0;
        }
        else
        {
            w = weight;
        }
    }

    void speak()
    {
        cout << "I'm a " << weight << " lb " << type << endl; 
    }

    void feed()
    {

    }
}
int main()
{
    //Make some constructors
	dog bonny;
	dog wimpy;
	dog fido("rottweiler", 200);
	dog snuffles(15);

	//A "setter" method
	bonny.setBreed("pit bull");
	bonny.setWeight(500);

	//Don't let the user set weight to something dumb...
	wimpy.setWeight(-300);

	//cout information about the dog in the speak method
	bonny.speak(); //I'm a 500 lbs pit bull
	wimpy.speak(); //I'm a 0 lbs mutt
	fido.speak();  //I'm a 200 lbs rottweiler
	snuffles.speak(); //I'm a 15 lbs mutt

	//feed the dog food to increase it's weight
	fido.feed(20);
	fido.speak(); //I'm a 220 lbs rottweiler

	bonny.feed(40);
	bonny.speak(); //I'm a 540 lbs pit bull

	//Freaky dog day
	bonny.switchBodies(fido);

	bonny.speak(); //I'm a 220 lbs rottweiler
	fido.speak();  //I'm a 540 lbs pit bull

}