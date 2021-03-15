#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
namespace items{   //the items(the means that all the items of the catalog)
   
const std::vector<std::string> Base{" : ","\" \"","___","   ",};
const std::vector<std::string> Torso{" : ","] [","> <","   ",};
const std::vector<std::string> Right_Arms_Down {">"," ","\\"," ",};
const std::vector<std::string> Right_Arms_Up {" ","/"," "," ",};
const std::vector<std::string> Left_Arms_Down {"<"," ","/"," ",};
const std::vector<std::string> Left_Arms_Up {" ","\\"," "," ",};
const std::vector<std::string> Eye {".","o","O","-",};
const std::vector<std::string> Nose_Mouth{",",".","_"," ",};
const std::vector<std::string> Hats  = {"     \n _===_"," ___ \n .....","  _  \n  /_\\ "," ___ \n (_*_)",};

}

using namespace std;
namespace ariel
{
vector<int> check_legal(int num){ //check if the number is in the range
    vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 0}; // init
    int digit = 0;
    const int minimum = 1;
    const int maximum = 4;    
    const int length = 8;
    const int res = 10;

for (int i = 0; i < length; i++)
    {
        digit =(num % res);
        if (digit > maximum || digit < minimum){    //digit < 0 || digit > 4
		throw std::out_of_range{"Illegal- out of range!"};       //exception
        }
        digit--;
        arr.at(length-1-i) = digit; // digit = arr[7-0] --> digit = arr[6-1]
        
        num = num / res;
    }
    return arr;
}

string  snowman(int num)
{
    //define const nummbers
    const int minimum = 10000000; // the small number
    const int maximum = 99999999; // the bigest number
    const int length = 8;
    const int B = 7;
    const int T = 6;
    const int Y = 5;
    const int X = 4;
    const int R = 3;
    const int L = 2;
    const int N = 1;
    const int H = 0;
    
    


   if (num < minimum || num > maximum){
    throw std::out_of_range{"Illegal- out of range!"};
    }

    
     vector<int> arr = check_legal(num);

    std::string ans = " "; // init enmpty string

                              //the build
                             //                  HHHHH
                            //                  X(LNR)Y
                           //                   X(TTT)Y
                          //                     (BBB)

        //hats:
                      //  HHHHH
                      //  HHHHH
    ans.append(items::Hats.at(arr.at(H)));
    ans.append("\n");

        //arms up, noise, eyes(right/left):

                     //X(LNR)Y
    ans.append(items::Left_Arms_Up.at(arr.at(X)));
    ans.append("(");   
    ans.append(items::Eye.at(arr.at(L)));
    ans.append(items::Nose_Mouth.at(arr.at(N)));
    ans.append(items::Eye.at(arr.at(R)));
    ans.append(")");
    ans.append(items::Right_Arms_Up.at(arr.at(Y)));
    ans.append("\n");
    
        //arms down,torso: 
                    // X(TTT)Y
    ans.append(items::Left_Arms_Down.at(arr.at(X)));
    ans.append("(");
    ans.append(items::Torso.at(arr.at(T)));
    ans.append(")");
    ans.append(items::Right_Arms_Down.at(arr.at(Y)));
    ans.append("\n");       
    
        //base:
                    //(BBB)
    ans.append("(");
    ans.append(items::Base.at(arr.at(B)));
    ans.append(")");

    return ans;
}

}