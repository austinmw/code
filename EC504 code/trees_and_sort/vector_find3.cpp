#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef string KeyType;

typedef string DataType;

struct PairType{
  KeyType key;
  DataType data;
} ;

bool compPairs(PairType v1,PairType v2){
   return v1.key < v2.key;
}

int search(const vector<PairType> & d,KeyType find_this){

 int middle,bottom,top;
  bottom=0;
  top=d.size();
  middle=top/2;

  while ( (top>bottom) and (d[middle].key != find_this) )
  {
   if (find_this > d[middle].key)
       bottom = middle+1;
   else 
       top = middle-1;

   middle = (bottom+top)/2;
  }
 
  if (d[middle].key == find_this)
    return middle;
  else
    return -1;
}


int main(int argc, char const *argv[])
{
  int NumVals=stoi(argv[1]);
  int NumFind=stoi(argv[2]);

  bool testing = (argc > 3) ? true : false;

  vector<PairType> database(NumVals);

	vector<KeyType> f(NumFind);
   

    for (int ii=0; ii < NumVals; ii++){
    	cin >> database[ii].key >> database[ii].data;

    }

    for (int ii=0; ii < NumFind; ii++)
    	cin >> f[ii];

   
    // Find the 3 nearest values in v to each value in f.


   sort(database.begin(),database.end(),compPairs);

  if (testing) {
     for (auto it = database.begin() ; it != database.end(); it++)
        cout << "k: " << it->key << ", d: " << it->data <<endl; 
   }

  for (auto keytofind : f) {

     int loc = search(database,keytofind);

     if (loc > 0){
       if (testing){
       cout << "Found " << keytofind <<endl;
       cout << "predecessor" <<endl;
       if (loc>0) cout << "k: " << database[loc-1].key << ", d: " << database[loc-1].data <<endl; 
       cout << "value" <<endl;
       cout << "k: " << database[loc].key << ", d: " << database[loc].data <<endl; 
       cout <<"successor" << endl;
       if (loc < NumVals-1) cout << "k: " << database[loc+1].key << ", d: " << database[loc+1].data <<endl; 
      }
      else {

        cout << ( (loc>0)         ? database[loc-1].data : "-end-") << " " 
             <<                     database[loc].data << " " 
             << ( (loc<NumVals-1) ? database[loc+1].data : "-end-") << endl;
      }
     }

  }

  // Next steps:
  // -implement same features using map
  // -randomize test strings (100,000 v 100)
  // -use python to generate data and time.
  //
	return 0;
}