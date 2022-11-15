#include <iostream>
#include "ForwardList.h"

int main()
{
    ForwardList<int> flist;
    flist.Add(100);
    flist.Add(200);
    flist.Add(300);
    flist.Add(400);
    flist.Add(500);

    //flist.Insert(10, 1000);

    std::cout << flist << "\n";
    std::cout << "remove value: " << flist.Remove(10) << "\n";
    std::cout << flist << "\n";


    //for(int i = 0; i < flist.Size(); i++)
    //    std::cout << flist.At(i) << " ";
}
