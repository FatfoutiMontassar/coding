#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tab[4] = {1,2,3,4} ;
    do{
        for(int i = 0 ; i < 4 ; i++)cout << tab[i] << ' ' ; cout << endl;

    }while(next_permutation(tab,tab+4)) ;
    return 0;
}
