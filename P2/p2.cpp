#include <iostream>
#include <vector>
using namespace std;

void numToVec(long long num, vector<int> &vec)
{
    vec.clear();       
    while (num > 0) {
        vec.push_back(num % 10);
        num /= 10;
    }
}

bool valid(vector<int> vec)
{
    int validCount = 0; 
    for(int i = 1; i <= vec.size()/2; i++)
    {
        if(vec.size()%i != 0) 
        {
            validCount++; 
            continue; 
        }  
        int base = i; 
        for(int k = 0; k < vec.size()/i; k++)
        {
         if(vec[k] != vec[(k+base)])
         {
            validCount++ ; 
            break; 
         } 
        }
    }
    return validCount == vec.size()/2;
}

int main() {
    long long lowerBound;
    long long upperBound;
    char dash;
    char comma;

    vector<int> lb_vec;
    vector<int> ub_vec;
    long long invalidSum = 0; 

    while (cin >> lowerBound >> dash >> upperBound) {

     
        while(lowerBound <= upperBound)
        {
            numToVec(lowerBound, lb_vec);
            numToVec(upperBound, ub_vec);
            if(!valid(lb_vec)) 
            {
                invalidSum +=lowerBound;
                cout << lowerBound << "\n";  
            }
            lowerBound++; 
        }

        cin >> comma;

    }

    cout << invalidSum << "\n"; 
}
