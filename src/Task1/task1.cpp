#include <bits/stdc++.h>
using namespace std;

map<string, int> map1;
void operate(string operation, string x, string y, string z)
{
    if (operation == "add")
        map1[x] = map1[y] + map1[z];
    else if (operation == "sw")
        map1["answer"] = map1[x];
    else if (operation == "mul")
        map1[x] = map1[y] * map1[z];
    else if (operation == "sub")
        map1[x] = map1[y] - map1[z];
    else if (operation == "and")
        map1[x] = map1[y] & map1[z];
    else if (operation == "or")
        map1[x] = map1[y] | map1[z];

    else if (operation == "addi")
    {
        stringstream string_to_number(z);
        int i = 0;
        string_to_number >> i;
        map1[x] = map1[y] + i;
    }

    else if (operation == "li")
    {
        stringstream string_to_num(y);
        int i = 0;
        string_to_num >> i;
        map1[x] = i;
    }
    else if (operation == "ori")
    {
        stringstream string_to_num(z);
        int i = 0;
        string_to_num >> i;
        map1[x] = map1[y] | i;
    }
    else if (operation == "andi")
    {
        stringstream string_to_num(z);
        int i = 0;
        string_to_num >> i;
        map1[x] = map1[y] & i;
    }
}


int solve(int n, vector<string> arr){
    int answer=0;
    // Start your code here
    for (int i = 0; i < n; i++)
    {
        string temp;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == ',')
            {
                break;
            }
            else
            {
                temp = temp + arr[i][j];
            }
        }
        arr[i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        stringstream ss;
        string str = arr[i];
        ss << str;
        ss >> str;
        string operation = str;
        ss >> str;
        string contnr1 = str;
        ss >> str;
        string contnr2 = str;
        ss >> str;
        string contnr3 = str;
        operate(oper, contnr1, contnr2, contnr3);
        answer = map1["answer"];
    }
    // End your code here
    return answer;
}

//int main(){
    // int n;
    // cin>>n;
    // cin.ignore();
    // vector<string> arr(n);
    // for(int i=0;i<n;i++){
    //     getline(cin,arr[i]);
    //     cout<<arr[i]<<endl;
    // }
    // cout<<solve(n,arr);
//    return 0;
//}

// ==> NOTE: Comment main function and uncomment below line to verify your code 
#include "../../include/test1_cases.h"
