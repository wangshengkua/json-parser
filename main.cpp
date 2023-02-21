#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

#include "json.h"

using namespace yazi::json;

int main(){
    ifstream fin("./test.json");
    stringstream ss;
    ss<<fin.rdbuf();
    const string & str = ss.str();
    Json v;
    v.parse(str);
    int total = v["code"];

	return 0;
}