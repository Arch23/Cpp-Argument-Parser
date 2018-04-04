#include <iostream>
#include <vector>
#include <sstream> 

using namespace std;

#include "Arg.hpp"


int main(int argc, char **argv){
    Arg arg(argc,argv);

    if(arg.getOption("n").empty()){
        cout<<"name of the tour is required"<<endl;
        return(0);
    }
    if(arg.getOption("s").empty()){
        cout<<"size of the population is required"<<endl;
        return(0);
    }else{
        try {
            cout<<"name "<<arg.getOption("n")<<endl;
            cout<<"size "<<stoi(arg.getOption("s"))<<endl;

            string tmp{""},cmd{"lib"};
            if(arg.isSet(cmd)){
                tmp = arg.getOption(cmd);
                if(tmp == ""){
                    cout<<"command "<<cmd<<" needs an argument"<<endl;
                    return(0);
                }else{
                    cout<<"lib path: "<<tmp<<endl;
                }
            }
            cmd = "id";
            if(arg.isSet(cmd)){
                tmp = arg.getOption(cmd);
                if(tmp == ""){
                    cout<<"command "<<cmd<<" needs an argument"<<endl;
                    return(0);
                }else{
                    cout<<"id: "<<tmp<<endl;
                }
            }
            cmd = "lk";
            if(arg.isSet(cmd)){
                tmp = arg.getOption(cmd);
                if(tmp == ""){
                    cout<<"command "<<cmd<<" needs an argument"<<endl;
                    return(0);
                }else{
                    cout<<"LK %: "<<tmp<<endl;
                }
            }
            cmd = "np";
            if(arg.isSet(cmd)){
                tmp = arg.getOption(cmd);
                if(tmp == ""){
                    cout<<"command "<<cmd<<" needs an argument"<<endl;
                    return(0);
                }else{
                    cout<<"new pop type: "<<tmp<<endl;
                }
            }
            cmd = "nb";
            if(arg.isSet(cmd)){
                tmp = arg.getOption(cmd);
                if(tmp == ""){
                    cout<<"command "<<cmd<<" needs an argument"<<endl;
                    return(0);
                }else{
                    cout<<"n best: "<<tmp<<endl;
                }
            }
            cmd = "bf";
            if(arg.isSet(cmd)){
                tmp = arg.getOption(cmd);
                if(tmp == ""){
                    cout<<"command "<<cmd<<" needs an argument"<<endl;
                    return(0);
                }else{
                    cout<<"best fitness: "<<tmp<<endl;
                }
            }
        } catch (invalid_argument &i_a) {
            cout << "Invalid argument!" << i_a.what() << endl;
            return (0);
        }
    }

    return(0);
}
