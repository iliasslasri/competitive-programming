#include <iostream>
#include <map>
#include <array>

using namespace std;

int main() {
    int N ,B;
    cin >> N >> B;
    array<bool, 16> state{0};

    for(int i=0; i<N; i++){
        cin >> state[i];
    }

    map<array<bool, 16>, int> mem;
    map<array<bool, 16>, int> mem_notfound;
    int x = 0;

    array<bool, 16> state_start;
    array<bool, 16> temp_state;
    for(int i=0; i<N; i++){
        state_start[i] = state[i];
    }
    bool ending = false;
    for (int b=0; b< B; b++){
        if(ending){
                       for(int i=0; i<N; i++){
                temp_state[i] = state[i];
            }
            for(int i=1; i<N; i++){
                if(temp_state[i-1]){
                    if (state[i])
                        state[i] = 0;
                    else state[i] = 1; 
                }
            }
            if(temp_state[N-1]){
                    if (state[0])
                        state[0] = 0;
                    else state[0] = 1; 
            }
        } else {
        auto search = mem.find(state);
        if (search != mem.end()){
            if(b + search->second < B){
                    b+=search->second;
            } else {ending = true;}
        } else {
            for(auto &k : mem_notfound) {
                k.second += 1;
            }
            auto search = mem_notfound.find(state);
            if(search == mem_notfound.end()){
                mem_notfound.insert({state, 0});
            } else{
                mem.insert({state, search->second});
                if(b + search->second < B){
                    b+=search->second;
                } else {ending = true;}
            }
            for(int i=0; i<N; i++){
                temp_state[i] = state[i];
            }
            for(int i=1; i<N; i++){
                if(temp_state[i-1]){
                    if (state[i])
                        state[i] = 0;
                    else state[i] = 1; 
                }
            }
            if(temp_state[N-1]){
                    if (state[0])
                        state[0] = 0;
                    else state[0] = 1; 
            }
        }
    //         for(int i=0; i<N; i++){
    //     cout << state[i] << ' ' ;
    // }
    // cout <<endl;
        }
}


    for(int i=0; i<N; i++){
        cout << state[i] <<endl;
    }
    return 0;
}