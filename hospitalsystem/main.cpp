#include <bits/stdc++.h>
using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

string names[MAX_SPECIALIZATION+1][MAX_QUEUE+1];
int status[MAX_SPECIALIZATION+1][MAX_QUEUE+1];
int queue_length[MAX_SPECIALIZATION+1];

void shift_right(int spec){
    int n=queue_length[spec];
    for (int i=n-1;i>=0;i--){
        names[spec][i+1]=names[spec][i];
        status[spec][i+1]=status[spec][i];
    }
    queue_length[spec]++;
}

void shift_left(int spec){
    int n=queue_length[spec];
    for (int i=0;i<n-1;i++){
        names[spec][i]=names[spec][i+1];
        status[spec][i]=status[spec][i+1];
    }
    queue_length[spec]--;
}

bool add(){
    cout<<"enter patient specialization & name & status\n";
    int spec ,stat;
    string name;
    cin>>spec>>name>>stat;
    int pos = queue_length[spec];
    if (pos >= MAX_QUEUE){
        cout<<"sorry we cant accept patients for this specialization\n";
        return false;
    }
    if (!stat){
        names[spec][pos]=name;
        status[spec][pos]=stat;
        queue_length[spec]++;
    }
    else {
        shift_right(spec);
        names[spec][0]=name;
        status[spec][0]=stat;
    }
    return true;
}

void print_patient(int spec, string names_sp[], int status_sp[]) {
    int len = queue_length[spec];
    if (len == 0)
        return;

    cout << "There are " << len << " patients in specialization " << spec << "\n";
    for (int i = 0; i < len; ++i) {
        cout << names_sp[i] << " ";
        if (status_sp[i])
            cout << "urgent\n";
        else
            cout << "regular\n";
    }
    cout << "\n";
}

void print_patients() {
    cout << "****************************\n";
    for (int spec = 0; spec < MAX_SPECIALIZATION; ++spec) {
        print_patient(spec, names[spec], status[spec]);
    }
}

void get_next_patient(){
    cout<<"enter specialization\n";
    int sp;
    cin>>sp;
    int n=queue_length[sp];
    if (n==0)cout<<"no patients waiting for this specialization\n";
    else{
        cout<<names[sp][0]<<" please go with the Dr\n";
        shift_left(sp);
    }
}

int choices(int &x){
    while(x==-1){
        cout<<"enter your choice:\n";
        cout<<"1) add new patient\n";
        cout<<"2) print all patients\n";
        cout<<"3) get next patient\n";
        cout<<"4) exit\n";
        int z;
        cin>>z;
        if (z>0 && z<5)x=z;
        else x=-1;
    }
}

void run(){
    while(true){
        int choice=-1;
        choices(choice);
        if (choice==1)
            add();

        else if (choice==2)
            print_patients();

        else if (choice==3)
            get_next_patient();

        else break;
    }
}

int main() {

    run();

    return 0;
}
