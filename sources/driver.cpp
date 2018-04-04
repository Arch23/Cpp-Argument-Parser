#include <iostream>
#include <vector>
#include <sstream> 
#include <stdexcept>

using namespace std;

#include "Arg.hpp"


int main(int argc, char **argv){
    Arg arg(argc,argv);
    string name,occupation;
    int age;
    bool newRecord;

    arg.newArgument("name",true);
    arg.newArgument("age",true);
    arg.newArgument("occupation",false,"oc");
    arg.newArgument("new");

    try{
        arg.validateArguments();
    }catch(std::runtime_error e){
        std::cout<<e.what()<<endl;
        return(0);
    }
    
    name = arg.getOption("name");
    age = stoi(arg.getOption("age"));
    occupation = (arg.getOption("occupation").empty()?("unemployed"):(arg.getOption("occupation")));
    newRecord = arg.isSet("new");

    cout<<"name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"occupation: "<<occupation<<endl;
    cout<<"new? "<<newRecord<<endl;

    return(0);
}