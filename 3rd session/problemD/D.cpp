#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int sizePattern, sizeSong ;
int pattern [10], song[20001], curPattern[10] ;

bool doMatch(int pos) { // O(sizePattern × log(sizePattern))
  copy(song+pos,song+pos+sizePattern,curPattern);
  sort(pattern,pattern+sizePattern) ;
  sort(curPattern,curPattern+sizePattern) ;
  const int diff = curPattern[0] - pattern[0] ; // compare both min
  for(int i = 1 ; i < sizePattern ; i++)
    if(curPattern[i] - pattern[i] != diff) // all need to be equal
      return false ;
  return true;
}

int main () {
  // reading input
  scanf("%d\n",&sizeSong);
  for(int id = 0 ; id < sizeSong ; id++ )
    scanf("%d\n",song+id) ;
  scanf("%d\n",&sizePattern);
  for(int id = 0 ; id < sizePattern ; id++ )
    scanf("%d\n",pattern+id) ;

  // main algorithm check all positions for matches
  // O( sizeSong × sizePattern log(sizePattern ))
  vector<int> matchs ;
  for(int pos = 0 ; pos+sizePattern <= sizeSong ; pos++)
    if(doMatch(pos))
      matchs.push_back(pos+1);

  // print out matches
  printf("%lu\n",matchs.size());
  for(int m : matchs)
    printf("%d\n",m);
  return 0;
}
