#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**************************************
To-do:

1) Preprocessing of tags and attributes

**************************************/

typedef struct attributes{
    string value; // Value of attribute
    string parent; // Parent object for the attribute
}attribute;

typedef struct tags{
    struct tags* next; // Linked tags
    string name; // Tag identifier
    vector<string> att_list; // List of attributes
    bool closed = false;
    vector<attribute*> att_pntr; // Addresses of attribute data types
}tag;

void struct_check(tag& tagged){
    /* Tested Successfully */
    if (&tagged != NULL){
        cout << "Tag Name: " << tagged.name << '\n';
        for(int i = 0; i < tagged.att_list.size(); i++){
            attribute temp = *(tagged.att_pntr[i]);
            cout << "----> " << tagged.att_list[i] << " = " << temp.value << '\n';
        }
        cout << endl;
    }
    if (tagged.next != NULL){
        struct_check(*tagged.next);
    }
    else{
        return;
    }
}

void syntax_decode(string syntax, int& att_count, bool& close, string& tag_name, vector<string>& att_list, vector<string>& att_value){
    // Restarting parameters
    int i = 1; att_count = 0; close = false; tag_name = ""; att_list.clear(); att_value.clear();

    if (syntax[1] == '/'){
        close = true;
        for (i = 2; syntax[i] != '>'; i++)
            tag_name.push_back(syntax[i]);
        return;
    }
    for (i = 1; syntax[i] != '>' && syntax[i] != ' '; i++)
        tag_name.push_back(syntax[i]);

    vector<string> preprocess; int j = 0, last = 5, next = 0;
    while ((next = syntax.find(' ', last)) != string::npos) {
        preprocess.push_back(syntax.substr(last, next - last));
        cout << preprocess[j] << endl;
        last = next + 1;
        j++;
    }
    next = syntax.find('>', last);
    preprocess.push_back(syntax.substr(last, next - last));
    cout << preprocess[j] << '\n';
    for (int k = 0; k + 1 < preprocess.size(); k++){
        if (preprocess[k + 1] == "="){
            att_list.push_back(preprocess[k]);
            att_value.push_back(preprocess[k + 2]);
        }
    }

    for (i; i < syntax.length(); i++)
        if (syntax[i] == '=')
            att_count++;
}

int main(void){

    // tag tag1;
    // tag1.name = "tag1";
    // tag1.att_list.push_back("value");
    // attribute value;
    // value.value = "HelloWorld";
    // value.parent = "tag1";
    // tag1.att_pntr.push_back(&value);
    //
    // tag tag2;
    // tag2.name = "tag2";
    // tag2.att_list.push_back("name");
    // attribute name;
    // name.value = "Name1";
    // name.parent = "tag2";
    // tag2.att_pntr.push_back(&name);
    // tag1.next = &tag2;
    // tag2.next = NULL;
    int n = 0, q = 0;
    cin >> n >> q;

    string input;
    int att_count = 0; bool close = false; string tag_name; int tag_count = 0;
    vector<string> att_list; vector<string> att_value;
    vector<tag> tag_list;
    tag tag1, tag2;
    getline(cin, input); // To prevent the function to ignore the enter pressed after entering 'n' and 'q'
    for (int i = 0; i < n && getline(cin, input); i++){
        cout << '\n';
        syntax_decode(input, att_count, close, tag_name, att_list, att_value);
        cout << "No. of attributes: " << att_count << '\n';
        cout << "It is a closing tag: " << close << '\n';
        cout << "Name of the tag: " << tag_name << '\n';
        for (int i = 0; i < att_list.size(); i++)
            cout << att_list[i] << " ----> " << att_value[i] << '\n';
        if (!close){
            if (tag_count == 0){
                tag1.name = tag_name;
                for (int i = 0; i < att_list.size(); i++){
                    tag1.att_list.push_back(att_list[i]);
                    tag1.closed = false;
                    attribute value;
                    value.value = att_value[i];
                    value.parent = tag_name;
                    tag1.att_pntr.push_back(&value);
                }
                tag_list.push_back(tag1);
                tag_count++;
            }
            else if (tag_list[tag_count - 1].closed == false){
                tag2.name = tag_name;
                for (int i = 0; i < att_list.size(); i++){
                    tag2.att_list.push_back(att_list[i]);
                    tag2.closed = false;
                    attribute name;
                    name.value = att_value[i];
                    name.parent = tag_name;
                    tag2.att_pntr.push_back(&name);
                    tag2.next = NULL;
                }
                tag2.att_list.push_back("name");
                attribute name;
                name.value = "Name1";
                name.parent = "tag2";
                tag2.att_pntr.push_back(&name);
                tag1.next = &tag2;

            }
            // if current tag is not closed
                // Link to it and add atrributes
            // If current tag is closed add a new tag to the List
                // Add its attributes
        }
        else{
            // Close the current tag
        }
    }

    return 0;
}
