#include "Arg.hpp"

#include <sstream>

Arg::Arg(int argc, char **argv):argc(argc),argv(argv){}

void Arg::newArgument(string arg, bool required, string alias ){
    arguments.push_back(Argument(arg, alias, required));
}

void Arg::validateArguments(){
    processInput();
    bool error{false};
    string errorMsg{""};
    for(Argument a : arguments){
        if(a.getRequired() && a.getOption().empty()){
            if(error){
                errorMsg += "\n";
            }
            error = true;
            errorMsg += "Required argument: "+a.getArg();
        }
    }
    if(error){
        throw std::runtime_error(errorMsg);
    }
}

void Arg::processInput(){
    vector<string> argVector;
    bool error{false};
    string errorMsg{""};

    for(int i=1;i<argc;i++){
        string arg = argv[i];
        if(arg[0] == '-'){
            arg.erase(0,1);
            argVector.push_back(arg);
        }else{
            argVector.back() += " ";
            argVector.back() += arg;
        }
    }
    
    for(string arg : argVector){
        vector<string> argSplited = split(arg);
        Argument *a = getArgument(argSplited[0]);
        if(a==nullptr){
            if(error){
                errorMsg += "\n";
            }
            error = true;
            errorMsg += "Unexpected argument: "+argSplited[0];
        }
        string option;
        for(unsigned i=1;i<argSplited.size();i++){
            option += argSplited[i];
            if((++i)<argSplited.size()){
                option += " ";
            }
        }
        a->setOption(option);
        a->setArg(true);
    }
    if(error){
        throw std::runtime_error(errorMsg);
    }
}

Arg::Argument* Arg::getArgument(string arg){
    for(Argument &a : arguments){
        if(a.getArg() == arg || a.getAlias() == arg){
            return(&a);
        } 
    }
    return(nullptr);
}

bool Arg::isSet(string arg){
    Argument *a = getArgument(arg);
    if(a!=nullptr){
        return(a->isSet());
    }
    return false;
}

string Arg::getOption(string arg){
    Argument *a = getArgument(arg);
    if(a!=nullptr){
        return(a->getOption());
    }
    return {};
}

vector<string> Arg::split(const string s, char c) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, c)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}