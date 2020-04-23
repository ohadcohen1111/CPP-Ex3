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
        string rel = "";

    public:
        //constructor
        Node(string name)
        {
            this->name = name;
            this->father = NULL;
            this->mother = NULL;
            this->gender = "";
            this->level = 1;
            this->rel = "";
        }

        //get
        Node * getFather(){return this->father;};
        Node * getMother(){return this->mother;};
        string getName(){return this->name;};
        string getGender(){return this->gender;};  
        int getLevel(){return this->level;};
        string getRel(){return this->rel;};  


        //set
        void setName(string name){this->name = name;};
        void setFather(Node * father){this->father = father;};
        void setMother(Node * mother){this->mother = mother;};
        void setLevel(int level){this->level = level;};
        void setGender(string gender){this->gender = gender;};
         void setRel(string s){this->rel = s;};
        void setRel(string g, int level)
        {  
            if ( g == "M" && level == 2 )
            {
                this->rel = "father";
                return;
            }else if (level == 2)
            {
                this->rel =  "mother";
                return;
            }
            else if(g != "M" && g != "F"){
                throw runtime_error("not exists");
            }
            string res= "";
            while (level-- >3)
            {
                res+="great-";
            }
            if ( g == "M")
            {
                res+="grandfather";
                rel=res;
                return;
            }
            res+="grandmother";
            rel=res;  
   
        }   
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
        Node * Help(Node * root, string name, int level);
        Node * relationHelp(Node * n, string name);
        string find(string name);
        void display();
        void display(Node * root);
        void remove(string name);
    };
};