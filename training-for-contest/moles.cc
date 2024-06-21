#include <iostream>

using namespace std;

int main(){

	int R, C;
	cin >> R >> C;
	char grid[R][C];
	int s=0;
	for (int i=0; i<R; i++){
		for (int j=0; j<C; j++){
			cin >> grid[i][j];
		}
	}

	for (int i=0; i<R; i++){
		for (int j =0; j< C; j++){
			if(grid[i][j] == '#'){
				s+=1;
				grid[i][j]='.';
				if(i==0){
					if(j==0){
						if(grid[i+1][j] == '#'){
							grid[i+1][j] = '.';
						} else if(grid [i][j+1] == '#'){
							grid[i][j+1] = '.';
						}
					} else if( j==C-1){
						if(grid[i+1][j] == '#'){
							grid[i+1][j] = '.';
						}
					} else 
					{ 	if(grid[i][j+1] == '#'){
							grid[i][j+1] = '.';
						} else if( grid[i+1][j] == '#'){
							grid[i+1][j] = '.';
						}
					}
				} else if( i == R-1){

					if( j==0){
						if(grid[i][j+1] == '#'){
							grid[i][j+1] = '.';
						}
					} else {
						if(grid[i][j+1] == '#'){
							grid[i][j+1] = '.';
						} else if(grid[i-1][j] == '#'){
							grid[i-1][j] = '.';
						}
					}
				} else {
					if(j==0){
						if(grid[i][j+1] == '#'){
							grid[i][j+1] = '.';
						} else if(grid[i+1][j] == '#'){
							grid[i+1][j] = '.';
						} 
					} else if(j==C-1){
						 if(grid[i+1][j] == '#'){
							grid[i+1][j] = '.';
						}
					} else {
						if(grid[i][j+1] == '#'){
							grid[i][j+1] = '.';
						} else if(grid[i+1][j] == '#'){
							grid[i+1][j] = '.';
						} else if(grid[i][j-1] == '#'){
							grid[i][j-1] = '.';
						} else if(grid[i-1][j] == '#'){
							grid[i-1][j] = '.';
						} 

					}
				}
			}
		}
	}

	cout << s << endl;
	return 0;
}