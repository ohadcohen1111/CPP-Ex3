#include "FamilyTree.hpp"

using namespace family;


Tree :: Tree(string name)
{
    root = new Node(name);
}

Tree &Tree :: addFather(string child, string father)
{
    Node * n = findNode(root, child);

    if (n != NULL)
    {
        if(n->getFather() == NULL)
        {
            Node * f = new Node(father);
            f->setGender("M");
            n->setFather(f);
            return *this;
        }
        throw runtime_error("already have a father");
    }
        throw runtime_error("the child doesnt exists");
}

Tree &Tree :: addMother(string child, string mother)
{
    Node * n = findNode(root, child);

    if (n != NULL)
    {
        if(n->getMother() == NULL)
        {
            Node * m = new Node(mother);
            m->setGender("F");
            n->setMother(m);
            return *this;
        }
        throw runtime_error("already have a mother");
    }
        throw runtime_error("the child doesnt exists");
}

Node * Tree :: findNode(Node * n, string name)
{
    if(n == NULL)
    {
        return NULL;
    }

    if(n->getName() == name)
    {
        return n;
    }


    Node * father = findNode(n->getFather(), name);

    if(father != NULL)
    {
        return father;
    }
    return findNode(n->getMother(), name);
}

string Tree :: relation(string name)
{
    if(root->getName() == name)
    {
        return "me";
    }

    if(root->getFather() != NULL && root->getFather()->getName() == name)
    {
        return "father";
    }

    if(root->getMother() != NULL && root->getMother()->getName() == name)
    {
        return "mother";
    }
    
    Node * n = relationHelp(root, name, 0);

    if(n == NULL)
    {
        return "unrelated";
    }

    int level = n->getLevel();
    // int sign = 0;
    // if(level < 0)
    // {
    //     sign = 1;
    //     level = ((-1) * level);
    // }

    string ans = "";
    while(level-- > 3)
    {
        ans += "great-";
    }
    if(n->getGender() == "F")
    {
        ans += "grandmother";
    }
    else
    {
        ans += "grandfather";
    }

    return ans; 
}

Node * Tree :: relationHelp(Node * root, string name, int level)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->getFather() == NULL && root->getMother() == NULL)
    {
        if(root->getName() == name)
        {
            root->setLevel(level + 1); 
            
            return root;
        }
        return NULL;
    }

    if(root->getName() == name)
    {
        root->setLevel(level + 1);
        return root;
    }

    Node * father = relationHelp(root->getFather(), name, level + 1);

    if(father != NULL)
    {
        return father;
    }
    return relationHelp(root->getMother(), name, level + 1);
}


 string Tree :: find(string name)
 {
     int size = getSize(root);
     string s [size];
     fillArray(root, s);

    for (size_t i = 0; i < size; i++)
    {
        string rel = this->relation(s[i]);
            if(rel == name)
            {
                return s[i];
            }
    }
    throw runtime_error("No such a " + name);
 }

static int place = 0;

 string * Tree :: fillArray(Node * root, string * s)
 {
    if(root != NULL)
    {
        fillArray(root->getFather(), s);
        s[place++] = root->getName();
        fillArray(root->getMother(), s);
    }
    return s;
 }


int Tree :: getSize(Node * root)
{  
    if (root == NULL)
    {
        return 0;  
    }
    else
    {
        return(getSize(root->getFather()) + 1 + getSize(root->getMother()));  
    }
} 




void Tree :: display()
{
    display(root);
}

void Tree :: display(Node * root)
{
     if(root != NULL)
    {
        display(root->getFather());
        cout << root->getName() << endl;
        display(root->getMother());
    }
    return;
}

int main()
{
    Tree T ("Shalom");
    T.addFather("Shalom", "Aharon").addMother("Shalom", "Yafa");
    T.addMother("Yafa", "Ahuva").addMother("Ahuva", "Miriam");
    T.addFather("Miriam", "Moshe");

    T.display();
    cout << endl;
    //cout << T.relation("Ahuva") << endl;
    cout << T.find("great-great-grandfather") << endl;
}



