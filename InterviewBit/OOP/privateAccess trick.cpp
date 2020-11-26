//g++  7.4.0
//Are private functions really private? Well...


// without using virtual keyword

#include <bits/stdc++.h>
using namespace std;

class SocialWebsite{
    private:
    protected:
    public:
};

class Facebook : public SocialWebsite{
    private:
        string fbPassword;
        
        void secret(){
            cout << "The Fb Password is:" << fbPassword << endl;
            cout << "Its risky, but its fine to print as its a private function";
        }
    
    public:
        Facebook(string pwd)
        {
            fbPassword = pwd;
        }
};

int main()
{
    Facebook f("MyPassword");
    f.secret();
}

/*
Compilation time: 1.23 sec, absolute service time: 1,32 sec
Error(s):
362344927/source.cpp: In function ‘int main()’:
362344927/source.cpp:32:14: error: ‘void Facebook::secret()’ is private within this context
     f.secret();
              ^
362344927/source.cpp:17:14: note: declared private here
         void secret(){
              ^~~~~~
*/

// with using virtual keyword

#include <bits/stdc++.h>
using namespace std;

class SocialWebsite{
    private:
    protected:
    public:
        virtual void secret() {}
};

class Facebook : public SocialWebsite{
    private:
        string fbPassword;
        
        void secret(){
            cout << "The Fb Password is:" << fbPassword << endl;
            cout << "Its risky, but its fine to print as its a private function";
        }
    
    public:
        Facebook(string pwd)
        {
            fbPassword = pwd;
        }
};

int main()
{
    Facebook f("MyPassword");
    //f.secret();
    SocialWebsite *ptr = &f;
    ptr->secret();
}

/*

Compilation time: 1.42 sec, absolute running time: 0.14 sec, cpu time: 0 sec, memory peak: 5 Mb, absolute service time: 1,76 sec

The Fb Password is:MyPassword
Its risky, but its fine to print as its a private function

*/