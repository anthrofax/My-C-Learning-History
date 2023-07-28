#include <iostream>
using namespace std;

int x = 10; //Variable global

int ambil_global() {
    return x; //Mengambil variable global
}

int x_local() {
    int x = 5; //variabel local scope
    return x;
}

int main() {
    cout<<"1. Variable global : " << x <<endl;
    int x = 8;
    cout<<"2. Variable local_main : " << x <<endl;
    cout<<"3. Variable ambil_global : " << ambil_global()<<endl;
    cout<<"4. Variable local_main : " << x <<endl;
    cout<<"5. Variable x_local : " << x_local() <<endl;
    cout<<"6. Variable local_main : " << x <<endl;

    cout<<"7. Variable local_main : " << x <<endl;
    {
        cout<<"8. Variable local_main : " << x <<endl;
            int x = 1;
        cout<<"9. Variable local_block : " << x <<endl;
        cout<<"10. Variable global (dengan cara lain) : " << ::x <<endl;
    }
    cout<<"11. Variable local_main : " << x <<endl;
    return 0;
}