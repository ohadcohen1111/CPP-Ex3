#include <iostream>
#include <string>

using namespace std;
namespace family
{
    class Node
    {
    private:
        string name;
        Node * father;
        Node * mother;
        string gender;
        int level;

    public:
        //constructor
        Node(string name)
        {
            this->name = name;
            this->father = NULL;
            this->mother = NULL;
            this->gender = "";
            this->level = 0;
        }

        //get
        Node * getFather(){return this->father;};
        Node * getMother(){return this->mother;};
        string getName(){return this->name;};
        string getGender(){return this->gender;};  
        int getLevel(){return this->level;};

        //set
        void setName(string name){this->name = name;};
        void setFather(Node * father){this->father = father;};
        void setMother(Node * mother){this->mother = mother;};
        void setLevel(int level){this->level = level;};
        void setGender(string gender){this->gender = gender;};
    };

class Tree
    {
    private:
        Node * root;
        
    public:
        Tree(string name);
        Tree &addFather(string child, string father);
        Tree &addMother(string child, string mother);
        Node * findNode(Node * n, string name);
        string relation(string name);
        Node * relationHelp(Node * root, string name, int level);
        string find(string name);
        void display();
        void display(Node * root);
        void remove(string name);
    };


};